// O(N^2)이면 TLE..
// 질문) 이분탐색으로 LIS를 구하면, 길이는 맞으나 그 안에 담겨있는 원소가 다를 수 있다.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int portNum;
vector<int> connection;
vector<int> findSeq;

int main(){
    // get the number of port
    cin >> portNum;

    // get the connections
    for(int i=0; i<portNum; i++){
        int num;
        cin >> num;
        connection.push_back(num);
    }

    // 이분탐색을 활용한 최장 증가 수열 길이 찾기
    for(int i=0; i<portNum; i++){
        // 수열이 비어있거나, 수열 내 모든 원소보다 큰 값을 찾았다면 findSeq에 삽입.
        if(findSeq.size()==0 || findSeq.back() < connection[i]){
            findSeq.push_back(connection[i]);
        }
        else{
            // 수열 내 원소 사이에 오름차순이 되도록 끼워넣기
            int idx = lower_bound(findSeq.begin(), findSeq.end(), connection[i]) - findSeq.begin();
            findSeq[idx] = connection[i];
        }
    }
    
    // the length of findSeq becomes the answer, but the element could be different
    cout << findSeq.size() << endl;

}