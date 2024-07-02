// 최단 경로를 찾는 문제로 생각 가능. -> bfs

#include <iostream>
#include <queue>
#include <set>
#include <algorithm> // to use swap()
using namespace std;

string answer = "123456780";
string str;
queue<pair<string, int>> q;
set<string> isVisited;
int dr[4]={-1,1,0,0}; // 상하좌우
int dc[4]={0,0,-1,1}; // 상하좌우

int bfs(){
    q.push(make_pair(str, 0));
    isVisited.insert(str);

    while(!q.empty()){
        string currStr = q.front().first;
        int cnt = q.front().second;
        q.pop();

        // 정답과 일치 시
        if(currStr == answer) return cnt;

        // 정답과 일치 x
        // 1. 0 위치 찾아 2차원 좌표로 맵핑
        int idx0 = currStr.find('0');
        int r = idx0 / 3;
        int c = idx0 % 3;

        // 2. 상하좌우에 대해
        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr < 0 || nr > 2 || nc < 0 || nc > 2 ) continue;
            string nextStr = currStr;
            swap(nextStr[r*3+c], nextStr[nr*3+nc]);
            if(isVisited.find(nextStr) == isVisited.end()){
                isVisited.insert(nextStr);
                q.push(make_pair(nextStr, cnt++));
            }
        }

    }
    return -1;
}

int main(){
    for(int i=0; i<9; i++){
        char c;
        cin >> c;
        str += c;
    }
    cout << bfs();
}