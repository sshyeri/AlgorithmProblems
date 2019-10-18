#include <iostream>
#include <fstream>

using namespace std;
int solve(int N){

	return 0;
}
int main(){
	int a, T;
	ifstream myfile("input.txt");
	if(myfile.is_open()){
		myfile >> T;
		for(int tc = 1; tc<=T; tc++){
			myfile >> a;
			cout<<'#'<<tc<<' '<<solve(a)<<endl;
		}
		myfile.close();
	}
	else cout<<"Unable to open file";
	return 0;
}