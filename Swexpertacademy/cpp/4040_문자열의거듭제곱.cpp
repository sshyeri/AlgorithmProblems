#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ifstream in("input.txt");

	int T;
	in>>T;
	for(int tc=1; tc<=T;tc++){
		string s;
		in>>s;
		int pe = 0, j = 0, cnt = 0;
		for(int i=0; i<s.size();i++){
			if (s[i] != s[j]) pe = i, j = 0, cnt = 0;
			else if(j==pe) cnt++, j = 0;
			else j++;
		}
		if(pe!=0) cnt++; 
		cout<<'#'<<tc<<' '<<cnt<<endl;
	}
	return 0;
}