#include <iostream>
#include <cstring>
using namespace std;
class MyCalendar
{
private:
    int n;
    int from[1000];
    int to[1000];

public:
    MyCalendar()
    {
        n = 0;
        memset(from, 0, 1000);
        memset(to, 0, 1000);
    }

    bool book(int start, int end)
    {
        if (n == 0)
        {
            from[n] = start;
            to[n] = end;
            n++;
            return true;
        }
        else
        {
            // from -- to
            // start -- end
            bool flag = false;
            int i = 0;
            
            while (i < n && to[i] <= start)
            {
                i++;
            }
            
            // 1. to[i-1] < start < end < from[i] < to[i]
            // 2. to[i-1] < from[i] < start < end < to[i]
            // 3. to[i-1] < from[i] < start < to[i] < end
            // 4. to[i-1] < start < from[i] < to[i] < end
            //
            if (n <= i || from[i] >= end)
            {
                flag = true;
                
                if (i == n)
                {
                    from[i] = start;
                    to[i] = end;
                    n++;
                }
                else if (from[i] >= end)
                {
                    
                    for (int j = n; j > i; j--)
                    {
                        from[j] = from[j - 1];
                        to[j] = to[j - 1];
                    }
                    from[i] = start;
                    to[i] = end;
                    n++;
                }
            }
            // for(int k = 0; k < n; k++)
            // {
            //     cout << from[k] <<"  " << to[k] << endl;
            // }
            return flag;
        }
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */


// ["MyCalendar","book","book","book","book","book","book","book","book","book","book"]
// [[],[47,50],[33,41],[39,45],[33,42],[25,32],[26,35],[19,25],[3,8],[8,13],[18,27]]
int main()
{
    MyCalendar *obj = new MyCalendar();
    // int n = 5;
    bool param;
    int a[] = {47,50,33,41,39,45,33,42,25,32,26,35,19,25,3,8,8,13,18,27};
    int n = sizeof(a)/sizeof(int)/2;
    for (int i = 0; i < n; i++)
    {
        int from = a[2 * i];
        int to = a[2 * i + 1];
        // cout << from << to << endl;
        param = obj->book(from, to);
        cout << param << endl;
    }
}