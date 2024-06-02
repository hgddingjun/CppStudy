#include <iostream>

using namespace std;

#if 1

template <>
class CCopy<0> {
public:
    static inline go(float* const out, float* const in, int i)
    {
    }
};

template <int count>
class CCopy {
public:
    static inline go(float* const out, float* const in, int i)
    {
        CCopy<count-1>::go(out, in, i);
        out[count][i] = in[count][i];
    }
};

template<int channelNum>
void pall_copy(float** out, float** in, size_t length)
{
    for(size_t i=0; i<length; ++i)
    {
        CCopy<channelName>::go(out, in, i);
    }
}

int main()
{
    return 0;
}

#else
template <typename T>
inline T const& Max(T const& a, T const& b)
{
    return a<b ? b : a;
}

int main()
{
    int i = 39;
    int j = 20;
    cout << "Max(i,j):" << Max(i,j) << endl;

    double f1 = 14.5;
    double f2 = 20.7;
    cout << "Max(f1,f2):" << Max(f1,f2) << endl;

    string s1 = "Hello C++!";
    string s2 = "World";
    cout << "Max(s1,s2):" << Max(s1,s2) << endl;
    return 0;
}
#endif
