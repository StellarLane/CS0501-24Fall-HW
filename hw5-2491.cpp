#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> allUglyNum = {1};
    int mul2Ind{0}, mul3Ind{0}, mul5Ind{0};
    for (int i{0}; i < n - 1; i++) {
        int tmp2{allUglyNum[mul2Ind] * 2}, tmp3{allUglyNum[mul3Ind] * 3}, tmp5{allUglyNum[mul5Ind] * 5};
        allUglyNum.push_back(min(min(tmp2, tmp3), tmp5));
        if (allUglyNum.back() == tmp2) mul2Ind++;
        if (allUglyNum.back() == tmp3) mul3Ind++;
        if (allUglyNum.back() == tmp5) mul5Ind++;
    }
    cout << allUglyNum.back();
}