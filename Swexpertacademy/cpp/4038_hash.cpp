#include <iostream>
using namespace std;
long long int M = 1000000007;
long long int d[100001]{};

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
            if(!d[i]) d[i] = (d[i-1]*259)%M;
            shash = (shash + S[sl-i-1]*d[i])%M;
            bhash = (bhash + B[sl-i-1]*d[i])%M;
        }
        if(!d[sl]) d[sl] = d[sl-1]*259;
        
        for(int i=0; i<bl;i++){
            if(shash==bhash) cnt++;
            bhash = ((( bhash*259 + B[i+sl])%M - B[i]*d[sl])%M+M)%M;
            //if(bhash<0)
//            bhash = (bhash+M)%M;
        }
        if(shash==bhash) cnt++;
        cout<<"#"<<tc<<" "<<cnt<<endl;
    }
    
}
