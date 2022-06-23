// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). : Fixed starting point
// The robot tries to move to the bottom-right corner (i.e., grid[m-1][n-1]). The robot can only move either down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

class Solution {
public:
//     int f(int i,int j,vector<vector<int>> obstacleGrid,vector<vector<int>> dp)
//     {
//         if(i>=0 && j>=0 && obstacleGrid[i][j]==1)    //If obstacle exists, don't count the path
//             return 0;
//         if(i==0 && j==0)
//             return 1;
//         if(i<0 || j<0)
//             return 0;
//         if(dp[i][j]!=-1)    return dp[i][j];
//         int left=f(i,j-1,obstacleGrid,dp);
//         int up=f(i-1,j,obstacleGrid,dp);
//         return dp[i][j]=left+up;
//     }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      
//       Recursion + Memorization :
//         int m=obstacleGrid.size();
//         int n=obstacleGrid[0].size();
//         vector<vector<int>> dp(m,vector<int>(n,-1));
        
//         return f(m-1,n-1,obstacleGrid,dp);
      
//       Tabulation :
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i>=0 && j>=0 && obstacleGrid[i][j]==1)
                    dp[i][j]=0;
                else if(i==0 && j==0)
                    dp[i][j]=1;
                else
                {
                    int left=0,up=0;
                    if(j>0)     left=dp[i][j-1];
                    if(i>0)     up=dp[i-1][j];
                    dp[i][j]=left+up;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
