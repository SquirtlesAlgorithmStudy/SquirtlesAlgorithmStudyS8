// 연결된 구역 찾기: DFS로 해결 가능.

#include <iostream>
using namespace std;


bool field[51][51] = {0,};
int fieldRow, fieldCol;

bool dfs(int row, int col){
    // 범위 벗어나는 경우 종료
    if (row <= -1 || row >= fieldRow || col <= -1 || col >= fieldCol) return false;

    // 배추가 있는 노드에 대해
    if (field[row][col] == 1){
        // 1. 방문 처리
        field[row][col] = 0;
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
    int testCaseNum;
    int cabageNum, cabageRow, cabageCol;
    int wormNum = 0;
    
    // seperate input and output: DO NOT USE 'endl'
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    // with regard to several testCase,
    cin >> testCaseNum;
    for(int test=0; test<testCaseNum; test++){
        // get field input
        cin >> fieldRow >> fieldCol >> cabageNum;
        for(int i=0; i<cabageNum; i++){
            cin >> cabageRow >> cabageCol;
            field[cabageRow][cabageCol] = 1;
        }

        // field debugging
        /*
        for(int i=0; i<fieldRow; i++){
            for(int j=0; j<fieldCol; j++){
                cout << field[i][j] << " ";
            }
            cout << endl;
        }
        */

        // find the number of worm needed
        for(int i=0; i<fieldRow; i++){
            for(int j=0; j<fieldCol; j++){
                if(dfs(i,j)){
                    wormNum++;
                }
            }
        }

        // print result
        cout << wormNum << "\n";
        
        // init wormNum for another test case
        wormNum = 0; 
    }
}