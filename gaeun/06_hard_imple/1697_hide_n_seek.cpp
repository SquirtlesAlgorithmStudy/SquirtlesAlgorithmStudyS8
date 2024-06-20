// 각 시점에서 3가지: +1, -1, *2. 최단경로 -> BFS

#include <iostream>
#include <queue>
using namespace std;

int subin;
int sister;
int findTime[100001] = {0, };

void bfs(){
    queue<int> q;
    q.push(subin); // 시작 node 삽입

    while(!q.empty()){ // 더 이상 방문할 node가 없을 때까지 
        int currLoc = q.front();
        q.pop();

        // 동생 찾았으면 결과 출력
        if(currLoc == sister){
            cout << findTime[currLoc];
            break;
        }

        // 못찾았을 때, -1의 거리 이동
        if(currLoc-1 >= 0 && findTime[currLoc-1] == 0){
            findTime[currLoc - 1] = findTime[currLoc] + 1; // -1의 거리 이동에 findTime 1 증가 
            q.push(currLoc - 1);
        }

        // 못찾았을 때, +1의 거리 이동
        if(currLoc+1 <= 100000 && findTime[currLoc+1] == 0){
            findTime[currLoc + 1] = findTime[currLoc] + 1;
            q.push(currLoc + 1);
        }

        // 못찾았을 때, *2의 거리 이동
        if(currLoc*2 <= 100000 && findTime[currLoc*2] == 0){
            // 만약 currLoc = 0 이라면, continue 넣어주면ㄴ 좋겠지? 0에 아무리 곱해봐야 0인데..
            findTime[currLoc * 2] = findTime[currLoc] + 1;
            q.push(currLoc * 2);
        }
    }
}

int main(){

    cin >> subin >> sister;
    bfs();
}