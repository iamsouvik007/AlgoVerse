#include<iostream>
#include<vector>
using namespace std;

int main() {
    int V, E;
    cout << "Enter no of vertices and edges: ";
    cin >> V >> E;
    
    // Adjacency list with pairs (neighbor, weight)
    vector<vector<pair<int, int>>> adjList(V);

    // Input with validation
    cout << "Enter " << E << " edges with weights (u v w): " << endl;
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        // Check for valid vertices
        if (u >= 0 && u < V && v >= 0 && v < V) {
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w}); // Remove for directed graph
        } else {
            cout << "Invalid edge: (" << u << ", " << v << "). Please enter valid vertices." << endl;
            return 0;
        }
    }

    // Print adjacency list
    cout << "\nAdjacency List is: " << endl;
    for(int i = 0; i < V; i++) {
        cout << i << " --> ";
        for(int j = 0; j < adjList[i].size(); j++) {
            cout << "(" << adjList[i][j].first << "," << adjList[i][j].second << ") ";
        }
        cout << endl;
    }

    return 0;
}
