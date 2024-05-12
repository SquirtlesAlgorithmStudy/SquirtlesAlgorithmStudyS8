#include <iostream>
#include <vector>
using namespace std;

int computerNum;
int connectedPairNum;
vector<int> computerMap[101];
bool is_visited[101] = {0, };
int result = 0;

void dfs(int node);

int main(){

    // get input
    cin >> computerNum;
    cin >> connectedPairNum;

    // 인접리스트 구현 for DFS
    for(int i=1; i<=connectedPairNum; i++){
        int a, b;
        cin >> a >> b;
        computerMap[a].push_back(b);
        computerMap[b].push_back(a);
    }

    // dfs
    is_visited[1] = 1;
    dfs(1);

    // print the result
    cout << result;
}

void dfs(int node){
    for(int i=0; i<computerMap[node].size(); i++){
        int connectedNode = computerMap[node][i];
        if(!is_visited[connectedNode]){
            is_visited[connectedNode] = 1;
            dfs(connectedNode);
            result++;
        }
    }
}