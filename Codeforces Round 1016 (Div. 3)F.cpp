By mostafijur721, contest: Codeforces Round 1016 (Div. 3), problem: (F) Hackers and Neural Networks, Accepted, #, Copy
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define endl "\n"
#define vec vector
#define pii pair<int, int>
#define se second
#define fi first
using namespace std;
typedef long long ll;
 
void runTestCase() {
    int studentCount, submissionCount;
    cin >> studentCount >> submissionCount;
 
    vec<string> originalAnswers(studentCount);
    for (int idx = 0; idx < studentCount; idx++) {
        cin >> originalAnswers[idx];
    }
 
    bool isValid = true;
    vec<bool> matchedStudents(studentCount, false);
    int maxMatched = 0;
 
    for (int submissionIdx = 0; submissionIdx < submissionCount; submissionIdx++) {
        int currentMatchCount = 0;
        vec<string> currentAnswers(studentCount);
 
        for (int stuIdx = 0; stuIdx < studentCount; stuIdx++) {
            cin >> currentAnswers[stuIdx];
            if (currentAnswers[stuIdx] == originalAnswers[stuIdx]) {
                currentMatchCount++;
                matchedStudents[stuIdx] = true;
            }
        }
 
        maxMatched = max(maxMatched, currentMatchCount);
    }
 
    for (int checkIdx = 0; checkIdx < studentCount; checkIdx++) {
        if (!matchedStudents[checkIdx]) {
            isValid = false;
            break;
        }
    }
 
    cout << (isValid ? 3 * studentCount - 2 * maxMatched : -1) << endl;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int totalTestCases;
    cin >> totalTestCases;
    for (int testCaseIdx = 0; testCaseIdx < totalTestCases; ++testCaseIdx)
        runTestCase();
}
