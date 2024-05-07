#include <iostream>
using namespace std;

int main(){
    int paperNum = 0;
    int whitePaper[100][100] = {};
    int numOfOne = 0;

    cin >> paperNum;

    int *row_inputPaper = new int[paperNum];
    int *col_inputPaper = new int[paperNum];

    for(int i=0; i<paperNum; i++){
        cin >> row_inputPaper[i] >> col_inputPaper[i];
        row_inputPaper[i] = row_inputPaper[i] - 1;
        col_inputPaper[i] = col_inputPaper[i] - 1;
    }

    for(int i=0; i<paperNum; i++){
        for(int row = row_inputPaper[i]; row < row_inputPaper[i]+10; row++){
            if(row >= 100) break;
            for(int col = col_inputPaper[i]; col < col_inputPaper[i]+10; col++){
                if(col >= 100) break;
                whitePaper[row][col] = 1;
            }
        }
    }

    for(int row = 0; row < 100; row++){
        for(int col = 0; col < 100; col++){
            if(whitePaper[row][col] == 1){
                numOfOne++;
            }
        }
    }

    cout << numOfOne;

    delete []row_inputPaper;
    delete []col_inputPaper;
}