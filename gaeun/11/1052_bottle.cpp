// 1. N을 2진수로 표현한다.
// 2. 2진수로 표현된 N의 bit 수를 센다. 이 때, K = bit 수
// 3. K 이하의 비트수가 되도록 1을 더해나간다. 더해진 1의 수가 구매한 물병 수.

#include <iostream>
using namespace std;

int N, K;
int bottlePurchased = 0;

string toBinary(int n){
    string bin = "";

    if(n == 0) bin = "0";
    while(n > 0){
        bin = ((n % 2 == 0) ? '0' : '1') + bin;
        n = n/2;
    }
    return bin;
}

int main(){
    cin >> N >> K;

    // express N in binary
    string bin = toBinary(N);

    // count the number of 1 
    int numOfone = 0;
    for(int i=0; i<bin.size(); i++){
        if(bin[i] == '1') numOfone++;
    }
    
    while(numOfone > K){
        N++;
        bottlePurchased++;

        string bin = toBinary(N);
        numOfone = 0;
        for(int i=0; i<bin.size(); i++){
            if(bin[i] == '1') numOfone++;
        }
    }

    cout << bottlePurchased;
}