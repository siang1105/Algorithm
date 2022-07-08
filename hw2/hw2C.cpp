#include <iostream>
#include <vector>
#include <stdint.h>
#include <algorithm>
using namespace std;

struct xy{
    long long x;
    long long y;
    long long val;
};

bool cmp(const xy &a, const xy &b){
    if(a.x == b.x){
        return a.y < b.y;
    }
    return a.x < b.x;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    vector<struct xy> vec;
    struct xy nowxy;

    long long N = 0;
    long long x = 0;
    long long y = 0;
    cin>>N;
    for(long long i = 0; i < N; i++){
        cin>>x>>y;
        nowxy.x = x;
        nowxy.y = y;
        vec.push_back(nowxy);
    }

    sort(vec.begin(), vec.end(), cmp);
    // cout<<"------"<<endl;
    // for(long long i = 0; i < N; i++){
    //     cout<<vec[i].x<<" "<<vec[i].y<<endl;
    // }
    vec[0].val = 1;
    long long max_val = 1;
    long long ans = 0;
    for(long long i = 0; i < N; i++){
        max_val = 1;
        for(long long j = 0; j < i; j++){
            if(vec[j].x <= vec[i].x && vec[j].y <= vec[i].y){
                // cout<<"i "<<i<<"j "<<j<<endl;
                // cout<<"max_val "<<max_val<<endl;
                // cout<<"vec[j].val "<<vec[j].val<<endl;
                max_val = max(max_val, vec[j].val+1);
                // cout<<"max_val "<<max_val<<endl;
                // cout<<"----"<<endl;
            }
        }
        vec[i].val = max_val;
        if(ans < max_val){
            ans = max_val;
        }
    }
    cout<<ans<<endl;
    return 0;
}
