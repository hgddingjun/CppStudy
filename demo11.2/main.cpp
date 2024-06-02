#include <vector>
#include <iostream>


#if 1
void foo(const char **p)
{
    const char* p2 = "world";
    pp = &p2;
    pp = nullptr;

    *pp = "world";
    return ;
}

int main()
{
    const char *p = "hello";
    foo(&p);
    return 0;
}
#elif 0
void bar1()
{
    return;
}

void bar ()
{
    return;
}

int main()
{
    bar();
    return 0;
}
#elif 0
void foo()
{
    return foo();
}

int main()
{
    foo();
    return 0;
}

#else

using namespace std;

unsigned long fibonacci(unsigned long n)
{
    static std::vector<unsigned long> memo = {0,1};

    if (n < memo.size()) {
        return memo[n];
    } else {
        unsigned long res = fibonacci(n-1) + fibonacci(n-2);
        memo.push_back(res);
        return res;
    }
}

int main()
{
    int a = 500;
    cout << "fibonacci(" << a << ")=" << fibonacci(a) << endl;
    return 0;
}

#endif // 1
