#include <string>
#include <vector>
using namespace std;

// 효율성2개통과, 정확성에서 시간초과..

int dr[4] = {-1, -1, 1, 1};
int dc[4] = {-1, 1, -1, 1};

int cross(vector<string> board, int i, int j, int n){
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
                if(k!=1) return (k-1)*2 + 1;            
                else return 0;
            }
        }
    }
    if(k!=1) return (k-1)*2 + 1;            
    else return 0;
    
}
int solution(vector<string> board) {
    int answer = 0;
    int n = board.size();   
    int i = n/2;
    while(i){
    	int p = n-i;
    	int j = i;   	
    	while(j<p){
            int temp;
    		temp = cross(board, i, j, n);
            if(temp>answer) answer = temp;
            if(answer >= i*2+1) return answer;
    		temp = cross(board, p-1, j, n);
            if(temp>answer) answer = temp;
            if(answer >= i*2+1) return answer;   		
    		j++;
            while(j*2+1<answer) j++;
            if((n-j)*2+1 < answer) break;
    	}
        j = i+1;
        while(j<p-1){
            int temp;
            temp = cross(board, j, i, n);
            if(temp>answer) answer = temp;
            if(answer >= i*2+1) return answer;
    		temp = cross(board, j, p-1, n);
            if(temp>answer) answer = temp;   
            if(answer >= i*2+1) return answer;
            j++;
            while(j*2+1<answer) j++;
            if((n-j)*2+1 < answer) break;
        }
        if(answer >= i*2+1) return answer;
        i--; 
    }       
    return answer;
}