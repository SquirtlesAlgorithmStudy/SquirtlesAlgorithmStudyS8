// Q. 시간 초과가 발생하는 이유는? 

#include <iostream>
#include <unordered_set>
#include <algorithm>
using namespace std;

string S,E,Q;
unordered_set<string> startMem;   // 중복 배제를 위한 set 사용. find는 O(log(n))
unordered_set<string> endMem;
int attendanceCnt = 0;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S >> E >> Q;

    string time;
    string memberName;

    // 입력 최대 10만개
    while(cin >> time >> memberName){   // EOF(ctrl+z같은) 받으면 종료
        // 시작 또는 시작한 시간에 참가했던 멤버 기록
        if(time <= S){
            startMem.insert(memberName); // log(n)
        }
        // 끝날때까지 있던 멤버 기록
        if(time >= E && time <= Q){
            endMem.insert(memberName);
        }
    }

    // 10만개*(20(string 최대 길이) * log(100,000) = 16.6) = 166만
    for(auto name : startMem){
        // 두 조건 모두 만족하면 출석한 인원으로 카운트.
        if(find(endMem.begin(), endMem.end(), name) != endMem.end()){
            attendanceCnt++;
        }
    }
    cout << attendanceCnt;

}