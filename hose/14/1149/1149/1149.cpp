// 1149.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N = 0;
    cin >> N;

    int** arr = new int* [N];

    arr[0] = new int[3];

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