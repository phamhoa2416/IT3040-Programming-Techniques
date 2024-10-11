#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

void bfs(vector<list<int>> adj)
{
    queue<int> q;

    // Mark all the vertices as not visited
    vector<bool> visited(adj.size(), false);
    q.push(1);
    // Mark the first node as visited
    visited[1] = true;

    // Iterate over the queue until it is empty
    while (!q.empty())
    {
        // Dequeue a vertex from queue and print it
        int front = q.front();
        q.pop();
        cout << front << endl;

        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it
        // visited and enqueue it
        for (int neighbor : adj[front])
        {
            // If the neighbor has not been visited
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
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
//     bfs(adj);
//
//    return 0;
// }