#include <iostream>
#include <string.h>

using namespace std;
int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};

string arr[20];
int chk[20][20][4][16];
int R, C;
bool tag;

bool dfs(int r ,int c, int d, int m){
    if(r<0) r = R-1;
    if(c<0) c = C-1;
    if(tag) return true;
    if(arr[r][c]=='@') return tag = true;
    if(chk[r][c][d][m]>1) return false;
    else chk[r][c][d][m]++;
    
    if(arr[r][c] == '>') dfs(r, (c+1)%C, 0, m);
    else if(arr[r][c]=='<') dfs(r, (c-1)%C, 1, m);
    else if(arr[r][c]=='^') dfs((r-1)%R, c, 2, m);
    else if(arr[r][c]=='v') dfs((r+1)%R, c, 3, m);
    else if(arr[r][c]=='_') m? dfs(r, (c-1)%C, 1, m) : dfs(r, (c+1)%C, 0, m);
    else if(arr[r][c]=='|') m? dfs((r-1)%R, c, 2, m) : dfs((r+1)%R, c, 3, m);
    else if(arr[r][c]=='.') dfs((r+dr[d])%R, (c+dc[d])%C, d, m);
    else if(arr[r][c]=='+') m==15? dfs((r+dr[d])%R, (c+dc[d])%C, d, 0) : dfs((r+dr[d])%R, (c+dc[d])%C, d, m+1);
    else if(arr[r][c]=='-') m? dfs((r+dr[d])%R, (c+dc[d])%C, d, m-1) : dfs((r+dr[d])%R, (c+dc[d])%C, d, 15);
    else if(arr[r][c]=='?'){
        if(!chk[r][(c+1)%C][0][m]) dfs(r, (c+1)%C, 0, m);
        if(!chk[r][(c-1)%C][1][m]) dfs(r, (c-1)%C, 1, m);
        if(!chk[(r-1)%R][c][2][m]) dfs((r-1)%R, c, 2, m);
        if(!chk[(r+1)%R][c][3][m]) dfs((r+1)%R, c, 3, m);
    }
    else dfs((r+dr[d])%R, (c+dc[d])%C, d, arr[r][c]-'0');
    return false;
}
int main(){
    int T;
    cin>>T;
    tag = true;
    for(int tc = 1; tc<=T; tc++){
        cin>>R>>C;
        for(int i = 0; i<R;i++){
            cin>>arr[i];
            if(tag) continue;
            if(arr[i].find('@') != -1) tag = true;
        }
        memset(chk, 0, sizeof(chk));
        if(tag) {
            tag = false;
            dfs(0, 0, 0, 0);
        }
        if(tag) cout<<'#'<<tc<<" YES"<<endl;
        else cout<<'#'<<tc<<" NO"<<endl;
    }
    return 0;
}
