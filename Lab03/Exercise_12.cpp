#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int countPath(const vector<vector<int>> &graph, int current_node, int k, unordered_set<int> &visited)
{
    if (k == 0)
        return 1; // If we have traversed exactly k edges

    int count = 0;
    visited.insert(current_node); // Mark the current node as visited

    for (int neighbor : graph[current_node])
        if (visited.find(neighbor) == visited.end())             // If neighbor has not been visited
            count += countPath(graph, neighbor, k - 1, visited); // Recursion for the next step

    visited.erase(current_node); // Backtracking: unmark the current node
    return count;
}

int main()
{
    int size, k;
    cin >> size >> k;

    vector<vector<int>> graph(size + 1);
    int number_edges;
    cin >> number_edges;

    for (int i = 0; i < number_edges; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    unordered_set<int> visited;
    int total_paths = 0;

    for (int i = 1; i <= size; ++i)
    {
        unordered_set<int> visited;
        total_paths += countPath(graph, i, k, visited);
    }

    cout << total_paths / 2 << endl;

    return 0;
}