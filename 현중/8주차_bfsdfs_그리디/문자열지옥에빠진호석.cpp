// 20166번 문자열 지옥에 빠진 호석
// 경로의 특징을 저장해야 하기에 dfs사용

//재방문 허용
//방문한 곳의 문자열 만듦

#include <iostream>
#include <string>
#include <unordered_map> // (s 각 문자열이 생성된 빈도수)cnt를 저장하는데 사용 

using namespace std;

struct pos
{
    int r;
    int c;
};

//3<N, M<10 행렬판
int N;
int M;
int K; // 문자열 수

string board[10]; // 격자내용 (M<10이기 때문에)
unordered_map<string, int> cnt; // key, value를 저장하는 해시테이블 기반 컨테이너

//격자 내부에 있는지 확인
bool in_range(pos p)
{
    if (p.r <0 || p.r >=N || p.c <0 || p.c >=M)
        return false;
    else 
        return true;
}

// 새로운위치 << 현재위치 + 이동방향 
pos get_pos(pos currunt, int d)
{
    int dr[] = {-1, -1, -1, 1, 1, 1, 0, 0};
    int dc[] = {-1, 0, 1, -1, 0, 1, 1, -1};
    /*int dr[] = {-1,-1,-1,1,1,1,0,0};
    int dc[] = {-1,0,1,-1,0,1,1,-1};*/

    pos next; 
    next.r = currunt.r + dr[d];
    next.c = currunt.c + dr[d];

                                     //  3x3일때 범위 벗어나는경우
    if(next.r<0)       next.r = N-1; //  위로넘어감 0,1 -> 2,1  
    if(next.r>=N)      next.r = 0;   // 아래로넘어감 2,1 -> 0,1
    if(next.c<0)       next.c = M-1; // 왼쪽으로 넘어감 1,0 -> 1,2
    if(next.c>=M)      next.c = 0;   // 오른쪽으로 넘어감 1,2 -> 1,0

    return next;
}

//경로의 특징을 저장해야 하기에 dfs사용
//경로를 탐색 -> 문자열 생성 -> 빈도cnt
void dfs(pos curr, string s)
{
    int i; // 방향

    s += board[curr.r][curr.c]; // 현좌표의 문자를 문자열에 추가
    cnt[s]++;                   

    // 최대길이5만큼가면 return  (1<문자열길이<5)
    if(s.size() == 5) 
        return;

    // 모든방향으로 dfs
    for(i=0; i<8; i++) //8방향
        dfs(get_pos(curr, i), s);
}

int main()
{
    int i;
    string s;
    pos p;


    /*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/

    cin>>N>>M>>K; //K : 처리해야할 문자열수 1<k<1000개

    for(i = 0; i < N; i++)
    {
        cin >> board[i]; // 각행을 입력받아 board에 저장
    }

    // 모든 좌표에서 시작하여 만들수 있는 문자열 확인
    for(p.r=0; p.r<N; p.r++){
        for(p.c=0; p.c<M; p.c++){
            dfs(p, "");
        }
    }

    //입력받은 문자열을 만들 수 있는 경우의 수
    for(i=0; i<K; i++){
        cin >> s;
        cout << cnt[s] << "\n";
    }

    return 0;
}
    





