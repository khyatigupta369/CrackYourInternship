class Solution
{
private:
    int lcs(string s, string t)
    {
        int n = s.size();
        int m = t.size();

        vector<int> prev(m + 1, 0), cur(m + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    cur[j] = 1 + prev[j - 1];
                }
                else
                    cur[j] = 0 + max(prev[j], cur[j - 1]);
            }
            prev = cur;
        }
        return prev[m];
    }

public:
    int minDistance(string word1, string word2)
    {
        return word1.size() + word2.size() - (2 * lcs(word1, word2));
    }
};