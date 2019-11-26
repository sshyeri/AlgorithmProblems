#include <iostream>
#include <fstream>

using namespace std;
int arr[202];

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
		int N, K;
		cin>>N>>K;
		for(int i=0; i<N; i++) cin>>arr[i];
		_sort(arr, arr+N);
		double score = 0;
		for(int i=N-K; i<N; i++){
			score = (score + arr[i])/2;
		}
		cout<<'#'<<tc<<' '<<score<<endl;
		

	}
	return 0;
}