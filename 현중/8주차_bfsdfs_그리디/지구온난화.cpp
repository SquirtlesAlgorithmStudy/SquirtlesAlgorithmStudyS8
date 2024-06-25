// 지구온난화

#include <iostream>
#include <vector>

using namespace std;


int R,C;

vector<string> grid, result;

// 인접한 바다의 갯수
int count_adjacent_sea(int r, int c){
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};
    int cnt = 0;

    
    for(int i=0; i<4; i++){
        int nr = r + dr[i];
        int nc = c + dc[i];

        if(nr <0 || nr >=R || nc <0 || nc >=C || grid[nr][nc] == '.'){
            cnt ++;
        }  
    }

    return cnt;
}

int main(){
    cin >>R>>C;
    grid.resize(R); // R개의 길이
    result.resize(R, string(C, '.')); // C인 문자열 초기화

    for(int i=0; i<R; i++){
        cin >> grid[i];
    }

    for(int r=0; r<R; r++){
        for(int c=0; c<C; c++){
            if(grid[r][c] == 'x'){
                if(count_adjacent_sea(r,c) >=3){
                    result[r][c] = '.';
                }
                else{
                    result[r][c] = 'x';
                }
            }
        }
    }
return 0;

}
    



