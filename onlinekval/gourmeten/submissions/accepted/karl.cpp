#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

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
int ways(int left)
{
    if (left == 0) return 1;
    if (dp[left] != -1)
        return dp[left];

    int ret = 0;
    for (int i = 0; i < n && foods[i] <= left; ++i)
        ret += ways(left - foods[i]);
    return dp[left] = ret;
}

int main()
{
    cin >> m >> n;

    dp = vi(m + 1, -1);

    foods.resize(n);
    range(i, 0, n)
        cin >> foods[i];

    sort(all(foods));

    cout << ways(m) << endl;
    return 0;
}

