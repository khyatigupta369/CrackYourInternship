/*Khyati Gupta*/
#include <iostream>
#include <vector>
using namespace ::std;

int main(){
    
    vector<int> coins =  {2, 3, 5,6};
    int target = 10;

    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < target+1; i++){
        for(int j = 0; j < coins.size(); j++){
            if(coins[j] <= i){
                dp[i] += dp[i - coins[j]];
            }
        }
    }
    cout << dp[target];
    return 0;
}