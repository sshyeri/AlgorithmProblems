#include <iostream>
using namespace std;

int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};
int arr[9][9];
int tot = 0;
int t = 0;
int watch = 0;
int Q[65][2];
int N, M;

int outlook(int i, int j, int d){
    bool tag = 0;
    if(i<0 || i>=N || j<0 || j>=M) return 0;
    if(!arr[i][j]) tag = 1;
    if(arr[i][j]==6) return 0;
    if(arr[i][j]<1) arr[i][j]--;
    return tag + outlook(i+dr[d], j+dc[d], d);
}
void back(int i, int j, int d){
    if(i<0 || i>=N || j<0 || j>=M) return;
    if(arr[i][j]<1) arr[i][j]++;
    if(arr[i][j]==6) return;
    return back(i+dr[d], j+dc[d], d);
}
void dfs(int cnt, int stage){
    if(cnt==tot) {
        watch = tot;
        return;
    }
    if(watch<cnt) watch = cnt;
    if(stage>=t) return;
    int i = Q[stage][0]; int j = Q[stage][1];
    switch(arr[i][j]){
        case 1:
            for(int d=0;d<4;d++){
                dfs(cnt + outlook(i+dr[d], j+dc[d], d), stage+1);
                back(i+dr[d], j+dc[d], d);
            }
            break;
        case 2:
            dfs(cnt + outlook(i+dr[0], j + dc[0], 0) + outlook(i+dr[2], j+dc[2], 2), stage+1);
            back(i + dr[0], j + dc[0], 0);
            back(i + dr[2], j + dc[2], 2);
            dfs(cnt + outlook(i+dr[1], j + dc[1], 1) + outlook(i+dr[3], j+dc[3], 3), stage+1);
            back(i + dr[1], j + dc[1], 1);
            back(i + dr[3], j + dc[3], 3);
            break;
            
        case 3:
            for(int d = 0; d<3; d++){
                dfs(cnt + outlook(i+dr[d], j + dc[d], d) + outlook(i+dr[d+1], j+dc[d+1], d+1), stage+1);
                back(i + dr[d], j + dc[d], d);
                back(i + dr[d+1], j + dc[d+1], d+1);
            }
            dfs(cnt + outlook(i+dr[0], j + dc[0], 0) + outlook(i+dr[3], j+dc[3], 3), stage+1);
                back(i + dr[0], j + dc[0], 0);
                back(i + dr[3], j + dc[3], 3);
            break;
        case 4:
            for(int p = 0; p<4; p++){
                int temp = cnt;
                for(int d=0; d<4;d++){
                    if(d==p) continue;
                    temp += outlook(i+dr[d], j+dc[d], d);
                }
                dfs(temp, stage+1);
                for(int d=0; d<4;d++){
                    if(d!=p) back(i + dr[d], j + dc[d], d);
                }
            }
    }
    return;
}
int main(){
    cin>>N>>M;
    int five = 64;
    for(int i=0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>arr[i][j];
            if(!arr[i][j]) tot++;
            else if(arr[i][j]==5){
                Q[five][0] = i;
                Q[five][1] = j;
                five--;
            }
            else if(arr[i][j]<5){
                Q[t][0] = i;
                Q[t][1] = j;
                t++;
            }
        }
    }
    if(tot){
        while(++five<65){
            for(int d=0;d<4;d++){
                tot -= outlook(Q[five][0]+dr[d], Q[five][1]+dc[d], d);
            }
        }
        dfs(0, 0);
        cout<<tot-watch;
    }
    else cout<<0;
    
    
}
