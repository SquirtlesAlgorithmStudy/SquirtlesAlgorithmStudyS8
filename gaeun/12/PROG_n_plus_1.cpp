#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int coin, vector<int> cards) {
    int answer = 0;
    int ptr = 0;

    // 1. find n and set the target sum
    int n = cards.size();
    int targetSum = n+1;

    // 2. make a card deck
    vector<int> deck;
    for (int i=0; i<n/3; i++) {
        deck.push_back(cards[i]);
    }
    ptr = n / 3;

    // 3. find the solution
    vector<int> newCards;
    while(1){
        // start from round 1
        answer++; 

        // init flag
        bool isFound = false;

        // terminate if ptr exceed the size of remained cards
        if(ptr > cards.size() - 1) break;

        // add two new cards every iteration
        newCards.push_back(cards[ptr]);
        newCards.push_back(cards[ptr+1]);
        ptr += 2;

        // if a pair can be made within the deck
        for(int i=0; i<deck.size(); i++){
            auto findIdx = find(deck.begin(), deck.end(), targetSum-deck[i]);
            if(findIdx != deck.end()){
                deck.erase(deck.begin() + i);
                if((deck.begin()+i) < findIdx) findIdx--;
                deck.erase(findIdx);
                isFound = true;
                break;
            }
        }

        // one from the deck, the other from the new cards
        if(!isFound && coin >= 1){
            for(int i=0; i<newCards.size(); i++){
                auto findIdx = find(newCards.begin(), newCards.end(), targetSum-deck[i]);
                if(findIdx != newCards.end()){
                    deck.erase(deck.begin() + i);
                    newCards.erase(findIdx);
                    coin--;
                    isFound = true;
                    break;
                }
            }
        }

        // two from the new cards
        if(!isFound && coin >= 2){
            for(int i=0; i<newCards.size(); i++){
                auto findIdx = find(newCards.begin(), newCards.end(), targetSum-newCards[i]);
                if(findIdx != newCards.end()){
                    newCards.erase(newCards.begin() + i);
                    if((newCards.begin()+i) < findIdx) findIdx--;
                    newCards.erase(findIdx);
                    coin -= 2;
                    isFound = true;
                    break;
                }
            }
        }

        if(!isFound) break;
    }

    return answer;
}


int main() {
    int coin = 4;
    vector<int> vec = {3, 6, 7, 2, 1, 10, 5, 9, 8, 12, 11, 4};
    cout << solution(4, vec);

    return 0;
}