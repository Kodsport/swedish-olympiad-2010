#include <iostream>
#include <climits>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

#define range(x,s,e) for(int x=s;x<e;++x)
#define all(v) v.begin(), v.end()
typedef vector<int> vi;
typedef unsigned long long ull;

const double pi = 3.14159265358979323846;

#define MAX(a,b) (a > b ? a : b)
#define MIN(a,b) (a < b ? a : b)

vi foods;
int m, n;
vi dp;
int ways(int left) {
    if (left == 0) return 1;
    if (dp[left] != -1)
        return dp[left];

    int ret = 0;
    for (int i = 0; i < n && foods[i] <= left; ++i)
        ret += ways(left - foods[i]);
    assert(ret < INT_MAX);
    return dp[left] = ret;
}

int main(int argc, char** argv) {
    int maxans = 0;
    for (int i = 1; i < argc; i++) {
        string s = argv[i];
        size_t ind = s.find('=');
        if (ind == string::npos) continue;
        auto before = s.substr(0, ind), after = s.substr(ind + 1);
        if (before == "maxans") {
            istringstream iss(after);
            iss >> maxans;
        }
    }
    cin >> m >> n;

    dp = vi(m + 1, -1);

    foods.resize(n);
    range(i, 0, n)
        cin >> foods[i];

    sort(all(foods));

    int ans = ways(m);
    assert(ans <= maxans);
    return 42;
}

