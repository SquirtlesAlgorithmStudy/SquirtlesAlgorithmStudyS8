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

    // handling if '0' has the cheapest price 
    if(N==1){
        cout << 0;
        return 0;
    } 
    else if(priceList[0].first == 0){
        // 0만 살 수 있을 때
        if(M >= priceList[0].second && M < priceList[1].second){
            cout << 0;
            return 0;
        }
        // 그렇지 않으면 맨 앞자리에 0 안됨 -> 일단 두번째로 싼 숫자 앉혀
        else if(M>=priceList[1].second){
            roomNumber = to_string(priceList[1].first);
            M = M - priceList[1].second;
        }
    }

    // 이제 0이 아닌 숫자가 가장 싸거나, 0이 가장 앞자리에 오는 것이 보정된 상태
    // 1. make the longest number with the digit of cheapest price
    while(M>=priceList[0].second){
        roomNumber += to_string(priceList[0].first);
        M = M - priceList[0].second;
    }

    // 2. 남는 돈으로 차액을 통해 큰 자리부터 바꿔나감
    // 만들어진 가장 긴 roonNumber의 모든 자리에 대해, 
    for(int i = 0; i < roomNumber.length(); i++){
        // 큰 수부터 해당 숫자까지
        for(int k = N-1; k > (roomNumber[i] - '0'); k--){
            // 차액이 남은 돈보다 작거나 같다면
            if(P[k] - P[(roomNumber[i] - '0')] <= M){
                // 차액만큼 M 감소시켜주고, roomNumber 바꿔
                M = M - (P[k] - P[(roomNumber[i] - '0')]);
                roomNumber[i] = (k + '0');
                break; // 더 작은 수로 바꿀 필요 없으니 break
            }
        }
    }

    cout << roomNumber;
}