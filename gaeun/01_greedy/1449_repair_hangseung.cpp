#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int leakNum;
    int tapeLen;

    // get the number of leak point and the length of tape
    cin >> leakNum >> tapeLen;
    // if there is no leak point, terminate
    if(leakNum == 0){
        cout << 0;
        return 0;
    }

    // get the locations of leak point
    int* leakLocation = new int[leakNum];
    for(int i=0; i<leakNum; i++){
        cin >> *(leakLocation + i);
    }

    // sort input in ascending order
    sort(leakLocation, leakLocation + leakNum);

    // calc the number of tape needed
    int maxDist = tapeLen - 1;
    int pointer = *leakLocation; 
    int idx = 0;
    int i=0;
    int d;
    int tapeNum = 1;
    while(i + idx < leakNum){
        d = *(leakLocation + i + idx) - pointer;
        if(d > maxDist){
            pointer = *(leakLocation + i + idx);
            idx = i + idx;
            tapeNum ++;
            i = 1;
        }
        else i++;
    }
    cout << tapeNum;
    delete[] leakLocation;
}