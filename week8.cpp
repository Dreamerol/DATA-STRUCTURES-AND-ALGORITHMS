//zadachi - lekcii
//zad1
int dp[1000]{}, n;
int fib(n){
    if(n == 2 || n == 1){
        return 1;
    }
    if(dp[n] != 0){
        return dp[n];
    }
    return dp[n] = fib(n-1) + fib(n-2);
}
//zad2
const int INF = 1000000;
int Min(int a, int b, int c){
    return min(min(a, b), c);
}
int dp[1000];
int ans(X){
    if(X == 0){
        return 0;
    }
    if(X < 0){
        return INF;
    }
    if(dp[X] != 0){
        return dp[X];
    }
    int val = Min(ans(X-2), ans(X-3), ans(X-7));
    if(val ==INF){
        return INF;
    }
    return dp[X] = val+1;
}
//zad 3
int dp[1000][1000];
int n,m;
int matrix[1000][1000];
//global matrix

int path(int x, int y){
    if(x == 0){
        return dp[x][y] = path(x, y-1) + matrix[x][y];
    }
    if(y == 0){
        return dp[x][y] = path(x-1, y) + matrix[x][y];
    }
    return dp[x][y] = min(path(x-1, y), path(x, y-1)) + matrix[x][y];
    
}
//zad 4
int dp[1000][1000];
int A[1000];
int W[1000];
int ans(int n, int x){
    if(n == 0){
        return 0;
    }
    if(dp[n][x] != 0){
        return dp[n][x];
    }
    if(x < W[n-1]){
        return dp[n][x] = ans(x, n-1);
    }
    return dp[n][x] = max(ans(x,n-1), (ans(x-W[n-1], n-1) + A[n-1]));
}
//zad 5
int dp[1000];
int n;
int a[1000];
int ans(int i){
    if(dp[i] != 0){
        return dp[i];
    }
    if(i == 0){
        return 1;
    }
    
    int res = 1;
    for(int j = 0;j<i;j++){
        if(a[i] > a[j]){
            res = max(res, 1 + ans(j));
        }
    }
    return dp[i] = res;
}
//zad 6
  int X;
    cin>>X;
    vector<int> a = {2, 3, 7};//vidove moneti
    int N = a.size();
    const int INF = 1e9;
    vector<vector<int>> DP(X+1, vector<int>(N+1, INF));
    for(int i = 0;i<=N;i++){
        DP[0][j] = 0;
    }
    for(int i = 1;i<=X;i++){
        for(int j =1;j<=N;j++){
            DP[i][j] = DP[i][j-1];
            
            if(i >= a[j-1]){
                DP[i][j] = min(DP[i][j], DP[i-a[j-1]][j] + 1);
            }
        }
    }
    if(DP[X][N] >= INF){
        cout<<"NOT POSSIBLE";
    }
    else{
        cout<<DP[X][N];
    }
    cout<<'\n';
    
//zad 7
int ans(vector<vector<int>>& dp, string word1, string word2,int i, int j){
    if(i < 0) return j+1;
    if(j < 0) return i+1; 
    if(dp[i][j] != -1) return dp[i][j];
    if(word1[i] == word2[j]){
        return dp[i][j] = ans(dp, word1, word2, i-1, j-1);
    }
    else{
        int del = ans(dp, word1, word2, i-1,j) + 1;
        int ins = ans(dp, word1, word2, i, j-1) + 1;
        int rep = ans(dp, word1, word2, i-1, j-1) + 1;

        return dp[i][j] = min(min(del, ins), rep); 
    }
    
}
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return ans(dp, word1, word2, n-1, m-1);

    }

//zad 8
 int ways(int amount, int idx, vector<vector<int>>& dp, vector<int>& coins){
        if(amount == 0) return 1;
        if(idx >= coins.size()) return 0;
        if(dp[amount][idx] != -1) return dp[amount][idx];
        int take = 0;
        if(amount>= coins[idx]){
            take = ways(amount-coins[idx], idx, dp, coins);
        }
        int skip = ways(amount, idx+1, dp, coins);
        return dp[amount][idx] = skip+take;

    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(amount+1, vector<int>(coins.size()+1, -1));
        return ways(amount, 0, dp, coins);
    }
