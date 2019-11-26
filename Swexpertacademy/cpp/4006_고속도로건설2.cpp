#include <iostream>
#include <fstream>
using namespace std;
#define ME 200002
#define MV 50001

int v[MV];
int size[MV];
int maxsize;
struct HEAP{
	int s;
	int e;
	int c;
	HEAP(){s=0, e=0, c=0;}
	HEAP(int s, int e, int c):s(s), e(e), c(c) {}
} edges[ME];
int pos;

void push(HEAP x){
	edges[++pos] = x;
	int i = pos;
	while(i>1){
		if(edges[i/2].c <= edges[i].c) break;
		HEAP t = edges[i];
		edges[i] = edges[i/2];
		edges[i/2] = t;
		i/=2;
	}
}
HEAP pop(){
	HEAP res = edges[1];
	edges[1] = edges[pos--];
	int i = 1;
	while(i*2<=pos){
		int left = edges[i*2].c;
		int right = edges[i*2+1].c;
		if(i*2+1 > pos) right = 10001;
		if(left<=right){
			if (edges[i].c <= left) break;
			else {
				HEAP t = edges[i];
				edges[i] = edges[i*2];
				edges[i*2] = t;
				i*=2;
			}
		}
		else{
			if(edges[i].c <= right) break;
			else{
				HEAP t = edges[i];
				edges[i] = edges[i*2+1];
				edges[i*2+1] = t;
				i = i*2+1;
			}
		}
	}
	return res;
}
int find(int x){
	while(x!=v[x]) x = v[x];
	return v[x];
}
void uni(int ap, int bp){
	if(size[ap]<size[bp]) {
		v[ap] = bp;
		size[bp] += size[ap];
		size[ap] = 0;
		if(size[bp] > maxsize) maxsize = size[bp];
	}
	else{
		v[bp] = ap;
		size[ap] += size[bp];
		size[bp] = 0;
		if(size[ap] > maxsize) maxsize = size[ap];
	}
}

int main(){
	freopen("input.txt", "r", stdin);

	int T;
	cin>>T;
	for(int tc=1; tc<=T;tc++){
		int N, M;
		int ans = 0;
		maxsize = 0;
		cin>>N>>M;
		pos = 0;	
		int s, e, c;
		int cnt = 1;
		for(int i=0; i<M; i++){
			cin>>s>>e>>c;
			push(HEAP(s, e, c));
		}
		for(int i=1;i<=N;i++){
			v[i] = i;
			size[i] = 1;
		}
		while(pos){
			HEAP now = pop();
			cout<<pos<<": "<<now.s<<' '<<now.e<<' '<<now.c<<endl;
			int ap = find(now.s);
			int bp = find(now.e);
			cout<<ap<<' '<<bp<<endl;
			if(ap!=bp) uni(ap, bp), ans += now.c;
			cout<<maxsize<<endl;
			cout<<"----------------"<<endl;
			if(maxsize >= N) break;
		}
		cout<<'#'<<tc<<' '<<ans<<endl;
	}
	return 0;
}	