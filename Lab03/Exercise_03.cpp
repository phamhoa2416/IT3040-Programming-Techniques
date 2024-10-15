#include <iostream>
#include <climits>

using namespace std;

#define MAX 100

int n, c[MAX][MAX];
int c_min = INT_MAX;
int best = INT_MAX;
int current;
int mark[MAX];
int x[MAX];

void input()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            cin >> c[i][j];
            if (c[i][j] > 0)
                c_min = min(c_min, c[i][j]);
        }
    }
}

void TRY(int k)
{
    for (int v = 2; v <= n; ++v)
    {
        if (!mark[v])
        {
            mark[v] = 1;
            x[k] = v;
            current += c[x[k - 1]][v];

            if (k == n)
                best = min(best, current + c[v][1]);
            else
                TRY(k + 1);

            mark[v] = 0;
            current -= c[x[k - 1]][v];
        }
    }
}

int main()
{
    input();
    x[1] = 1;
    TRY(2);
    cout << best;
    return 0;
}