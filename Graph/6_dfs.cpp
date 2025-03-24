// Graph traversal using DFS
// DFS is a traversing algorithm where you should start traversing from a selected node (source or starting node) and traverse the graph
// as far as possible in a given direction before backtracking. It is a recursive algorithm that uses the idea of backtracking.

#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited){
    visited[node] = true;
    cout<<node<<" ";

    // visit all the adjacent nodes of the current node
    for(int i=0; i<adj[node].size();i++){
        if(!visited[adj[node][i]]){
            dfs(adj[node][i], adj, visited);
        }
    }


}

int main(){
    int V,E;
    cout<<"Enter the number of vertices and edges: ";
    cin>>V>>E;
    vector<vector<int>> adj(V);
    vector<bool> visited(V, false);

    cout<<"Enter "<<E<<" edges: "<<endl;
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        if(u>=0 && u<V && v>=0 && v<V){
            adj[u].push_back(v);
            adj[v].push_back(u); // remove for directed graph
        }else{
            cout<<"Invalid input"<<endl;
            i--;
        }

    }

    int start;
    cout<<"Enter the starting node: ";
    cin>>start;

    cout<<"DFS Traversal: ";
    dfs(start, adj, visited);
    cout<<endl;

    return 0;
}

// space complexity: O(V) // O(V) + O(V) = O(V) // for visited array and stack of recursion calls 
// time complexity: O(V+E) // for traversing all the vertices and edges




