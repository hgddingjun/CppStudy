#include <iostream>

using namespace std;

class CVector {
public:
    explicit CVector(size_t size)
    : sz(size),
      elem(new double[sz])
    {
    }
    ~CVector()
    {
        delete [] elem;
    }
    double& operator [](int i)
    {
        return elem[i];
    }
    size_t size(void)
    {
        return sz;
    }
    CVector(const CVector& other ); //拷贝构造函数

    CVector& operator=(const CVector& other); //赋值构造函数

private:
    size_t sz;
    double* elem;
};

//拷贝构造函数
CVector::CVector(const CVector& other)
    : sz(size()),
      elem(new double[sz])
{
    for(int i=0; i!=sz; i++)
    {
        elem[i] = other.elem[i];
    }

}

//赋值构造函数
CVector& CVector::operator=(const CVector& other)
{
    //如果引用地址就是对象本身，则直接返回this指针
    if(&other == this)
        return *this;

    double *ptr = new double[other.sz];
    for(int i=0; i!=sz; i++)
    {
        ptr[i] = other.elem[i];
    }
    delete [] elem; //删除old元素
    elem = ptr;
    sz = other.sz;
    return *this;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
