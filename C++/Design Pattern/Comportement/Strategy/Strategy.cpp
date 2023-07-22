#include <iostream>

/*
 * Strategy
 * declares an interface common to all supported algorithms
 */
class Strategy
{
public:
  virtual ~Strategy() { /* ... */ }
  virtual void algorithmInterface() = 0;
  // ...
};

/*
 * Concrete Strategies
 * implement the algorithm using the Strategy interface
 */
class ConcreteStrategyA : public Strategy
{
public:
  ~ConcreteStrategyA() {}
  
  void algorithmInterface()
  {
    std::cout << "Concrete Strategy A" << std::endl;
  }
};

class ConcreteStrategyB : public Strategy
{
public:
  ~ConcreteStrategyB() {}
  
  void algorithmInterface()
  {
    std::cout << "Concrete Strategy B" << std::endl;
  }
};

class ConcreteStrategyC : public Strategy
{
public:
  ~ConcreteStrategyC() {}
  
  void algorithmInterface()
  {
    std::cout << "Concrete Strategy C" << std::endl;
  }
};

/*
 * Context
 * maintains a reference to a Strategy object
 */
class Context
{
private :
	void clearStategy()
	{
		if(strategy)
		{
			delete strategy;
			strategy = NULL;
		}
	}
public:
  Context(Strategy *s) : strategy( s ) {
  }
  
  ~Context()
  {
	  clearStategy();
  }
  
  void proccess()
  {
	  if (strategy != NULL){
		  strategy->algorithmInterface();
	  }

  }

	void setStrategy(Strategy *strategy)
	{
		clearStategy();
		this->strategy = strategy;
	}


private:
  Strategy *strategy;
};


int main()
{
  Context* context = new Context(new ConcreteStrategyA ());
  context->proccess();
  context->setStrategy( new ConcreteStrategyB() );
  context->proccess();
  context->setStrategy( new ConcreteStrategyC() );
  context->proccess();

  return 0;
}
