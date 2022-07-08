#include <iostream>
#include <string>
using namespace std;

// long long ans[10000][10000] = {0};

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long a = 0;
    long long b = 0;
    long long c = 0;
    
    string S;
    string T;
    cin>>a>>b>>c;
    cin.ignore();
    getline(cin, S);
    getline(cin, T);
    long long rows = S.size()+5;
    long long cols = T.size()+5;
    long long row = S.size();
    long long col = T.size();

    long long **ans = (long long **) malloc(rows * sizeof(*ans));
    for (long long i = 0; i < rows; i++){
        ans[i] = (long long *) malloc(cols * sizeof(long long));
    }

    for(long long i = 0; i <= row; i++){
        ans[i][0] = i * b;
    }
    for(long long i = 0; i <= col; i++){
        ans[0][i] = i * a;
    }

    for(long long i = 1; i <= row; i++){
        for(long long j = 1; j <= col; j++){
            if(S[i-1] == T[j-1]){
                ans[i][j] = ans[i-1][j-1];
            }
            else{
                int s = S[i-1];
                int t = T[j-1];
                int offset = abs(s-t);
                offset = min(offset, 26-offset);
                // cout<<"i "<<i<<"j "<<j<<endl;
                // cout<<"check"<<S[i-1]<<" "<<T[j-1]<<endl;
                // cout<<ans[i-1][j-1] + offset * c<<endl;
                // cout<<ans[i-1][j] + b<<endl;
                // cout<<ans[i][j-1] + a<<endl;
                // cout<<"-----"<<endl;
                ans[i][j] = min(min(ans[i-1][j-1] + (offset * c), ans[i-1][j] + b), ans[i][j-1] + a);
            }
        }
    }
    // for(int i = 0; i <= row; i++){
    //     for(int j = 0; j <= col; j++){
    //         cout<<ans[i][j]<<"  ";
    //     }
    //     cout<<endl;
    // }
    cout<<ans[row][col]<<endl;
    return 0;
}