//{ Driver Code Starts
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	    int lcs(int x, int y, string s1, string s2)
        {
            // your code here
            int dp[x+1][y+1];
            for(int i=0;i<=x;i++){
                dp[i][0]=0;
            }
            for(int i=0;i<=y;i++){
                dp[0][i]=0;
            }
            for(int i=1;i<=x;i++){
                for(int j=1;j<=y;j++){
                    if(s1[i-1]==s2[j-1])
                        dp[i][j]=1+dp[i-1][j-1];
                    else
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
            return dp[x][y];
        }
        set<string>st;
        
        void f(string s,string t,int i,int j,string &temp,vector<string>&ans,int count){
            if(count==0){
                if(st.find(temp)==st.end()){
                    st.insert(temp);
                    ans.push_back(temp);
                }
                return;
            }
            if(i>=s.size() || j>=t.size()) return;
            
            for(int x=i;x<s.size();x++){
                for(int y=j;y<t.size();y++){
                    if(s[x]==t[y]){
                        temp.push_back(s[x]);
                        f(s,t,x+1,y+1,temp,ans,count-1);
                        temp.pop_back();
                    }
                }
            }
        }
		vector<string> all_longest_common_subsequences(string s, string t)
		{
		    // Code here
		    int x=s.length();
		    int y=t.length();
		    int count=lcs(x,y,s,t);
		    vector<string>ans;
		    string temp="";
		    f(s,t,0,0,temp,ans,count);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	vector<string> ans = ob.all_longest_common_subsequences(s, t);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}


// } Driver Code Ends