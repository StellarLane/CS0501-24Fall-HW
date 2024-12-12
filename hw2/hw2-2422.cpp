#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 有stl就不手写来给自己找罪受了🤗

int main() {
    unsigned kidNum, maxTimeOnce;
    cin >> kidNum;
    cin >> maxTimeOnce;
    unsigned *playTime = new unsigned[kidNum];
    for (unsigned i{0}; i < kidNum; i++) {
        cin >> playTime[i];
        playTime[i] = playTime[i] % maxTimeOnce == 0 ? playTime[i] / maxTimeOnce : playTime[i] / maxTimeOnce + 1;
    }
    map<unsigned, vector<unsigned>> dict;
    for (unsigned i{0}; i < kidNum; i++) {
        dict[playTime[i]].push_back(i);
    }

    for (const auto &pair : dict) {
        for (unsigned index : pair.second) {
            cout << index << " " << flush;
        }
    }
    return 0;
}