//zad 9
    const int INF = 1e9;
    int ways(vector<vector<int>>& dp, vector<int>& coins, int amount, int idx){
        if(amount == 0) return 0;
        if(idx >= coins.size()) return INF;
        if(dp[amount][idx] != -1){
            return dp[amount][idx];
        }
        int take = INF;
        if(amount >= coins[idx]){
            take = 1 +ways(dp, coins, amount - coins[idx], idx);
        }
        int skip = ways(dp, coins, amount, idx+1);
        //we compare skip and take only if both of them give valid combinations
        //if we cant make combination when removing that coin -> then we take = INF
        return dp[amount][idx] = min(skip, take);
    }
    int coinChange(vector<int>& coins, int amount) {
       vector<vector<int>> dp(amount+1, vector<int>(coins.size() + 1, -1));
       int k = ways(dp, coins, amount, 0); 
       if(k == INF) return -1;
       return k;  
    }

//zad 10
//1 nachin
int climbStairs(int n) {
        if(n == 1){
            return 1;
        }
        if(n == 2){
            return 2;
        }
        return climbStairs(n-1) + climbStairs(n-2);
    }
//2 nachin
 int climbStairs(int n) {
        if (n <= 3) return n;

        int cur = 0;
        int prev1 = 2;
        int prev2 = 3;
        for(int i = 3;i<n;i++){
            cur = prev1 + prev2;
            prev1 = prev2;
            prev2 = cur;
        }

        return cur;
    }

//zad 11
  int countOnes(int i){
        int count = 0;
        while(i){
            count += i%2;
            i/=2;
            
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> bits(n+1);
        bits[0] = 0;
       for(int i = 1;i<=n;i++){
        bits[i] = countOnes(i);
       } 
       return bits;
    }


    vector<int> countBits(int n) {
        vector<int> bits(n+1);
        bits[0] = 0;
       for(int i = 1;i<=n;i++){
        bits[i] = bits[i/2] + (i% 2);
       } 
       return bits;
    }
//zad 12
  bool isSubSeq(string& s, string& t, int i, int j){
        
        if(i==0 && j==0){
            if(s[i] == t[j])return true;
            return false;}
        if(i<0)return true;
        if(j<0) return false;
        if(s[i] == t[j]){
            return isSubSeq(s, t, i-1, j-1);
        }
         
        return isSubSeq(s, t, i, j-1);
    }
    bool isSubsequence(string s, string t) {
        if(s.size() == 0)return true;
        if(s.size() > t.size()) return false;
        return isSubSeq(s, t, s.size()-1, t.size()-1);
    }

//zad 13
int costUntilNow(vector<int>& dp, vector<int>& cost, int n){
        if(n>=dp.size())return 0;
        if(dp[n] != -1){
            return dp[n];
        }
     dp[n] = min(costUntilNow(dp, cost, n+1), costUntilNow(dp, cost, n+2)) + cost[n];
      cout<<dp[n]<<' ';
      return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);

       // dp[n] = 0;
       //checking the first case when we get from the step 0 or step 1
        return min(costUntilNow(dp, cost, 0), costUntilNow(dp, cost, 1));
    }

//zadachi seminar
//zad 14
 vector<int> nextRow(vector<int>& prevRow){
        vector<int> row;
        row.push_back(1);
        int prev = 1;
        int curr = 1;
        for(int i = 0;i<prevRow.size()-1;i++){
           row.push_back(prevRow[i]+prevRow[i+1]);
        }
        row.push_back(1);
        return row;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec;
        if(numRows == 0) return vec;
        if(numRows == 1) return {{1}};
        if(numRows == 2) return {{1}, {1, 1}};
        vec.push_back({1});
        vec.push_back({1,1});

        for(int i = 2;i<numRows;i++){
            vector<int> currRow = nextRow(vec[i-1]);
            vec.push_back(currRow);
        }
        return vec;

    }
//zad 15
int ways(int n, vector<int>& houses){
        if(n >= houses.size()) return 0;
        return max((ways(n+2, houses) + houses[n]), ways(n+1, houses));
    }
    int rob(vector<int>& nums) {
        return max(ways(0, nums), ways(1, nums));
    }

 int rob(vector<int>& nums){
       if(nums.size() == 1){
        return nums[0];
       }
       vector<int> dp(nums.size(), 0);
       dp[0] = nums[0];
       dp[1] = max(nums[0], nums[1]);
       for(int i=2;i<nums.size();i++){
        dp[i] = max(dp[i-1], (dp[i-2] + nums[i]));
       }

       return dp.back();
    }

//zad 16
    int ans(vector<vector<int>>& dp,int i, int j, vector<vector<int>>& grid){
          if(i<0 || j<0)return 0;
          if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i == 0){
            return dp[i][j] = ans(dp, i, j-1, grid) + grid[i][j];
        }
        if(j == 0){
            return dp[i][j] = ans(dp,i-1,j, grid) + grid[i][j];
        }
        
        return dp[i][j] = min(ans(dp, i, j-1, grid), ans(dp, i-1, j, grid)) + grid[i][j];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return ans(dp, n-1, m-1, grid);
    }

