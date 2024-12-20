#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

// Structure to store a wall segment and its current state
struct Wall {
    int enemies;      // Total enemies
    int protect_ability; // Defense ability per soldier
    int soldiers_allocated; // Soldiers allocated to this wall

    // Calculate breached enemies for the current state
    int breachedEnemies() const {
        return max(0, enemies - soldiers_allocated * protect_ability);
    }

    // Calculate marginal gain in reducing breached enemies if one more soldier is allocated
    int marginalGain() const {
        return min(protect_ability, breachedEnemies());
    }
};

// Comparator for priority queue: prioritize walls with the highest marginal gain
struct Compare {
    bool operator()(const Wall& a, const Wall& b) {
        return a.marginalGain() < b.marginalGain();
    }
};

int calculateEnemies(vector<pair<int, int>>& walls, int soldiers) {
    // Convert walls into a priority queue of Wall structures
    priority_queue<Wall, vector<Wall>, Compare> pq;
    for (const auto& wall : walls) {
        pq.push(Wall{wall.first, wall.second, 0});
    }

    // Allocate soldiers dynamically based on marginal gain
    while (soldiers > 0 && !pq.empty()) {
        Wall current = pq.top();
        pq.pop();

        if (current.breachedEnemies() == 0) continue; // No more enemies to breach on this wall

        // Allocate one soldier to this wall
        current.soldiers_allocated++;
        soldiers--;

        // Push the updated wall back into the queue
        pq.push(current);
    }

    // Calculate total breached enemies
    int total_breached = 0;
    while (!pq.empty()) {
        Wall current = pq.top();
        pq.pop();
        total_breached += current.breachedEnemies();
    }

    return total_breached;
}

int main() {
    ifstream inputFile("Test BTVN 4-11.txt");
    ofstream outputFile("Result BTVN 4-11.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        if (line.substr(0, 5) == "case=") {
            string caseNumber = line;
            getline(inputFile, line);

            int n, s;
            if (line.substr(0, 6) == "input=") {
                stringstream ss(line.substr(6));
                ss >> n >> s;
            } else {
                cerr << "Input format error!" << endl;
                return 1;
            }
            vector<pair<int, int>> walls(n);
            for (int i = 0; i < n; i++) {
                getline(inputFile, line);
                stringstream ss(line);
                int enemies, protect_ability;
                ss >> enemies >> protect_ability;
                walls[i] = make_pair(enemies, protect_ability);
            }

            int result = calculateEnemies(walls, s);
            outputFile << caseNumber << "\n";
            outputFile << "The total number of breached enemies is: " << result << "\n\n";
        }
    }

    inputFile.close();
    outputFile.close();
}
