#include <iostream>
#include <vector>
using namespace std;

struct Session {
    int start;
    int end;
};

int main() {
    int n, globalEnd{0};
    int ans{0};
    cin >> n;
    vector<Session> allSessions;
    for (int i{0}; i < n; i++) {
        Session tmp;
        cin >> tmp.start;
        cin >> tmp.end;
        globalEnd = globalEnd >= tmp.end ? globalEnd : tmp.end;
        allSessions.push_back(tmp);
    }
    for (int i{0}; i < globalEnd; i++) {
        int neededThisTime = 0;
        for (Session session : allSessions) {
            if (i > session.start && i <= session.end) {
                neededThisTime++;
            }
        }
        ans = ans > neededThisTime ? ans : neededThisTime;
    }
    cout << ans << endl;
    return 0;
}
