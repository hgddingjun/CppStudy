#include <iostream>
#include <vector>
#include <list>

using namespace std;

class CContainer {
public:
    CContainer(){}

    //虚函数必须要实现
    virtual double& operator[](int i);
    virtual size_t size(void);

    virtual ~CContainer() {}
};

class CVector : public CContainer {
public:
    CVector(initializer_list<double> v)
    : m_Vector(v) {}

    ~CVector() {}

    virtual double& operator[](int i)
    {
        return m_Vector[i];
    }

    virtual size_t size(void)
    {
        return m_Vector.size();
    }
private:
    std::vector<double> m_Vector;
};

class CList : public CContainer {
public:
    CList(initializer_list<double> l)
    : m_List(l){}

    ~CList() {}

    virtual double& operator[](int i)
    {
        for(auto& x : m_List)
        {
            if(0 == i) return x;
            --i;
        }
        throw out_of_range("list container");
    }

    virtual size_t size(void)
    {
        return m_List.size();
    }
private:
    std::list<double> m_List;
};

void display(CContainer& c)
{
    const size_t sz = c.size();
    for (int i=0; i<sz; i++)
    {
        cout << c[i] << endl;
    }
}

void g()
{
    CVector vc = {10., 9., 8., 0.};
    display(vc);
}

void h()
{
    CList lt = {1., 3., 5., 7.};
    display(lt);
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
