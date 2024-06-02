#include <iostream>
#include <algorithm>
#include <vector>

namespace mySTD {
    using namespace std;

    template <typename T>
    void sort(T& c) {
        sort(c.begin(), c.end());
    }

    template <typename T, typename Pred>
    void sort(T& c, Pred p) {
        sort(c.begin(), c.end(), p);
    }
}

int main()
{
    std::vector<std::string> vs {"red", "green", "blue", "green", "orange", "green"};
    std::cout << "Before sort Strings: ";
    for(auto s : vs)
        std::cout << s << " ";
    std::cout << std::endl;
    mySTD::sort(vs);
    std::cout << "After  sort Strings: ";
    for(auto s : vs)
        std::cout << s << " ";
    std::cout << std::endl;
    std::cout << "Template program sort!" << std::endl;
    return 0;
}
