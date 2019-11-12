// solution.cpp

#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool compare(string a, string b){
    return a.len(), b.len()
}
int solution(vector<string> strs, string t)
{
    int answer = 0;
    vector<string>::iterator it=strs.begin();
    strs.sort(strs.begin(), strs.end(), compare)
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    for(auto v : strs){
    	cout>>*v<<" ";
    }
    return answer;
}
int main(){
	vector<stirng> strs = {'ba','na','n','a'};
	string t = "banana";
	solution(strs, t);
	return 0;
}