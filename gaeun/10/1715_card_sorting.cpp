// 최소 합 구하기
// 입력이 최대 10만개 -> 완탐은 안될듯. 

#include <iostream>
#include <queue> // to use priority_queue
#include <algorithm> 
using namespace std;

int cardNum;
priority_queue<int, vector<int>, greater<int>> pq; // ascending
int minSortingNum = 0;

int main(){
    cin >> cardNum;
    for(int i=0; i<cardNum; i++){
        int numInDummy;
        cin >> numInDummy;
        pq.push(numInDummy);
    }
    while (pq.size() > 1) {
        int card1 = pq.top();
        pq.pop();
        int card2 = pq.top();
        pq.pop();
        int nextCard = card1 + card2;
        pq.push(nextCard);
        minSortingNum+=nextCard;
    }
    cout << minSortingNum;

}