//zad 17
int ans(int i, vector<int>& nums, vector<int>& dp){
        if(dp[i] != -1){
            return dp[i];
        }
        int res = 1;
        for(int j = 0;j<i;j++){
            if(nums[i] > nums[j]){
                res = max(ans(j, nums, dp) + 1, res);
            }
        }
        return dp[i] = res;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int best = 0;
        for(int i = 0;i<nums.size();i++){
            best=max(best, ans(i, nums, dp));
        }
        return best;
    }

//zad 18
   int uniqPaths(int m, int n,int i, int j, vector<vector<int>>& dp){
        if(i>=m || j >= n) return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        //when we reach the destination we have passed one way
        if(i == m-1 && j == n-1){
            return 1;
        }
    //    if(i == 0 || j == 0) return dp[i][j] = 1;
        return dp[i][j] = uniqPaths(m,n,i, j+1, dp) + uniqPaths(m,n,i+1, j, dp);

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n ,-1));
        return uniqPaths(m,n,0,0,dp);
    }
//iterative way = bottom-up
 vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int i = 1;i<m;i++){
            for(int j = 1;j<n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }

        }
        return dp[m-1][n-1];

//zad 19
  int fib(int n) {
        if(n == 0 || n == 1){
            return n;
        }
        return fib(n-1) + fib(n-2);
    }

//zad 20
int paths(vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp, int i, int j){
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        if(i >= n || j>= m){
            return 0;
        }
        if(obstacleGrid[i][j] == 1) return 0;      
        if(i == n-1 && j == m-1) return 1;
        
  
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        return dp[i][j] = paths(obstacleGrid, dp, i+1, j) + paths(obstacleGrid, dp, i, j+1);

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return paths(obstacleGrid, dp, 0, 0);
    }

//zad 21
 int sum(vector<vector<int>>& triangle, int curRow, int i){
        if(curRow == triangle.size())return 0;
        if(i<0 || i >= triangle[curRow].size()) return 0;
        return min(sum(triangle, curRow+1, i), sum(triangle, curRow+1, i+1)) + triangle[curRow][i];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return sum(triangle, 0, 0);
    }

//working solution
   int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0] = triangle[0][0];
        for(int i = 1;i<n;i++){
           dp[i][0] = dp[i-1][0] + triangle[i][0];
        }
        for(int i = 1;i<n;i++){
            dp[i][i] = dp[i-1][i-1] + triangle[i][i];
        }
        //  for(int i = 0;i<n;i++){
        //     for(int j = 0;j<=i;j++){
        //         cout<<dp[i][j]<<' ';
        //     }
        //     cout<<'\n';
        // }
        for(int i = 2;i<n;i++){
            for(int j = 1;j<i;j++){
              
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
                
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
       
    }
//zad 22
simpler version
bool canJump(vector<int>& nums) {
        int jump = nums[0];
        int res = nums[0];
        int n = nums.size();
        if(n == 1) return true;

        while(res<nums.size()){
            if(res == nums.size()-1)return true;
            if(nums[res] == 0) return false;
            
            jump = nums[res];
            res += jump;
            
        }
        return true;
    }
//zad 23
bool canJump(vector<int>& nums) {
        int reach = 0;
        for(int i = 0;i<nums.size();i++){
            if(i > reach) return false;
            reach = max(reach, i+nums[i]);
        }
        return true;
    }

//zad 24
 int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(text1[i] == text2[j]) dp[i+1][j+1] = dp[i][j] + 1;
                else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        return dp[n][m];
    }

  int longest(vector<vector<int>>& dp, string text1, string text2, int i, int j){
        if(j<0 || i<0)return 0; 
        if(dp[i][j] != -1)return dp[i][j];
        if(text1[i]==text2[j]) return dp[i][j] = longest(dp, text1, text2, i-1, j-1) + 1;
        else return dp[i][j] = max(longest(dp, text1, text2, i-1, j), longest(dp, text1, text2, i, j-1));
        

    }

//zad 25
longest palindrom
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        string rev = s;
        reverse(rev.begin(), rev.end());
        return longest(dp, s, rev, s.size() - 1, s.size() - 1);
    }


    int longest(int i, int j, string s){
        if(i == j) return 1;
        if (i > j) return 0;
        
        if(s[i] == s[j]) return longest(i+1,j-1, s) + 2;
        else return max(longest(i+1, j, s), longest(i, j-1, s));
    }

