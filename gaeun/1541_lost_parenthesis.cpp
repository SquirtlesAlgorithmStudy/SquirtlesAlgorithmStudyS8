#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int sum = 0;
    string equation;
    string number = "0";

    bool isMinus = false;

    cin >> equation;
    if(equation[0] == '-') isMinus = true;
    for(int i=0; i<=equation.size(); i++){
        char c = equation[i];
        if(c == '+' || c == '-' || c == '\0'){
            if(isMinus){
                sum -= stoi(number);
                number = "";
            }
            else{
                sum += stoi(number);
                number = "";
            }
            if(c == '-'){
                isMinus = true;
            } 
        }
        else{
            number += c;
        }
    }
    
    cout << sum;
}