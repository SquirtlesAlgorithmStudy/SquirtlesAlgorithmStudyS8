// 인구이동 bfs : 너비우선
// 개어렵네 야발 10번 풀면 익숙해질듯

#include<iostream>
#include<queue>
#include<vector>
#include<cmath> //절대값 계산하기 위해

using namespace std;
#define MAX 51

// 땅의크기 : N*N
// 국경선 open : 1< L< 인구차이 <R <100
// 행 : r , 열 : c , 명 A[r][c]
int N,L,R, arr[MAX][MAX]; // 인구수 A[r][c]
bool visited[MAX][MAX];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

queue<pair<int,int>> q;  // bfs 탐색을 위한 queue
vector<pair<int,int>> v; // 연합된 국가들의 좌표들을 저장할 벡터 / v size(1) = 국경선 열리는 곳 x

bool flag = true; // 연합여부
int sum =0;        // 평균을 구하기 위해


// Queue를 사용하여 인접한 좌표를 탐색, 조건에 맞으면 연합에 추가 및 재분배
void bfs(pair<int,int> start){ // bfs를 시작할 좌표를 queue에 추가
    q.push(start); 
    visited[start.first][start.second] = true; // 시작할 좌표를 방문처리

    while(!q.empty()){ // queue가 빌때까지 반복
        pair<int, int> temp = q.front(); // queue의 맨 앞 좌표 가져오기 
        q.pop(); // queue의 맨 앞 좌표 제거

        for(int i =0; i <4; i++){ // 동서남북 탐색
            int new_x = temp.first + dx[i];
            int new_y = temp.second + dy[i];

        // 1. 범위 안에 있고 2. 방문하지 않으며 3. 인구차이가 조건에 맞음
        if(new_x>=0 && new_y>=0 && new_x < N && new_y < N && !visited[new_x][new_y]){
            if( abs(arr[new_x][new_y] - arr[temp.first][temp.second]) >=L && abs(arr[new_x][new_y] - arr[temp.first][temp.second]) <=R ){
                q.push({new_x, new_y}); //1. queue에 새로운 좌표를 추가하여 다음 탐색 노드 설정
                visited[new_x][new_y] = true; //2. 방문처리
                v.push_back({new_x,new_y}); //3. 연합된 국가벡터에 새로운 좌표 추가하여 연합에 포함된 국가 목록 추가
                sum += arr[new_x][new_y]; // 4. 연합된 인구 합계에 새로운 좌표의 인구수를 추가하여 연합된 인구수 계산

            }
        }

        }
    }

}


void clear(){ // visited 배열을 초기화 -> 왜해줘야해?????????????
    for(int i =0; i<N; i++)
        for(int j =0; j<N; j++)
            visited[i][j] = false;
}

int main(){ // 인구이동 전체 일 수 계산
    int days = 0;
    cin >> N >> L >> R; // 입력값 받기
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin >> arr[i][j]; // 각 위치의 인구 수 입력받기
        }
    }


    while(flag){ // 연합이 일어나는 한 계속 반봅
        flag = false; // 연합 초기화
        for(int i=0; i < N; i++){
            for(int j=0; j < N; j++){
                if(!visited[i][j]){
                    v.clear();
                    v.push_back({i,j});
                    sum = arr[i][j];
                    bfs({i,j});
                }

                if(v.size()>=2){
                    flag = true;
                    for(int i=0; i<v.size(); i++){
                        arr[v[i].first][v[i].second] = sum / v.size();
                    }

                }
            }
        }

        if(flag) days++;

        clear();

    }

    cout <<days;

}

