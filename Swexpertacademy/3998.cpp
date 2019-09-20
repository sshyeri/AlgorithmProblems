#include <iostream>

using namespace std;
#define MAX 100001

int A[MAX];
int temp[MAX];

long long int conquer(int l, int m, int r){
    long long int val = 0;
    int i=l;int j=m+1; int k=l;
    while(i<=m && j<=r){
        if(A[i]<A[j]) {
            temp[k] = A[i];
            k++;i++;
        }
        else{
            temp[k] = A[j];
            k++;j++;
            val += m-i+1;
        }
    }
    int t = i>m? j:i;
    while(k<=r) {
        temp[k] = A[t];
        k++;t++;
    }
    for(int i=l; i<=r; i++) A[i] = temp[i];
    return val;
}

long long int count(int l, int r){
    if(l==r) return 0;
    int m = (l+r)/2;
    long long int val = count(l, m) + count(m+1, r);
    val += conquer(l, m, r);
    return val;
}
int main(){
    int T, N;cin>>T;
    for(int tc=1;tc<=T;tc++){
        cin>>N;
        for(int i=1;i<=N;i++) cin>>A[i];
        cout<<"#"<<tc<<" "<<count(1, N)<<endl;
    }
    return 0;
}
