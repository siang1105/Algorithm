#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int map[3030][3030] = {0};
int visited[3030] = {0};
int depth[3030] = {0};

vector<int> ans;
vector<int> neighbor;
vector<int> adj[3030];

int N = 0;
int D = 0;
int x, y;
int stop = 0;

void insertEdges(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int id){
    // cout<<"rec"<<endl;
    // cout << id << " ";
    ans.push_back(id);
    if(adj[id].size() > 1){
        sort(adj[id].begin(), adj[id].end());
    }
    // for(int i = 0; i < adj[id].size(); i++){
    //     cout<<adj[id][i]<<" ";
    // }
    // cout<<endl;
    for (int i = 0; i < adj[id].size(); i++) {
        
        if(stop == 1) return;
        if (visited[adj[id][i]] == 0){
            visited[id] = 1;
            depth[adj[id][i]] = depth[id] + 1;
            if(depth[adj[id][i]] > D) stop = 1;
            dfs(adj[id][i]);
        } 
    }
}

// void DFS(int id){
//     if(stop == 1) return;
//     ans.push_back(id);
// 	// cout<<id<<" ";
// 	for(int i = 1; i <= N; i++){
//         if(stop == 1) return;
// 		if(map[id][i] == 1 && visited[i] == 0){
// 			visited[i] = 1;
// 			depth[i] = depth[id] + 1;
//             if(depth[i] > D) stop = 1;
// 			DFS(i);
// 		}
// 	}
// }

int main(){
    bool check = false;
    int start = 0;
    int noAns = 0;
    cin>>N>>D;
    for(int i = 0; i < N-1; i++){
        cin>>x>>y;
        insertEdges(x, y);
    }
    // for(int i = 0; i <= N; i++){
    //     for(int j = 0; j <= N; j++){
    //         cout<<map[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    while(check == false){
        stop = 0;
        if((check == false && start == N ) || (D == 0 && N > 1)){
            noAns = -1;
            break;
        }
        memset(visited, 0, (N+1) * sizeof(visited[0]));
        memset(depth, 0, (N+1) * sizeof(depth[0]));
        start++;
        visited[start] = 1;
	    depth[start] = 0;
	    dfs(start);
        if(stop == 1){
            check = false;
            ans.clear();
        }
        else check = true;
    }
    // for(int i = 1; i <= N; i++){
    //     cout<<depth[i]<<" ";
    // }
    // cout<<endl;
    // cout<<"ans"<<endl;
    if(noAns == -1) cout<<-1<<endl;
    else{
        for(int i = 0; i < N; i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}