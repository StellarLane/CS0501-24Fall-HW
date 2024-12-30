#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int charParser(char c, vector<char> alphabet) {
    for (int i{0}; i < alphabet.size(); i++) {
        if (c == alphabet[i]) {
            return i;
        }
    }
}

bool compare(const vector<int>& a, const vector<int>& b) {
    int i;
    for (i = 0; i < a.size() && i < b.size(); i++) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
    }
    return a.size() == b.size() || i >= a.size();
}

void printAll(const vector<vector<int>> ordered, vector<char> alphabet) {
    for (auto v : ordered) {
        for (int i{0}; i < v.size(); i++) {
            cout << alphabet[v[i]];
        }
        cout << endl;
    }
}

vector<int> stringParser(string str, vector<char> alphabet) {
    vector<int> res;
    for (int i{0}; i < str.size(); i++) {
        res.push_back(charParser(str[i], alphabet));
    }
    return res;
}

int main() {
    int letterCount, wordCount;
    char tmp;
    vector<vector<int>> allWords;
    string line;
    cin >> letterCount >> wordCount;
    vector<char> alphabet;
    for (int i{0}; i < letterCount; i++) {
        cin >> tmp;
        alphabet.push_back(tmp);
    }
    for (int i{0}; i < wordCount; i++) {
        cin >> line;
        allWords.push_back(stringParser(line, alphabet));
    }

    sort(allWords.begin(), allWords.end(), [](const vector<int>&a, const vector<int>&b) {
        return compare(a, b);
    });
    printAll(allWords, alphabet);
    return 0;
}