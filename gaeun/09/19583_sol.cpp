#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

string S,E,Q;
set<string> startMem;   // 중복 배제를 위한 set 사용. find는 O(log(n))
map<string, int> member;
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
            member.insert({memberName,0});
        }
        // 시작할 때 있었고, 끝까지 참여한 멤버라면 출석 인원 증가
        if(time >= E && time <= Q){
            if((member.find(memberName) != member.end()) && member[memberName] == 0){
                attendanceCnt++;
                member[memberName]++; // to 중복방지
            }
        }
    }
    cout << attendanceCnt;

}