#include <iostream>
#include <stack>

using namespace std;

int dist;
stack<int> acc;

void sol(int N, int K){
    //cin >> N >> K;
    dist = N - 1;
    acc.push(K);
    dist = dist - K;

    while(dist!=0){
        int currAcc = acc.top();
        int caseK=0;
        int checkAcc=0;
        bool accFlag = false;

        // check if accel is available
        for(int i=K; i>=1; i--){
            caseK = i;
            checkAcc=0;
            for(int i=currAcc+caseK; i>=0; i=i-K){
                checkAcc = checkAcc + i;
            }
            if(checkAcc <= dist){
                acc.push(currAcc+caseK);
                dist = dist - (currAcc + caseK);
                accFlag = true;
                break;
            }
        }

        // accel is unavailable
        if(!accFlag){
            // maintain current acc
            checkAcc = 0;
            for(int i=currAcc; i>=0; i=i-K){
                checkAcc = checkAcc + i;
            }
            if(checkAcc <= dist){
                acc.push(currAcc);
                dist = dist - currAcc;
                accFlag = true;
            }
            // decel is needed
            else{
                checkAcc = 0;
                caseK = 0;
                for(int i=1; i<=K; i++){
                    caseK = i;
                    checkAcc=0;
                    for(int i=currAcc-caseK; i>=0; i=i-K){
                        checkAcc = checkAcc + i;
                    }
                    if(checkAcc <= dist){
                        acc.push(currAcc-caseK);
                        dist = dist - (currAcc - caseK);
                        break;
                    }
                }
            }
        }
    }

    cout << "size: " << acc.size() << endl;
}

int main(){
    sol(23, 2); // ans: 6
    acc = stack<int>();
    sol(9, 2); // ans: 3
    acc = stack<int>();
    sol(10, 1); // ans: 5
}