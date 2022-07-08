#include <iostream>
#include <vector>

using namespace std;


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);


    long long N = 0;
    long long U = 0;
    vector<long long> TW;
    vector<long long> TV;
    long long W = 0;
    long long V = 0;
    long long A = 0;
    cin>>N>>U;
    
    for(long long i = 0; i < N; i++){
        cin>>W>>V>>A;
        for(long long j = 1; j <= A; j *= 2){
            A -= j;
            TW.push_back(W*j);
            TV.push_back(V*j);
        }
        if(A > 0){
            TW.push_back(W*A);
            TV.push_back(V*A);
        }
    }
    long long row = TW.size();
    long long col = U+1;
    long long *ans = (long long *)calloc(U+5, sizeof(long long));
    
    // for(long long i = 1; i < TW.size(); i++){
    //     for(long long j = 0; j <= U; j++){
    //         if(TW[i] > j){
    //             ans[i][j] = ans[i-1][j];
    //         }
    //         else{
    //             ans[i][j] = max(TV[i] + ans[i-1][j-TW[i]], ans[i-1][j]);
    //         }
    //     }
    // }

    for (int i = 0; i < TW.size(); ++i){
        for (int j = U; j - TW[i] >= 0; --j){  // 由後往前
            ans[j] = max(ans[j], ans[j - TW[i]] + TV[i]);
        }
    }

    
    cout<<ans[U]<<endl;
   
    return 0;
}