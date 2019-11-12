#include <iostream>
#include <fstream>
using namespace std;
#define INF -987654321
class 
int main(){
	ifstream in("input.txt");

	int T;
	in>>T;
	for(int tc=1; tc<=T; tc++){
		int N, M;
		in>>N>>M;
		int **costs = new int*[M];
		for(int i=0; i<M; i++) {
			costs[i] = new int[3];
			in>>costs[i][0]>>costs[i][1]>>costs[i][2];
		}

	}
	return 0;
}