#include <iostream>

using namespace std;
#define MAX 1000001

long long int A[MAX]{};
long long int S[MAX]{};
int p = 1;

void phi(int b){
    for(;p<=b;p++){
        if(!A[p]){
            for(int i = p; i<MAX; i+=p) {
                if(!A[i]) A[i] = i;
                A[i] = A[i] * (p-1)/p;
            }
        }
        S[p] = S[p-1] + A[p];
    }
    return;
}
int main(){
    A[1] = 1; S[1] = 1;
    int T;cin>>T;
    for(int tc=1;tc<=T;tc++){
        int a, b; cin>>a>>b;
        if(p<=b) phi(b);
        cout<<"#"<<tc<<" "<<S[b] - S[a-1]<<endl;
    }
    return 0;
}
