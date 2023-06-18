#include <iostream>
#include <vector>
using namespace std;
// 每层都得考虑了，不是考虑单层
int coinChange(vector<int> &coins, int amount)
{
    int coinClass = coins.size();
    int arr[amount + 1][coinClass];
    for (int i = 0; i < coinClass; i++)
    {
        for (int j = 0; j < amount + 1; j++)
        {
            if (j % coins[i] == 0)
            {
                arr[j][i] = j / coins[i];
            }
            else
            {
                arr[j][i] = -1;
            }
        }
    }

    for (int i = 1; i < amount + 1; i++)
    {
        for (int j = 1; j < coinClass; j++)
        {
            int minval = -1;
            if (arr[i][j - 1] != -1)
            {
                minval = arr[i][j - 1];
            }
            for (int k = 0; k <= j; k++)
            {
                if (i - coins[j] >= 0 && arr[i - coins[j]][k] != -1)
                {
                    if (minval != -1)
                        minval = min(minval, arr[i - coins[j]][k] + 1);
                    else
                        minval = arr[i - coins[j]][k] + 1;
                }
            }
            arr[i][j] = minval;
        }
    }
    int minva = arr[amount][0];
    for (int i = 0; i < coinClass; i++)
    {
        if (arr[amount][i] != -1 && (minva > arr[amount][i] || minva == -1))
        {
            minva = arr[amount][i];
        }
    }
    return minva;
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 15;
    cout << coinChange(coins, amount);
}