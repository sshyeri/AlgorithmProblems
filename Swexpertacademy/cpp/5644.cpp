#include <iostream>

using namespace std;

int arr[10][10][3];
int ans = 0;
int dr[5] = {0, -1, 0, 1, 0};
int dc[5] = {0, 0, 1, 0, -1};
int AM[101];
int BM[101];
int power[9] = {0,};
int Q[100][3];

void setPower(int r, int c, int i){
    if(!arr[r][c][0]) {
        arr[r][c][0] = i;
        return;
    }
    int maxp = arr[r][c][0];
    arr[r][c][0] = -1;
    if(power[maxp]<power[i]) swap(maxp, i);
    arr[r][c][1] = maxp;
    arr[r][c][2] = i;
}
void bfs(int r, int c, int i, int area){
    int nr, nc;
    int h = 0; int t = 1;
    Q[h][0] = r; Q[h][1] = c; Q[h][2] = area;
    while(h<t){
        r = Q[h][0]; c = Q[h][1]; area = Q[h][2]; h++;
        if(!area) continue;
        for(int k = 1; k<5;k++){
            nr = r + dr[k]; nc = c + dc[k];
            if(0<=nr && 0<=nc && nr<10 && nc<10 && arr[nr][nc][0] != -1 && arr[nr][nc][0] != i){
                setPower(nr, nc, i);
                Q[t][0] = nr; Q[t][1] = nc; Q[t][2] = area-1; t++;
            }
        }
    }
    
}
int main(){
    int T;
    int M, A, r, c, area, nr, nc;
    cin>>T;
    AM[0] = 0; BM[0] = 0;
    for(int tc = 1; tc<=T; tc++){
        int ans = 0;
        cin>>M>>A;
        for(int i = 1; i<=M; i++) cin>>AM[i];
        for(int i = 1; i<=M; i++) cin>>BM[i];
        for(int i = 0; i<10; i++){
            for(int j = 0; j<10; j++){
                arr[i][j][0] = 0;
            }
        }
        for(int i = 1; i<=A; i++){
            cin>>c>>r>>area>>power[i];
            r--;c--;
            setPower(r, c, i);
            bfs(r, c, i, area);
        }
        for(int i = 0; i<10; i++){
            for(int j = 0; j<10; j++){
                cout<<arr[i][j][0]<<" ";
            }cout<<endl;
        }
        cout<<"power-------------"<<endl;
        for(int i = 0; i<9; i++){
            cout<<power[i]<<" ";
        }cout<<endl;
        // ---------end Init
        int ar = 0; int ac = 0; int br = 9; int bc = 9;
        for(int m = 0; m<=M; m++){
            ar += dr[AM[m]]; ac += dc[AM[m]];
            br += dr[BM[m]]; bc += dc[BM[m]];

            if(arr[ar][ac][0] && arr[ar][ac][0] == arr[br][bc][0] ){
                // 둘 다 경계
                if(arr[ar][ac][0] == -1 ) {
                    int temp = power[arr[ar][ac][1]] + power[arr[br][bc][2]];
                    int ttemp = power[arr[ar][ac][2]] + power[arr[br][bc][1]];
                    ans += temp<ttemp? ttemp:temp;
                }
                // 같은 공간
                else ans += power[arr[ar][ac][0]];
            }
            // A만 경계
            else if(arr[ar][ac][0] == -1) {
                ans += power[arr[br][bc][0]];
                if( arr[ar][ac][1] == arr[br][bc][0]) ans += power[arr[ar][ac][2]];
                else ans += power[arr[ar][ac][1]];
            }
            // B만 경계
            else if(arr[br][bc][0] == -1) {
                ans += power[arr[ar][ac][0]];
                if( arr[br][bc][1] == arr[ar][ac][0]) ans += power[arr[br][bc][2]];
                else ans += power[arr[br][bc][1]];
            }
            // 둘 다 서로 다른 곳, 경계X or 0
            else ans += power[arr[ar][ac][0]] + power[arr[br][bc][0]];
            
            cout<<"-----T"<<m<<"---------"<<endl<<ar<<" "<<ac<<" "<<br<<" "<<bc<<" : "<<ans<<endl;
        }
        cout<<'#'<<tc<<' '<<ans<<endl;
    }
}
