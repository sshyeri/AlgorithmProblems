#include <iostream>
using namespace std;
int T, N, n, s;
int main(){
    cin>>T;
    for(int t = 1; t<T; t++){
        cin>>N; s = 0;
        for(int i = 0; i<N;i++){
            cin>>n;
            if(!n) continue;
            if(s<2 || n<2) s += n;
            else s *= n;
        }
        cout<<"#"<<t<<" "<<s<<endl;
    }
}
