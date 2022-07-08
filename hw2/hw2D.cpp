#include <iostream>
#include <vector>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr); 
    
    long long N = 0;
    long long v = 0;
    long long ma = 0;
    long long mi = 0;
    vector<long long> value;
    vector<long long> Amin;
    vector<long long> Amax;
    cin>>N;
    for(long long i = 0; i < N; i++){
        cin>>v;
        value.push_back(v);
    }

    long long tmp = value.back();
    value.pop_back();
    Amax.push_back(tmp);
    Amin.push_back(tmp);
    mi = tmp;
    ma = tmp;
    for(long long i = 1; i < N; i++){
        tmp = value.back();
        value.pop_back();
        ma = max(max(ma, tmp - mi), tmp);
        mi = min(min(mi, tmp - ma), tmp);
        Amax.push_back(ma);
        Amin.push_back(mi);
    }
    cout<<Amax.back()<<endl;
    return 0;
}


