#include <iostream>
#include <vector>
using namespace std;
bool canPartition(vector<int> &nums)
{
    int arrsum = 0;
    int max = nums[0];
    for (int item : nums)
    {
        arrsum += item;
        if (max < item)
        {
            max = item;
        }
    }
    if (arrsum % 2 == 1 || arrsum < 2 * max)
    {
        return false;
    }
    else
    {
        int goal_value = arrsum / 2;
        int len = nums.size();
        int arr[len][goal_value + 1] = {0};
        for (int i = 0; i < len; i++)
        {
            for (int j = 0; j < goal_value + 1; j++)
            {
                arr[i][j] = false;
            }
        }
        for (int i = 0; i < len; i++)
        {
            arr[i][0] = true;
            arr[i][nums[i]] = true;
        }
        for (int i = 1; i < len; i++)
        {
            for (int j = 1; j < goal_value + 1; j++)
            {
                if (nums[i] <= j)
                {
                    arr[i][j] = arr[i - 1][j] | arr[i - 1][j - nums[i]];
                }
                else
                {
                    arr[i][j] = arr[i - 1][j];
                }
            }
        }
        for (int i = 0; i < len; i++)
        {
            if (arr[i][goal_value] == true)
            {
                return true;
            }
        }
        return false;
    }
}
int main()
{
    vector<int> nums = {1, 2, 3, 5};
    cout << canPartition(nums);
}