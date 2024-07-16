#include <iostream>
#include <bitset>
using namespace std;

#define BITS 20

int count(int num){
    int cnt = 0;
    for(int i=0; i<BITS; i++){
        if(num & (0b01 << i)) cnt++;
    }
    return cnt;
}

int main(){
    int N, K;
    cin >> N >> K;

    int purchasedBottle = 0;

    while(count(N) > K){
        N++;
        purchasedBottle++;
    }

    cout << purchasedBottle;
}