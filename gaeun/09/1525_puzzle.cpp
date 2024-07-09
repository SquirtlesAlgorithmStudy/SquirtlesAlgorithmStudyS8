// cnt 1번 증가에 최대 (9+9)*9*4*(9+9) -> cnt가 8000 이상이 되면 time over
// Q. 시간복잡도 이렇게 계산하는 것 맞나?
// bfs는 one of 완탐, bfs도 시간초과 안되는데 greedy로 시간초과? -> 무한 loop 걸린겨

#include <iostream>
using namespace std;

int sorted[3][3] = {{1,2,3},{4,5,6},{7,8,0}};
int puzzle[3][3];
int dr[4]={-1,1,0,0}; // 상하좌우
int dc[4]={0,0,-1,1}; // 상하좌우
int cnt = 0;

bool checkSolved(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(puzzle[i][j] != sorted[i][j]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    // get input
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cin >> puzzle[i][j];
        }
    }

    while(!checkSolved()){
        // check if it's sorted
        if(checkSolved()){
            cout << cnt;
            return 0;
        }

        // 정렬되지 않은 채 0이 마지막 위치에 도달했다면 -1 출력.
        if(!checkSolved() && puzzle[2][2] == 0){
            cout << -1;
            return 0;
        }

        // 정렬
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){                    
                if(puzzle[i][j] == 0){
                    int minDiff = 10;
                    int swapRow;
                    int swapCol;

                    // 1.search: 현재 0 위치에 와야하는 값과 차가 가장 작은 상하좌우 원소 찾기
                    for(int d=0; d<4; d++){
                        int nr = i+dr[d];
                        int nc = j+dc[d];
                        // 범위 넘어가면 제외
                        if(nr < 0 || nr > 2 || nc < 0 || nc > 2 ) continue;
                        if(abs(sorted[i][j] - puzzle[nr][nc]) < minDiff){
                            minDiff = abs(sorted[i][j] - puzzle[nr][nc]);
                            swapRow = nr;
                            swapCol = nc;
                        }
                    }

                    // 2.swap
                    cnt++;
                    puzzle[i][j] = puzzle[swapRow][swapCol];
                    puzzle[swapRow][swapCol] = 0;

                    // 3. check if it's sorted
                    if(checkSolved()){
                        cout << cnt;
                        return 0;
                    }

                    // 4. 정렬되지 않은 채 0이 마지막 위치에 도달했다면 -1 출력.
                    if(!checkSolved() && puzzle[2][2] == 0){
                        cout << -1;
                        return 0;
                    }
                }
            }
        } 
    }   
}

// #include <iostream>
// using namespace std;

// int sorted[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
// int puzzle[3][3];
// int dr[4] = {-1, 1, 0, 0}; // 상하좌우
// int dc[4] = {0, 0, -1, 1}; // 상하좌우
// int cnt = 0;

// bool checkSolved() {
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//             if (puzzle[i][j] != sorted[i][j]) {
//                 return false;
//             }
//         }
//     }
//     return true;
// }

// int main() {
//     // get input
//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//             cin >> puzzle[i][j];
//         }
//     }

//     while (!checkSolved()) {

//         // the last element became 0 w/o sorted
//         if (puzzle[2][2] == 0 && !checkSolved()) {
//             cout << -1;
//             return 0;
//         }       

//         // 0의 위치 찾기
//         int zeroRow, zeroCol;
//         for (int i = 0; i < 3; i++) {
//             for (int j = 0; j < 3; j++) {
//                 if (puzzle[i][j] == 0) {
//                     zeroRow = i;
//                     zeroCol = j;
//                     break;
//                 }
//             }
//         }

//         // 0의 새로운 위치 업데이트 및 swap
//         int minDiff = 10;
//         int swapRow = zeroRow;
//         int swapCol = zeroCol;

//         // 1. search: 현재 0 위치에 와야하는 값과 차가 가장 작은 상하좌우 원소 찾기
//         for (int d = 0; d < 4; d++) {
//             int nr = zeroRow + dr[d];
//             int nc = zeroCol + dc[d];
//             // 범위 넘어가면 제외
//             if (nr < 0 || nr > 2 || nc < 0 || nc > 2) continue;
//             // swap 대상 찾기
//             if (abs(sorted[zeroRow][zeroCol] - puzzle[nr][nc]) < minDiff) {
//                 minDiff = abs(sorted[zeroRow][zeroCol] - puzzle[nr][nc]);
//                 swapRow = nr;
//                 swapCol = nc;
//             }
//         }

//         // 2. swap
//         cnt++;
//         puzzle[zeroRow][zeroCol] = puzzle[swapRow][swapCol];
//         puzzle[swapRow][swapCol] = 0;

//         // 3. check if it's sorted
//         if (checkSolved()) {
//             cout << cnt;
//             return 0;
//         }
//     }

//     cout << cnt;
// }
