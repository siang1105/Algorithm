#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

long long ans = 0;
long long T = 0;
int N = 0;
unordered_map<long long, int> mp;
int once = 1;


void DFS_L(int start, vector<long long>S, long long sum){
    if(mp.count(sum)){
        ++mp[sum];
        // cout<<"mp["<<sum<<"] = "<<mp[sum]<<endl;
    }
    else{
        // if(T == 0 && once == 1){
        //     once = 2;
        // }
        // else{
            mp[sum] = 1;
            // cout<<"mp["<<sum<<"] = "<<mp[sum]<<endl;
        // }
    }
    for(int i = start; i < N/2; ++i){
        // cout<<"in"<<endl;
        DFS_L(i+1, S, sum + S[i]);
    }
}

void DFS_R(int start, vector<long long>S, long long sum){
    if(mp.count(T-sum)){
        // cout<<"T-sum"<<T-sum<<"      sum"<<sum<<endl;
        ans += mp[T-sum];
    }
    for(int i = start; i < N; ++i){
        DFS_R(i+1, S, sum + S[i]);
    }
}

int main(){
    long long tmp = 0;
    vector <long long> S;
    vector <long long> arr;
    int start = 0;
    long long sum = 0;
    
    cin>>N>>T;
    for(int i = 0; i < N; i++){
        cin>>tmp;
        S.push_back(tmp);
    }
    DFS_L(0, S, 0);
    DFS_R(N/2, S, 0);
    // sort(S.begin(), S.end());
    // DFS(start, S, sum, arr);
    if(T == 0) ans--;
    cout<<ans<<endl;

    return 0;
    //dfs?
}