#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 0;
    long long tmp = 0;
    long long cost = 0;
    
    int check = 0;
    cin>>n;
    vector<long long> v;
    priority_queue<long long,vector<long long>,greater<long long> > pq;
    map<long long, int> ma;

    for(int i = 0; i < n; i++){
        cin>>tmp;
        ma[tmp] = i;
        v.push_back(tmp);
        pq.push(tmp);
    }


    for (int i = 0; i < n; i++){
        long long num = pq.top();
        int index = ma[num];
        // cout<<"min "<<num<<endl;
        // cout<<"index"<<index<<endl;
        pq.pop();
        if(v[i] > num){
            ma[num] = i;
            ma[v[i]] = index;
            // cout<<"in"<<endl;
            swap(v[index], v[i]);
            cost = cost + ((((v[i] + v[index]) % 1000000007) * (abs(i-index) % 1000000007)) % 1000000007);
            cost = cost % 1000000007;
        }
    }

    cout<<cost<<endl;
    return 0;
}