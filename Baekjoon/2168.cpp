#include <iostream>
using namespace std;

int dr[4] = {0, 0, -1, 1};
int dc[4] = { 1, -1, 0, 0 };
int K, N, M;
int cnt = 0;
string word;
string arr[100];
int path[100][100][80]= {0,};

bool chk(int nr, int nc) {
   return 0 <= nr && 0 <= nc && nr < N && nc < M;
}
int dfs(int r, int c, int l){
    if(l<0) return 1;
    if(path[r][c][l] > -1) return path[r][c][l];
    path[r][c][l] = 0;
    int nr, nc;
    for (int i = 1; i <= K; i++) {
        for (int p = 0; p < 4; p++) {
            nr = r + i * dr[p];
            nc = c + i * dc[p];
            if (chk(nr, nc) && arr[nr][nc] == word[l]) path[r][c][l] += dfs(nr, nc, l-1);
        }
    }
    return path[r][c][l];
}
int main() {
    int i, j;
    cin >> N >> M >> K;
    for (i = 0; i < N; i++) cin >> arr[i];
    cin >> word;
    int l = word.length();
    for (i = 0; i < N; i++) {
       for (j = 0; j < M; j++) {
           for(int k = 0; k<l;k++) path[i][j][k] = -1;
        }
    }l--;
    for (i = 0; i < N; i++) {
       for (j = 0; j < M; j++) {
          if (arr[i][j] == word[l]) cnt += dfs(i, j, l-1);
       }
    }
    cout << cnt;   
    return 0;
}