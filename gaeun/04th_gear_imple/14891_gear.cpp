#include <iostream>
#include <deque>
#include <queue>
#include <vector>
using namespace std;


int main(){
    vector<string> gears(4);
    vector<deque<int>> allGears(4);
    int numRotation;
    int tmpWhichGear;
    int tmpRotationDir;
    queue<int> whichGear;
    queue<int> rotationDir;
    int score = 0;

    cin >> gears[0];
    cin >> gears[1];
    cin >> gears[2];
    cin >> gears[3];

    cin >> numRotation;

    // get each rotation procedure and do processing
    for(int i=0; i<numRotation; i++){
        cin >> tmpWhichGear >> tmpRotationDir;
        whichGear.push(tmpWhichGear);
        rotationDir.push(tmpRotationDir);
    }

    // processing gear deque
    for(int i=0; i<gears.size(); i++){
        for(int j=0; j<8; j++){
            allGears[i].push_back(gears[i][j] - '0');
        }
    }

    for(int k=0; k<numRotation; k++){
        int targetGearNum = whichGear.front() - 1;
        int dir = rotationDir.front();
        int gearDir[4] = {0,0,0,0};

        switch(whichGear.front()){
            case 1:
                gearDir[0] = dir;
                if(allGears[targetGearNum][2] != allGears[targetGearNum+1][6]) gearDir[1] = -dir;
                else break;
                if(allGears[targetGearNum+1][2] != allGears[targetGearNum+2][6]) gearDir[2] = -gearDir[1];
                else break;
                if(allGears[targetGearNum+2][2] != allGears[targetGearNum+3][6]) gearDir[3] = -gearDir[2];
                break;

            case 2:
                gearDir[1] = dir;
                if(allGears[targetGearNum][6] != allGears[targetGearNum-1][2]) gearDir[0] = -dir;
                if(allGears[targetGearNum][2] != allGears[targetGearNum+1][6]) gearDir[2] = -dir;
                else break;
                if(allGears[targetGearNum+1][2] != allGears[targetGearNum+2][6]) gearDir[3] = -gearDir[2];
                break;

            case 3:
                gearDir[2] = dir;
                if(allGears[targetGearNum][2] != allGears[targetGearNum+1][6]) gearDir[3] = -dir;
                if(allGears[targetGearNum][6] != allGears[targetGearNum-1][2]) gearDir[1] = -dir;
                else break;
                if(allGears[targetGearNum-1][6] != allGears[targetGearNum-2][2]) gearDir[0] = -gearDir[1];                
                break;

            case 4:
                gearDir[3] = dir;
                if(allGears[targetGearNum][6] != allGears[targetGearNum-1][2]) gearDir[2] = -dir;
                else break;
                if(allGears[targetGearNum-1][6] != allGears[targetGearNum-2][2]) gearDir[1] = -gearDir[2];
                else break;
                if(allGears[targetGearNum-2][6] != allGears[targetGearNum-3][2]) gearDir[0] = -gearDir[1];
                break;
        }

        for(int i=0; i<allGears.size(); i++){
            // CW
            if(gearDir[i] == 1){
                int tmp;
                tmp = allGears[i].back();
                allGears[i].pop_back();
                allGears[i].push_front(tmp);
            }

            // CCW
            else if(gearDir[i] == -1){
                int tmp;
                tmp = allGears[i].front();
                allGears[i].pop_front();
                allGears[i].push_back(tmp);
            }
        }

        whichGear.pop();
        rotationDir.pop();

        for(int a=0; a<allGears.size(); a++){
            cout << "gear " << a << ": ";
            for(int b=0; b<allGears[0].size(); b++){
                cout << allGears[a][b];
            }        
            cout << endl;
        }
        cout << " ------------- " << endl;
    }   

    

    // score calc
    if(allGears[0][0] == 1) score += 1;
    if(allGears[1][0] == 1) score += 2;
    if(allGears[2][0] == 1) score += 4;
    if(allGears[3][0] == 1) score += 8;

    cout << score;

}