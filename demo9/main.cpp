#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <memory>
#include <vector>
#include <algorithm>
#include <forward_list>
using namespace std;


#if 1

template <typename C>
using Value_type = typename C::value_type;  //C's value type

template <typename C>
using Iterator_type = typename C::iterator; //C's iterator type

template <typename Iter>
using Iterator_category = typename std::iterator_traits<Iter>::iterator_category;//Iter's category


template <typename RA> //random access iterators
void sort_helper(RA beg, RA end, random_access_iterator_tag)
{
    std::sort (beg,end);
}


template <typename For> //forward iterators
void sort_helper(For beg, For end, forward_iterator_tag)
{
    vector<Value_type<For>> v {beg, end};
    sort(v.begin(), v.end());
    //copy(v.begin, v.end(), beg); //copy the elements back
}


template <typename C>
void MySort(C& c)
{
    using Iter = Iterator_type<C>;
    sort_helper(c.begin(), c.end(), Iterator_category<Iter>{});
}

void test(vector<string>& v, forward_list<int>& sl)
{
    MySort(v);
    MySort(sl);
}


int main()
{
    return 0;
}
#elif 0
template <typename T>
void print(const vector<T>& v)
{
    for(T n : v) {
        cout << n << " ";
    }
    cout << endl;
}

class IncreasingNumberGenerator {
public:
    int operator()() noexcept {
        return number++;
    }
private:
    int number {0};
};

int main()
{//functor
    const size_t AMOUNT_OF_NUMBER (10);
    vector<int> number (AMOUNT_OF_NUMBER);
    std::generate(std::begin(number), std::end(number), IncreasingNumberGenerator());
    print(number);
    return 0;
}
#elif 0
int main()
{//lambda
    vector<string> quote {"this", "is", "a", "C++", "class"};
    vector <string> result;
    transform(begin(quote), end(quote), back_inserter(result),
              [](const string& word){
                  return "<" + word + ">";
              } );
    for_each(begin(result), end(result),
             [](const string& word){
                cout << word << " ";
             });
    cout << endl;

    string name = "lambda function square called";
    auto square = [&name](const auto& value)
    {//C++14 generic lambda
        name = "inside lambda function";
        cout << name << endl;
        return value*value;
    };

    cout << square(10) << endl;
    cout << square(11.11) << endl;
    cout << square('a') << endl;
    return 0;
}
#elif 0
class ResourceType {
public:
    void foo() { cout << "foo called!" << endl; }
    //...
};

void doWork(const weak_ptr<ResourceType>& wptr)
{
    if(wptr.expired()) return;
    auto shareResource = wptr.lock();
    // more work here ...
}

int main()
{
    shared_ptr<ResourceType> r1 {std::make_shared<ResourceType>()};

    weak_ptr<ResourceType> weakResource(r1);

    doWork(weakResource);
    r1.reset();
    doWork(weakResource);
    return 0;
}
#elif 0
class ResourceType {
public:
    void foo() { cout << "foo called!" << endl; }
    //...
};

using ResourceVector = vector<shared_ptr<ResourceType>>;

int main()
{
    //ResourceType* nakePtr = new ResourceType;

    shared_ptr<ResourceType> r1 {std::make_shared<ResourceType>()};

    auto r2 {std::make_shared<ResourceType>()};

    r1->foo();

    shared_ptr<ResourceType> r3 = r2;//std::move(r2);

    ResourceVector vec;
    vec.push_back(std::move(r3));

    return 0;
}
#elif 0
class ResourceType {
public:
    void foo() { cout << "foo called!" << endl; }
    //...
};

using ResourceVector = vector<unique_ptr<ResourceType>>;

int main()
{
    //ResourceType* nakePtr = new ResourceType;

    unique_ptr<ResourceType> r1 {std::make_unique<ResourceType>()};

    auto r2 {std::make_unique<ResourceType>()};

    r1->foo();

    unique_ptr<ResourceType> r3 = std::move(r2);

    ResourceVector vec;
    vec.push_back(std::move(r3));

    return 0;
}
#elif 0
class MyException : public exception {
public:
    string msg() const {
        return "my exception";
    }
};

class A {
public:

    A() { cout << "A constructor called!" <<endl;}
    ~A() { cout << "A destructor called!" <<endl;}

};

int main()
{
    try {

        throw MyException();
        A a;
    } catch (MyException& e) {
        cout << "MyException caught:" << endl;
        cout << e.msg() << endl;
    }
    return 0;
}
#else

int main()
{
    ofstream outfile;
    outfile.open("myfile.data");

    cout << "enter some data:" << endl;

    char data[100] = {0};
    cin.getline(data, 100);


    cout << "outfile content is:" << endl;
    outfile << data << endl;

    outfile.close();

    ifstream infile;

    //char* p = new char[100];
    char ch;
    infile.open("myfile.data");
    cout << "read file content is:" << endl;
    while(infile.get(ch))
    {
        cout << ch;
    }
    cout << endl;
    infile.close();
    //delete [] p;
    return 0;
}
#endif // 1
