#include <iostream>

using namespace std;

int T, N, v, mi, ma;
long long int a[200000][2];
int p[200000][2];
void frommin(int i, int k){
    if(a[i][0] <= a[k][0] && a[i][1] <= a[k][1]){
        p[i][0] = p[k][0];
        p[i][1] = k;
        p[k][0] = i;
        if(p[i][0] == -1) mi = i;
        return;
    }
    else frommin(i, p[k][1]);
    return;
}
void frommax(int i, int k) {
    if(a[i][0] >= a[k][0] && a[i][1] >= a[k][1]){
        p[i][1] = p[k][1];
        p[i][0] = k;
        p[k][1] = i;
        if(p[i][1] == -1) ma = i;
        return;
    }
    else frommax(i, p[k][0]);
    return;
}
int main(){
    cin>>T;
    for(int tc=1; tc<=T; tc++){
        cin>>N;
        cin>>a[0][0]>>a[0][1];
        p[0][0] = -1; p[0][1] = -1;
        mi = 0; ma = 0;
        for(int i = 1; i<N; i++){
            cin>>a[i][0]>>a[i][1];
            a[i][0]-a[mi][0] < a[ma][0] - a[i][0] ? frommin(i, mi) : frommax(i, ma); 
        }
        for(int i=0;i<N;i++){
            cout<<p[i][0]<<p[i][1]<<endl;
        }
        cout<<mi<<ma<<endl;
    }
}