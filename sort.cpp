#include <iostream>
using namespace std;

void mysort(int *a, int left, int right)
{
    if (left < right)
    {
        int benchmark = a[right];
        int start = left;
        int end = right - 1;
        int pos = right;
        while (start <= end) // 等号有用，两个情况也要考虑
        {
            if (a[start] < benchmark && a[end] < benchmark)
            {
                start++;
            }
            else if (a[start] > benchmark && a[end] < benchmark)
            {
                int tmp = a[start];
                a[start] = a[end];
                a[end] = tmp;
                start++;
                end--;
            }
            else if (a[start] > benchmark && a[end] > benchmark)
            {
                end--;
            }
            else
            {
                start++;
                end--;
            }
        }
        a[pos] = a[start];
        a[start] = benchmark;
        pos = start;
        mysort(a, left, pos - 1);
        mysort(a, pos + 1, right);
    }
}
int main()
{
    int a[] = {4, 3, 5, 2, 1, 8};
    mysort(a, 0, 5);
    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}