#include <iostream>
#include <fstream>
#include <vector>
#define md 20001
using namespace std;


//가변배열

//폴더#
struct DIRR{
    char *name;
    DIRR* parent;
    int cnt;
    DIRR(){cnt = 0;}
 };

struct DIR{
	string name;
	vector<DIR>::iterator parent;
	vector<vector<DIR>::iterator> children;
} folder;
vector<DIR> folders;
vector<DIR>::iterator now;

bool mkdir(string s){
	folder.name = s;
	folder.parent = now;	
	now->children.push_back(folders.end());
	folders.push_back(folder);
	return 1;
}
// bool cd(string s){
// 	if(s=="/") {
// 		now = folders.begin();
// 		return 1;
// 	}
// 	else if(s==".."){
// 		if(now->name=="0") return 0;
// 		else{

// 		}
// 	}
// }
// int rm(){

// }
// int ls(){

// }
int main(){
	freopen("input.txt", "r", stdin);

	int T;
	cin>>T;
	folder.name = '0';
	folders.push_back(folder);
	now = folders.begin();
	for(int tc=1; tc<=T;tc++){
		int S, N;
		cin>>S>>N;
		int op;
		string x;		
		for(int n=0; n<N; n++){
			cin>>op>>x;
			if(op==1) mkdir(x);
			for(vector<DIR>::iterator it = folders.begin(); it<folders.end();it++){
				cout<<it->name<<endl;
			}
			

		}
	}
	string str = "abc";
	cout<<"-------:"<<str.find("abc")<<endl;
	cout<<str.compare("b")<<endl;
	return 0;
}