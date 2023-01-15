/*Khyati Gupta
https://www.youtube.com/watch?v=Zobz9BXpwYE&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=5&ab_channel=Pepcoding
*/

#include <iostream>
#include <vector>
using namespace ::std;

int solveTab(vector<int> &arr, int n)
{
    // to save memory usagae and not repeat declaration
    static vector<int> dp(n + 1, 0);
    // base case
    dp[n] = 1;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= arr[i] && i + j < dp.size(); j++)
        {
            dp[i] += dp[j + i];
        }
    }

    return dp[0];
}

int main()
{
    int n = 6;
    // cin >> n;

    vector<int> arr = {3, 3, 0, 2, 2, 3};

    cout << solveTab(arr, n);
    return 0;
}

// 6
// 3 3 0 2 2 3
// -> 8