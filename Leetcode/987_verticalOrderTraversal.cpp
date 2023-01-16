// striver
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<vector<int>> ans;
        map<int, map<int, multiset<int>>> nodes;

        if (root == NULL)
            return ans;

        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push(make_pair(root, make_pair(0, 0)));

        while (!q.empty())
        {
            auto temp = q.front();
            TreeNode *frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            q.pop();

            nodes[hd][lvl].insert(frontNode->val);

            if (frontNode->left)
                q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));
            if (frontNode->right)
                q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
        }

        for (auto i : nodes)
        {
            vector<int> v;
            for (auto j : nodes[i.first])
            {
                v.insert(v.end(), j.second.begin(), j.second.end());
            }
            ans.push_back(v);
        }

        return ans;
    }
};