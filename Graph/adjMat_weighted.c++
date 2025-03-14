#include<iostream>
#include<vector>
using namespace std;

int main(){
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;

    // Declaring and initializing adjacency matrix with 0
    vector<vector<int>> adjMatrix(V, vector<int>(V, 0));

    // Taking input for weighted edges with validation
    cout << "Enter " << E << " edges with weights (u v w): " << endl;
    for(int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        // Check for valid vertices
        if(u >= 0 && u < V && v >= 0 && v < V) {
            adjMatrix[u][v] = w;
            adjMatrix[v][u] = w; // Remove for directed graph
        } else {
            cout << "Invalid edge: (" << u << ", " << v << "). Please enter valid vertices." << endl;
            i--; // Decrement counter to allow re-entry of this edge
        }
    }

    // Printing adjacency matrix with labels
    cout << "\nAdjacency Matrix is:" << endl;
   
   

    for(int i = 0; i < V; i++) {
        cout << i << " ";  // Row labels
        for(int j = 0; j < V; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
