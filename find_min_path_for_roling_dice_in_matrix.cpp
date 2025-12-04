

#include <iostream>
#include <vector>
using namespace std;
vector<int> rotateDiceForward(vector<int>& dice){
     return {dice[3], dice[0], dice[2], dice[5], dice[4],dice[1]};
    
}
vector<int> rotateDiceRight(vector<int>& dice){
    return {dice[4], dice[1], dice[0], dice[3], dice[5],dice[2]};
      
}
struct State{
  int cost;
  vector<int> dice;
    State():cost(0){};
    
};
int ways(vector<vector<State>>& dp, vector<int>& dice,int n, int m, int i, int j){
    dp[0][0].cost = dice[5];
    dp[0][0].dice = dice;
   //vector<int> currdice = dice;
    
    for(int i = 1;i<n;i++){
        dp[i][0].dice = rotateDiceForward(dp[i-1][0].dice);
        dp[i][0].cost = dp[i-1][0].cost + dp[i][0].dice[5];
    }
    for(int j = 1;j<m;j++){
        dp[0][j].dice = rotateDiceRight(dp[0][j-1].dice);
        dp[0][j].cost = dp[0][j-1].cost + dp[0][j].dice[5];
    }
    //dice = currdice;
    for(int i = 1;i<n;i++){
        for(int j = 1;j<m;j++){
            if(dp[i][j-1].cost > dp[i-1][j].cost){
                dp[i][j].dice = rotateDiceForward(dp[i-1][j].dice);
                dp[i][j].cost = dp[i-1][j].cost + dp[i][j].dice[5];
            }
            else{
                dp[i][j].dice = rotateDiceRight(dp[i][j-1].dice);
                dp[i][j].cost = dp[i][j-1].cost + dp[i][j].dice[5];
            }
            
            
        }
    }
    
    return dp[n-1][m-1].cost;
    
}
int main()
{
    vector<int> dice = {6,2,5,3,4,1};
    int n = 2;
    int m = 2;
    vector<vector<State>> dp(n, vector<State>(m));
    cout<<ways(dp, dice, n, m ,0, 0);
    return 0;
}
