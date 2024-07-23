// fav sol: bit shift
#include <iostream>

#define BITS 32

int count(int num){
    int cnt = 0;
    for(int i=0; i<BITS; i++){
        if(num & (0b01 << i)) cnt++;
    }
    return cnt;
}

int main(){
    int N, K;
    scanf("%d %d", &N, &K);

    int purchasedBottle = 0;

    while(count(N) > K){
        N++;
        purchasedBottle++;
    }

    printf("%d", purchasedBottle);
}