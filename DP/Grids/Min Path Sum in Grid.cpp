// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.

 

// Example 1:


// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

class Solution {
public:
//   Recursive + Memorized Solution :
//     int f(int i,int j,vector<vector<int>> grid,vector<vector<int>> dp)
//     {
//         if(i==0 && j==0)
//             return grid[0][0];
        
//         if(dp[i][j]!=-1)    return dp[i][j];
        
//         int up=INT_MAX,left=INT_MAX;
//         if(i>0)     up=f(i-1,j,grid,dp);
//         if(j>0)     left=f(i,j-1,grid,dp);
        
//         return dp[i][j]=grid[i][j]+min(up,left);
//     }
  
  
    int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();
//         vector<vector<int>> dp(m,vector<int> (n,-1));
//         dp[0][0]=1;
//         return f(m-1,n-1,grid,dp);
      
//       Tabulation :
      int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,-1));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    dp[i][j]=grid[0][0];
                else
                {
                    int up=INT_MAX,left=INT_MAX;
                    if(i>0)     up=dp[i-1][j];
                    if(j>0)     left=dp[i][j-1];
                    dp[i][j]=grid[i][j]+min(up,left);
                }
            }
        }
        return dp[m-1][n-1];
      
    }
};
