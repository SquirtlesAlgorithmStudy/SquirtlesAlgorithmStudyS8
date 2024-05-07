/*
    대체 뭐 어디가 틀린건지 모르겠음 -> 반복 시 flag=true 안해줬었다
*/


#include <iostream>
#include <stack>
using namespace std;

int main(){
    string inputString;
    bool flag = true;
    ios::sync_with_stdio(0);
	cin.tie(0);
    while(1){
        getline(cin, inputString);
        if(inputString == ".") break;

        stack<char> c1;
        for(int i=0; i<inputString.size(); i++){
            flag = true;
            if(inputString[i] == '(' || inputString[i] == '['){
                c1.push(inputString[i]);
            }
            else if(inputString[i] == ')'){
                if(c1.empty()){
                    flag = false;
                    break;
                } 
                else{
                    if(c1.top() == '('){
                        flag = true;
                        c1.pop();
                    } 
                    else{
                        flag = false;
                        break;
                    }
                }
            }
            else if(inputString[i] == ']'){
                if(c1.empty()){
                    flag = false;
                    break;
                } 
                else{
                    if(c1.top() == '['){
                        flag = true;
                        c1.pop();
                    }
                    else{
                        flag = false;
                        break;
                    } 
                }
            }
        }
        if(c1.empty() && flag) cout << "yes\n";
        else cout << "no\n";
    }
   
}