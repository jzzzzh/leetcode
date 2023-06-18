#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int a, b;
        bool flag = false;
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = target - nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] == temp)
                {
                    a = i;
                    b = j;
                    flag = true;
                    break;
                }
            }
            if (flag == true)
                break;
        }
        return {a, b};
    }
    
};