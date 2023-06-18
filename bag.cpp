#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool test(string s, vector<string> &wordDict)
{
    bool arr[s.size() + 1] = {0};
    for (int i = 0; i < s.size() + 1; i++)
    {
        arr[i] = 0;
    }
    arr[0] = true;
    for (int i = 1; i < s.size() + 1; i++)
    {
        for (int j = 0; j < wordDict.size(); j++)
        {
            if (arr[i] == false && i >= wordDict[j].size() && s.substr(i - wordDict[j].size(), wordDict[j].size()) == wordDict[j])
            {
                arr[i] = arr[i - wordDict[j].size()];
            }
        }
    }
    for (int i = 0; i < s.size() + 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return arr[s.size()];
}
int main()
{
    string s = "dogs";
    vector<string> wordDict = {"dog", "s", "gs"};
    cout << test(s, wordDict);
}