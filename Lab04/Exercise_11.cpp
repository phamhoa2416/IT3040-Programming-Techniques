#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculateEnemies(vector<pair<int, int>>& walls, int soldiers, int n) {
    int enemies_passed = 0;
    for (auto& wall : walls) {
        int max_enemies = wall.first * wall.second;

        int soldiers_needed = (max_enemies -  wall.second + 1) / wall.second;
        if (soldiers >= soldiers_needed) {
            soldiers -= soldiers_needed; 
        } else {
            enemies_passed += max_enemies - soldiers * wall.second;
            soldiers = 0;
        }
    }

    return enemies_passed;
}

int main() {
    int n, s;
    cin >> n >> s;

    vector<pair<int, int>> walls(n);
    for (int i = 0; i < n; ++i) {
        cin >> walls[i].first >> walls[i].second;
    }

    sort(walls.begin(), walls.end(), [](const pair<int, int>& a, const pair<int, int>&b) {
        return (double) a.first / a.second > (double) b.first / b.second;
    });

    int result = calculateEnemies(walls, s, s);

    cout << result;
    return 0;
}
