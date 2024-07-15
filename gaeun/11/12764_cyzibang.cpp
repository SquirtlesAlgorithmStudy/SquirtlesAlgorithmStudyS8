#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// pair의 first 기준 min heap(작을수록 top에)
struct ascendingFirst{
    bool operator()(const pair<int,int>& a, const pair<int,int>& b){
        return a.first > b.first;
    }
};

// pair의 second 기준 min heap(작을수록 top에)
struct ascendingSecond{
    bool operator()(const pair<int,int>& a, const pair<int,int>& b){
        return a.second > b.second;
    }
};

int N;
priority_queue<pair<int, int>, vector<pair<int, int>>, ascendingFirst> startPQ;
priority_queue<pair<int, int>, vector<pair<int, int>>, ascendingSecond> endPQ;
vector<int> seat;
int maxIdx = 0;
map<pair<int, int>, int> seatMap;
vector<bool> seatStatus(100000, true);
int emptySeatIdx;

void findEmptySeat(){
    // get the smallest number of empty seat
    for(int i=0; i<100000; i++){
        if(seatStatus[i] == true){
            emptySeatIdx = i;
            break;
        }
    }

    // update the max num of seat
    if(emptySeatIdx > maxIdx) maxIdx = emptySeatIdx;
}

int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        int P, Q;
        cin >> P >> Q;
        startPQ.push({P,Q});
        endPQ.push({P,Q});
    }

    while(!startPQ.empty()){
        if(startPQ.top().first < endPQ.top().second){
            // 1. '<20,50>, 0'과 같이 특정시간 이용자가 앉는 자리 저장
            findEmptySeat();
            seatMap[startPQ.top()] = emptySeatIdx; // map 요소 추가: 1. insert(), 2. [] 연산자

            // 2. 해당 자리에 앉았던 사람 명 수 기억, 해당 자리 occupied 처리
            seat.push_back(1);
            seatStatus[emptySeatIdx] = false;

            // 3. 변수 업데이트
            startPQ.pop();
        }
        else{
            // 1. 사용기간 끝난 자리 release
            while(startPQ.top().first > endPQ.top().second){
                seatStatus[seatMap[endPQ.top()]] = true;
                endPQ.pop();
            }

            // 2. 최소 번호의 자리에 앉히기, 인원 증가, occupied 처리
            findEmptySeat();
            seat[emptySeatIdx]++;
            seatStatus[emptySeatIdx] = false;

            // 4. 앉을 자리 저장
            seatMap[startPQ.top()] = emptySeatIdx;

            // 5. 변수 update
            startPQ.pop();
        }
    }

    cout << maxIdx + 1 << endl;
    for(int i=0; i<maxIdx + 1; i++){
        cout << seat[i] << " ";
    }
    
}