#include <bits/stdc++.h>

using namespace std;

int m, n, S_MIN = 100000;
long long S = 0;
int c_min = 100000000;
int x[100];
int c[100][100];
vector<int> flag(100, false);

void TRY(int k) {
    for (int i = 2; i <= n; ++i) {
        if (flag[i] == false && c[x[k - 1]][i] != 0) { // Check if node[i] is not visted and there is a path from node[k - 1]
            flag[i] = true; // Mark node[i] as visited
            x[k] = i; // Set the current node to node[i]
            S = S + c[x[k - 1]][i]; // Add the cost of the path from node[k - 1] to node[i] 

            if (k == n) {
                if (S + c[i][1] < S_MIN && c[i][1] != -1) // Check if returning to the starting node is cheaper
                    S_MIN = S + c[i][1]; // Update the minimum cost
            } else if (S + c_min * (n - k + 1) < S_MIN) // Prune the search if the current path is promising 
                TRY(k + 1); // Recur to the next node
            flag[i] = false; // Unmark node[i] as visited
            S = S - c[x[k - 1]][i]; // Subtract the cost of the path from node[k - 1] to node[i]
        }
    }
}

int main() {
    int a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (i == j) 
                c[i][j] = 0;
            else 
                c[i][j] = -1;
        }
    }

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        cin >> c[a][b];

        if (c[a][b] < c_min)
            c_min = c[a][b];
    }

    x[1] = 1;
    flag[1] = true;
    TRY(2);
    cout << S_MIN;
}