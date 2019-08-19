#include <iostream>
using namespace std;

int T, N, M, x, y;
bool a[11][11];
bool chk[11] = {0,};
int m = 0;
int dfs(int i, int cnt){
    chk[i] = 1;
    for(int p=1; p<=N; p++) if(a[i][p] && !chk[p]) dfs(p, cnt+1);
    for(i=1;i<=N;i++) chk[i] = 0;
    if(m<cnt) m=cnt;
    return m;
}
int main(){
    cin>>T;
    for(int t=1;t<=T;t++){
        cin>>N>>M;
        m = 0;
        for(int i = 1; i<=N ; i++){
            for(int j = 1; j<=N; j++) a[i][j] = 0;
        }
        for(int i = 0; i<M;i++){
            cin>>x>>y;
            a[x][y] = 1; a[y][x] = 1;
        }
        for(int i = 1; i <= N; i++){
            dfs(i, 1);
        }
        cout<<"#"<<t<<" "<<m<<endl;
    }
}