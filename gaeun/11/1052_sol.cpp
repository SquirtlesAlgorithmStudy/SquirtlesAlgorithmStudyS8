#include <iostream>
#include <bitset>
using namespace std;

int main(){
    int N, K;
    cin >> N >> K;

    int purchasedBottle = 0;

    while(bitset<32>(N).count() > K){
        N++;
        purchasedBottle++;
    }

    cout << purchasedBottle;
}