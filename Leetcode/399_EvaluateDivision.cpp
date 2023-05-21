class Solution {
public:
//     algo is make graph and traverse it
    // graph is value u to v and 1/value v to u
        // find min distance between c to d 
    
    
    double dfs(string st, string end, map<string, bool> vis, map<string, vector<pair<string, double>>> graph){
        if(st == end) return 1.00;
        vis[st] = true;
        
        for(auto i : graph[st]){
            string child = i.first;
            if( !vis[child]){
                double temp = dfs(child, end, vis, graph);
                if(temp != -1) return i.second*temp;
            }
        }
        
        return -1;
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        map<string, vector<pair<string, double>>> graph;
        
//         construction of graph
        for(int i = 0; i < values.size(); i++){
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], double(1.00/values[i])});
        }
        
        for(int i = 0; i < queries.size(); i++){
//             not a valid node in our constructed graph
            string st = queries[i][0], ed = queries[i][1];
            map<string, bool> vis;
            if(graph.find(st) == graph.end() || graph.find(ed) == graph.end()) 
                ans.push_back(-1);
            else ans.push_back(dfs(st, ed, vis, graph));
        }
        return ans;
    }
};