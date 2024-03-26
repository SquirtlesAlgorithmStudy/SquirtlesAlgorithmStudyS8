#include <iostream>
#include <queue>
using namespace std;

int main(){
    int cardNum;
    queue<int> qCard;

    cin >> cardNum;
    for(int i=1; i<= cardNum; i++){
        qCard.push(i);
    }
    for(int i=1; i<= cardNum; i++){
        qCard.pop();
        qCard.pop();
        qCard.push(i+1);
        if(qCard.size() == 1) break;
    }
    cout << qCard.front() << endl;

}