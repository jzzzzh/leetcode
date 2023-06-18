#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
double f(double x, double *a, int n)
{
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += pow(x, n - i) * a[i];
    }
    return ans;
}
int main(void)
{
    int n;
    cin >> n;
    double left, right;
    cin >> left;
    cin >> right;
    double a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    double t;
    cin >> t;
    while (right - left >= 1e-5)
    {
        double mid1, mid2;
        mid1 = left + (right - left) / 3;
        mid2 = right - (right - left) / 3;
        if (f(mid1, a, n) > f(mid2, a, n))
        {
            right = mid2;
        }
        else
        {
            left = mid1;
        }
    }
    printf("%.5f\n", (left+right)/2);
    return 0;
}