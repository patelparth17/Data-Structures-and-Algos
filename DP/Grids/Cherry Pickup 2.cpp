// You are given a rows x cols matrix grid representing a field of cherries where grid[i][j] represents the number of cherries that you can collect from the (i, j) cell.

// You have two robots that can collect cherries for you:

// Robot #1 is located at the top-left corner (0, 0), and
// Robot #2 is located at the top-right corner (0, cols - 1).
// Return the maximum number of cherries collection using both robots by following the rules below:

// From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
// When any robot passes through a cell, It picks up all cherries, and the cell becomes an empty cell.
// When both robots stay in the same cell, only one takes the cherries.
// Both robots cannot move outside of the grid at any moment.
// Both robots should reach the bottom row in grid.

class Solution {
public:
    int f(int i,int j1,int j2,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp)   
    {
        int rows=grid.size();
        int cols=grid[0].size();
        
        if(j1<0 || j1==cols || j2<0 || j2==cols)    //Out of bound conditions for the columns as i will never go out of bounds
            return 0;
        
        if(i==rows-1)                             //At the last row,
        {
            if(j1==j2)                            //if both have reached the same cell, return the cell.
                return grid[i][j1];
            else
                return grid[i][j1]+grid[i][j2];   //else return their sum.
        }
        
        if(dp[i][j1][j2]!=-1)
            return dp[i][j1][j2];
            
        int mx=INT_MIN;
        for(int dj1=-1;dj1<=1;dj1++)            //For 1 movement of robot 1,
        {
            for(int dj2=-1;dj2<=1;dj2++)        //there can be 3 movements of robot 2 at -1,0 and 1.
            {
                if(j1==j2)
                    mx=max(mx,grid[i][j1]+f(i+1,j1+dj1,j2+dj2,grid,dp));              //these conditions are same as base condition; just return their max as ans.
                else
                    mx=max(mx,grid[i][j1]+grid[i][j2]+f(i+1,j1+dj1,j2+dj2,grid,dp));
            }
        }
        
        return dp[i][j1][j2]=mx;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        vector<vector<vector<int>>> dp(rows,vector<vector<int>>(cols,vector<int>(cols,-1)));   //As 3 variables are changing,a 3D array is required.
        
        return f(0,0,cols-1,grid,dp);   //As both robots are moving simultaneously in the grid row-wise, we maintain only 1 pointer for both of them.
                                        //But column-wise, one starts moving from col 0 while other from col n-1 so different pointers.
    }
};
