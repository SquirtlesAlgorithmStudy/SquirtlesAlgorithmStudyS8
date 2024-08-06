#include <iostream>
#include <vector>   
#include <algorithm> // sort()
using namespace std;

int C,N;
vector<int> X;

int findMinDist();

int main(){
    // get the number of house and router
    cin >> N >> C;

    // get each coordinate of routers
    for(int i=0; i<N; i++){
        int coordinate;
        cin >> coordinate;
        X.push_back(coordinate);
    }    

    // sort in ascending order
    sort(X.begin(), X.end());

    // find the minimum distance between routers
    cout << findMinDist();
}

int findMinDist(){
    // goal: find maximum gap satisfies the given conditions
    int gap = 0;
    int start = 1; // smallest possible gap
    int end = X.back() - X.front(); // biggest possible gap

    // binary search의 조건을 만족시키는 동안, 
    while(start <= end){
        // 첫번째 공유기에는 무조건 설치
        int installedhouse = X[0];
        int cnt = 1;

        // 왼쪽부터 순차적으로 설치, 특정 거리보다 큰 gap을 가져야 설치. 이 때, '특정 거리'는 bianry search를 활용하고자 mid를 이용.
        int mid = (start + end)/2; // 초기 mid값은 주어진 공유기들의 최대 gap의 절반으로.
        for(int i=1; i<X.size(); i++){
            // 기준 거리보다 큰 gap을 갖는 집을 찾았다면, 공유기 설치. 
            if(X[i]-installedhouse >= mid){
                // 공유기를 설치했다면, 기준점을 업데이트하여 다음 설치할 집을 찾도록
                installedhouse = X[i];

                // 공유기 설치 개수 증가
                cnt++;
            }
        }

        // 주어진 공유기 수보다 같거나 많이 설치했다면 -> start를 키워 기준 거리(mid) 늘려서 재탐색
        if(cnt >= C){
            start = mid+1;
            gap = mid; // 조건을 만족시켰으므로 gap update. 
        }

        // 적게 설치했다면 -> end를 감소시켜 기준 거리(mid) 줄여서 재탐색 
        else{
            end = mid-1;
        }
    }
    return gap;
}


// ** Binary Search:
// 정렬되어 있는 리스트에서, 탐색 범위를 절반씩 좁혀가며 데이터를 탐색하는 방법. 
// start, mid, end의 세 변수를 이용하며, 데이터를 mid와 비교하며 세 변수를 업데이트. 
// O(logN) 보장