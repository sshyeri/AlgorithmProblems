#include <iostream>
#include <map>
using namespace std;
long long printAll(long long n, int cnt) {
    while(cnt--) cout<<" "<<n;
    return n+1;
}
int main(){
    map<long long, int> A;
    map<long long, int>::iterator iter;
    int T, N;
    long long k;
    cin>>T;
    for(int i = 1; i<=T; i++){
        cin>>N;
        if(N==1) {
            cin>>k;
            cout<<"#"<<i<<" "<<k;
        }else{
            for(int p = 0; p < N; p++){
                cin>>k;
                if(A.find(k)==A.end()) A[k] = 1;
                else A[k]++;
            }
            cout<<"#"<<i;
            if(A.size()==1){
                while(N--) cout<<" "<<k;
            }else if(A.size()==2 && A.find(A.begin()->first+1) != A.end()){
                iter = ++A.begin();
                while(iter->second--) cout<<" "<<iter->first;
                --iter;
                while(iter->second--) cout<<" "<<iter->first;            
            }else{
                iter = A.begin();
                k = printAll(iter->first, iter->second);
                iter->second = 0; ++iter;
                map<long long, int>::iterator jter = A.end();
                --jter;--jter;
                while(iter != jter){                   
                    if(iter->second){
                        if(k==iter->first && A.upper_bound(k)->second){
                            A.upper_bound(k)->second--;
                            cout<<" "<<A.upper_bound(k)->first;
                        }
                        k = printAll(iter->first, iter->second);
                        iter->second = 0; 
                    }++iter;
                }++jter;
                if(k==iter->first && jter->second){
                    jter->second--;
                    cout<<" "<<jter->first;
                }k = iter->first;
                if(jter->first == k+1){
                    printAll(k+1, jter->second );
                    printAll(k, iter->second);
                }else{
                    printAll(k, iter->second);
                    printAll(jter->first, jter->second);
                }
            }
            A.clear();
        }
        cout<<endl;
    }

    return 0;
}