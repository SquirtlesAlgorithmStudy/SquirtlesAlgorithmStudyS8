#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

string S,E,Q;
set<string> startMem;
set<string> endMem;
int attendanceCnt = 0;


int rmColonNtoInt(string str){
    str.erase(remove(str.begin(), str.end(), ':'), str.end());
    // remove(): 삭제되어야 할 원소들의 위치에 유지될 원소들의 값을 덮어 씌움 -> 뒷쪽에 쓸데없는 데이터가 남음
    // erase() 함께 사용: remove() 사용 이후 발생하는 필요없는 중복 데이터 삭제 가능.
    return stoi(str);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> S >> E >> Q;
    int s,e,q;
    s = rmColonNtoInt(S);
    e = rmColonNtoInt(E);
    q = rmColonNtoInt(Q);

    string time;
    string memberName;
    while(cin >> time >> memberName){
        int recordedTime = rmColonNtoInt(time);
        // 시작 또는 시작한 시간에 참가했던 멤버라면, 
        if(recordedTime <= s){
            startMem.insert(memberName);
        }
        if(recordedTime >= e && recordedTime <= q){
            endMem.insert(memberName);
        }
    }

    for(auto name : startMem){
        // 두 이름이 startMem, endMem에 모두 존재하면, 
        if(find(endMem.begin(), endMem.end(), name) != endMem.end()){
            attendanceCnt++;
        }
    }
    cout << attendanceCnt;

}