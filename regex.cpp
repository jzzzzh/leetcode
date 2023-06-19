#include <regex>
#include <iostream>
using namespace std;
int main()
{
    regex re("[1,2,3]*");
    auto ans = regex_match("111", re);
    auto ans2 = regex_match("44", re);
    cout << ans << ans2;
}