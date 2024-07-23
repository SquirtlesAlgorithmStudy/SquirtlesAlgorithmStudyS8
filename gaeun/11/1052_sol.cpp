#include <iostream>
#include <bitset>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    int purchasedBottle = 0;

    // bitset: 1인 bit을 설정한다 -> .count method는 설정된 bit를, 즉 1인 bit를 셈.
    while(bitset<32>(N).count() > K){
        N++;
        purchasedBottle++;
    }

    cout << purchasedBottle;
}