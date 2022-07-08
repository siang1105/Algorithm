#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

long long N = 0;
long long M = 0;
char input;
int Lx = 0;
int Ly = 0;
int Bx = 0;
int By = 0;
int Dx = 0;
int Dy = 0;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

struct  point{
   int x;
   int y;
};

int check( int x, int y){
    return (x >= 0 && x < N && y >= 0 && y < M);
}

int BFS(int **arr, int second){
    queue <point> bfs;
    point top;
    point tmp;
    top.x = Bx;
    top.y = By;
    
    bfs.push(top);
    int can = 0;
    int vis[1001][1001] = {0};
    while(bfs.empty() == false){
        top = bfs.front();
        bfs.pop();
        for(int i = 0; i < 4; i++){
            tmp.x = top.x + dx[i];
            tmp.y = top.y + dy[i];
            if((check(tmp.x, tmp.y) == 1) && ((arr[tmp.x][tmp.y] > second) || (arr[tmp.x][tmp.y] == -1)) && (vis[tmp.x][tmp.y] == 0 )){
                if(tmp.x == Dx && tmp.y == Dy) can = second;
                vis[tmp.x][tmp.y] = 1;
                bfs.push(tmp);
            }
        }
    }
    return can;
}

queue <point> Q;

int floodfill(int **arr){
    point top;
    point tmp;
    int second = 1;
    while(Q.empty() == false){
        int size = Q.size();
        while(size--){
            top = Q.front();
            Q.pop();
            for(int i = 0; i < 4; i++){
                tmp.x = top.x + dx[i];
                tmp.y = top.y + dy[i];
                if(check(tmp.x, tmp.y) && arr[tmp.x][tmp.y] == 0 ){
                    arr[tmp.x][tmp.y] = second;
                    Q.push(tmp);
                }
            }
        }
        second++;
    }
    int low = 0;
    int high = second;
    int can = 0;
    int n = 4;
    int guess = 0;
    if(second % 2 == 0) guess = second / 2;
    else guess = (second + 1) / 2;
    
    while(1){
        if(low == high){
            can = BFS(arr, guess);
            if(can > 0) guess = high;
            else guess = high -1;
            break;
        }
        can = BFS(arr, guess);
        if(can > 0){
            if(guess == high) break;
            low = guess + 1;
        }
        else{
            if(guess == low){
                guess = low - 1;
                break;
            }
            high = guess - 1;
        }
        if((high + low) % 2 == 0) guess = (high + low) / 2;
        else guess = (high + low - 1) / 2;
    }
    can = BFS(arr, guess);
    return can;
}


int main(){
    point q;
    cin>>N>>M;
    int **arr = (int **) malloc(N * sizeof(*arr));
    for (int i = 0; i < N; i++){
        arr[i] = (int *) malloc(M * sizeof(int));
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin>>input;
            if(input == 'C'){
                arr[i][j] = 0;
            }
            else if(input == 'L'){
                arr[i][j] = 1;
                q.x = i;
                q.y = j;
                Q.push(q);
                Lx = i;
                Ly = j;
            }
            else if(input == 'B'){
                arr[i][j] = -2;
                Bx = i;
                By = j;
            }
            else if(input == 'O'){
                arr[i][j] = -3;
            }
            else if(input == 'D'){
                arr[i][j] = -1;
                Dx = i;
                Dy = j;
            }
        }
    }
    int an = floodfill(arr);
    if(an == 0) an = -1;
    cout<<an<<endl;
    return 0;

}