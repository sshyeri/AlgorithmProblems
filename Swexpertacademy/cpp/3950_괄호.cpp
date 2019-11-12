#include <iostream>
#include <fstream>
using namespace std;
string s;
int arr[1001][2];
int main(){
	ifstream in("input.txt");

	int T;
	in>>T;
	for(int tc=1; tc<=T;tc++){
		int N;
		in>>N>>s;
		if(N%2) cout<<'#'<<tc<<' '<<-1<<endl;
		else{
			int cnt = 0;
			int ans = 0;
			int p = -1;
			for(int i=0; i<s.size(); i++){
				
			}
			cout<<'#'<<tc<<' '<<ans<<endl;
		}
	}
	return 0;
}	