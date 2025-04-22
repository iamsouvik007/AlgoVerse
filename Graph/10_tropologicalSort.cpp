#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Recursive DFS function for topological sorting
void DFS(vector<int> adj[], int U, vector<bool> &visited, stack<int> &st) {
    visited[U] = true; // Mark current node as visited

    // Visit all unvisited adjacent nodes
    for (int &v : adj[U]) {
        if (!visited[v]) {
            DFS(adj, v, visited, st);
        }
    }

    // After visiting all children, push current node to stack
    st.push(U);
}

// Function to perform topological sort on a DAG
vector<int> topoSort(int V, vector<int> adj[]) {
    vector<bool> visited(V, false); // Track visited nodes
    stack<int> st; // Stack to store the topological order

    // Call DFS for every unvisited node
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            DFS(adj, i, visited, st);
        }
    }

    // Pop elements from stack to get the topological ordering
    vector<int> result;
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    return result;
}

int main() {
    int V, E;
    cout << "Enter number of vertices (V): ";
    cin >> V;
    cout << "Enter number of edges (E): ";
    cin >> E;

    // Adjacency list to store graph
    vector<int> adj[V];

    // Input all edges
    cout << "Enter edges in the format (u v) meaning u -> v:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Directed edge from u to v
    }

    // Get topological sort
    vector<int> sorted = topoSort(V, adj);

    // Output the result
    cout << "Topological Sort of the given graph:\n";
    for (int node : sorted) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}

/*
===========================================
🧠 THEORY SECTION: TOPOLOGICAL SORT (DAG)
===========================================

🔹 WHAT IS TOPOLOGICAL SORT?
---------------------------------
Topological sorting is a linear ordering of vertices in a Directed Acyclic Graph (DAG)
such that for every directed edge u → v, vertex u comes BEFORE vertex v in the ordering.

⚠️ Note: Only works on DAGs (Directed Acyclic Graphs). If the graph contains cycles, 
topological sorting is NOT possible.

🔹 WHY DO WE NEED TOPO SORT?
---------------------------------
- Task Scheduling (where task dependencies exist)
- Course prerequisites problem
- Compiling source code with dependency files
- Resolving software/package dependency graphs

🔹 HOW DOES THIS CODE WORK?
---------------------------------
1. We represent the graph using an adjacency list.
2. We perform DFS from every unvisited node.
3. After visiting all children of a node, we push it onto a stack.
4. After DFS completes for all nodes, we pop the stack to get the Topological Order.

🔹 KEY COMPONENTS:
---------------------------------
- `visited[]` : Keeps track of visited nodes.
- `stack<int>` : Stores the reverse of the topological order (due to DFS nature).
- `DFS()` : Recursively visits nodes and builds the stack.

🔹 TIME COMPLEXITY:
---------------------------------
- O(V + E), where V = number of vertices, E = number of edges

🔹 EXAMPLE INPUT:
---------------------------------
Vertices (V) = 6
Edges (E) = 6

Enter edges:
5 2
5 0
4 0
4 1
2 3
3 1

🔹 POSSIBLE OUTPUT:
---------------------------------
Topological Sort of the given graph:
4 5 2 3 1 0

(Note: Multiple valid topological sorts may exist.)

🔹 BONUS CHALLENGE:
---------------------------------
Try modifying this code to detect cycles in the graph.
If a cycle is detected, topological sort is not possible.

🔥 Stay curious, keep building!
*/
