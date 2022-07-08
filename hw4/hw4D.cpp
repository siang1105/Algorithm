#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;
  
 
int bfs(int rGraph[400][400], int s, int t, int parent[], int V){
    bool visited[V];
    memset(visited, 0, sizeof(visited));
  
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
  
    while (!q.empty()){
        int u = q.front();
        q.pop();
  
        for (int v=0; v<V; v++){
            if (visited[v]==false && rGraph[u][v] > 0){
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
  
    return (visited[t] == true);
}

void dfs(int rGraph[400][400], int s, bool visited[], int V){
    visited[s] = true;
    for (int i = 0; i < V; i++)
       if (rGraph[s][i] && !visited[i])
           dfs(rGraph, i, visited, V);
}

void minCut(int graph[400][400], int s, int t, int V){
    int u, v;

    int rGraph[400][400];
    for (u = 0; u < V; u++)
        for (v = 0; v < V; v++)
             rGraph[u][v] = graph[u][v];
  
    int parent[V];
  
    while (bfs(rGraph, s, t, parent, V)){
        int path_flow = INT_MAX;
        for (v=t; v!=s; v=parent[v]){
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }

        for (v=t; v != s; v=parent[v]){
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
    }
  
    bool visited[V];
    memset(visited, false, sizeof(visited));
    dfs(rGraph, s, visited, V);
    long long sum = 0;
    for (int i = 0; i < V; i++){
        for (int j = 0; j < V; j++){
            if (visited[i] && !visited[j] && graph[i][j]) sum += graph[i][j];
        }
    }
    cout<<sum<<endl;
    return;
}

int main(){
    int N, M;
    int graph[400][400] = {0};
    
    cin>>N>>M;
    int V = N + 2;
    for(int i = 1; i <= N; i++){
        int w;
        cin>>w;
        graph[0][i] = w;
    }
    for(int i = 1; i <= N; i++){
        int w;
        cin>>w;
        graph[i][V-1] = w;
    }
    for(int i = 0; i < M; i++){
        int u, v, w;
        cin>>u>>v>>w;
        graph[u][v] = w;
        graph[v][u] = w;
    }
    // for(int i = 0; i < V; i++){
    //     for(int j = 0; j < V; j++){
    //         cout<<graph[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    minCut(graph, 0, V-1, V);
  
    return 0;
}