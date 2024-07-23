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
priority_queue<int, vector<int>, greater<int>> emptySeatPQ; // min-heap
vector<int> seat(100000, 0);
int maxIdx = 1;
map<pair<int, int>, int> seatMap;
int emptySeatIdx;

void findEmptySeat(){
    if(emptySeatPQ.empty()){
        emptySeatPQ.push(maxIdx);
        maxIdx++;
    } 
    // get the smallest number of empty seat
    emptySeatIdx = emptySeatPQ.top();
    emptySeatPQ.pop();
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

            // 2. 해당 자리에 앉았던 사람 명 수 기억
            seat[emptySeatIdx]++;

            // 3. 변수 업데이트
            startPQ.pop();
        }
        else{
            // 1. 사용기간 끝난 자리 release
            while(startPQ.top().first > endPQ.top().second){
                emptySeatPQ.push(seatMap[endPQ.top()]);
                endPQ.pop();
            }

            // 2. 최소 번호의 자리에 앉히기, 인원 증가, occupied 처리
            findEmptySeat();
            seat[emptySeatIdx]++;

            // 4. 앉을 자리 저장
            seatMap[startPQ.top()] = emptySeatIdx;

            // 5. 변수 update
            startPQ.pop();
        }
    }

    cout << maxIdx-1 << endl;
    for(int i=1; i<maxIdx; i++){
        cout << seat[i] << " ";
    }
    
}