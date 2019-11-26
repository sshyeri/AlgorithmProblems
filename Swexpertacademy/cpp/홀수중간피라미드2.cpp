// #include <fstream>
#include <iostream>

using namespace std;

int arr[200002];
int N;
int ans;

void binsearch(int s, int e){
	while(s<=e){
		int mid = (s+e)/2;
		int n = arr[N]>=mid;
		int nl = arr[N-1]>=mid;
		int nr = arr[N+1]>=mid;
		if(n && (nl||nr)){
			s = mid + 1;
			if(mid>ans) ans = mid;
			continue;
		}
		else if(!n && !(nl*nr)){
			e = mid - 1;
			continue;
		}
		else{
			int ll, l, rr, r;
			l = nl;
			r = nr;
			bool tag = false;
			for(int t=2; t<N; t++){
				ll = l;
				rr = r;
				l = arr[N-t]>=mid;
				r = arr[N+t]>=mid;
				if((!ll && !l) || (!r && !rr)){
					e = mid - 1;
					tag = true;
					break;
				}
				else if((ll && l) ||  (r && rr)){
					s = mid + 1;
					if(mid>ans) ans = mid;
					tag = true;
					break;
				}
			}
			if(!tag){
				if(l&&r) {
					s = mid+1; 
					if(mid>ans) ans = mid;
				}

				else e = mid - 1;
			}
		}
	}
	return;
}
int main(){
	// freopen("input.txt", "r", stdin);
	
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin>>T;
	for(int tc=1; tc<=T; tc++){
		cin>>N;
		ans = 0;
		int first = 2*N-1;	
		for(int i=1; i<=first; i++) cin>>arr[i];
		binsearch(1, first);	
		cout<<'#'<<tc<<' '<<ans<<'\n';
		
	}
	return 0;
}

