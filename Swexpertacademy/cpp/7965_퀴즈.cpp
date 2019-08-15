#include <iostream>
using namespace std;

int T, N, i;
long dp[1000000] = {0,}; 
int Tag = 0;
long ns, t;
const int mok = 1000000007;
#define nam(k) k<mok? k : (k)%mok

long square(int n){
    int p = 0;
    long temp = n;
    int end = n;
    long a = 1;
    while(p<n){
        for(i=1; i*2<=end; i*=2) temp = nam(temp*temp);
        a = nam(a*temp);  
        p += i;
        temp = n;
        end -= i;
    }
    if( p == n-1 ) return a*n;
    return a;
}
int main(){
    cin>>T;
    dp[0] = 1; Tag = 0;
    for(int tc = 1; tc <= T; tc++){
        cin>>N;
        while(Tag<=N-1){
            Tag++;
            ns = square(Tag+1);
            dp[Tag] = nam(dp[Tag-1]+ns);
        }
        cout<<"#"<<tc<<" "<<dp[N-1]<<endl;
    }
    return 0;
}