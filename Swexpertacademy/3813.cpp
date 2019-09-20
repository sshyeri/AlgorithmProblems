#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
void printW(vector<pair<int, int> > &W, int N){
    cout<<"W : ";
    for(int i = 0; i<N; i++) cout<<"( "<<W[i].first<<", "<<W[i].second<<" )";
    cout<<endl;
}
void printV(vector<int> &S, int N, char C){
    cout<<C<<" : ";
    for(int i = 0; i<N; i++) cout<<S[i]<<" ";
    cout<<endl;
}
int main(){
    int T;
    cin>>T;
    for(int tc = 1; tc<=T; tc++){
        vector<pair<int, int> > W;
        vector<int> S;
        cin>>N>>K;
        int tmp, i;
        for(i=0; i<N;i++){
            cin>>tmp;
            W.push_back(pair<int, int> (tmp, i));
        }
        for(i=0;i<K;i++) {
            cin>>tmp;
            S.push_back(tmp);
        }
        sort(W.begin(), W.end());
        vector<int> chk;
        chk.assign(N, 0);
        printW(W, N);
        printV(S, K, 'S');
        printV(chk, N, 'C');
        W.clear();
        S.clear();
    }
}