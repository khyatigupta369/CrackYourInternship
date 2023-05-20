#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class group
{
public:
    int l, i, val;
    string psf;

    group(int l, int i, int val, string psf)
    {
        this->l = l;
        this->i = i;
        this->val = val;
        this->psf = psf;
    }
};

void Lis(vector<int> arr, int n)
{
    string str;
    int idx;
    vector<int> dp(n, 1);
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if (dp[i] > ans)
        {
            ans = dp[i];
            idx = i;
        }
    }
    cout << ans << endl;

    queue<group *> q;
    group *g = new group(ans, idx, arr[idx], to_string(arr[idx]) + "");
    q.push(g);

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();

        if (temp->l == 1)
            cout << temp->psf << endl;

        for (int j = 0; j < temp->i - 1; j++)
        {
            if (dp[j] == temp->l - 1 && temp->val > arr[j])
            {
                group *gg = new group(dp[j], j, arr[j], to_string(arr[j]) + "->" + temp->psf);
                q.push(gg);
            }
        }
    }
}

int main()
{
    // int n;
    // cin >> n;
    // vector<int> arr(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    // }

    vector<int> arr = {10, 22, 42, 33, 21, 50, 41, 60, 80, 3};
    int n = arr.size();
    Lis(arr, n);
}