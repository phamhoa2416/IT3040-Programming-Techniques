#include <bits/stdc++.h>

using namespace std;

void dfs(vector<list<int>> adj)
{
    // Create a stack for DFS
    stack<int> s;
    vector<bool> visited(adj.size(), false);
    s.push(1);

    // Iterate over the stack until it is empty
    while (!s.empty())
    {
        // Pop a vertex from stack and print it
        int top = s.top();
        s.pop();

        // Stack may contain same vertex twice. So
        // we need to print the popped item only
        // if it is not visited
        if (!visited[top])
        {
            cout << top << endl;
            visited[top] = true;

            vector<int> neighbors(adj[top].begin(), adj[top].end());
            reverse(neighbors.begin(), neighbors.end());

            // Get all adjacent vertices of the popped vertex s
            // If a adjacent has not been visited, then push it
            // to the stack
            for (int neighbor : neighbors)
            {
                if (!visited[neighbor])
                {
                    s.push(neighbor);
                }
            }
        }
    }
}

// int main()
// {
//     int n = 7;
//     vector<list<int>> adj(n + 1);
//     adj[1].push_back(2);
//     adj[2].push_back(4);
//     adj[1].push_back(3);
//     adj[3].push_back(4);
//     adj[3].push_back(5);
//     adj[5].push_back(2);
//     adj[2].push_back(7);
//     adj[6].push_back(7);
//     dfs(adj);
// }