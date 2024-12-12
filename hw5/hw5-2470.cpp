#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct dateReadPair {
    int date{};
    int read{};
};

struct comparator {
    bool operator()(const dateReadPair& a, const dateReadPair& b) {
        return a.read < b.read;
    }
};

int main() {
    int T, D, P;
    cin >> T >> D >> P;
    vector<priority_queue<dateReadPair, vector<dateReadPair>, comparator>> allDataMax(P);
    vector<vector<dateReadPair>> hottest(P);
    for (int d{0}; d < D; d++) {
        for (int p{0}; p < P; p++) {
            dateReadPair tmpNode;
            tmpNode.date = d;
            cin >> tmpNode.read;
            allDataMax[p].push(tmpNode);
            while (allDataMax[p].top().date <= d - T) {
                allDataMax[p].pop();
            }
            hottest[p].push_back(allDataMax[p].top());
        }
    }
    for (int d{0}; d < D; d++) {
        int ans{0};
        for (int i{0}; i < P; i++) {
            ans = hottest[i][d].read >= hottest[ans][d].read ? i : ans;
        }
        cout << ans + 1 << " ";
    }
}