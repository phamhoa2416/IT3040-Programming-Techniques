#include <bits/stdc++.h>

using namespace std;

int w, h;
int table[601][601];

void init() {
    for (int i = 1; i <= h; ++i) 
        for (int j = 1; j <= w; ++j) 
            table[i][j] = i * j;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    int n;
    cin >> w >> h;
    cin >> n;
    init();

    for (int i = 0; i < n; ++i) {
        int width, height;
        cin >> width >> height;
        table[height][width] = 0;
    }

    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            int minWaste = table[i][j];

            // horizontal cut
            for (int k = 1; k <= i; ++k)
                minWaste = min(minWaste, table[k][j] + table[i - k][j]);

            // vertical cut
            for (int k = 1; k <= j; ++k)
                minWaste = min(minWaste, table[i][k] + table[i][j - k]);

            table[i][j] = minWaste;  
        }
    }

    cout << table[h][w] << endl;
}