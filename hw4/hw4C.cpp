#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF ((long long)1e15)

struct edge {
    long long x;
    long long w;
};

vector<long long> dijkstra(vector<vector<struct edge> > &vec, int n, int s){
    priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > > pq;
    
    vector<long long> ans(n+1);
    fill(ans.begin(), ans.end(), INF);
    pq.push(make_pair(0, s));
    ans[s] = 0;

    while(!pq.empty()){
        // cout<<pq.top().first<<" "<<pq.top().second<<endl;
        long long from = pq.top().second;
        pq.pop();
        for(int i = 0; i < vec[from].size(); i++){
            long long to = vec[from][i].x;
            if(ans[from] + vec[from][i].w < ans[to]){
                ans[to] = ans[from] + vec[from][i].w;
                pq.push(make_pair(ans[to], to));
            }
        }
    }
    // cout<<"------------"<<endl;
    return ans;
}

int main(){
    int N, M;
    int H, SF, SC, C;
    struct edge tmp;
    cin>>N>>M;
    cin>>H>>SF>>SC>>C;
    vector<vector<struct edge> > vec(N+1);
    for(int i = 0; i < M; i++){
        long long u, v, w;
        cin>>u>>v>>w;
        tmp.x = v; 
        tmp.w = w;
        vec[u].push_back(tmp);
        tmp.x = u;
        vec[v].push_back(tmp);
    }
    vector<long long> result1 = dijkstra(vec, N, SF);
    vector<long long> result2 = dijkstra(vec, N, C);
    // for(int i = 0; i < result1.size(); i++){
    //     cout<<result1[i]<<" ";
    // }
    // cout<<endl;
    // cout<<"-------------"<<endl;
    // for(int i = 0; i < result2.size(); i++){
    //     cout<<result2[i]<<" ";
    // }
    // cout<<endl; 

    // cout<<result1[H]<<endl;
    // cout<<result1[SC]<<endl;
    // cout<<result2[SC]<<endl;
    // cout<<result2[H]<<endl;
    long long answer = result1[H] + result1[SC] + result2[SC] + result2[H];
    cout<<answer<<endl;


    return 0;
}