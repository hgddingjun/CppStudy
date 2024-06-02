#include <iostream>

using namespace std;

class complex {
public:
    complex(double r, double i) : re{r}, im{i} {}
    complex(double r) : re{r}, im{0} {}
    complex() : re{0}, im{0} {}
    double real() const {return re;}
    void real(double d) {re = d;}
    double imag() const {return im;}
    void imag(double d) {im = d;}

    complex& operator+=(complex z) { re+=z.re; im+=z.im; return *this; }
    complex& operator-=(complex z) { re-=z.re; im-=z.im; return *this; }

//    complex& operator*=(complex);
//    complex& operator/=(complex);

    virtual ~complex() {}

private:
    double re;
    double im;
};

complex operator+(complex a, const complex b) { return a+=b; }
complex operator-(complex a, const complex b) { return a-=b; }
complex operator-(complex a) { return{ -a.real(), -a.imag()}; }
//complex operator*(complex a, const complex b) { return a*=b; }
//complex operator/(complex a, const complex b) { return a/=b; }

bool operator==(const complex a, const complex b)
{
    return ( a.real()==b.real() && a.imag()==b.imag() );
}

bool operator!=(const complex a, const complex b)
{
    return !(a==b);
}
int main()
{
    cout << "Complex Math!" << endl;
    return 0;
}
