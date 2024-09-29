#include <iostream>

using namespace std;

typedef struct
{
    int x, y, z;
} block;

int n;
block a[100];
int maxh[100];

void input()
{
    cin >> n;
    if (n == 0)
        exit(0);
    int x, y, z;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x >> y >> z;
        a[3 * i - 2].x = x;
        a[3 * i - 2].y = y;
        a[3 * i - 2].z = z;
        a[3 * i - 1].x = x;
        a[3 * i - 1].y = z;
        a[3 * i - 1].z = y;
        a[3 * i].x = y;
        a[3 * i].y = z;
        a[3 * i].z = x;
    }

    for (int i = 0; i < 100; ++i)
        maxh[i] = 0;
}

int dp(int i)
{ // Find the height of the tower with the ith block at the top
    if (maxh[i] != 0)
        return maxh[i];
    maxh[i] = a[i].z;
    for (int j = 1; j <= 3 * n; ++j)
    {
        if (a[i].x < a[j].x && a[i].y < a[j].y || a[i].x < a[j].y && a[i].y < a[j].x)
            maxh[i] = max(maxh[i], a[i].z + dp(j));
    }
    return maxh[i];
}

int main()
{
    int count = 1;
    while (true)
    {
        int result = 0;
        input();
        for (int i = 1; i <= 3 * n; ++i)
        {
            result = max(result, dp(i));
        }
        printf("Case %d: maximum height = %d\n", count++, result);
    }
    return 0;
}