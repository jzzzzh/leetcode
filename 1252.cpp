#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution
{
public:
    int oddCells(int m, int n, vector<vector<int>> &indices)
    {
        int ans = 0;
        int a[m];
        int b[n];
        memset(a, 0, sizeof(int) * m);
        memset(b, 0, sizeof(int) * n);
        for (int i = 0; i < indices.size(); i++)
        {
            a[indices[i][0]]++;
            b[indices[i][1]]++;
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans += ((a[i] + b[j]) % 2 == 1 ? 1 : 0);
            }
        }
        return ans;
    }
};

int main()
{
    int m = 48;
    int n = 37;
    vector<vector<int>> indices = {{40, 5}};
    Solution s;
    cout << s.oddCells(m, n, indices);
}