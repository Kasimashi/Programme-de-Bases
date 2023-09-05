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
    return "Un café";
  }
  double prix() {
	  return _price;
  }
};

class Expresso : public Boisson {
private:
	double _price = 1.5; // 1.5€ l'expresso
 public:
  std::string Description() const override {
    return "Un expresso";
  }
  double prix() {
	  return _price;
  }
};

class DecoratorBoisson : public Boisson {
 protected:
	Boisson* component_;
 public:
	DecoratorBoisson(Boisson* component) : component_(component) {
  }
};

class Sucre : public DecoratorBoisson {
private:
	double _price = 1.0; // 1€ le sucre
 public:
	Sucre(Boisson* component) : DecoratorBoisson(component) {
  }
  std::string Description() const override {
    return "Je rajoute du sucre dans (" + component_->Description() + ")";
  }
  double prix() {
	  return component_->prix() + _price;
  }

};

class Lait : public DecoratorBoisson {
private:
	double _price = 3.0; // 3€ le lait
 public:
	Lait(Boisson* component) : DecoratorBoisson(component) {
  }

  std::string Description() const override {
    return "Je rajoute du lait dans (" + component_->Description() + ")";
  }
  double prix() {
	  return component_->prix() + _price;
  }

};

class Chantilly : public DecoratorBoisson {
private:
	double _price = 2.0; // 2€ la chantilly
 public:
	Chantilly(Boisson* component) : DecoratorBoisson(component) {
  }

  std::string Description() const override {
    return "Je rajoute de la chantilly dans (" + component_->Description() + ")";
  }
  double prix() {
	  return component_->prix() + _price;
  }

};

int main() {

	Boisson* Cafe = new Coffee;
	std::cout << Cafe->Description() << "\n";


	DecoratorBoisson *sucre1 = new Sucre(Cafe);
	DecoratorBoisson *lait1 = new Lait(sucre1);
	DecoratorBoisson *chantilly1 = new Chantilly(lait1);

	Boisson* CafeDecore = chantilly1;

	std::cout  << CafeDecore->Description() << "\n";
	std::cout  << "Le prix total de mon café est de : " << CafeDecore->prix() << "€ \n";

	delete Cafe;
	delete chantilly1;
	delete lait1;
	delete sucre1;


	Boisson* expresso = new Expresso();

	DecoratorBoisson *sucre2 = new Sucre(expresso);
	DecoratorBoisson *lait2 = new Lait(sucre2);
	DecoratorBoisson *chantilly2 = new Chantilly(lait2);

	Boisson* expressoDecore = chantilly2;

	std::cout  << "Le prix total de mon expresso est de : " << expressoDecore->prix() << "€ \n";

	delete expresso;
	delete chantilly2;
	delete lait2;
	delete sucre2;

  return 0;
}
