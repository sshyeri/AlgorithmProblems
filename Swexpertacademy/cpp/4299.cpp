#include <iostream>
using namespace std;

int main(){
    int T, i;
    cin>>T;
    for(i = 1; i<=T; i++){
        int D, H, M, ans;
        cin>>D>>H>>M;
        ans = D*24*60 + H*60 + M;
        ans -= 11*24*60 + 11*60 + 11;
        if(ans<0) cout<<"#"<<i<<" "<<-1<<endl;
        else cout<<"#"<<i<<" "<<ans<<endl;
    }
    return 0;
}