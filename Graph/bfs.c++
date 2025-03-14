#include<bits/stdc++.h>
using namespace std;

void bfs(int start, vector<vector<int>> &adj, int n){
    vector<bool> visited(n, false); // Mark all vertices as not visited
    queue<int> q; // Create a queue for BFS
    
    visited[start] = true;
    q.push(start);

    cout<<"BFS Traversal: ";

    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";

        //Traversal of all the adjacent nodes of the current node
        for(int i=0; i<adj[node].size();i++){
            if(!visited[adj[node][i]]){   // If the node not visited
                visited[adj[node][i]] = true; // Mark it as visited
                q.push(adj[node][i]);      // Push it to the queue
            }
        }
    }
    cout<<endl;
    
}

int main(){
    int V,E; // Number of vertices and edges
    cout<<"Enter the number of vertices and edges: ";
    cin>>V>>E;
    vector<vector<int>> adj(V);
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

        bfs(start,adj,V);

        return 0;

}
// space complexity: O(V) + O(V) = O(V) // for visited array and queue
// time complexity: O(V+E) // for traversing all the vertices and edges












