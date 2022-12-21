/*Khyati Gupta*/
#include <iostream>
#include <vector>
#include <string.h>
#include <map>
#define mp make_pair
#define pb push_back
#define ll long long
using namespace ::std;

int fibMem(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
        return n;
    if (dp[n])
        return dp[n];

    return dp[n] = fibMem(n - 1, dp) + fibMem(n - 2, dp);
}

int main()
{
    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    cout << fibMem(n, dp);
    return 0;
}