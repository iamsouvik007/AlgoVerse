// Graph Representation using Adjacency Matrix


#include<iostream>
using namespace std;

int main(){
    int V,E; // Number of vertices and edges
    cout<<"Enter the number of vertices and edges: ";
    cin>>V>>E;

    // Declaring adjancy matrix
    int adjMatrix[V][V];

    // Initializing all elements of adjancy matrix to 0
    for(int i=0; i<V; i++){
        for(int j=0; j<V;j++){
            adjMatrix[i][j] = 0;
        }
    }

    // Taking input of edges
    cout<<"Enter "<<E<<" edges: "<<endl;
    for(int i=0; i<E;i++){
        int u,v;
        cin>>u>>v;
        if(u>=0 && u<V && v>=0 && v<V){
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // remove for directed graph
    }else{
        cout<<"Invalid input"<<endl;
        i--;
    }
}

    // Printing adjancy matrix
    cout<<"Adjancy matrix is: "<<endl;
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

// Space Complexity: O(V^2)
// Time Complexity: O(V^2)

}









