// 1715 카드정렬하기

// 카드를 정렬하는데 비교해야하는 최소의 횟수를 구하자
// 이는 가장 적은 2개의 묶음을 우선적으로 계산하는 것 -> 힙으로
// 카드 묶음을 합치는 횟수 : N-1



#include<iostream>
#include<queue>

#define MAX 10000

using namespace std;

int N; //카드묶음
int Arr[MAX];

void Input(){
    cin >> N; // 카드 묶음 수
    for(int i=0; i<N; i++){
        cin >> Arr[i]; // 각 카드 묶음 크기 
    }
}

void solution(){
    priority_queue<int> PQ; //최소힙
    for(int i=0; i<N; i++)
        PQ.push(-Arr[i]);

    int Answer =0;
    int Compare_Cnt = 0;

    while (PQ.empty()==0){ // 우선순위 큐가 비어있지 않을때까지 반복
        if(Compare_Cnt == N-1) // 모든 비교가 완료되면 반복 종료
            break;
        int NUM1 = -PQ.top(); // 가장 작은 두 카드 묶음 
            PQ.pop();
        int NUM2 = -PQ.top();
            PQ.pop();

        Answer = Answer + (NUM1 + NUM2);
        PQ.push(-(NUM1 + NUM2));
    }
    cout << Answer << endl;
}

void Solve(){
    Input();
    solution();
}


int main(void){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    Solve();

    return 0;
}