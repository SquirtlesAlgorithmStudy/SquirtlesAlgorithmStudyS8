// 백준_8980_택배

// 정보
// 마을수, 트럭용량
// 배송정보 수

// 접근법
// 받는 마을을 기준으로 오름차순 정리(가까운 마을, 박스수가 작은거 부터)
// 각 구간별로 트럭에 실을 수 있는 최대 박스수 계산

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C, V; // City, Volume
int B;    // Box

// <<보내는 마을번호, 받는 마을번호>, 박스갯수>
vector <pair<pair<int, int>, int>> list;

int truck[2001]; // City별 truck에 싣고있는 택배수 저장
int answer;      // 최대 박스 수

bool compare(pair< pair<int,int>,int >a, pair< pair<int,int>,int >b){
    if(a.first.second == b.first.second)
        return a.first.first < b.first.first;
    else
        return a.first.second < b.first.second;
}

int main(){

    cin >> C >> V;
    cin >> B;

    // 배송정보를 받아 저장하고, 배송정보를 저장
    for(int i=0; i<B; i++){
        int send, receive, box;
        cin >> send >> receive >> box;

        list.push_back({ {send, receive}, box }); // push_back(Vector의 마지막에 새로운 2차원배열을 추가하기 위해 임시 객체를 하나 만들어서 거기에 값을 복사 후, Vector에 삽입하는 과정)
    }
    sort(list.begin(), list.end(), compare); // 오름차순

    // 배송정보 처리, 싣을 수 있는 최대 박스수 계산, 트럭 상태변수에 저장
    for(int i=0; i<list.size(); i++){
        int from = list[i].first.first;  // 출발
        int to   = list[i].first.second; // 도착
        int 
    }
}







