#include <iostream>
#include <vector>
using namespace std;
int searchInsert(vector<int> &nums, int target)
{
    int ans = 0;
    if (nums[0] >= target)
    {
        ans = 0;
    }
    else if (nums[nums.size() - 1] < target)
    {
        ans = nums.size();
    }
    else
    {
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == target)
            {
                ans = i;
                break;
            }
            else if (nums[i] > target && nums[i - 1] < target)
            {
                ans = i;
                break;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 3, 5, 6};
    int target = 4;
    int ans = searchInsert(nums, target);
    cout << ans << endl;
}