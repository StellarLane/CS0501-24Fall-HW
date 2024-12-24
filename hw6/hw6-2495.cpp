#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

vector<int> constructPattern(vector<string> content) {
    vector<int> pattern;
    int index{0};
    unordered_map<string, int> stringMap;
    for (string word : content) {
        auto res = stringMap.find(word);
        if (res != stringMap.end()) {
            pattern.push_back(res->second);
        } else {
            stringMap[word] = index;
            pattern.push_back(index);
            index++;
        }
    }
    return pattern;
}


int compareVector(vector<int> a, vector<int> b, int n) {
    unordered_map<int, int> mapA={}, mapB={};
    for (int i = 0; i < a.size(); i++) {
        int x = a[i], y = b[i+n];
        auto resA = mapA.find(x);
        auto resB = mapB.find(y);

        if (resA == mapA.end() && resB == mapB.end()) {
            mapA[x] = y;
            mapB[y] = x;
        } else if (resA == mapA.end()) {
            if (resB->second != x) return i;
        } else if (resB == mapB.end()) {
            if (resA->second != y) return i;
        } else {if(resA->second!=y || resB->second!=x)
            return i;
        }

    }
    return -1;
}

int findMatch(vector<int> pattern, vector<int> content) {
    for (int i{0}; i <= content.size() - pattern.size() ; ) {
        int tmp = compareVector(pattern, content, i);
        if (tmp==-1) {
            return i+1;
        }
        else i+=tmp;
    }
    return 0;
}

int main() {
    string tmp;
    vector<string> encrypted;
    vector<string> target;
    while (cin >> tmp && tmp != "$") {
        encrypted.push_back(tmp);
    }
    while (cin >> tmp && tmp != "$") {
        target.push_back(tmp);
    }
    cout << findMatch(constructPattern(target), constructPattern(encrypted)) << endl;
    return 0;
}