#include <iostream>

using namespace std;

#define MAX 50001
long long int opt[MAX][MAX] {};
long long int arr[MAX][MAX] {};
int N,X;
long long int route(int ss, int s, int e, long long int m, long long int t){
    if(opt[s][e]) return opt[s][e];
    if(s==e) return t;
    for(int i=s; i<=N; i++){
        if(arr[s][i] && arr[s][i] + t < m) return route(i, i, e, m, arr[s][i] + t );
    }
    return m;

}

int main(){
    int T; cin>>T;
    for(int tc=1; tc<=T; tc++){
        int M;cin>>N>>M>>X;
        int s,e,t;
        for(int i=0; i<M; i++){
            cin>>s>>e>>t;
            arr[s][e] = t;
        }
        int ans = 50000000;
        for(int i=1;i<N;i++){
            if(i==X) continue;           
            if(!opt[i][X]) {
                int temp = arr[i][X]? arr[i][X]:50000000;
                opt[i][X] = route(i, i, X, temp, 0);
            }
            if(!opt[X][i]) {
                int temp = arr[X][i]? arr[X][i]:50000000;
                opt[X][i] = route(i, i, X, temp, 0);
            }
            t = opt[i][X] + opt[i][X];
            if(ans<t) ans = t;
        }
        cout<<ans<<endl;
    }
}