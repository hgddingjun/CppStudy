#include <iostream>

using namespace std;
class Animal {
public:
    virtual void PrintFunc(void) const {
        cout <<"This is Animal!"<< endl;
    }
};

class Dog : public Animal {
public:
    void PrintFunc(void) const {
        cout <<"This is Dog!"<< endl;
  }
};

class Cat : public Animal {
public:
    void PrintFunc(void) const {
        cout <<"This is Cat!"<< endl;
  }
};

void myPrint(Animal& animal) {
    animal.PrintFunc();
}

int main(void)
{
    cout << "Welcome to C++ polymorphic world!" << endl;
    Dog d;
    Cat c;
    Animal& a1 = d;
    Animal& a2 = c;
    myPrint(a1);
    myPrint(a2);
    return 0;
}
