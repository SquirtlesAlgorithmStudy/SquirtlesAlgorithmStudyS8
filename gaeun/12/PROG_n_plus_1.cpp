#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int coin, vector<int> cards) {
    int answer = 0;
    int ptr = 0;

    // 1. find n
    int n = cards[0];
    for(int i=1; i<cards.size(); i++){

        if(cards[i] > n) n = cards[i];

    }

    // 2. make a card deck and sort it in ascending order
    vector<int> deck;
    for (int i=0; i<n/3; i++) {
        deck.push_back(cards[i]);
    }
    sort(deck.begin(), deck.end());
    ptr = n / 3;

    // 3. create toNplusOne array
    vector<int> toNplusOne;
    for (int i = 0; i < deck.size(); i++) {
        toNplusOne.push_back((n + 1) - deck[i]);
    }

    if (!deck.empty() && ptr < cards.size()) {
        // 'n+1' can be made within the card deck 
        for (int i = 0; i < deck.size(); i++) {
            int isFoundIdx = lower_bound(deck.begin(), deck.end(), toNplusOne[i]) - deck.begin();
            if (isFoundIdx < deck.size() && deck[isFoundIdx] == toNplusOne[i]) {
                deck.erase(deck.begin() + i);
                if (isFoundIdx > i) {
                    isFoundIdx--;
                }
                deck.erase(deck.begin() + isFoundIdx);
                toNplusOne.erase(toNplusOne.begin() + i);
                toNplusOne.erase(toNplusOne.begin() + isFoundIdx);
                answer++;
                i = -1; // erase 수행 시 기존 element의 idx가 바뀌므로 for loop 처음부터
            }
        }

        // 기존 deck 다 털었으면 새로운 카드 확인
        vector<int> newCards(2);
        while (coin > 0 && !deck.empty() && ptr + 1 < cards.size()) {
            // 1. get two new cards            
            newCards[0] = cards[ptr];
            newCards[1] = cards[ptr + 1];
            ptr += 2;

            // 2. if the two new can be a pair
            if (coin >= 2 && (newCards[0] + newCards[1] == n + 1)) {
                answer++;
                coin -= 2;
                continue; // 새로운 카드로 계속 진행
            }

            // 3. if one of the cards can be a pair with existed one
            if (coin >= 1) {
                int new1matchIdx = lower_bound(toNplusOne.begin(), toNplusOne.end(), newCards[0]) - toNplusOne.begin();
                int new2matchIdx = lower_bound(toNplusOne.begin(), toNplusOne.end(), newCards[1]) - toNplusOne.begin();

                if (new1matchIdx < toNplusOne.size() && toNplusOne[new1matchIdx] == newCards[0]) {
                    answer++;
                    coin--;

                    deck.erase(deck.begin() + (new1matchIdx));
                    toNplusOne.erase(toNplusOne.begin() + (new1matchIdx));
                }

                if (coin >= 1 && new2matchIdx < toNplusOne.size() && toNplusOne[new2matchIdx] == newCards[1]) {
                    answer++;
                    coin--;

                    deck.erase(deck.begin() + (new2matchIdx));
                    toNplusOne.erase(toNplusOne.begin() + (new2matchIdx));
                }
            }
        }
    }

    return answer;
}


int main() {
    vector<int> vec = { 1,2,3,4,5 };
    int arr[5] = {6,7,8,9,10};

    // lower_bound 및 upper_bound가 반환한 반복자(포인터) 값을 출력
    cout << lower_bound(vec.begin(), vec.end(), 5) - vec.begin() << endl;
    cout << lower_bound(vec.begin(), vec.end(), 11) - vec.begin() << endl;

    cout << lower_bound(arr, arr+5, 10) - arr << endl;
    cout << lower_bound(arr, arr+5, 15) - arr << endl;

    return 0;
}