#include <iostream>

using namespace std;
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int solution(vector<string> board) {
    int answer = 0;
    int i=n/2;
    int j;
    int n = board.size();
    int dr[4] = {-1, -1, 1, 1};
    int dc[4] = {-1, 1, -1, 1};

    for(int i = n/2; i; i--){
    	int p = n-i;
    	int j = i;   	
    	while(j<p){
    		arr[i][j];
    		arr[p-1][j];
    		arr[j][i];
    		arr[j][p-1];
    		j++;
    	}	
    }
    while(i){
        int j = answer? answer/2:1;
        while(j){
            int k = 0;
            bool tag = true;
            while(tag){
                k++;
                int nr, nc;
                for(int d = 0; d<4; d++){
                    nr = i + dr[d]*k;
                    nc = j + dc[d]*k;
                    if(nr<0 || nr>=n || nc<0 || nc >=n || board[nr][nc] != board[i][j]){
                        tag = false;
                        break;
                    }
                }
            }
            if(k!=1){
                k = (k-1)*2 + 1;            
                if(k>answer) answer = k;
            }        
            j++;
            while(j*2+1<answer) j++;
            if((n-j)*2+1 < answer) break;
            while(i*2+1<answer) i++;
            if((n-i)*2+1 < answer) break;
        }
        i++;
        while(i*2+1<answer) i++;
        if((n-i)*2+1 < answer) break;       
    }
    return answer;
}
int main(){
	int n = 6;
	int **arr;
	for(int i=0; i<3; i++){
		*arr = new int[n];
	}
	arr[0][0] = 1;
	cout<<arr[0][0];
	return 0;
}