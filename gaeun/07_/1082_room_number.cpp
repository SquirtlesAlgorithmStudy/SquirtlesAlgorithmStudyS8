// strategy: 숫자 가장 길게 만들기 + 남은 돈으로 앞자리부터 바꿔

#include <iostream>
#include <vector>
#include <algorithm> // to use sort()
using namespace std;

int N;
int P[10] = {0,};
vector<pair<int, int>> priceList;
int M;
string roomNumber = "";

int main(){
    // get inputs
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> P[i];
        priceList.push_back(make_pair(i, P[i]));
    }
    cin >> M;

    // sort price from the cheapest one - !!Lambda function!!
    sort(priceList.begin(), priceList.end(), [](pair<int,int> a, pair<int,int> b){
        return a.second < b.second;}
    );

    // 두자리 이상 가능할 때, 0은 가장 앞자리에 올 수 없음
    if(M>=priceList[1].first && priceList[0].first == 0){
        roomNumber = to_string(priceList[1].first);
        M = M - priceList[1].second;
    }

    // to make the longest number, purchase the cheapest number as much as possible.
    while(M>=priceList[0].second){
        roomNumber += to_string(priceList[0].first);
        M = M - priceList[0].second;
    }

    // 남는 돈으로 차액을 통해 큰 자리부터 바꿔나감
    for(int i = 0; i < roomNumber.length(); i++){
        // 큰 수부터 해당 숫자까지
        for(int k = N-1; k > (roomNumber[i] - '0'); k--){
            // 차액이 남은 돈보다 작거나 같다면
            if(P[k] - P[roomNumber[i] - '0'] <= M){
                // 차액만큼 M 감소시켜주고, rommNumber 바꿔
                M = M - (P[k] - P[roomNumber[i] - '0']);
                roomNumber[i] = k + '0';
            }
        }
    }

    cout << roomNumber;
}