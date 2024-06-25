#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R;
int C;
char** MAP; // Q. 동적할당 필요한 것 아닌가?
int dr[4] = {-1, 1, 0, 0}; // in the order of 상하좌우
int dc[4] = {0, 0, -1, 1}; // in the order of 상하좌우
vector<pair<int, int>> disappearIdx; 
vector<pair<int, int>> landIdx;

int main(){
    // get R and C
    cin >> R >> C;

    // dynamic allocation for 2D array
    MAP = new char*[R];
    for(int i=0; i<R; i++){
        MAP[i] = new char[10];
    }

    // get the map
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin >> MAP[i][j];
        }
    }

    // find the lands will be disappeared
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(MAP[i][j] == 'X'){ // 전체 MAP 순회하다가 땅 발견 시
                int cnt = 0;
                for(int k=0; k<4; k++){
                    if(i+dr[k]<0 || i+dr[k]>=R || j+dc[k]<0 || j+dc[k]>=C){ // 범위 초과는 바다로 간주
                        cnt++;
                        continue;
                    }
                    if(MAP[i+dr[k]][j+dc[k]] == '.'){ // 상하좌우에 대해 바다가 3면 이상인지 확인
                        cnt++;
                    }
                }
                if(cnt < 3){ // 3면 미만의 살아남을 땅이라면,
                    landIdx.push_back(make_pair(i,j)); // 해당 땅의 idx를 pair로 저장
                }
                else{ // 사라질 땅 idx 저장
                    disappearIdx.push_back(make_pair(i,j));
                }
            }
        }
    }

    // 사라질 땅을 바다로 교체
    for(auto x:disappearIdx){
        MAP[x.first][x.second] = '.';
    }

    // find the smallest and the largest row index
    sort(landIdx.begin(), landIdx.end(), [](pair<int, int> r1, pair<int, int> r2){
        return r1.first < r2.first;
    });
    int smallestRow = landIdx[0].first;
    int largestRow = landIdx[landIdx.size()-1].first;
    
    // find the smallest and the largest column index
    sort(landIdx.begin(), landIdx.end(), [](pair<int, int> r1, pair<int, int> r2){
        return r1.second < r2.second;
    });
    int smallestCol = landIdx[0].second;
    int largestCol = landIdx[landIdx.size()-1].second;

    // print the new map
    for(int i=smallestRow; i<=largestRow; i++){
        for(int j=smallestCol; j<=largestCol; j++){
            cout << MAP[i][j];
        }
        cout << endl;
    }
}