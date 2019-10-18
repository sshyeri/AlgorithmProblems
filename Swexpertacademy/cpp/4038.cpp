#include <iostream>
using namespace std;
string B;
string S;
int cnt;
int search(int i, int sl, int bl){
    int p = 0; int e = 0;
    while(i<bl && p<sl && B[i]==S[p]){
        ++i;++p;
        if(p==sl){
            cnt++;return e? e:i;
        }
        if(B[i]==S[0] && bl-i>=sl) e = search(i, sl, bl);
    }
    return e? e:i;
}
int main(){
    int T; cin>>T;
    for(int tc = 1; tc<=T; tc++){
        cnt = 0;
        cin>>B>>S;
        int bl = B.length(); int sl = S.length();
        int i = -1;
        while(++i<bl){
            if(B[i]==S[0]){
                if(sl==1) cnt++;
                else if(bl-i>=sl) i=search(i, sl, bl)-1;     
            }                    
        }
        cout<<"#"<<tc<<" "<<cnt<<endl;
    }
    return 0;
}