int longest(int i, int j, string& s, vector<vector<int>>& dp){
        if(i == j) return 1;
        if (i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]) return dp[i][j] = longest(i+1,j-1, s, dp) + 2;
        else return dp[i][j] = max(longest(i+1, j, s, dp), longest(i, j-1, s, dp));
    }
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return longest(0, s.size() - 1, s, dp);
    }

//zad 26
//how many insertions to transform the string to palindrome?
  int longestPalindrome(vector<vector<int>>& dp, int i, int j, string& s){
        if(i == j) return 1;
        if (i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == s[j]) return dp[i][j] = longestPalindrome(dp, i+1,j-1,s) + 2;
        else return dp[i][j] = max(longestPalindrome(dp, i+1, j,s), longestPalindrome(dp, i, j-1, s));
    }
    int minInsertions(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return s.size() - longestPalindrome(dp, 0, s.size()-1, s);
    }

//zad 27
 int decoder(string s, int i, int cnt){
        if(i == s.length() || i == s.length() - 1) return 1;
        int way = stoi(s.substr(i, cnt));
        if(way < 10 && cnt == 2) return 0;
        return decoder(s,i+1,1) + decoder(s, i+1, 2);
    }
    int numDecodings(string s) {
        return decoder(s, 0, 1);
    }
//better solution
    int numDecodings(string s) {
        if(s.empty() || s[0] == '0') return 0;
        int n = s.length();
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2;i<=n;i++){
            int oneDigit = s[i-1] - '0';
            int twoDigits = stoi(s.substr(i-2,2));

            if(oneDigit != 0){
                dp[i] += dp[i-1];
            }
            if(twoDigits >= 10 && twoDigits<= 26) {
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }

//zad 28
  int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> travel(begin(days), end(days));
        int dp[366] = {};
        for(int i = 1;i<366;i++){
            if(travel.find(i) == travel.end()) dp[i] = dp[i-1];
            else{
                dp[i] = min({ dp[i-1] + costs[0], dp[max(i-7, 0)] + costs[1], dp[max(i-30, 0)] + costs[2]});
            }
            
        }
        return dp[365];
    }
//zad 29
int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 1;i<=m;i++){
           for(int j = 1;j<=n;j++){
            if(nums1[i-1] == nums2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
           }
        }

        return dp[m][n];
    }

//zad 30
int maxProfit(vector<int>& prices) {
       int buy = prices[0];
       int profit=0;
       for(int i = 1;i<prices.size();i++){
        if(prices[i]<buy)buy = prices[i];
       
       else if(
        prices[i]-buy > profit
       ) profit = prices[i] - buy;}
       return profit;
}

//whole profit


    int profit(vector<int>& prices, int i, int has, vector<vector<int>>& dp){
        if(i>=prices.size()) return 0;
        if(dp[i][has] != -1) return dp[i][has];
        if(has){
            return dp[i][has] = max(prices[i] + profit( prices, i+1, 0, dp), profit( prices, i+1, 1, dp));
       
    }
    else{
        return dp[i][has] = max(-prices[i] + profit( prices, i+1, 1, dp) , profit( prices, i+1, 0, dp));
    
    }
    }


//HW
#include <cmath>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;



void parser(const char* line, map<string, set<string>>& mp){
    int n = strlen(line);
    for(int i = 0;i<n;i++){
  
        
        if(line[i] != '<') continue;
        i++;
        if(i<n && line[i] == '/') continue;
        string tag = "";
        while(i<n && line[i] != '>' && line[i] != ' ')tag+=line[i++];
        mp[tag];
        
        while(i<n && line[i] != '>'){
            while(i<n && (line[i] == ' ' || line[i] == '/'))i++;
            if(i>=n || line[i] == '>') break;
            string attr = "";
              while(i<n && line[i] != '>' && line[i] != '=')attr+=line[i++];
            if(!attr.empty())mp[tag].insert(attr);
            if(i<n && line[i] == '='){
                i++;
                if(i<n && (line[i]=='"' || line[i] == '\'')){
                    char quote = line[i++];
                    while(i<n && line[i] != quote)i++;
                    i++;
                } 
                else{
                  while(i<n && line[i] != '>' && line[i] != ' ')i++;
                }
            }
        }
        

    }}



int main() 
{
    int N;
    cin>>N;
    cin.ignore();
    map<string, set<string>> mp;
   
    for(int i = 0;i<N;i++){
        char line[10240];
        cin.getline(line, 10240);
        //cout<<line;
        parser(line, mp);

    }
     for(auto& z : mp){
     cout<<z.first;
        cout<<":";
         bool first = true;
        for(auto s: z.second){
            if(!first) cout<<",";
            cout<<s;
            first = false;}
        
        cout<<'\n';
    }
    return 0;
}
