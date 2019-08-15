#include <iostream>
#include <string>
using namespace std;

int q[201];
int team[201] ;

int chkRHS(string RHS[], int k, string name){
    for(int i = 0; i < k; i++){
        if (!RHS[i].compare(name)) return i;
        int len = RHS[i].length();
        if(len==name.length()){
            for(int j = 0; j<len ; j++){
                if(RHS[i][j] != name[j] && RHS[i][j]-32 != name[j] && RHS[i][j]+32 != name[j]) break;
                if(j==len-1) return i;
            }
        }
    }
    return k;
}

bool isBipartite(int **table, int len){
    for(int i = 0; i < len; i++)  team[i] = 0;
    int head = 0;
    int tail = 1;
    team[head] = 1;
    q[head] = 0;
    while (head < tail){
        int temp = q[head];
        head++;
        for(int i = 0; i < len; i++){
            if(table[temp][i] && !team[i]){
                team[i] = team[temp] * -1;
                q[tail] = i;
                tail++;
            }
            else if(table[temp][i] && team[i] + team[temp]){
                return false;
            }
        }
    }
    return true;
}

int main() {
    int T, K, lt, rt;
    string l, r;
    cin>>T;
    for(int tc=1; tc<=T; tc++){
        cin>>K;
        string RHS[K*2];
        int **table = new int*[K*2];
        for(int i = 0; i < K*2; i++) {
            table[i] = new int[K*2];
            for(int j = 0; j<K*2; j++)
                table[i][j] = 0;
        }
        int len = 0;
        for(int k = 0; k < K; k++){
            cin>>l>>r;
            lt = chkRHS(RHS, len, l);
            rt = chkRHS(RHS, len, r);
            if(lt == len || rt == len) {
                if(rt==lt){
                    rt++;
                    len++;
                }
                len++;
            }
            RHS[lt] = l;
            RHS[rt] = r;
            table[lt][rt] = 1;
            table[rt][lt] = 1;
        }
        cout<<"#"<<tc<<" ";
        isBipartite(table, len)? cout<<"Yes"<<endl : cout<<"No"<<endl;       
        for(int i = 0; i < K*2; ++i) delete [] table[i];
   		delete [] table;
    }
    return 0;
}
