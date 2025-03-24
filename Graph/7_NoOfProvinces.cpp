#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int n, vector<vector<int>> &isConnected, vector<bool> &visited) {
        visited[n] = true;
        
        for (int i = 0; i < isConnected[n].size(); i++) {
            if (isConnected[n][i] == 1 && !visited[i]) {
                dfs(i, isConnected, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, isConnected, visited);
                count++;
            }
        }
        return count;
    }
};

int main() {
    int n;
    cout << "Enter the number of cities (nodes): ";
    cin >> n;

    vector<vector<int>> isConnected(n, vector<int>(n));
    cout << "Enter the adjacency matrix (0/1):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> isConnected[i][j];
        }
    }

    Solution obj;
    int provinces = obj.findCircleNum(isConnected);
    cout << "Number of provinces: " << provinces << endl;

    return 0;
}
