#include <iostream>
#include <vector>
#include <sstream>
#include <climits>
#include <algorithm>

using namespace std;

void findMinCost(const vector<vector<int>>& price, 
                const vector<int>& places, 
                vector<int>& path, 
                vector<bool>& visited, 
                int current, 
                int currentCost, 
                int& minCost
){
    int numOfPlaces = places.size();
    
    for (int i = 1; i < numOfPlaces - 1; ++i){
        if (!visited[places[i]] && price[path[current - 1]][places[i]] > 0){
            visited[places[i]] = true;
            currentCost += price[path[current - 1]][places[i]];
            path[current] = places[i];

            if (current == numOfPlaces - 2) {
                if (price[path[current]][places.back()] == 0) {
                    visited[places[i]] = false;
                    currentCost -= price[path[current - 1]][places[i]];
                    continue;
                }
                minCost = min(minCost, currentCost + price[path[current]][places.back()]);
            }
            else {
                findMinCost(price, places, path, visited, current + 1, currentCost, minCost);
            }

            visited[places[i]] = false;
            currentCost -= price[path[current - 1]][places[i]];
        }
    }
}

int main(){
    int n, r;
    cin >> n >> r;
    
    vector<vector<int>> price(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> price[i][j];
        }
    }
    
    cin.ignore();
    
    vector<int> places;
    vector<bool> visited;
    vector<int> path;

    for (int i = 0; i < r; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        
        int place;
        while (ss >> place) {
            places.push_back(place - 1);
        }

        int start = places.front();
        int end = places.back();
        int numOfPlaces = places.size(); 
        
        path.resize(numOfPlaces);
        path[0] = start; 
        path[numOfPlaces - 1] = end;

        visited.resize(n, false);

        int minCost = INT_MAX; 

        findMinCost(price, places, path, visited, 1, 0, minCost);

        if (minCost == INT_MAX) cout << "0" << endl;
        else cout << minCost << endl;

        places.clear();
    }
}
