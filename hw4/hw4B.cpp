#include <iostream>
#include <vector>
#include <algorithm>
#define INF ((long long)1e15)
using namespace std;

struct edge{
    int x;
    int y;
    long long w;
};

int N,M;

vector<struct edge> vec;
vector<struct edge> MST;
int num[1010],parent[1010];

int findParent(int a){
  while(a != parent[a]){
    a = parent[a];                  
  }    
  return a;   
}

int ST(vector<struct edge>vec, int N, int M, int run){
    int numEdge = 0;
    long long result = 0;
    long long bottleneck = INF;
    for(int i = 0; i < N; i++){
        parent[i] = i;
        num[i] = 1;            
    }
    for(int i = 0; i < M && numEdge < N; i++){
      int a,b;
      a = findParent(vec[i].x);
      b = findParent(vec[i].y);
      if (a != b){
        //   cout<<vec[i].w<<endl;
        if(num[a] > num[b]){
          parent[b] = a;
          num[a] += num[b];      
        }
        else{
          parent[a] = b;
          num[b] += num[a];      
        }
        if(bottleneck > vec[i].w) bottleneck = vec[i].w;
        result += vec[i].w;
        numEdge++;                                         
      } 
    }
    if(run == 1) return bottleneck;
    else return result;
}

bool cmp(const edge &a, const edge &b){
    return a.w > b.w;
}

bool cmp2(const edge &a, const edge &b){
    return a.w < b.w;
}

int main(){
    struct edge tmp;
    cin>>N>>M;
    for(int i = 0; i < M; i++){
        int u, v;
        long long w;
        cin>>u>>v>>w;
        tmp.x = u;
        tmp.y = v;
        tmp.w = w;
        vec.push_back(tmp);
    }
    sort(vec.begin(), vec.end(), cmp);
    int bottleneck = ST(vec, N, M, 1);
    // cout<<bottleneck<<endl;
    for(int i = 0; i < vec.size(); i++){
        struct edge tmp;
        if(vec[i].w >= bottleneck){
            tmp.x = vec[i].x;
            tmp.y = vec[i].y;
            tmp.w = vec[i].w;
            MST.push_back(tmp);
        }
    }
    
    sort(MST.begin(), MST.end(), cmp2);
    // for(int i = 0; i < MST.size(); i++){
    //     cout<<MST[i].x<<" ";
    //     cout<<MST[i].y<<" ";
    //     cout<<MST[i].w<<" "<<endl;
    // }
    // cout<<"------"<<endl;
    long long result = ST(MST, N, MST.size(), 2);
    cout<<result<<endl;
    return 0;

}