#include <iostream>
#include <fstream>
using namespace std;

int main(){
	freopen("input.txt", "r", stdin);

	int T;
	cin>>T;
	int X, N;
	for(int tc=1; tc<=T;tc++){
		cin>>X>>N;
		int s, e;
		bool stag, etag = false;
		int ans = 0;
		for(int i=0; i<N; i++){
			cin>>s>>e;
			if(!stag && s<=1) stag = true;
			if(!etag && e>=X) etag = true;
			if(s>X) continue;


		}
		if(stag && etag){
			//solve
		}
		cout<<'#'<<tc<<' '<<ans<<'\n';

	}
}