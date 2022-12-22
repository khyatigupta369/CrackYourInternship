/*Khyati Gupta
link: https://www.youtube.com/watch?v=A6mOASLl2Dg&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=2&ab_channel=Pepcoding
*/

// Tabulation steps :
// 1. storage assign &conotate meaning to it
// 2. Direction decide
// 3. Travel and solveMem the problem
#include <iostream>
#include <vector>
using namespace ::std;

int solveMem(int n, vector<int> &dp)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (dp[n])
        return dp[n];
    return dp[n] = solveMem(n - 1, dp) + solveMem(n - 2, dp) + solveMem(n - 3, dp);
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, 0);
    cout << solveMem(n, dp);
    return 0;
}