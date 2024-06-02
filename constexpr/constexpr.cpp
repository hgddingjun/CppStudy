// 作者：Codebowl靓仔
// 链接：https://www.zhihu.com/question/35614219/answer/2077809581
// 来源：知乎
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

// ### constexpr：常量表达式  
// constexpr（常量表达式）：是指值不会改变并且在编译过程就能得到计算结果的表达式。  
// 常量表达式的优点是将计算过程转移到编译时期，那么运行期就不再需要计算了，程序性能也就提升了。  
// const好用，但是在某些情况下，我们还是会被它所谓的”常量“，给迷惑，产生错误用法，那既然如此，到底有没有真正的常量定义呢！  
// 答案：有的。  
// C++11 提供了 constexpr 让用户显式的声明函数或对象构造函数在编译期会成为常量表达式，这 个关键字明确的告诉编译器应该去验证  
// constexpr定义的值在编译期就应该是一个常量表达式。  
// 
// constexpr int len = 5;  
// int a[len];  
// 此时使用合法！  
// 
// ### constexpr定义函数  
// constexpr int LengthConstexpr()  
// {  
//     return 5;  
// } 
// 
// char arr2[LengthConstexpr() + 1]; // 合法  
// constexpr返回值也是常量！ 
//   
// 但是constexpr函数和正常函数肯定是不一样的，因为它需要在编译期做事，需要有一定的使用限制！  
// 从C++11开始，constexpr函数不仅可以返回常量，还可以进行递归操作。  
// constexpr int fibonacci(const int n)   
// {  
//     return n == 1 || n == 2 ? 1 : fibonacci(n-1)+fibonacci(n-2);  
// }  
// 从 C++14 开始，constexpr 函数可以在内部使用局部变量、循环和分支等简单语句。  
// constexpr int fibonacci(const int n)   
// {  
// 	if(n == 1) return 1;  
// 	if(n == 2) return 1;  
// 	return fibonacci(n-1) + fibonacci(n-2);  
// }  
// ### 编译期的优化  
// C++ 本身已经具备了常量表达式的概念，比如 1+2, 3*4 这种表达式总是会产生相同的结果并且没 有任何副作用。如果编译器能够在编译时就把这些表达式直接优化并植入到程序运行时，将能增加程序的性能。 

#include <ctime>
#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;

const int TEST_COUNT = 100000000;

constexpr int Calculate1 (int x, int y)
{
    return x * y * 32 / 14;
}
int Calculate2 (int x, int y)
{
    return x * y * 32 / 14;
}

int main(void)
{
    auto start = system_clock::now();
    for(int i = 0;i <TEST_COUNT ; i++)
    {
//也可以换成const修饰，也是常量表达式
        constexpr int ret = Calculate1 (11, 12); 
    }
    auto end = system_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    auto spendtime = double(duration.count()) * microseconds::period::num / microseconds::period::den;
    cout<< "[1] spend time: " << spendtime <<" us" << endl;
       
    start = system_clock::now();
    for(int i = 0;i < TEST_COUNT; i++)
    {
//不能用constexpr修饰，不是常量表达式，会编译报错
        int ret = Calculate2 (11, 12);
    }
    end = system_clock::now();
    duration = duration_cast<microseconds>(end - start);
    spendtime = double(duration.count()) * microseconds::period::num / microseconds::period::den;
    cout<< "[2] spend time: " << spendtime <<" us" << endl;
    return 0;
}

// [1] spend time: 0.121507 us
// [2] spend time: 0.183504 us
// 
// [1] spend time: 0.118966 us
// [2] spend time: 0.182768 us
// 
// [1] spend time: 0.1192 us
// [2] spend time: 0.184798 us
// 
// [1] spend time: 0.120369 us
// [2] spend time: 0.184354 us
// 
// [1] spend time: 0.119698 us
// [2] spend time: 0.183629 us

