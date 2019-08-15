#include <iostream>
using namespace std;
int T,N;short k;
int main(){
    int sum, max;
    cin>>T;
    for(int tc = 1; tc <= T; tc++){
        cin>>N;
        sum = 0;max = 0;
        while(N--){
            cin>>k;
            sum = sum+k<0? 0:sum+k; 
            if(max<sum) max = sum;
        } cout<<"#"<<tc<<" "<<max<<endl;       
    } return 0;
}