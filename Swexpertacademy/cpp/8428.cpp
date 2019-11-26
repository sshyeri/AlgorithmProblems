#include <iostream>
#include <fstream>

using namespace std;
#define MN 100001
int arr[MN];
template<typename T> 
void _swap(T &a, T&b){
	T temp = a;
	a = b;
	b = temp;
}
template<typename It>
void _sort(It begin, It end){
	if(begin==end) return;
	_swap(*begin, *(((end-begin)/2) + begin));
	It pivot = begin;
	It left = begin + 1;
	It right = end - 1;
	while(left<=right){
		while(left <= right && *pivot >= *left) left++;
		while(left <= right && *right >= *pivot) right--;
		if(left<=right) _swap(*left, *right);
	}
	_swap(*pivot, *right);
	_sort(begin, right);
	_sort(right+1, end);
}
int main(){
	freopen("input.txt", "r", stdin);
	int T;
	cin>>T;
	for(int tc=1; tc<=T; tc++){
		int N;
		cin>>N;
		for(int i=1; i<N+1; i++) arr[i] = 0;
		for(int i=0; i<N-1; i++){
			int x, y;
			cin>>x>>y;
			arr[x]++;
			arr[y]++;
		}
		int ans = 0;
		if(N%2) ans += arr[N]/2+1;
		_sort(arr+1, arr+N);
		for(int i = 1; i<N; i+=2){
			ans -= arr[i]/2;
			ans += arr[i+1]/2;
		}

		
		cout<<'#'<<tc<<' '<<ans<<endl;

	}
	return 0;
}