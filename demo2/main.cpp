#include <iostream>

using namespace std;

int fibonacci(int number) {
    if (number < 3) {
        return 1;
    }
    return fibonacci(number - 1) + fibonacci(number - 2);
}

void fib_driver(int number) {
    cout << "fibonacci(" << number << ")=" << fibonacci(number) << endl;
}

int main()
{
    fib_driver(1);
    fib_driver(2);
    fib_driver(3);
    fib_driver(4);
    fib_driver(5);
    cout << "Hello world!" << endl;
    return 0;
}
