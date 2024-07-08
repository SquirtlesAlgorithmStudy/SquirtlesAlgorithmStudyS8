#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {

    priority_queue<int, vector<int>, greater<int>> pq;
    int n = 0;
    cin >> n;

    int res = 0;

    for (int i = 0; i < n; ++i) {
        int m = 0;
        cin >> m;
        pq.push(m);
    }

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    for (int i = 0; i < n-1 ; ++i) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a+b);

        res += a+b;
    }


    cout << res << endl;
    return 0;
}