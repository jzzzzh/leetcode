#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 给你一个整数数组 nums，和一个整数 k 。
// 对于每个下标 i（0 <= i < nums.length），将 nums[i] 变成 nums[i] + k 或 nums[i] - k 。
// nums 的 分数 是 nums 中最大元素和最小元素的差值。
// 在更改每个下标对应的值之后，返回 nums 的最小 分数 。

int smallestRangeII(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int nums_min = nums[0];
    int nums_max = nums[nums.size() - 1];
    int ans = nums_max - nums_min;
    for (int i = 1; i < nums.size(); i++)
    {
        int num1 = nums_max - k;
        int num2 = nums[i] - k;
        int num3 = nums[i - 1] + k;
        int num4 = nums_min + k;
        int nummax = max(max(num1, num2), max(num3, num4));
        int nummin = min(min(num1, num2), min(num3, num4));
        ans = ans > nummax - nummin ? nummax - nummin : ans;
    }
    return ans;
}
int main()
{
    vector<int> nums = {1, 3, 6};
    int k = 3;
    int ans = smallestRangeII(nums, k);
    cout << ans << endl;
}