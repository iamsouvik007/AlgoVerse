#include <iostream>
#include <vector>
using namespace std;

const int INF = 999999; // Large value representing infinity

// Function to find the minimum weight edge from selected vertices
int find_min_edge(int V, vector<vector<int>>& G, vector<bool>& selected, int& x, int& y) {
    int min_weight = INF;

    for (int i = 0; i < V; i++) {
        if (selected[i]) {
            for (int j = 0; j < V; j++) {
                if (!selected[j] && G[i][j] > 0) {
                    if (G[i][j] < min_weight) {
                        min_weight = G[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }
    }
    return min_weight;
}

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    vector<vector<int>> G(V, vector<int>(V)); // Adjacency matrix
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> G[i][j];
        }
    }

    vector<bool> selected(V, false); // Track selected vertices

    int no_edge = 0; // Number of edges in MST

    selected[0] = true; // Start from first vertex

    cout << "Edge : Weight\n";

    while (no_edge < V - 1) {
        int x = -1, y = -1;
        int min_edge = find_min_edge(V, G, selected, x, y);

        if (x != -1 && y != -1) {
            cout << x << " - " << y << " : " << min_edge << endl;
            selected[y] = true;
            no_edge++;
        } else {
            cout << "Graph is not connected!" << endl;
            break;
        }
    }

    return 0;
}
