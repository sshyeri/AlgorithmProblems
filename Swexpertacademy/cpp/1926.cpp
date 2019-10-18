#include <iostream>

using namespace std;


int main(){
	int n;
	cin>>n;
	for(int i=1; i<=n; i++){
		int p = i;
		int tag = false;
		while(p){
			switch(p%10){
				case 3: 
				case 6: 
				case 9: 
					tag = true;
					cout<<'-';
			}
			p/=10;
		}
		if(!tag) cout<<i;
		cout<<' ';
	}
		
	return 0;
}