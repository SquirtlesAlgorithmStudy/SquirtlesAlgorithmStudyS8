// 1149.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
using namespace std;


// 우리가 구하고 싶은 것
// an을 구하는 것. n은 1 ~ 1000

// 1. 
// 만약 an에 red를 칠하고 싶다면 an = an-1 + red
// 이 경우에 an-1 = min(an-2 + green, an-2 + blue)

// 2.
// 만약 an에 green을 칠하고 싶다면 an = an-1 + green
// 이 경우에 an-1 = min(an-2 + red, an-2 + blue)

// 3.
// 만약 an에 blue를 칠하고 싶다면 an = an-1 + blue
// 이 경우에 an-1 = min(an-2 + red, an-2 + green)

// an = 위 세가지 경우에서 최소값을 선택하면 됨.


// 미지수 x에 대하여 ax가 r인 경우, g인 경우, b인 경우 모두 구해야함.
// 그래서 n by 3 배열을 만들어야함.

// 정의 
// n번째 집에 red를 칠할 때 a[n-1][0] + r
// n번째 집에 green을 칠할 때 a[n-1][1] + g
// n번째 집에 blue를 칠할 때 a[n-1][2] + b


// n-1 번째 집에 red를 칠할 때 a[n-2][1] + r
// n-1 번째 집에 green을 칠할 때 a[n-2][0] + g
// n-1 번째 집에 blue를 칠할 때 a[n-2][2] + b

/// ...

// a[1][0] =  2번째 집에 red를 칠할 때
// a[1][1] = 2번째 집에 green을 칠할 때
// a[1][2] = 2번째 집에 blue를 칠할 때

// 그러면 a[1][0]의 값은 어떻게 구해야하나.
// a[1][0] = min(a[0][1], a[0[2]]) + r




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;
    cin >> N;

    // N by 3 mertix
    int** arr = new int* [N];

    for (int i = 0; i < N; ++i)
    {
        arr[i] = new int[3];

        if (i == 0)
        {
			cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
			continue;
		}

        int r, g, b;
		cin >> r >> g >> b;

		arr[i][0] += min(arr[i - 1][1], arr[i - 1][2]) + r;
		arr[i][1] += min(arr[i - 1][0], arr[i - 1][2]) + g;
		arr[i][2] += min(arr[i - 1][0], arr[i - 1][1]) + b;
	}

    int result = min(arr[N - 1][0], min(arr[N - 1][1], arr[N - 1][2]));
    cout << result << endl;

    return 0;
}