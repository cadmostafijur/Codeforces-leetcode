//Codeforces Round 1016 (Div. 3)D.cpp
By mostafijur721, contest: Codeforces Round 1016 (Div. 3), problem: (D) Skibidi Table, Accepted, #, Copy
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define endl "\n"
#define vec vector
#define pii pair<int, int>
#define se second
#define fi first
 
using namespace std;
typedef long long ll;
 
ll getPosition(int level, int row, int col) {
    if (level == 1) {
        if (row == 1 && col == 1) return 1;
        if (row == 2 && col == 2) return 2;
        if (row == 2 && col == 1) return 3;
        return 4;
    }
    int half = 1 << (level - 1);
    ll blockSize = 1LL << (2 * (level - 1));
 
    if (row <= half && col <= half) 
        return getPosition(level - 1, row, col);
    if (row > half && col > half) 
        return blockSize + getPosition(level - 1, row - half, col - half);
    if (row > half && col <= half) 
        return 2 * blockSize + getPosition(level - 1, row - half, col);
    return 3 * blockSize + getPosition(level - 1, row, col - half);
}
 
pii getCoordinates(int level, ll position) {
    if (level == 1) {
        if (position == 1) return {1, 1};
        if (position == 2) return {2, 2};
        if (position == 3) return {2, 1};
        return {1, 2};
    }
 
    int half = 1 << (level - 1);
    ll blockSize = 1LL << (2 * (level - 1));
 
    if (position <= blockSize) {
        auto result = getCoordinates(level - 1, position);
        return {result.first, result.second};
    }
    if (position <= 2 * blockSize) {
        auto result = getCoordinates(level - 1, position - blockSize);
        return {result.first + half, result.second + half};
    }
    if (position <= 3 * blockSize) {
        auto result = getCoordinates(level - 1, position - 2 * blockSize);
        return {result.first + half, result.second};
    }
    auto result = getCoordinates(level - 1, position - 3 * blockSize);
    return {result.first, result.second + half};
}
 
void processQuery() {
    int matrixLevel, queryCount;
    cin >> matrixLevel >> queryCount;
 
    while (queryCount--) {
        string queryType;
        cin >> queryType;
 
        if (queryType == "->") {
            int rowIndex, colIndex;
            cin >> rowIndex >> colIndex;
            cout << getPosition(matrixLevel, rowIndex, colIndex) << endl;
        } else {
            ll posValue;
            cin >> posValue;
            pii coordinates = getCoordinates(matrixLevel, posValue);
            cout << coordinates.first << " " << coordinates.second << endl;
        }
    }
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int totalTests;
    cin >> totalTests;
    for (int testIndex = 0; testIndex < totalTests; ++testIndex)
        processQuery();
}
