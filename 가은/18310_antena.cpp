#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int houseNum;
    int antena;

    cin >> houseNum;

    // get the locations of houses
    int* houseLocations = new int[houseNum];
    for(int i=0; i<houseNum; i++){
        cin >> *(houseLocations + i);
    }

    // sort in ascending order
    sort(houseLocations, houseLocations+houseNum);

    // set the location of antena
    if(houseNum % 2 == 0) antena = houseLocations[houseNum/2 - 1];
    else antena = houseLocations[houseNum/2];

    cout << antena;
    delete[] houseLocations;
}