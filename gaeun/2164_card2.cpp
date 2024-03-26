#include <iostream>
#include <queue>
using namespace std;

int main(){
    int cardNum;
    int goBehindNum;
    queue<int> qCard;

    cin >> cardNum;
    for(int i=1; i<= cardNum; i++){
        qCard.push(i);
    }
    for(int i=1; i<cardNum; i++){
        qCard.pop();
        if(qCard.size() == 1) break;
        goBehindNum = qCard.front();
        qCard.pop();
        qCard.push(goBehindNum);        
    }
    cout << qCard.front() << endl;

}