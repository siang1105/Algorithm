#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int edge[110][110];
int dis[110][110];

int main(){
    int N,M;
    cin>>N>>M;
    for(int i = 1; i <= N; i++){
        for(int j = 1;j <= N;j++){
            if(i != j) edge[i][j] = dis[i][j] = 1e8;//初始化
        }
    }

    for(int i = 1; i <= M; i++){
        int u,v,w;
        cin>>u>>v>>w;
        edge[u][v] = edge[v][u] = min(edge[u][v], w);
        dis[u][v] = dis[v][u] = edge[u][v];
    }
    cout<<"edge"<<endl;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            cout<<edge[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"dis"<<endl;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }

    int ans = 1e8;
    for(int k = 1; k <= N; k++){
        for(int i = 1; i < k; i++){
            for(int j = i+1; j < k; j++){// 注意这里i,j不能相等
                ans = min(ans, dis[i][j] + edge[j][k] + edge[k][i]);
                cout<<ans<<endl;
            }
        }
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= N; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    cout<<"-----------------"<<endl;
    cout<<"edge"<<endl;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            cout<<edge[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"dis"<<endl;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
    if(ans == 1e8) cout<<"-1"<<endl;
    else cout<<ans<<endl;;
    return 0;
}