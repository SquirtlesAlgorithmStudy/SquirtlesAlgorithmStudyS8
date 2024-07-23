#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(int coin, vector<int> cards) {
    int answer = 1;

    // 1. find n and set the target sum
    int n = cards.size();

    // 2. make a card deck
    set<int> deck;
    for (int i=0; i<n/3; i++) {
        deck.insert(cards[i]);
    }
    int ptr = n / 3;

    // 3. find the solution
    set<int> newCards;
    while(ptr < n){
        // init flag
        bool isFound = false;

        // add two new cards every iteration
        newCards.insert(cards[ptr]);
        newCards.insert(cards[ptr+1]);
        ptr += 2;

        // if a pair can be made within the deck
        for(int element: deck){
            int target = (n+1) - element;
            if((deck.find(target) != deck.end())){         
                deck.erase(element);
                deck.erase(target);
                isFound = true;
                answer++;
                break;
            }
        }

        // one from the deck, the other from the new cards
        if(!isFound && coin >= 1){
            for(int element: deck){
                int target = (n+1) - element;
                if((newCards.find(target) != newCards.end())){
                    deck.erase(element);        
                    newCards.erase(target);                                
                    coin--;
                    isFound = true;
                    answer++;
                    break;
                }
            }
        }

        // two from the new cards
        if(!isFound && coin >= 2){
            for(int element: newCards){
                int target = (n+1) - element;
                if((newCards.find(target) != newCards.end())){
                    newCards.erase(element);
                    newCards.erase(target);
                    coin -= 2;
                    isFound = true;
                    answer++;
                    break;
                }
            }
        }
        if(!isFound) break;
    }

    return answer;
}