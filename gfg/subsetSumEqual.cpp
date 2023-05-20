//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
// pepcoding
// striver
    bool isSubsetSum(vector<int>arr, int sum){
        vector<bool> prev(sum + 1), cur(sum + 1);
        int n = arr.size();
        for(int i = 0; i < n+1; i++){
            for(int j = 0; j < sum+1; j++){
                if(i == 0 && j == 0) cur[j] = true;
                else if(i == 0) cur[j] = false;
                else if(j == 0) cur[j] = true;
                else{
                    cur[j] = prev[j] ?  true : (arr[i-1] <= j ? prev[j-arr[i-1]] : false);
                }
            }
            prev = cur;
        }
        return prev[sum];
    }

    // bool isSubsetSum(vector<int> arr, int sum){
    //     int n = arr.size();
    //     vector<vector<bool>> dp(n+1, vector<bool> (sum+1));
        
    //     for(int i = 0; i < n+1; i++){
    //         for(int j = 0; j < sum+1; j++){
    //             if(i == 0 && j == 0) dp[i][j] = true;
    //             else if(i == 0) dp[i][j] = false;
    //             else if(j == 0) dp[i][j] = true;
    //             else{
    //                 dp[i][j] = dp[i-1][j] ?  true : (arr[i-1] <= j ? dp[i-1][j-arr[i-1]] : false);
    //             }
    //         }
    //     }
    //     return dp[n][sum];
    // }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends