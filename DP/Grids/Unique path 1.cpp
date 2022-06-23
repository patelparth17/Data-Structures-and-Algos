// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). 
// The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
// The robot can only move either down or right at any point in time.

// Given the two integers m and n, 
// return the number of possible unique paths that the robot can take to reach the bottom-right corner.

//Why DP and not Greedy?
//Because there maybe optimal paths in the future which Greedy would miss if it goes with current optimal path.

// Why DP and not Recusrsion?
// Because in Grid problems, there maybe the overlapping problem of a cell which is visited by a function 
// and will again be visited by another function in the future so store the cell's value.

class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m,vector<int> (n,-1));
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)        //Base Case of recursion
                    dp[i][j]=1;
                else
                {
                    int up=0,left=0;
                    if(i>0)     up=dp[i-1][j];      //Doing stuffs on the index
                    if(j>0)     left=dp[i][j-1];
                    dp[i][j]=up+left;               //As we are told to count all paths,so adding the paths
                                                    //which we got from travelling up and left.
                }
            }
        }
        return dp[m-1][n-1];
    }
};