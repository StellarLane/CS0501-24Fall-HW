#include <iostream>
#include <vector>
using namespace std;

int getFish(vector<vector<int>>& lake, int i, int j) {
    if (lake[i][j] == 0) return 0;
    int fishNum = lake[i][j];
    lake[i][j] = 0;
    fishNum += getFish(lake, i - 1, j);
    fishNum += getFish(lake, i, j - 1);
    fishNum += getFish(lake, i + 1, j);
    fishNum += getFish(lake, i, j + 1);
    return fishNum;
}

int main() {
    int m, n, fish, ans{0};
    vector<vector<int>> lake;
    cin >> m >> n;
    vector<int> edge(n + 2);
    lake.push_back(edge);
    for (int i{1}; i <= m; i++) {
        vector<int> tmp = {0};
        for (int j{1}; j <= n; j++) {
            cin >> fish;
            tmp.push_back(fish);
        }
        tmp.push_back(0);
        lake.push_back(tmp);
        tmp.clear();
    }
    lake.push_back(edge);
    for (int j{0}; j <= n + 1; j++) {
        lake[0][j] = 0;
        lake[m + 1][j] = 0;
    }
    for (int i{0}; i <= m + 1; i++) {
        lake[i][0] = 0;
        lake[i][n + 1] = 0;
    }
    for (int i{1}; i <= m; i++) {
        for (int j{1}; j <= n; j++) {
            if (lake[i][j] != 0) {
                int fish = getFish(lake, i, j);
                ans  = fish > ans ? fish : ans;
            }
        }
    }
    cout << ans << endl;

    return 0;
}