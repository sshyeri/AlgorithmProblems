#include <iostream>
using namespace std;
int ans = 0;
int T;
int arr[4][4];
int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};
bool chk[10000000];
int p[10000001];

void dfs(int r, int c, int n, int cnt){
    if(cnt==7){ 
        if(chk[n]!=1){
            chk[n] = 1;
            p[ans++] = n;
        }
        return;           
    } 
    for(int i = 0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr>=0 && nr<4 && nc>=0 && nc<4) dfs(nr, nc, n*10+arr[nr][nc], cnt+1);
    }
    return;
}
int main(){
    cin>>T; 
    for(int t = 1; t<=T; t++){
        for(int i = 0; i<4; i++){
            for(int j = 0; j<4; j++) cin>>arr[i][j];
        }
        for(int i = 0; i<4; i++){
            for(int j = 0; j<4; j++) dfs(i, j, arr[i][j], 1);
        }
        cout<<"#"<<t<<" "<<ans<<endl;
        while(--ans) chk[p[ans]] = 0;
        chk[p[0]] = 0;
    }
    return 0;
}