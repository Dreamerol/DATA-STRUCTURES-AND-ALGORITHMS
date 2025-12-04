

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



//void rotateDiceBackward(vector<int>& dice){
//      dice = {dice[1], dice[5], dice[2], dice[0], dice[4],dice[3]};
    
// }
// void rotateDiceLeft(vector<int>& dice){
//     dice = {dice[2], dice[1], dice[5], dice[3], dice[0],dice[4]};
      
// }


// int ways(vector<vector<int>>& dp, vector<int> dice, int i, int j){
//     if(i<0 || j<0) return 1e9;
//     if(i == 0 && j == 0) return dp[0][0] = dice[5];
    
//     if(dp[i][j] != -1) return dp[i][j];
//     if(i == 0){
//         rotateDiceLeft(dice);
//         return dp[i][j] = ways(dp, dice,i,j-1) + dice[5];
//     }
//     if(j == 0){
//         rotateDiceBackward(dice);
//         return dp[i][j] = ways(dp, dice, i-1, j) + dice[5];
//     }
//     rotateDiceLeft(dice);
//     int k1 = ways(dp, dice,i, j-1) + dice[5];
//     rotateDiceBackward(dice);
//     int k2 = ways(dp, dice, i-1, j) + dice[5];
    
//     return dp[i][j] = min(k1, k2);
    
// }


#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9;
void rotateDiceBackward(vector<int>& dice){
     dice = {dice[1], dice[5], dice[2], dice[0], dice[4],dice[3]};
    
}
void rotateDiceLeft(vector<int>& dice){
    dice = {dice[2], dice[1], dice[5], dice[3], dice[0],dice[4]};
      
}
int ways(int i, int j, vector<int>& dice){
    if(i < 0 || j < 0)return INF;
    if(i == 0 && j == 0)return dice[5];
    vector<int> L = dice;
    rotateDiceLeft(L);
    int cost1 = ways(i, j-1, L) + dice[5];
    vector<int> B = dice;
    rotateDiceBackward(B);
    int cost2 = ways(i-1,j,B) + dice[5];

return min(cost1, cost2);
    
}
int main()
 {
     
    vector<int> dice = {6,2,5,3,4,1};
    int n = 2;
    int m = 2;
 
    cout<<ways(n-1, m-1, dice);
    return 0;
}

