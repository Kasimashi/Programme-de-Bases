#include <iostream>


class Boisson {
 public:
  virtual ~Boisson() {}
  virtual std::string Description() const = 0;
  virtual double prix() = 0;
};

class Coffee : public Boisson {
private:
	double _price = 2; // 2€ le café.
 public:
  std::string Description() const override {
    return "Je suis un café";
  }
  double prix() {
	  return _price;
  }
};

class DecoratorCoffee : public Boisson {
 protected:
	Boisson* component_;
 public:
	DecoratorCoffee(Boisson* component) : component_(component) {
  }
  std::string Description() const override {
    return this->component_->Description();
  }
  double prix() {
  	  return this->component_->prix();
    }
};

class Sucre : public DecoratorCoffee {
private:
	double _price = 1.0; // 1€ le sucre
 public:
	Sucre(Boisson* component) : DecoratorCoffee(component) {
  }
  std::string Description() const override {
    return "Je rajoute du sucre dans (" + DecoratorCoffee::Description() + ")";
  }
  double prix() {
	  return DecoratorCoffee::prix() + _price;
  }

};

class Lait : public DecoratorCoffee {
private:
	double _price = 3.0; // 3€ le lait
 public:
	Lait(Boisson* component) : DecoratorCoffee(component) {
  }

  std::string Description() const override {
    return "Je rajoute du lait dans (" + DecoratorCoffee::Description() + ")";
  }
  double prix() {
	  return DecoratorCoffee::prix() + _price;
  }

};

class Chantilly : public DecoratorCoffee {
private:
	double _price = 2.0; // 2€ la chantilly
 public:
	Chantilly(Boisson* component) : DecoratorCoffee(component) {
  }

  std::string Description() const override {
    return "Je rajoute de la chantilly dans (" + DecoratorCoffee::Description() + ")";
  }
  double prix() {
	  return DecoratorCoffee::prix() + _price;
  }

};

int main() {

  Boisson* Cafe = new Coffee;
  std::cout << Cafe->Description() << "\n";

  Boisson* CafeDecore = new Chantilly(new Lait(new Sucre(Cafe)));
  std::cout  << CafeDecore->Description() << "\n";
  std::cout  << "Le prix total de mon café est de : " << CafeDecore->prix() << "€ \n";

  delete Cafe;
  delete CafeDecore;

  return 0;
}
