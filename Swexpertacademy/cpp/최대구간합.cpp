#include <iostream>
#include <fstream>
int arr[1000001];
int main(){
	freopen("input.txt", "r", stdin);
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin>>T;
	for(int tc=1; tc<=T; tc++){
		int N;
		cin>>N;
		 
		for(int i=0; i<N; i++) {
			cin>>arr[i];
		}
	}
	return 0;
}