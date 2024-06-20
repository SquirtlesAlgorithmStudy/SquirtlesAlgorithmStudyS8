#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int A[50][50] = {0,};
bool isVisited[50][50] = {0,};
int N, L, R;
int drow[4] = {-1, 1, 0, 0}; // 상하좌우
int dcol[4] = {0, 0, -1, 1}; // 상하좌우
int countryNumInUnion = 0;
int populationSum = 0;
int newPopulation = 0;
int movementDays = 0;
vector<pair<int, int>> countryIdxInUnion;
bool isUnionFound = 1;

void clearIsVisited() {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            isVisited[r][c] = 0;
        }
    }
}

// dfs: union발견 시 union 내 국가 수, 총 인구 수, node idx 저장
void dfs(int row, int col) {  
    int nrow, ncol;  
    isVisited[row][col] = 1;
    countryNumInUnion++;
    populationSum += A[row][col];
    countryIdxInUnion.push_back({row, col});

    for (int i = 0; i < 4; i++) {
        nrow = row + drow[i];
        ncol = col + dcol[i];

        if (nrow < 0 || nrow >= N || ncol < 0 || ncol >= N) continue;

        if (abs(A[row][col] - A[nrow][ncol]) >= L && abs(A[row][col] - A[nrow][ncol]) <= R) {
            if (isVisited[nrow][ncol] == 0) {                
                dfs(nrow, ncol); 
            }
        }
    }
}

int main() {
    // get input
    cin >> N >> L >> R;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> A[r][c];
        }
    }

    while (isUnionFound) {
        // 한바퀴 다 돌면: isVisited, isUnionFound 초기화
        isUnionFound = 0;
        clearIsVisited();

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                // 방문하지 않았던 노드라면, do dfs
                if (!isVisited[r][c]) {
                    countryNumInUnion = 0;
                    populationSum = 0;
                    countryIdxInUnion.clear();
                    dfs(r, c);
                    // union 발견 시, 인구 이동
                    if (countryNumInUnion > 1) {
                        newPopulation = populationSum / countryNumInUnion;
                        for(int i=0; i<countryIdxInUnion.size(); i++){
                            int rMove = countryIdxInUnion[i].first;
                            int cMove = countryIdxInUnion[i].second;
                            A[rMove][cMove] = newPopulation;
                        }
                        // 한 번이라도 union이 있었다는 것을 flag
                        isUnionFound = 1;
                    }
                }            
            }
        }

        // 한 번이라도 union이 있었다면 days 증가
        if (isUnionFound) {
            movementDays++;
        }
    }

    cout << movementDays << endl;

    return 0;
}
