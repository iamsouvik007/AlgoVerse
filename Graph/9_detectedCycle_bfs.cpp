#include <bits/stdc++.h>
using namespace std;

// *Function to detect cycle using BFS*
bool isCycleBFS(int start, vector<int> adj[], vector<bool> &visited) {
    queue<pair<int, int>> q;
    q.push(make_pair(start, -1));  // (node, parent)
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        // Traverse all adjacent nodes
        for (int i = 0; i < adj[node].size(); i++) {
            int neighbor = adj[node][i];

            // If it's the parent, skip it
            if (neighbor == parent) continue;

            // If it's visited and not the parent, cycle found
            if (visited[neighbor]) return true;

            // Otherwise, mark as visited and push to queue
            visited[neighbor] = true;
            q.push(make_pair(neighbor, node));
        }
    }
    return false;
}

// Function to check for cycle in an undirected graph
bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCycleBFS(i, adj, visited)) return true;
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
