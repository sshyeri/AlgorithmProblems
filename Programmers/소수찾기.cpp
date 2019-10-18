#include <iostream>
#include <fstream>

using namespace std;
int solution(string numbers) {
    int answer = 0;
    answer = numbers[0]-48;
    return stoi(numbers);
}
int main(){
	int T; 
	string s;
	ifstream myfile("input.txt");
	if(myfile.is_open()){
		myfile >> T;
		for(int tc = 1; tc<=T; tc++){
			myfile >> s;
			cout<<'#'<<tc<<' '<<solution(s)<<endl;
		}
		myfile.close();
	}
	else cout<<"Unable to open file";
	return 0;
}