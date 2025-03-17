// Detect cycle in a graph using DFS

#include <bits/stdc++.h>
using namespace std;

bool isCycleDFS(int node, vector<int> adj[], vector<bool> &visited, int parent) {
    visited[node] = true;

    for (int i = 0; i < adj[node].size(); i++) {
        int v = adj[node][i];  // Get the adjacent node

        if (v == parent) continue;  // Skip the parent node

        if (visited[v]) return true;  // Cycle detected

        if (isCycleDFS(v, adj, visited, node)) return true;
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCycleDFS(i, adj, visited, -1)) return true;
        }
    }
    return false;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    vector<int> adj[V];  // Adjacency list

    cout << "Enter " << E << " edges (0-based index):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Since it's an undirected graph
    }

    if (isCycle(V, adj)) {
        cout << "Cycle detected in the graph!\n";
    } else {
        cout << "No cycle in the graph.\n";
    }

    return 0;
}
