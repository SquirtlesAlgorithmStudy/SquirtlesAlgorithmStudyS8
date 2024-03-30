#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

/* 
    문장으로 입력을 받고, 그 수식을 계산하는 프로그램
*/
int main(){
    int sum = 0;
    string equation;
    string number = "0";
    
    bool isPlus = false;
    bool isMinus = false;
    bool isParenthesis = false;

    cin >> equation;
    if(equation[0] == '-') isMinus = true;

    // get the number of input numbers
    for(int i=0; i<=equation.size(); i++){
        char c = equation[i];
        if(c == '+' || c == '-' || c == '\0'){
            if(isPlus){
                sum += stoi(number);
                number = "";
            }
            else if(isMinus){
                sum -= stoi(number);
                number = "";
            }
            if(c == '+'){
                isPlus = true;
                isMinus = false;
            } 
            else if(c == '-'){
                isMinus = true;
                isPlus = false;
            } 
        }
        else{
            number += c;
        }        
        cout << number << endl;
    }

    // print the result
    cout << sum;
}