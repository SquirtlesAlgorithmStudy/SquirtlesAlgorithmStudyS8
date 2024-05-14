#include <iostream>
using namespace std;

int picture[101][101];
int col, row;
bool isVisitedR[101][101] = {0, };
bool isVisitedG[101][101] = {0, };
bool isVisitedB[101][101] = {0, };

bool isVisitedWeaknessB[101][101] = {0, };
bool isVisitedWeaknessNotB[101][101] = {0, };

char dfsR(int r, int c){
    if(r < 0 || c <0 || r > row-1 || c > col-1) return '0';
    else{
        if(isVisitedR[r][c] == 0 && picture[r][c] == 'R'){
            isVisitedR[r][c] = 1;
            dfsR(r-1,c);
            dfsR(r+1,c);
            dfsR(r,c-1);
            dfsR(r,c+1);
            return 'R';
        }
    }
    return '0';
}
char dfsG(int r, int c){
    if(r < 0 || c <0 || r > row-1 || c > col-1) return '0';
    else{
        if(isVisitedG[r][c] == 0 && picture[r][c] == 'G'){
            isVisitedG[r][c] = 1;
            dfsG(r-1,c);
            dfsG(r+1,c);
            dfsG(r,c-1);
            dfsG(r,c+1);
            return 'G';
        }
    }
    return '0';
}
char dfsB(int r, int c){
    if(r < 0 || c <0 || r > row-1 || c > col-1) return '0';
    else{
        if(isVisitedG[r][c] == 0 && picture[r][c] == 'B'){
            isVisitedG[r][c] = 1;
            dfsB(r-1,c);
            dfsB(r+1,c);
            dfsB(r,c-1);
            dfsB(r,c+1);
            return 'B';
        }
    }
    return '0';
}
char dfsWeaknessB(int r, int c){
    if(r < 0 || c <0 || r > row-1 || c > col-1) return '0';
    else{
        if(isVisitedWeaknessB[r][c] == 0 && picture[r][c] == 'B'){
            isVisitedWeaknessB[r][c] = 1;
            dfsWeaknessB(r-1,c);
            dfsWeaknessB(r+1,c);
            dfsWeaknessB(r,c-1);
            dfsWeaknessB(r,c+1);
            return 'B';
        }
    }
    return '0';
}
char dfsWeaknessNotB(int r, int c){
    if(r < 0 || c <0 || r > row-1 || c > col-1) return '0';
    else{
        if(isVisitedWeaknessNotB[r][c] == 0 && picture[r][c] == 'C'){
            isVisitedWeaknessNotB[r][c] = 1;
            dfsWeaknessNotB(r-1,c);
            dfsWeaknessNotB(r+1,c);
            dfsWeaknessNotB(r,c-1);
            dfsWeaknessNotB(r,c+1);
            return 'C';
        }
    }
    return '0';
}

int main(){
    // get the input    
    cin >> col;
    row = col;
    for(int i=0; i<col; i++){
        for(int j=0; j<row; j++){
            scanf(" %c",&picture[i][j]); // 공백 제거
        }
    }

    // normal check
    int Rnum = 0;
    int Gnum = 0;
    int Bnum = 0;
    for(int i=0; i<col; i++){
        for(int j=0; j<row; j++){
            if(dfsR(i,j) == 'R') Rnum++;
            if(dfsG(i,j) == 'G') Gnum++;
            if(dfsB(i,j) == 'B') Bnum++;
        }
    }
    
    // weakness check
    for(int i=0; i<col; i++){
        for(int j=0; j<row; j++){
            if(picture[i][j] == 'G') picture[i][j] = 'C';
            if(picture[i][j] == 'R') picture[i][j] = 'C';
        }
    }
   int weaknessCheckB = 0;
   int weaknessCheckNotB = 0;
    for(int i=0; i<col; i++){
        for(int j=0; j<row; j++){
            if(dfsWeaknessB(i,j) == 'B') weaknessCheckB++;
            if(dfsWeaknessNotB(i,j) == 'C') weaknessCheckNotB++;
        }
    }
    cout << Rnum + Gnum + Bnum << " " << weaknessCheckB + weaknessCheckNotB;
}