#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 효율성 실패

int solution(vector<string> board) {
    int answer = 0;
    int i=1;
    int j;
    int n = board.size();
    int dr[4] = {-1, -1, 1, 1};
    int dc[4] = {-1, 1, -1, 1};
    while(i<n-1){
        int j = answer? answer/2:1;
        while(j<n-1){
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