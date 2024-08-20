// 2839 deliver sugar
// greedy

#include <iostream>

using namespace std;

int N;
int main()
{
    cin >> N;    // 설탕무게
    int ans = 0; // 봉지갯수
    while (N >= 0)
    {
        if (N % 5 == 0)
        {                   // 5로 나눌 수 있는가?
            ans += (N / 5); // 있다면 몫이 정답
            cout << ans << endl;
            return 0;
        }
        // 5로 나눌 수 없는가?
        N -= 3; // 3kg을 빼고
        ans++;  // 3키로 설탕가방 +1
    }
    cout << -1 << endl; // 5,3으로 나눌수 없으면 -1출력
}