#include <iostream>
#include <queue>
#include <climits>

using namespace std;

vector<int> dijkstra(const vector<vector<pair<int, int>>> &adj)
{
    priority_queue<pair<int, int>> queue;
    vector<int> distance(adj.size(), INT_MAX);

    distance[0] = 0;
    queue.push({0, 0});

    while (!queue.empty())
    {
        pair<int, int> u_pair = queue.top();
        queue.pop();

        int u = u_pair.first;
        for (auto v_pair : adj[u])
        {
            int v = v_pair.first;
            int w = v_pair.second;

            if (distance[v] > distance[u] + w)
            {
                distance[v] = distance[u] + w;
                queue.push({v, distance[v]});
            }
        }
    }

    return distance;
}

// int main()
// {
//     int size = 9;
//     vector<vector<pair<int, int>>> adj(size);

//     auto add_edge = [&adj](int u, int v, int w)
//     {
//         adj[u].push_back({v, w});
//         adj[v].push_back({u, w});
//     };

//     add_edge(0, 1, 4);
//     add_edge(0, 7, 8);
//     add_edge(1, 7, 11);
//     add_edge(1, 2, 8);
//     add_edge(2, 3, 7);
//     add_edge(2, 8, 2);
//     add_edge(3, 4, 9);
//     add_edge(3, 5, 14);
//     add_edge(4, 5, 10);
//     add_edge(5, 6, 2);
//     add_edge(6, 7, 1);
//     add_edge(6, 8, 6);
//     add_edge(7, 8, 7);

//     vector<int> distance = dijkstra(adj);
//     for (int i = 0; i < distance.size(); ++i)
//     {
//         cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
//     }
//     return 0;
// }