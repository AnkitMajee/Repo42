//Bellman Ford

#include <iostream>
#include <climits>

using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

void printArr(int dist[], int n) {
    cout << "Vertex Distance from Source\n";
    for (int i = 0; i < n; ++i)
        cout << i << "\t\t" << dist[i] << "\n";
}

void BellmanFord(struct Graph* graph, int src) {
    int V = graph->V;
    int E = graph->E;
    int dist[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    for (int i = 0; i < E; i++) {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle";
            return;
        }
    }

    printArr(dist, V);

    return;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    struct Graph* graph = createGraph(V, E);

    cout << "Enter edges (source, destination, weight):\n";
    for (int i = 0; i < E; ++i) {
        cout << "Edge " << i + 1 << ":\n";
        cout << "Source: ";
        cin >> graph->edge[i].src;
        cout << "Destination: ";
        cin >> graph->edge[i].dest;
        cout << "Weight: ";
        cin >> graph->edge[i].weight;
    }

    int sourceVertex;
    cout << "Enter the source vertex: ";
    cin >> sourceVertex;

    BellmanFord(graph, sourceVertex);

    return 0;
}
