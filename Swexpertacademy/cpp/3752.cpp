// 조합
#include <iostream>
using namespace std;

int sum[10001]={0,};
int arr[100];
int chk[10001]={0,};
int cnt = 1;
int temp, j, p;

int combination(){
    return 1;
}
int main(){
    int T, N;
    cin>>T; 
    for(int tc = 1; tc <=T; tc++){
        cin>>N;
        for(int i = 0; i<N;i++) {
            cin>>arr[i];
            p = cnt;
            for(int j = 0; j<p;j++){
                temp = sum[j] + arr[i];
                if(!chk[temp]){
                    chk[temp]++;
                    sum[cnt] = temp;
                    cnt++;
                }
            }
        }
        cout<<"#"<<tc<<" "<<cnt<<endl;
        while(--cnt) chk[sum[cnt]] = 0;
        cnt++;
        sum[1] = 0;
    }
    return 0;
}