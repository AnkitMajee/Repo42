#include <bits/stdc++.h>
using namespace std;
#define V 4

vector<int> dijkstra(int graph[V][V], int src)
{
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    vector<bool> fin(V, false);

    for (int count = 0; count < V - 1; count++)
    {
        int u = -1;

        for (int i = 0; i < V; i++)
            if (!fin[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        fin[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 && !fin[v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    return dist;
}

int main()
{
    int graph[V][V] = { { 0, 50, 100, 0 },
                        { 50, 0, 30, 200 },
                        { 100, 30, 0, 20 },
                        { 0, 200, 20, 0 } };

    vector<int> distances = dijkstra(graph, 0);
    for (int i = 0; i < V; i++)
    {
        cout << "Vertex " << i << " distance from source: " << distances[i] << endl;
    }

    return 0;
}
