#include <iostream>

using namespace std;

int arr[1000000];
int main(){
	int T, n;
	cin>>T;
	for(int tc=1; tc<=T; tc++){
		cin>>n;
		for(int i=0; i<n; i++) cin>>arr[i];
		int sell = arr[n-1]
		int ans = 0;
		for(int i=n-2;i>=0;i--){
			if(arr[i]<sell) ans += (sell-arr[i]);
			else sell = arr[i];
		}
		cout<<'#'<<tc<<' '<<ans<<'\n';
	}
	return 0;
}