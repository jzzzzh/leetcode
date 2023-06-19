// 给你一个整数数组 nums 和两个整数 k 和 p ，找出并返回满足要求的不同的子数组数，要求子数组中最多 k 个可被 p 整除的元素。
// 如果满足下述条件之一，则认为数组 nums1 和 nums2 是 不同 数组：
// 两数组长度 不同 ，或者
// 存在 至少 一个下标 i 满足 nums1[i] != nums2[i] 。
// 子数组 定义为：数组中的连续元素组成的一个 非空 序列。
#include <iostream>
#include <vector>
using namespace std;
int countDistinct(vector<int> &nums, int k, int p)
{
    int nums_length = nums.size();
    int is_ok[nums_length + 1];
    is_ok[0] = 0;
    for (int i = 1; i < nums_length + 1; i++)
    {
        is_ok[i] = (nums[i - 1] % p == 0 ? is_ok[i - 1] + 1 : is_ok[i - 1]);
    }
    int ans = 0;
    for (int a : is_ok)
    {
        cout << a << " ";
    }
    cout << endl;
    for (int i = 1; i < nums_length + 1; i++)
    {
        for (int j = 0; j < nums_length - i + 1; j++)
        {
            if (is_ok[j + i] - is_ok[j] <= k)
            {
                ans++;
            }
            cout << is_ok[j + i] - is_ok[j] << " ";
        }
        cout << endl;
    }
    return ans;
}
int main()
{
    // vector<int> nums = {2, 3, 3, 2, 2};
    // int k = 2, p = 2;
    vector<int> nums = {1, 2, 3, 4};
    int k = 4, p = 1;
    int ans = countDistinct(nums, k, p);
    cout << ans << endl;
    return 0;
}