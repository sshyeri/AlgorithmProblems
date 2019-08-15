#include <iostream>
using namespace std;

int T, N, r, l;
char f[49];

int main(){
    int sum = 0;
    cin>>T;
    for(int tc = 1; tc<=T; tc++){
        cin>>N;
        r = N/2;
        l = N/2;
        for(int i=0; i<N;i++){
            cin>>f;
            for(int j=r; j<=l; j++) sum += f[j]-'0';
            if(i<N/2) {
                r--;l++;
            }else if(i>=N/2){
                r++;l--;
            }
        }
        cout<<"#"<<tc<<" "<<sum<<endl;
        sum = 0;
    }
    return 0;
}