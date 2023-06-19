// map学习
#include <iostream>
#include <map>
#include <set>
using namespace std;
int main()
{
    set<int> s;
    s.insert(1);
    s.insert(0);
    int t = 1;
    cout << s.count(t) << endl;
    cout << *s.find(t) << endl;
    return 0;
}