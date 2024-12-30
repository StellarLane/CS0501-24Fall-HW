#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, tmp;
    int count0{0}, count1{0}, count2{0};
    int count1in0{0}, count2in0{0}, count0in1{0}, count2in1{0}, count0in2{0}, count1in2{0};
    vector<int> allPkg;
    cin >> n;
    for (int i{0}; i < n; i++) {
        cin >> tmp;
        allPkg.push_back(tmp);
    }
    for (auto i : allPkg) {
        switch (i) {
            case 0: count0++; break;
            case 1: count1++; break;
            case 2: count2++; break;
        }
    }
    for (int i{0}; i < count0; i++) {
        switch (allPkg[i]) {
            case 1: count1in0++; break;
            case 2: count2in0++; break;
        }
    }
    for (int i{count0}; i < count0 + count1; i++) {
        switch (allPkg[i]) {
            case 0: count0in1++; break;
            case 2: count2in1++; break;
        }
    }
    for (int i{count0 + count1}; i < n; i++) {
        switch (allPkg[i]) {
            case 0: count0in2++; break;
            case 1: count1in2++; break;
        }
    }
    int tmp1{min(count0in1, count1in0)};
    int tmp2{min(count2in0, count0in2)};
    int tmp3{min(count1in2, count2in1)};
    int tmp4{max(count0in1, count1in0) - tmp1};
    int tmp5{max(count2in0, count0in2) - tmp2};
    int tmp6{max(count1in2, count2in1) - tmp3};

    cout << (tmp1 + tmp2 + tmp3) + (tmp4 + tmp5 + tmp6) / 3 * 2 << endl;

    return 0;
}