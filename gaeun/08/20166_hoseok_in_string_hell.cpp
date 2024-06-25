#include <iostream>
using namespace std;

int N;
int M;
int K;
char GRID[11][11]; // 1x1 ~ NxM
string beLovedStrings[1000];
int caseNum[1000]={0,};
int dr[8] = {-1, 1, 0, 0, -1, 1, 1, -1}; // 상하좌우, 2, 3, 4, 1사분면 대각선
int dc[8] = {0, 0, -1, 1, -1, -1, 1, 1}; // 상하좌우, 2, 3, 4, 1사분면 대각선

void dfs(int row, int col, int stringIdx, string beLovedStr, int charIdx, int strSize){
    int nrow, ncol;

    if(GRID[row][col] == beLovedStr[charIdx]){
        // 상하좌우, 각 대각선에 대해
        for(int i=0; i<8; i++){
            nrow = row + dr[i];
            ncol = col + dc[i];

            // make it circular
            if(nrow < 1) nrow = N;
            if(nrow > N) nrow = 1;
            if(ncol < 1) ncol = M;
            if(ncol > M) ncol = 1;

            // 특정 방향에 대해 주어진 문자열의 '다음 글자'와 일치하는지 확인. 일치한다면,
            int checkIdx = charIdx + 1;
            if(GRID[nrow][ncol] == beLovedStr[checkIdx]){
                // 주어진 문자열의 끝까지 검사했다면 경우의 수 +1
                if(checkIdx == strSize-1){
                    caseNum[stringIdx]++;
                    continue; // 다른 방향에서 만족시키는 경우 있는지 확인하러.
                } 
                // 아직 아니라면 특정 방향에 대해 그 다음 글자 일치 여부 확인하기 위한 dfs 실행.
                else dfs(nrow, ncol, stringIdx, beLovedStr, checkIdx, strSize);
            }
        }
    }
    
}

int main(){
    // get input
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> GRID[i][j];
        }
    }
    for(int i=0; i<K; i++){
        cin >> beLovedStrings[i];
    }

    // use greedy to find the number of cases
    for(int stringIdx=0; stringIdx<K; stringIdx++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=M; j++){
                // GRID에서 첫번째 단어와 일치하는 문자를 찾았다면, 
                if(GRID[i][j] == beLovedStrings[stringIdx][0]){
                    dfs(i,j,stringIdx,beLovedStrings[stringIdx],0,beLovedStrings[stringIdx].size());
                }
            }
        }
    }

    // result
    for(int i=0; i<K; i++){
        cout << caseNum[i] << endl;
    }    

}