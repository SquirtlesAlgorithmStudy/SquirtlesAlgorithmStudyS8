// 신이 좋아하는 문자열 입력 후 search -> 최대 10*10*8^5*1000 (+ alpha) = 4억 = 4초
// grid에서 만들 수 있는 문자열을 모두 저장 후, 문자열을 k개 입력받아 search -> 최대 10*10*8^5(3백만대) + 탐색
// O(logN)을 갖고, key-value쌍을 지원하는 map을 써봅시다. 

#include <iostream>
#include <map>
using namespace std;

int N;
int M;
int K;
char GRID[11][11]; // 1x1 ~ NxM
map <string, int> strCases; // doesn't allow duplicated strings
int dr[8] = {-1, 1, 0, 0, -1, 1, 1, -1}; // 상하좌우, 2, 3, 4, 1사분면 대각선
int dc[8] = {0, 0, -1, 1, -1, -1, 1, 1}; // 상하좌우, 2, 3, 4, 1사분면 대각선

void dfs(int row, int col, string str, int charNum){
    int nrow, ncol;

    str += GRID[row][col];
    charNum++;

    // map에 저장되어 있지 않는 문자열이라면 저장
    if(strCases.find(str) == strCases.end()){
        strCases.insert({str,1});
    }
    // 이미 저장된 것이라면 경우의 수만 증가 
    else{
        strCases[str]++;
    }

    // 글자수가 5 미만이라면 계속 탐색
    if(charNum < 5){
        // 상하좌우, 각 대각선에 대해
        for(int i=0; i<8; i++){
            nrow = row + dr[i];
            ncol = col + dc[i];

            // make it circular
            if(nrow < 1) nrow = N;
            if(nrow > N) nrow = 1;
            if(ncol < 1) ncol = M;
            if(ncol > M) ncol = 1;
            
            // dfs
            dfs(nrow, ncol, str, charNum);
        }    
    }

    
}

int main(){
    // print after get all the inputs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // get input
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin >> GRID[i][j];
        }
    }

    // store all possible strings
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            dfs(i,j,"",0);
        }
    }

    for(int i=0; i<K; i++){
        string beLovedString;
        cin >> beLovedString;

        // GRID에서 만들어질 수 없는 문자열이라면 0 출력
        if(strCases.find(beLovedString) == strCases.end()){
            cout << 0 << '\n';
        }
        // 만들어질 수 있는 문자열이라면 그 경우의 수 출력
        else cout << strCases[beLovedString] << '\n';
    }
}