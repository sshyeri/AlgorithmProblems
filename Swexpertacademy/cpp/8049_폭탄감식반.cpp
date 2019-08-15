#include <iostream>
using namespace std;

const char bomb11[3] = "FF";
const char bomb12[4] = "MCM";
const char bomb21[3] = "FC";
const char bomb22[3] = "MF";
bool chk(string bomb, int i){
    while(i >= 4){
        if(i >= 5 && !bomb.find(bomb11)){
            bomb.erase(0,2);
            i -= 2;
            while(bomb.at(0)=='F'){ 
                bomb.erase(0,1);
                i--;
                if(i < 3) return false;
            }
            if(bomb.find(bomb12)) return false;
            else {
                bomb.erase(0,3);
                i -= 3;
                while(i && bomb.at(0)=='M') {
                    bomb.erase(0,1);
                    i --;
                }
            }
        }
        else if(i >= 4 && !bomb.find(bomb21)){
            bomb.erase(0,2);
            i -= 2;
            while(bomb.at(0) == 'C'){
                bomb.erase(0,1);
                i --;
                if(i < 2) return false;
            }
            if(bomb.find(bomb22)) return false;
            else{
                bomb.erase(0, 2);
                i -= 2;
            }           
        }else return false;
    }
    if (!i) return true;
    return false;
}
int main(){
    int T;
    cin>>T;
    bool B = true;
    string bomb;
    for(int tc = 1; tc<=T; ++tc){
        cin>>bomb;
        int i = bomb.size();
        if(i >= 4) B = chk(bomb, i);
        else B = false;
        cout<<"#"<<tc<<" ";
        if(B) cout<<"DETECTED!"<<endl;
        else cout<<"NOTHING!"<<endl;
    }
    return 0;
}