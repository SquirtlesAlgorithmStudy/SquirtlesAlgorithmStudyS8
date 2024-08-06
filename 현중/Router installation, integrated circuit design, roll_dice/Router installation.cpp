// Router_installation_integrated_circuit_design_roll_dice

// N개의 집이 수직선 (2 < N < 200,000) (0 < x < 1,000,000,000)
// C개의 공유기 설치 (2 < C  < N)
// 가장 인접한 두 공유기C 사이거리를 최대!!


// 핵심
// 1. 
// 2. 인접한 공유기들의 간격이 최대가 된게 설치되기를 원함
// 3. 따라서 집의 위치보다는 집 사이 거리가 중요
// 4. 최대 거리의 mid_dist를 구하여 이분탐색하자

// 풀이
// 1. 집 위치 좌표를 오름차순으로 정렬
// 2. 최대간격을 구한 후, mid_dist를 기준으로 시작
// 3. mid_dist를 기준으로 탐색을 한 후 공유기 갯수대로 설치를 못하면 F를 때리고, 그 이상은 다 F 
// 4. T가 나온다면 또 반복하여 T가 나오는 가장 큰 dist를 구하자



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int n,c; // n : 집의 갯수, c : 공유기 갯수
    cin >> n >> c;
    vector<int> houses(n); // [1,2,4,8,9]

    // 집 좌표를 입력으로 받아서
    for(int i =0; i < n; i++){
        cin >> houses[i];
    }

    // 오름차순으로 정리하고
    sort(houses.begin(), houses.end());

    // 최대거리 구해
    int min_dist = 1;                       // 최소거리
    int max_dist = houses[n-1] - houses[0]; // 최대거리
    int ans = 0;

    // 이분탐색
    while (min_dist <= max_dist){
        int mid_dist = (min_dist + max_dist) /2; // mid_dist = 4
        int cnt = 1; // 첫번째 집은 설치했다 가정 후, 설치 cnt
        int install = houses[0]; // 설치 후 기준!

        // 첫번째 집은 이미 설치했다하고 두번째 집부터 mid_dist 이상인지 탐색
        for(int i =1; i <n; i++){
            if((houses[i] - install) >= mid_dist){ // 집 - 설치 >= mid_dist
                cnt++;
                install = houses[i]; // 공유기가 설치된 집의 위치를 저장 후 현재집은 기준으로 다시 거리 측정
            }
        }

        // 설치한 공유기 갯수가 c 이상이면 mid_dist 간격은 True, c 미만이면 False
        if (cnt < c){
            max_dist = mid_dist -1; // mid_dist가 너무 커서 c갯수 만큼 설치 못할 경우 mid_dist를 내리기 ex) 4-> 2
        }
        else {
            ans = mid_dist;
            min_dist = mid_dist +1; // mid_dist가 작아 c갯수 이상일 때, mid_dist를 늘려서 해보기 ex) 2->3
        }
    }


    cout << ans << '\n';
    return 0;
}
