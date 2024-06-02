#include <iostream>

using namespace std;

class CBase {
public:
    CBase()
    {
        cout << "base constructor" << endl;
    }

    virtual void foo (void)
    {
        cout << "Base foo()!" << endl;
    }

    virtual ~CBase()
    {
        cout << "base destructor" << endl;
    }
};

class CDerived : public CBase {
public:
    CDerived()
    {
        cout << "derived constructor" << endl;
    }

    virtual void foo(void)
    {
        cout << "Derived foo()!" << endl;
    }

    virtual ~CDerived()
    {
        cout << "derived destructor" << endl;
    }
};

int main()
{
    CBase *b1 = new CDerived;
    b1->foo();
    delete b1;
    return 0;
}
