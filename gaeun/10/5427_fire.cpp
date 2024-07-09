#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int testCaseNum;
int w,h;
char buildingMap[1000][1000];
queue<pair<int,int>> sangeun;
queue<pair<int,int>> fire;
int dr[4] = {-1, 1, 0, 0}; // 상하좌우
int dc[4] = {0, 0, -1, 1}; // 상하좌우

void fireSpreading(){
    // 현재 모든 불 위치에 대해
    int fireQsize = fire.size();
    for(int fireIdx=0; fireIdx < fireQsize; fireIdx++){
        pair<int, int> currFire = fire.front();
        int r = currFire.first;
        int c = currFire.second;
        fire.pop();

        // spreading
        for(int i=0; i<4; i++){
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= h || nr < 0 || nc >= w || nc < 0) continue;
            if(buildingMap[nr][nc] != '.') continue;

            buildingMap[nr][nc] = '*';
            fire.push(make_pair(nr,nc));
        }
    }
}

int moveSangeun(){
    int escapeTime = 0;

    // 상근이의 위치를 담은 queue가 비지 않았다면, 
    while(!sangeun.empty()){
        // 1. 탈출 시간 증가
        escapeTime++;

        // 2. 불 번지게 만든 후
        fireSpreading();

        // 3. 상근이의 위치 탐색
        int sangeunQsize = sangeun.size();
        for(int sangeunIdx = 0; sangeunIdx < sangeunQsize; sangeunIdx++){
            pair<int, int> currSangeun = sangeun.front();
            int r = currSangeun.first;
            int c = currSangeun.second;
            sangeun.pop();

            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];

                // 범위를 벗어나면 탈출한 것
                if(nr >= h || nr < 0 || nc >= w || nc < 0) return escapeTime; // escape
                // '#'벽이나, '*'불로는 움직일 수 없음
                if(buildingMap[nr][nc] != '.') continue;

                buildingMap[nr][nc] = '@';
                sangeun.push({nr,nc});
            }
        }
    }

    // 더 이상 '.'이 존재하지 않으면 sanguen queue는 빌 것이고, 이는 탈출하지 못함을 의미. 
    return -1;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> testCaseNum;
    for(int i=0; i<testCaseNum; i++){
        // get a building map
        cin >> w >> h;
        for(int r=0; r<h; r++){
            for(int c=0; c<w; c++){
                cin >> buildingMap[r][c];

                // track the location of sangeun
                if(buildingMap[r][c] == '@'){
                    sangeun.push(make_pair(r,c));
                }
                // track the location of fire
                if(buildingMap[r][c] == '*'){
                    fire.push(make_pair(r,c));
                }
            }
        }

        // get the result
        int escapeTime = moveSangeun();

        // print the result
        if(escapeTime != -1) cout << escapeTime << '\n';
        else cout << "IMPOSSIBLE" << '\n';

        // reset
        while (!sangeun.empty()) sangeun.pop();
        while (!fire.empty()) fire.pop();
    }    
}