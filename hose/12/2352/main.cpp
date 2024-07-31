#include <iostream>
#include <vector>
using namespace std;


int arr[40001];

int main() {
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> v;
    v.push_back(arr[0]);

    for (int i = 1; i < n; ++i) {
        if (v.back() < arr[i]) {
            v.push_back(arr[i]);
        } else {
            auto it = lower_bound(v.begin(), v.end(), arr[i]);
            v[it - v.begin()] = arr[i];
        }
    }
    
    cout << v.size() << '\n';


    return 0;
}