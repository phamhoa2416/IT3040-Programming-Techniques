#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0, sum = 0;
    while (n--)
    {
        int k, t;
        cin >> k >> t;

        if (t == 1)
        {
            while (k--)
            {
                int a;
                cin >> a;
                sum += a;
            }
        }
        else if (t == -1)
        {
            while (k--)
            {
                int a;
                cin >> a;
                sum -= a;
            }
        }

        if (-sum > ans)
            ans = -sum;
    }

    cout << ans;
}