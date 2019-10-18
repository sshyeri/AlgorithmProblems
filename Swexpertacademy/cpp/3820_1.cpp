#include <iostream>

using namespace std;

int T, N, v, mi, ma;
long long int a[200000][2];
int p[200000];

void merge(int l, int r, int m){
    int i = l; int j = m+1; int k = l;
    while(i<=m && j<=r){
        if(a[j][1]*(a[i][0]-1) <= a[i][1]*(a[j][0]-1)) p[k++] = i++;
        else p[k++] = j++;
    }
    int t = i>m? j:i;
    while(l<=t || t<=r) p[k++] = t++; 
}
void partition(int l, int r){
    if(l<r){
        int m = (l+r)/2;
        partition(l, m);
        partition(m, r);
        merge(l, r, m);
    }
}
int main(){
    cin>>T;
    for(int tc=1; tc<=T; tc++){
        cin>>N;
        for(int i = 0; i<N; i++) cin>>a[i][0]>>a[i][1];
        partition(0, N-1);
        for(int i = 0; i<N; i++) cout<<p[i];
    }
}