#include <iostream>

using namespace std;

void bar()
{
    return;
}

void foo(int i, int j)
{
    int a = i+j;
    return;
}

int main()
{
    //int matrix[10][10] = {'c'};
    int a = 100;
    int b = 50;

    foo(a, b);
    bar();

    return 0;
}
