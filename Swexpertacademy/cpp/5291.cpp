#include <iostream>
using namespace std;

int arr[1000001] = {0, };

int prime(int a, int b){
    int r = 0;
    if(a<3) r+=2;
    for(int i = 3; i<b; i+=2){
        if(!arr[i]){
            if(i>a) r+=i;
            for(int j = i+i; j<b; j+=i) if(!arr[j]) arr[j] = 1;
        }
    }
    return r;
}
int main(){
    int T, a, b, i;
    cin>>T;
    for(i = 4; i<1000001; i+=2) arr[i] = 1;
    for(i = 6; i<1000001; i+=3) arr[i] = 1;
    for(int t = 1; t<=T; t++){
        cin>>a>>b;     
        cout<<"#"<<t<<" "<<prime(a, b)<<endl;       
    }
    return 0;
}
