class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> combined;
        long long ans = 0;
        long long sum = 0;
        for(int i = 0; i < nums1.size(); i++)
            combined.push_back({nums2[i], nums1[i]});
        sort(combined.begin(), combined.end(), greater<pair<int, int>> ());
        
//         min heap
        priority_queue<int, vector<int>, greater<int>> pq;
//         0 indexing -> k-1
        for(int i = 0; i < k-1; i++){
            sum+= combined[i].second;
            pq.push(combined[i].second);
        }
        
        for(int i = k-1; i < nums1.size(); i++){
            
            sum+= combined[i].second;
            pq.push(combined[i].second);

            ans = max(ans, sum * combined[i].first );

            sum -= pq.top();
            pq.pop();
        }
        
        return ans;
    }
};