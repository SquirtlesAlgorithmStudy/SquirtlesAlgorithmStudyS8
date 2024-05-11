// 옛날컴이라.. 배열 크기 300000으로 잡으니 segment fault..

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int childrenNum;
    int groupNum;
    int height;
    int totalCost = 0;

    // get input
    cin >> childrenNum >> groupNum;

    int* childHeight = new int[childrenNum];
    for(int i=0; i<childrenNum; i++){
        cin >> childHeight[i];
    }

    // get cost of subsequent element
    int* cost = new int[childrenNum - 1];
    for(int i=0; i<childrenNum-1; i++){
        cost[i] = childHeight[i+1] - childHeight[i];
        totalCost += cost[i];
    }

    // sort cost in ascending
    sort(cost, cost+childrenNum-1);

    // subtract biggest cost of the number of boundaries
    for(int i=childrenNum-2; i > childrenNum-2 - (groupNum - 1); i--){
        totalCost -= cost[i];
    }

    // print result
    cout << totalCost;   

}