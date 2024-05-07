#include <iostream>
using namespace std;

int main(){
    int croatiaCounter = 0;
    string input= "";
    
    cin >> input;
    for(int i=0; i<input.size(); i++){
        if(input[i] == 'c' && i != input.size()-1){
            if(input[i+1] == '=' || input[i+1] == '-'){
                croatiaCounter--;
            }
        }
        if(input[i] == 'd' && i != input.size()-1){
            if(input[i+1] == '-'){
                croatiaCounter--;
            }
            if(input[i+1] == 'z'){
                if(input[i+2]=='='){
                    croatiaCounter--;
                }
            }
        }
        if(input[i] == 'l' && i != input.size()-1){
            if(input[i+1] == 'j'){
                croatiaCounter--;
            }
        }
        if(input[i] == 'n' && i != input.size()-1){
            if(input[i+1] == 'j'){
                croatiaCounter--;
            }
        }
        if(input[i] == 's' && i != input.size()-1){
            if(input[i+1] == '='){
                croatiaCounter--;
            }
        }
        if(input[i] == 'z' && i != input.size()-1){
            if(input[i+1] == '='){
                croatiaCounter--;
            }
        }

        croatiaCounter++;
    }
    cout << croatiaCounter;
}