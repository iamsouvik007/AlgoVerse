// Adjacency List representation in C++ for undirected graph
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int V,E;
    cout<<"Enter the number of vertices and edges: ";
    cin>>V>>E;

    vector<vector<int>> adjList(V);

    cout<<"Enter "<<E<<" edges: "<<endl;
    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); //Remove for directed graph
    }
    
    // Print adjacency list
    cout<<"\nAdjacency List is: "<<endl;
    for(int i=0;i<V;i++){
        cout<<i<<" --> ";
        for(int j=0;j<adjList[i].size();j++){
            cout<<adjList[i][j]<<" ";
        }
        cout<<endl;
    }
// Space Complexity: O(V+E)
// Time Complexity: O(V+E)
    
return 0;

}













