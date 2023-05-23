class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        unordered_map<int, int> freq;
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // construct map - O(N)
        for (auto i : nums)
            freq[i]++;

        // construct heap   first - freq, second - number - O(N)
        for (auto i : freq)
        {
            pq.push({i.second, i.first});
            if (pq.size() > k)
                pq.pop();
        }

        // O(K)
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};