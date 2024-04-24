/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <iostream>
#include <string>
using namespace std;

class FlyBehavior
{
public:
    virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior
{
public:
    void fly()
    {
        cout << "I'm flying!!" << endl;
    }
};

class FlyNoWay : public FlyBehavior
{
public:
    void fly()
    {
        cout << "I can't fly" << endl;
    }
};

class QuackBehavior
{
public:
    virtual void quack() = 0;
};

class Quack : public QuackBehavior
{
public:
    void quack()
    {
        cout << "Quack" << endl;
    }
};

class MuteQuack : public QuackBehavior
{

public:
    void quack()
    {
        cout << "<< Silence >>" << endl;
    }
};

class Squeak : public QuackBehavior
{
public:
    void quack()
    {
        cout << "Squeak" << endl;
    }
};

class Duck
{
private:
    FlyBehavior *flyBehavior;
    QuackBehavior *quackBehavior;
public:
    Duck(){};
    void performFly()
    {
        flyBehavior->fly();
    }
    void performQuack()
    {
        quackBehavior->quack();
    }
    void swim()
    {
        cout << "All ducks float, even decoys!" << endl;
    }
    void setFlyBehavior(FlyBehavior *fb)
    {
        flyBehavior = fb;
    }
    void setQuackBehavior(QuackBehavior *qb)
    {
        quackBehavior = qb;
    }
};

class MallardDuck : public Duck
{
public:
    MallardDuck()
    {
        setFlyBehavior(new FlyWithWings());
        setQuackBehavior(new Quack());
    }
};

class ModelDuck : public Duck
{
public:
    ModelDuck()
    {
        setFlyBehavior(new FlyNoWay());
        setQuackBehavior(new Quack());
    }
    void display()
    {
        cout << "I'm a model duck" << endl;
    }
};

class FlyRocketPowered : public FlyBehavior
{
public:
    void fly()
    {
        cout << "I'm flying with a rocket" << endl;
    }
};

int main()
{
    Duck *model = new ModelDuck();
    model->performFly();
    model->setFlyBehavior(new FlyRocketPowered());
    model->performFly();
    model->performQuack();
    model->swim();
    return 0;
}