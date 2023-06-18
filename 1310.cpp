#include <iostream>
#include <vector>
using namespace std;
// 有一个正整数数组 arr，现给你一个对应的查询数组 queries，其中 queries[i] = [Li, Ri]。
// 对于每个查询 i，请你计算从 Li 到 Ri 的 XOR 值（即 arr[Li] xor arr[Li+1] xor ... xor arr[Ri]）作为本次查询的结果。
// 并返回一个包含给定查询 queries 所有结果的数组。

vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    vector<int> ans;
    int arrlenth = arr.size();
    int arrarr[arrlenth + 1];
    arrarr[0] = 0;
    arrarr[1] = arr[0];
    for (int i = 1; i < arrlenth; i++)
    {
        arrarr[i + 1] = arrarr[i] xor arr[i];
    }
    for (vector<int> x : queries)
    {
        if (x[0] != x[1])
            ans.push_back(arrarr[x[0]] xor arrarr[x[1] + 1]);
        else
        {
            ans.push_back(arr[x[0]]);
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {4, 8, 2, 10};
    vector<vector<int>> queries = {{2, 3}, {1, 3}, {0, 0}, {0, 3}};
    vector<int> ans = xorQueries(arr, queries);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
}