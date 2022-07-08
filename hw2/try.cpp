// long long ans[10005][10005];
// int TS[10005][10005] = {0};

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N = 0;
    long long x = 0;
    long long y = 0;
    long long max_x = 0;
    long long max_y = 0;
    vector<long long> xx;
    vector<long long> yy;
    
    

    cin>>N;
    
    for(long long i = 0; i < N; i++){
        cin>>x>>y;
        // TS[x][y] = 1;
        xx.push_back(x);
        yy.push_back(y);
        if(x > max_x){
            max_x = x;
        }
        if(y > max_y){
            max_y = y;
        }
    }
    // long long **ans = new long long*[max_x+5];
    // for(long long i = 0; i < max_x+5; ++i) {
    //     ans[i] = new long long[max_y+5];
    // }

    // int **TS = new int*[max_x+5];
    // for(int i = 0; i < max_x+5; ++i) {
    //     TS[i] = new int[max_y+5]();
    // }

    int8_t **TS = (int8_t **)calloc(max_x+1, sizeof(int8_t*));
    for(int i = 0; i < max_x+1; i++) {
        TS[i] = (int8_t *)calloc(max_y+1, sizeof(int8_t));
    }

    // cout<<xx.size()<<endl;
    while(!xx.empty()){
        long long nx = xx.back();
        long long ny = yy.back();
        xx.pop_back();
        yy.pop_back();
        TS[nx][ny] = 1;
    }
    long long **ans = (long long **) malloc((max_x+1) * sizeof(*ans));
    
    for (long long i = 0; i < (max_x+1); i++){
        ans[i] = (long long *) malloc((max_y+1) * sizeof(long long));
    }
    // cout<<max_x<<max_y<<endl;
    // for(int i = 0; i <= max_x; i++){
    //     for(int j = 0; j <= max_y; j++){
    //         cout<<TS[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(long long i = 0; i <= max_x; i++){
        ans[i][0] += TS[i][0];
    }

    for(long long i = 0; i <= max_y; i++){
        ans[0][i] += TS[0][i];
    }
    
    for(long long i = 1; i <= max_x; i++){
        for(long long j = 1; j <= max_y; j++){
            ans[i][j] = max(ans[i-1][j] + TS[i][j], ans[i][j-1] + TS[i][j]);
            // cout<<"i "<<i<<"j "<<j<<endl;
            // cout<<ans[i][j]<<endl;
            // cout<<"----"<<endl;
        }
    }
    cout<<ans[max_x][max_y]<<endl;
    return 0;
}
