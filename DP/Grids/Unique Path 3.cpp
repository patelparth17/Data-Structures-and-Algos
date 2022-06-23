// You are given an m x n integer array grid where grid[i][j] could be:

// 1 representing the starting square. There is exactly one starting square.
// 2 representing the ending square. There is exactly one ending square.
// 0 representing empty squares we can walk over.
// -1 representing obstacles that we cannot walk over.
// Return the number of 4-directional walks from the starting square to the ending square, that walk over every non-obstacle square exactly once.

class Solution {
public:
    int f(int i,int j,int starti,int startj,int invalid,vector<vector<int>> &grid,int cnt)
    {
        int m=grid.size();
        int n=grid[0].size();
        
        if(i<0 || j<0 || i>=m || j>=n)    //Returning invalid path
            return 0;
        
        if(grid[i][j]==-1)    //Invalid Path
            return 0;
        
        if(i==starti && j==startj)
        {
            if(cnt==m*n-invalid-1)    //If all available blocks are travelled and start point is reached, return 1.
                return 1;
            else
                return 0;
        }
        
        grid[i][j]=-1;    //Block the point indicating that the current point should not be traversed again by it's neoghbours.
        cnt++;            //Increase the cnt indicating the current point is taken into consideration.
        int up=0;
        int down=0;
        int left=0;
        int right=0;
        
        up=f(i-1,j,starti,startj,invalid,grid,cnt);
        right=f(i,j+1,starti,startj,invalid,grid,cnt);
        down=f(i+1,j,starti,startj,invalid,grid,cnt);
        left=f(i,j-1,starti,startj,invalid,grid,cnt);
        grid[i][j]=0;   //Unblock the current point after traversing all the neighbours.
        return up+down+left+right;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int starti,startj,endi,endj;
        int invalid=0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    starti=i;
                    startj=j;
                }
                if(grid[i][j]==2)
                {
                    endi=i;
                    endj=j;
                }
                if(grid[i][j]==-1)
                {
                    invalid++;    //count the number of blocks 
                }
            }
        }
        return f(endi,endj,starti,startj,invalid,grid,0);
    }
};
