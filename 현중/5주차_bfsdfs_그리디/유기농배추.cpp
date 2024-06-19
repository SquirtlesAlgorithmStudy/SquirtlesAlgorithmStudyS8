// 유기농 배추 dfs 
// 배추구역이 몇개? -> dfs : 이미 탐색한 구역의 배추인지 방문표시, 주변조사

#include<iostream>
#include<cstring>

using namespace std;

// 첫줄에는 테스트 케이스의 갯수 T가 주어짐

// 입력
int n; // 배추밭의 세로길이 1<n<50
int m; // 배추밭의 가로길이 1<m<50
int cabbage;

bool a[51][51]; // 배추가 심어진 위치를 저장
bool check[51][51];

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};


//3. 주변으로 이동
//4. 이동한 위치의 배추, 주변조사 (if 배추가 있다면 방문표시, dfs통해 주변 조사, 더 이상 배추가 없을 때 까지) 
bool dfs(int y, int x){
    if(check[y][x])    return false;
    
    check[y][x] = true;
    
    for(int i=0; i<4; i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];

        if(next_x >=0 && next_y >=0 && next_x < m && next_y <n && a[next_y][next_x]) // 인근에 배추 존재 -> 해당지역 방문처리
        dfs(next_y, next_x);  
    }
    return true;
}

// 배추 군집의 수를 계산
int main(void){
    int TC;
    scanf ("%d", &TC);
    for(int i =0; i< TC; i++){ //testcase loop 초기화
        scanf("%d %d %d", &m, &n, &cabbage);
        memset(a,0, sizeof(a)); // 배추가 심어진 위치를 저장하는 배열을 초기화
        memset(check,0,sizeof(check)); // check 배열을 초기화


        for (int j = 0; j < cabbage; j++)
        {
            int x=0, y=0;
            scanf("%d %d", &x, &y);
            a[y][x] = 1;
        }

        int bug_count =0; //배추의 군집수를 count


        //2. 전체 칸 조사 -> 배추가 있을 경우 조사하지 않은 구역이라면 dfs를 통해 주변에 다른 배추가 있는지 조사
        for(int j = 0; j<n; j++){
            for(int k = 0; k<m; k++ ){
                if (a[j][k] && !check[j][k]){
                    // 배추흰지렁이 마리수 : 방문하지 않은곳을 +1
                    // 이미 방문한 곳을 들러도 다시 방문하면 dfs에서 false 반환하여 애벌래수가 증가하지 않게
                    if(dfs(j,k)) //k : 배추가 심어져 있는 위치 갯수 1<k<2500
                    bug_count ++;
                }
            }
        }
        printf("%d\n", bug_count);
    }
} 


