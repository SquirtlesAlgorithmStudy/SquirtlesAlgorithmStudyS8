#include <iostream>
#include <deque>
#include <queue>
#include <vector>
using namespace std;


int main(){
    string input_gear1, input_gear2, input_gear3, input_gear4; 
    deque<int> gear1dq, gear2dq, gear3dq, gear4dq;
    vector<deque<int>> allGears = {gear1dq, gear2dq, gear3dq, gear4dq};

    int idxGearTooth;
    int numRotation;
    int tmpWhichGear;
    int tmpRotationDir;
    queue<int> whichGear;
    queue<int> rotationDir;
    int score = 0;

    cin >> input_gear1;
    cin >> input_gear2;
    cin >> input_gear3;
    cin >> input_gear4;

    cin >> numRotation;

    // get each rotation procedure and do processing
    for(int i=0; i<numRotation; i++){
        cin >> tmpWhichGear >> tmpRotationDir;
        whichGear.push(tmpWhichGear);
        rotationDir.push(tmpRotationDir);
    }

    // processing gear deque
    for(int i=0; i<8; i++){
        gear1dq.push_back(input_gear1[i] - '0');
        gear2dq.push_back(input_gear2[i] - '0');
        gear3dq.push_back(input_gear3[i] - '0');
        gear4dq.push_back(input_gear4[i] - '0');
    }

    allGears = {gear1dq, gear2dq, gear3dq, gear4dq};
    for(int i=0; i<allGears.size(); i++){
        cout << "gear " << i << " : " << allGears[i].back() << endl;
    }
}
