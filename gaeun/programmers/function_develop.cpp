#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> days;
    for(int i=0; i<progresses.size(); i++){
        int day = (100-progresses[i])/speeds[i];
        if((100-progresses[i]) % speeds[i] != 0) day++;
        days.push(day);
    }
    
    int distribute = days.front();
    days.pop();
    int distributeDays = 1;
    printf("days.size(): %d\n",days.size());
    while(!days.empty()){
        while(!days.empty() && distribute >= days.front()){
            days.pop();
            distributeDays++;            
            printf("# here\n");
            printf("days.size(): %d\n",days.size());
        }
        if(days.empty()){
            break;
        } 
        answer.push_back(distributeDays);
        distribute = days.front();
        days.pop();
        distributeDays = 1;
        printf("## here\n");
        printf("days.size(): %d\n",days.size());
    }
    answer.push_back(distributeDays);    
    printf("### here\n");
    printf("days.size(): %d\n",days.size());
    
    return answer;
}

int main(){
    vector<int> p1 = {95, 90, 99, 99, 80, 99};
    vector<int> s1 = {1, 1, 1, 1, 1, 1};
    vector<int> ans;
    ans = solution(p1, s1);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " " << endl;
    }
}
    