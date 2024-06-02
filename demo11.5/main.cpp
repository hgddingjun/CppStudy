#include <iostream>

using namespace std;

template <std::size_t N>
struct stFibonacci {
   static constexpr const std::size_t value = stFibonacci<N-1>::value + stFibonacci<N-2>::value;
};

//特化1的情况
template <>
struct stFibonacci<1> {
    static constexpr const std::size_t value = 1;
};

//特化0的情况
template <>
struct stFibonacci<0> {
    static constexpr const std::size_t value = 0;
};

int main()
{
    cout << "Fibonacci<900>:" << stFibonacci<900>::value << endl;
    return 0;
}
