// 연결된 구역 찾기: DFS로 해결 가능.

#include <iostream>
using namespace std;

int testCaseNum;
bool field[51][51] = {0,}; // use index 1~50
int fieldRow, fieldCol, cabageNum;
int cabageRow, cabageCol;

bool dfs(int row, int col){
    // 범위 벗어나는 경우 종료
    if (row <= -1 || row >= fieldRow || col <= -1 || col <= fieldCol) return false;

    // 배추가 있는 노드에 대해
    if (field[row][col] == ?){
        // 1. 방문 처리
        field[row][col] = ?;
        // 2. 해당 노드에 연결된 노드를 상하좌우 재귀로, 가장 깊은 노드까지 탐색
        dfs(row-1,col);
        dfs(row,col-1);
        dfs(row+1,col);
        dfs(row,col+1);
        return true;
    }
    // 배추가 없는 노드라면
    return false;
}

int main(){   
    
    // get input
    cin >> testCaseNum;
    cin >> fieldRow >> fieldCol >> cabageNum;
    for(int i=0; i<cabageNum; i++){
        cin >> cabageRow >> cabageCol;
        field[cabageRow][cabageCol] = 1;
    }

    // field debugging
    for(int i=0; i<fieldRow; i++){
        for(int j=0; j<fieldCol; j++){
            cout << field[i][j] << " ";
        }
        cout << endl;
    }


}