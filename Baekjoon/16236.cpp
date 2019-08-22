#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int N;
int arr[21][21];
int shark = 2;
int R, C;
int dr[4] = {-1,0,1,0};
int dc[4] = {0,-1,0,1};
int ans = 1;

int swim(int si, int sj, int fi, int fj){
    int chk[21][21] = {{0,},};
    chk[si][sj] = ans;
    queue< pair<int, int> > Q;
    int ni, nj;
    Q.push(make_pair(si, sj));
    while(!Q.empty()){
        pair<int, int> now = Q.front();
        Q.pop();
        si = now.first; sj = now.second;
        if(si==fi && sj==fj)  return chk[fi][fj];
        for(int p = 0; p<4; p++){
            ni = si + dr[p]; nj = sj + dc[p];
            if(0<=ni && ni < N && 0<=nj && nj < N && !chk[ni][nj]){
                if(arr[ni][nj]<=shark){
                    chk[ni][nj] = chk[si][sj] + 1;
                    Q.push(make_pair(ni, nj));
                }
            }
        }
    }
    return 555;
}
int search(int si, int sj){
    int dist = 500;
    arr[si][sj] = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(arr[i][j] && arr[i][j]<shark){
                int temp = swim(si, sj, i, j);
                if(temp < dist) {
                    dist = temp;
                    R = i; C = j;
                }
            }
        }
    }
    return dist==500? false: dist;
}
int main(){
    cin>>N;
    int si, sj;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>arr[i][j];
            if(arr[i][j]==9){
                si = i; sj = j;
            } 
        }
    } 
    int cnt = 0;
    while(true){
        int temp = search(si, sj);
        if (temp) {
            ans = temp;
            if(shark == ++cnt) {shark++; cnt = 0;}
            si = R; sj = C;
        } else break;
    } cout<<ans-1;
}