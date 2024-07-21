// 프로그래머스 n + 1 카드게임

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include<vector>


using namespace std;

int n =0; // 카드 갯수

int MyCardList[1001]  = {0,}; // 배열의 index를 1부터 할거임 1~1000
int CardsList[1001] = {0,}; // 내가 뽑을 수 있는 카드 리스트


// 1. 코인을 소모하고 카드를 뽑는 함수(카드 적힌 수가 n+1)

// 손에 들고있는 카드와 뽑지 않은 카드를 조합하여 n+1만들어주기
int Get_Card(){

    // 1장을 뽑을 경우
    for(int i=0; i<=n; i++){
        // ex) 12까지 카드가 있다고 가정했을 때, 2 + (12+1-2) = 13
        if (MyCardList[i] == 1 && CardsList[n+1-i] == 1){ 
            MyCardList[i] =0;
            CardsList[n+1-i] =0;
            return 1;
        }
    }
    // 2장을 뽑을 경우
    for(int i=0; i<=n; i++){
        if (MyCardList[i] == 1 && CardsList[n+1-i] == 1){
            MyCardList[i] =0;
            CardsList[n+1-i] =0;
            return 2;
        }
    }

    // 0장을 뽑는 경우
    return 0; 
}

// 2. 코인을 소모하지 않고 버리는 함수

// 손에 들고 있는 카드를 조합하여 n+1 찾아주기
int Trash_Card(){

    for(int i =1; i<=n; i++){
        if(MyCardList[i] ==1 && MyCardList[n+1-i] ==1){
            MyCardList[i] = 0;
            MyCardList[n+1-i] = 0;
            // n+1조건을 만족하는 첫번째 카드의 index(두번째는 자동으로 알 수 있음)
            return i; 
        }
    } 
    return 0;
}


// cards_len은 배열 cards의 길이입니다.
int Solution(int coin, vector<int> cards) {
    int answer = 0;

    n = cards.size();

    int NowCount = n/3;
    int temp = 0;

    // 뽑은 카드를 1처리
    for(int i=0; i < NowCount; i++){
        MyCardList[cards[i]] =1;
    }

    // 라운드 진행
    for(int i = NowCount; i< NowCount; i++){
        answer 
    }


    return answer;
}