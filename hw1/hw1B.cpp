#include <iostream>
using namespace std;

void recur(int st[], int sp[], int n, int &ans, int col_wal, int row_wal, int st2[], int sp2[]){
    
    if(n == 0) return;

    int index = n;
    n = 0;
    int index_x = 0;
    int index_y = 0;
    int prey = 0;
    int prex = 0;
    int max_x = col_wal;
    int max_y = row_wal;

    for(int i = 0; i < index; i++){
        if(st[i] > max_x && sp[i] >= row_wal){
            max_x = st[i];
            index_x = i;
        }
        else if(st[i] == max_x && sp[i] >= row_wal){
            if(sp[i] > prey){
                max_x = st[i];
                index_x = i;
                prey = sp[i];
            }
        }
        if(sp[i] > max_y && st[i] >= col_wal){
            max_y = sp[i];
            index_y = i;
        }
        else if(sp[i] == max_y && st[i] >= col_wal){
            if(st[i] > prex){
                max_y = sp[i];
                index_y = i;
                prex = st[i];
            }
        }
    }

    col_wal = st[index_y];
    row_wal = sp[index_x];
    
    for(int i = 0; i < index; i++){
        if(st[i] == max_x) ans++;
        if(sp[i] == max_y) ans++;
        if(st[i] == max_x && sp[i] == max_y) ans--;

        if(st[i] >= col_wal && sp[i] >= row_wal ){
            if(st[i] != max_x && sp[i] != max_y){
                st2[n] = st[i];
                sp2[n] = sp[i];
                n++;
            }
        }
    }
    recur(st2, sp2, n, ans, col_wal, row_wal, st, sp);
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n = 0;
    cin>>n;
    int ans = 0;

    int *st = (int*)malloc(n * sizeof(int));
    int *sp = (int*)malloc(n * sizeof(int));
    int *st2 = (int*)malloc(n * sizeof(int));
    int *sp2 = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        cin>>st[i]>>sp[i];
    }

    recur(st, sp, n, ans, 0, 0, st2, sp2);

    cout<<ans<<endl;

    return 0;
}