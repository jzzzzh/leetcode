#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int rearrangeCharacters(string s, string target)
{
    int arrtarget[26];
    int arrs[26];
    for (int i = 0; i < 26; i++)
    {
        arrtarget[i] = 0;
        arrs[i] = 0;
    }
    for (char ch : s)
    {
        arrs[ch - 'a']++;
    }
    for (char ch : target)
    {
        arrtarget[ch - 'a']++;
    }
    int mymax = -1;
    for (int i = 0; i < 26; i++)
    {
        if (arrtarget[i] != 0)
        {
            if (mymax == -1)
            {
                mymax = arrs[i] / arrtarget[i];
            }
            else
            {
                mymax = min(arrs[i] / arrtarget[i], mymax);
            }
        }
    }
    if (mymax == -1)
        mymax = 0;
    return mymax;
}
int main()
{
    string s = "ilovecodingonleetcode", target = "code";
    int ans = rearrangeCharacters(s, target);
    cout << ans << endl;
}