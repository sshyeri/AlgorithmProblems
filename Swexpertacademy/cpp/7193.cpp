#include <iostream>
using namespace std;
int T, N, n;
string X;
int main(){
    cin>>T;
    for(int tc = 1; tc<=T; tc++){
        cin>>N>>X; n = 0;
        for(int i = 0; i<X.length(); i++) n += X[i]-'0';
        cout<<"#"<<tc<<" "<<n%(N-1)<<endl;
    }
}