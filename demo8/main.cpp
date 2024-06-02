#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

#if 1
int main()
{
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
    return 0;
}
#elif 0
int main()
{
    map<string, int> mapOfWords;

    mapOfWords.insert(std::make_pair("earth", 1));
    mapOfWords.insert(std::make_pair("water", 2));

    mapOfWords["sun"] = 3;

    for(auto& e : mapOfWords)
    {
        cout << "first:" << e.first << " , " << "second:" << e.second << endl;
    }

    if(mapOfWords.find("sun") != mapOfWords.end()) {
        cout << "find search element: sun" << endl;
    }
    return 0;
}
#elif 0
int main()
{
    list<int> intList = {1,2,3,4,5};
    list<int>::iterator p = intList.begin();
    cout << "list p: " << *p <<endl;

    advance(p,2);
    cout << "2nd p: " << *p <<endl;

    auto q = intList.end();
    q--;
    cout << "1st q: " << *q <<endl;

    cout << "distance: " << distance(p,q) <<endl;

    iter_swap(p,q);
    cout << "after swapping: " <<endl;
    for(auto& e : intList)
    {
        cout << e << " ";
    }
    cout << endl;
    return 0;
}

#else
int main()
{
    vector<int> vecInt;
    cout << "vecInt.size()=" << vecInt.size() << endl;
    vecInt.push_back(42);
    cout << "vecInt.size()=" << vecInt.size() << endl;

    vecInt.push_back(100);
    cout << "vecInt.size()=" << vecInt.size() << endl;
    vecInt.push_back(120);
    cout << "vecInt.size()=" << vecInt.size() << endl;
    cout << "vecInt.capacity()=" << vecInt.capacity() << endl;





    vector<int>::iterator iter = vecInt.begin();
    //cout <<"vecInt.begin()=" << vecInt.begin() << endl;
    //cout <<"vecInt.end()=" << vecInt.end() << endl;
    while(vecInt.end() != iter)
    {
        cout << "value of vecInt: " << *iter << endl;
        ++iter;
     }

    return 0;
}
#endif // 1
