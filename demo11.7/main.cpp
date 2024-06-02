#include <map>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

//input: Container (string, list, vector)
//output: Container of element of element that support *(point) operation
//T1::value
//typename T1::value_type
//模板元编程
template <typename T>
using FindIterator = typename T::iterator;

template <typename T1, typename T2>
//vector<typename T1::iterator>
vector<FindIterator<T1>>
find_all(T1& c, T2 v)
{
    //vector<typename T1::iterator> res;
    vector<FindIterator<T1>> res;
    for (auto p=c.begin(); p!=c.end(); ++p) {
        if(*p == v)
            res.push_back(p);
    }
    return res;
}

void run()
{
    string m {"Mary had a little lamb"};
    for (auto p : find_all(m, 'a'))
        if(*p != 'a')
            cerr << "string bug!" << endl;
        else
            cout << *p << " ";
        cout << endl;

    list<double> ld {1.1, 2.2, 3.3, 1.1};
    for (auto p : find_all(ld, 1.1))
        if(*p != 1.1)
            cerr << "list bug!" << endl;
        else
            cout << *p << " ";
        cout << endl;

    vector<string> vs {"red", "green", "blue", "green", "orange", "green"};
    for (auto p : find_all(vs, "red"))
        if(*p != "red")
            cerr << "vector bug!" << endl;
        else
            cout << *p << " ";
        cout << endl;

    for (auto p : find_all(vs, "green")) {
            *p = "changed";
        cout << *p << " ";
    }
    cout << endl;
}
int main()
{
    run();
    cout << "Template program!" << endl;
    return 0;
}
