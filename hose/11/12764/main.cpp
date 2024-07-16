#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;


struct Person {
    int start;
    int end;
   Person(int s, int e) : start(s), end(e) {}
};

struct ComparePerson {
    bool operator()(const Person& p1, const Person& p2) {
        return p1.start > p2.start;
    }
};



struct Computer {
    int end;
    int number;

    Computer(int e, int n) : end(e), number(n) {}
};


struct CompareComputer {
    bool operator()(const Computer& c1, const Computer& c2) {
        return c1.number > c2.number;
    }
};
struct CompareComputer2 {
    bool operator()(const Computer& c1, const Computer& c2) {
        return c1.number > c2.number;
    }
};


int main() {

    priority_queue<Person, vector<Person>, ComparePerson> pq;
    priority_queue<Computer, vector<Computer>, CompareComputer> cq;
    std::map<int, int> map;

    int n = 0;
    cin >> n;

    int res = 0;

    for (int i = 0; i < n; ++i) {
        int start = 0;
        int end = 0;
        cin >> start >> end;
        pq.push(Person{start, end});
    }

    if (n == 1) {
        std::cout << 1 << endl;
        std::cout << 1 << endl;
        return 0;
    }

    Person fp = pq.top();
    pq.pop();
    res++;
    cq.push(Computer{fp.end, res});
    map[res] = 1;

    for (int i = 1; i < n; ++i) {

        Person p = pq.top();
        pq.pop();
    
        int start = p.start;

        Computer c = cq.top();
        cq.pop();

        if (c.end < start) {
            cq.push(Computer{p.end, c.number});
            map[c.number] = map[c.number] + 1;
        } else {
            res++;
            cq.push(Computer{p.end, res});
            map[res] = 1;
        }
    }

    std::cout << res << endl;

    for (auto it = map.begin(); it != map.end(); ++it) {
        std::cout << it->second;
        if (next(it) != map.end()) {
            std::cout << " ";
        }
    }
    std::cout << endl;
    return 0;
}