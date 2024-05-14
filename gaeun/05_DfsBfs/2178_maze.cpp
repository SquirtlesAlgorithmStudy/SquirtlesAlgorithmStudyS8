#include <iostream>
#include <queue>
using namespace std;

int maze[101][101] = {0,};
int mazeRow, mazeCol;

// 상,하,좌,우 이동 방향
int dRow[] = {-1,1,0,0};
int dCol[] = {0,0,-1,1};

int bfs(int r, int c){
    queue<pair<int,int>> q;
    // 시작 node 삽입, 방문처리는 'maze[nRow][nCol] = maze[row][col] + 1' 로직으로
    q.push({r,c});
    while(!q.empty()){ // 더 이상 방문할 node가 없을 때까지 
        int row = q.front().first;
        int col = q.front().second;
        q.pop(); // 시작 node 꺼내고,
        /*
            방문하지 않은 인접 노드들 중 다음 조건을 만족시키는 노드만 큐에 삽입
            1. maze 범위 벗어나지 않을 것
            2. 갈 수 있는 길이며 첫 방문(1)일 것
        */ 
        // 상하좌우
        for(int i=0; i<4; i++){
            int nRow = row + dRow[i];
            int nCol = col + dCol[i];

            // maze 범위 확인
            if(nRow <= -1 || nRow >= mazeRow || nCol <= -1 || nCol >= mazeCol) continue;

            // 갈 수 있는 길이고, 첫 방문이라면(1) 이전 노드 경로 길이에 +1, 큐에 삽입
            if(maze[nRow][nCol] == 1){
                maze[nRow][nCol] = maze[row][col] + 1; 
                q.push({nRow,nCol});                
            }           
        }      
        // just for debugging
        for(int i=0; i<mazeRow; i++){
                for(int j=0; j<mazeCol; j++){
                   cout << maze[i][j] << " ";
                }
                cout << endl;
            }
        cout << "current q size: " << q.size() << endl;
        cout << "q.front: " << row << ", " << col << endl; 
    }
    // 마지막 maze node에 저장된 경로 길이 값 return
    return maze[mazeRow-1][mazeCol-1];  
}

int main(){
    // get maze input
    cin >> mazeRow >> mazeCol;
    for(int row=0; row<mazeRow; row++){
        for(int col=0; col<mazeCol; col++){
            scanf("%1d", &maze[row][col]);
        }
    }

    /* maze debugging
    for(int i=0; i<mazeRow; i++){
        for(int j=0; j<mazeCol; j++){
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }*/    

    // print the result
    cout << bfs(0,0) << '\n';
}

