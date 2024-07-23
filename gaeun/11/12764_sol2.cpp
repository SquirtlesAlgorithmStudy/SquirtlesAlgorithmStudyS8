#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> userVec;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> seatAllocPQ;
priority_queue<int, vector<int>, greater<int>> emptySeatPQ; // min-heap
vector<int> seat(100000, 0);
int maxIdx=0;

int main(){
    // get input
    cin >> N;
    int P, Q;
    for(int i=0; i<N; i++){
        cin >> P >> Q;
        userVec.push_back({P,Q});
    }

    // 시작시간 기준 오름차순 정렬
    sort(userVec.begin(), userVec.end());

    for(int i=0; i<userVec.size(); i++){
        while(!seatAllocPQ.empty()){
            // 새로운 사용자의 시작 시각보다 기존 사용자의 종료 시각이 빠를 때
            if(userVec[i].first > seatAllocPQ.top().first){
                emptySeatPQ.push(seatAllocPQ.top().second);
                seatAllocPQ.pop();
            }
            else break;
        }
        
        // 새로운 자리 할당
        if(emptySeatPQ.empty()){
            seatAllocPQ.push({userVec[i].second, maxIdx});
            seat[maxIdx]++;
            maxIdx++;
        }

        // 빈자리가 났다면, 그 중 가장 작은 번호의 자리 할당
        else{
            int seatIdx = emptySeatPQ.top();
            seatAllocPQ.push({userVec[i].second, seatIdx});
            seat[seatIdx]++;
            emptySeatPQ.pop();
        }
    }

    cout << maxIdx << endl;
    for(int i=0; i<maxIdx; i++){
        cout << seat[i] << " ";
    }
}