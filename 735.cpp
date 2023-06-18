#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> ans = {};
        int p = 1;
        bool flag = true;
        while (flag == true)
        {
            flag = false;
            int i;
            // cout << asteroids.size() << ",,";
            for (i = 0; i < asteroids.size() - 1; i++)
            {
                if (!(asteroids[i] > 0 && asteroids[i + 1] < 0))
                {
                    ans.push_back(asteroids[i]);
                    // cout << asteroids[i] << ",";
                }
                else
                {
                    flag = true;
                    int add = asteroids[i] + asteroids[i + 1];
                    cout << asteroids[i] << ":" << asteroids[i + 1] << endl;
                    // cout << add << endl;
                    if (add > 0)
                    {
                        ans.push_back(asteroids[i]);
                        i++;
                        // cout << i << ";";
                    }
                    else if (add < 0)
                    {
                        ans.push_back(asteroids[i + 1]);
                        i++;
                    }
                    else
                    {
                        i += 1;
                        cout << i << endl;
                        // cout << "-1:1" << endl;
                        // cout << i << endl;
                    }
                }
            }
            cout << i << endl;
            if (i < asteroids.size())
            {
                ans.push_back(asteroids[i]);
            }
            if (ans.size() == 0)
                flag = false;
            if (flag == true)
            {
                asteroids = ans;
                ans = {};
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> asteroids = {-2, 1, -1, -2, 1};
    Solution solution;
    vector<int> ans = solution.asteroidCollision(asteroids);
    for (auto i : ans)
    {
        cout << i << ",";
    }
    cout << endl;
}