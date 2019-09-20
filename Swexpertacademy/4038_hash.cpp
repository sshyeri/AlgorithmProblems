#include <iostream>
using namespace std;
unsigned long long int M = 1000000007;
long long int d[100001];

int main(){
    int T, bl, sl; cin>>T;
    string B,S;
    d[0] = 1; d[1] = 259;
    for(int tc = 1; tc<=T; tc++){
        cin>>B>>S;
        sl = S.length();
        bl = B.length()-sl;
        int cnt = 0;
        long long int shash = 0;  long long int bhash = 0;
        for(int i = 0; i<sl; i++){
            if(!d[i]) d[i] = (d[i-1]*d[1])%M;
            shash = (shash + S[i]*d[i])%M;
            bhash = (bhash + B[i]*d[i])%M;
        }
        d[sl] = d[sl-1]*d[1];
        for(int i=0; i<bl;i++){
            if(shash==bhash) cnt++;
            bhash = (( bhash*d[1])%M + B[i+sl] - B[i]*d[sl] + M )%M;
        }
        if(shash==bhash) cnt++;
        cout<<"#"<<tc<<" "<<cnt<<endl;
    }
    
}
