#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Define a structure for edges
struct Edge {
    int src, dest, weight;
};

// Function to implement the Bellman-Ford algorithm using a priority queue
void bellmanFordPQ(vector<Edge>& edges, int V, int E, int src) {
    // Create a priority queue to store vertices that are being preprocessed
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    // Create a vector for distances and initialize all distances as infinite (INT_MAX)
    vector<int> dist(V, INT_MAX);
    
    // Insert source itself in priority queue and initialize its distance as 0
    pq.push(make_pair(0, src));
    dist[src] = 0;
    
    // Loop until priority queue becomes empty
    while (!pq.empty()) {
        // Extract the vertex with the minimum distance value
        int u = pq.top().second;
        pq.pop();
        
        // Traverse through all adjacent vertices of the extracted vertex u
        for (auto edge : edges) {
            if (edge.src == u) {
                int v = edge.dest;
                int weight = edge.weight;
                
                // If there is a shorter path to v through u
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
    }
    
    // Print shortest distances stored in dist[]
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; ++i)
        cout << i << "\t\t" << dist[i] << endl;
}

int main() {
    // Number of vertices and edges
    int V = 5;
    int E = 8;
    
    // Create a vector of edges
    vector<Edge> edges(E);
    
    // Add edges to the graph
    edges[0] = {0, 1, -1};
    edges[1] = {0, 2, 4};
    edges[2] = {1, 2, 3};
    edges[3] = {1, 3, 2};
    edges[4] = {1, 4, 2};
    edges[5] = {3, 2, 5};
    edges[6] = {3, 1, 1};
    edges[7] = {4, 3, -3};
    
    // Source vertex
    int src = 0;
    
    // Call Bellman-Ford algorithm
    bellmanFordPQ(edges, V, E, src);
    
    return 0;
}
