// 불_5427

// 불이 퍼지기 전에 건물에서 탈출하여 최단경로를 탐색해야 하기에 bfs사용

// 불은 동서남북 인접합 방향으로 퍼짐
// 인접한 곳으로 옮겨가는데 1초가 걸림
// 불과 불이 붙으려는 곳으로는 이동 x -> 불이 먼저 이동하고 상근이가 이동해야 됌

#include<iostream>
#include<queue> // FIFO구조

#define MAX 1000 +1 // 지도 너비w 높이h 최대 크기
#define X second
#define Y first 

using namespace std;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

char map[MAX][MAX];
int w,h;

queue <pair<int,int>> sq; // 상근이 위치
queue <pair<int,int>> fq; // 불의 위치


// 불이 퍼져나가는 것을 구현하는 함수
void MoveFire(){
    int cnt = fq.size(); // 현재 불의 위치 갯수를 고정
    for(int i=0; i<cnt; i++){
        pair<int, int> cur = fq.front(); // (queue의 맨 앞에 있는) 현재위치 불의 위치를 가져와
        fq.pop(); // 처리한 불의 위치 제거

        for(int dir = 0; dir <4; dir++){ // 불이 상하좌우로 퍼짐
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];

            if(ny<0 || nx<0 || nx >= h || ny>=w) // 경계밖이면
                continue; // 다음 방향으로 이동
            if(map[ny][nx] !='.') // 빈공간이 아닌 경우
                continue;

            map[ny][nx] = '*'; //불을 퍼뜨리고
            fq.push({ny,nx});  // 해당위치를 큐에 추가
        }
    }

}


// 상근이가 이동하는 함수 
int MoveS(){
    int time =0; // 탈출시간 초기화
    while(!sq.empty()){
        time++;  //1. 시간 +1하면
        MoveFire(); // 2. 불이 먼저 이동 (탐색전 MoveFire를 호출하여 불이 먼저 움직인 다음 상근이가 움직이게)

        int cnt = sq.size(); // 3. 현재 상근이 위치 수를 고정하고 
        for (int i=0; i< cnt; i++){
            pair<int,int> cur = sq.front(); // 앞에 있는 상근이의 위치를 가져와서 
            sq.pop();                       // 처리한 상근이의 위치를 queue에서 제거
            for(int dir=0; dir<4; dir++){ // 상근이의 현재 위치 상하좌우 이동
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];

            if(ny<0 || nx<0 || nx >= h || ny>=w) // 경계조건을 
                return time;                     // 벗어나면 탈출에 성공한 것으로 현재 시간을 반환
            if(map[ny][nx] !='.')                // 빈공간이 아니면 다음 방향 시도
                continue;

            map[ny][nx] = '@';                   // 새로운 위치에 상근이 추가
            sq.push({ny,nx});                    // 새로운 위치를 queue에 추가


            }
        }
    }

    return -1; //queue가 비어있을대가지 탈출하지 못한 경우 탈출 불가
}


// testcase별 지도 초기화
void Reset(int w, int h){
    for(int y=0; y<h; y++){
        for(int x=0; x<w; x++){
            map[y][x] = '.';
        }
    }

    while(!sq.empty())
        sq.pop();
    while(!fq.empty())
        fq.pop();
}


int main(){
    int t; 
    cin >> t; // 입력1 testcase 갯수

    for(int i=0; i<t; i++){ 
        cin >> w>> h; // 입력2 너비, 높이
        for(int y=0; y<h; y++){     
            for(int x=0; x<w; x++){
                cin >> map[y][x];   // 입력3 격자의 각 위치의 내용 입력
 
                if(map[y][x] == '@')// 상근이 초기 위치 queue에 저장
                    sq.push({y,x});
                else if(map[y][x] == '*') // 불 초기 위치 queue에 저장
                    fq.push({y,x});
            }
        }

    int time = MoveS(); // 상근 탈출 시간 계산

    if (time == -1)
        cout << "IMPOSSIBLE" << endl;   // 탈출x
    else 
        cout<< time << endl;            // 출력 탈출
    
    Reset(w,h);                         // 각 testcase마다 상태 초기화
    }

    return 0;

}






