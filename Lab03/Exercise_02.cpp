#include <iostream>

using namespace std;

int n;
int X[100], Y[100]; // Save the coordinates of the moves of the knight
int mark[100][100]; // Mark the visited cells that the knight has moved to

// The array hx, hy describes the 8 possible moves of the knight
const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};

void print_sol()
{
    for (int j = 1; j <= n * n; ++j)
        printf("(%d %d)\n", X[j], Y[j]);
    exit(0);
}

// Backtracking
void TRY(int k)
{
    for (int i = 0; i < 8; ++i)
    {
        int xx = X[k - 1] + hx[i];
        int yy = Y[k - 1] + hy[i];
        if ((xx >= 1 && xx <= n) && (yy >= 1 && yy <= n) && mark[xx][yy] == 0)
        {
            X[k] = xx;
            Y[k] = yy;
            mark[xx][yy] = 1;
            if (k == n * n)
                print_sol();
            else
                TRY(k + 1);
            mark[xx][yy] = 0;
        }
    }
}

int main()
{
    cin >> n;
    mark[1][1] = 1;
    X[1] = 1;
    Y[1] = 1;
    TRY(2);
    return 0;
}