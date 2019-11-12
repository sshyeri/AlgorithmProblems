#include <iostream>
#include <fstream>
using namespace std;

string arr[1001];
int dp[1001][1001];

int min(int i, int j, int k){
	if(i<j){
		if(k<i) return k;
		else return i;
	}
	else{
		if(k<j) return k;
		else return j;
	}
}
int main(){
	ifstream in("input.txt");
	int T;
	in>>T;
	for(int tc=1; tc<=T;tc++){
		int N;
		in>>N;
		int maxc = 0;
		for(int i=0; i<N;i++) in>>arr[i];
		for(int i=0; i<N;i++) {
			dp[0][i] = arr[0][i]=='0'? 1: 0;
			dp[i][0] = arr[i][0]=='0'? 1: 0;
		}
		for(int i=1; i<N; i++){
			for(int j=1; j<N; j++){
				if(arr[i][j]=='0'){
					dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1;
					if(dp[i][j] > maxc) maxc = dp[i][j];
				}
				else dp[i][j] = 0;
			}
		}
		cout<<"#"<<tc<<' '<<maxc<<endl;
	}
	return 0;
}