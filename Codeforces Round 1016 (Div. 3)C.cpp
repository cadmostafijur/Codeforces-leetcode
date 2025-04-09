By mostafijur721, contest: Codeforces Round 1016 (Div. 3), problem: (C) Simple Repetition, Accepted, #, Copy
#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define endl "\n"
#define vec vector
#define pii pair<int, int>
#define se second
#define fi first
 
using namespace std;
 
typedef long long ll;
 
bool isPrime(ll number) {
    if (number < 2) return false;
    for (ll divisor = 2; divisor * divisor <= number; ++divisor)
        if (number % divisor == 0) return false;
    return true;
}
 
void checkCondition() {
    ll inputNumber;
    int requiredCount;
    cin >> inputNumber >> requiredCount;
 
    cout << (requiredCount == 1 
        ? (isPrime(inputNumber) ? "YES" : "NO") 
        : ((inputNumber == 1 && requiredCount == 2) ? "YES" : "NO")) << endl;
}
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int totalCases;
    cin >> totalCases;
    for (int currentCase = 0; currentCase < totalCases; ++currentCase)
        checkCondition();
}
