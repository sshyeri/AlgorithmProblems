#include <iostream>

using namespace std;

int H = 1;
int T, N;
int arr[8][8];

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int dfs(int r, int c, int l, int k){
    if(l>H) H = l;
    if(H>l+arr[r][c]+bool(k)) return 0;
    int nr, nc;
    for(int i = 0; i<4; i++){
        nr = r + dr[i]; nc = c + dc[i];
        if(0<=nr && nr<N && 0<=nc && nc<N){
            if(arr[nr][nc] < arr[r][c]) dfs(nr, nc, l+1, k);
            else if(k && arr[nr][nc] - k < arr[r][c]){
                arr[nr][nc] = arr[r][c] - 1;
                dfs(nr, nc, l+1, 0);
            }
        }
    }
    return 0;
}
int main(){
    cin>>T; int K;
    for(int tc = 1; tc <=T; tc++){
        cin>>N>>K;
        int P = 0; H = 1;
        for(int i = 0; i<N;i++){
            for(int j = 0; j<N; j++){
                cin>>arr[i][j];
                if(arr[i][j] > P) P = arr[i][j];
            }
        }
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                if(arr[i][j]==P) dfs(i, j, 1, K);
            }
        }
        cout<<"#"<<tc<<" "<<H<<endl;
    }
}