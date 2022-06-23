// Given a triangle array, return the minimum path sum from top to bottom.

// For each step, you may move to an adjacent number of the row below. 
// More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

// Example 1:

// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

class Solution {
public:
  
//   Recursion + Memorization :
  
//     int f(int ind,int level,vector<vector<int>> triangle,vector<vector<int>> &dp)
//     {
//         int n=triangle.size();
//         if(level==n-1)
//             return triangle[level][ind];
        
//         if(dp[level][ind]!=-1)
//             return dp[level][ind];
        
//         int left=f(ind,level+1,triangle,dp);
//         int right=f(ind+1,level+1,triangle,dp);
//         return dp[level][ind]=triangle[level][ind] + min(left,right);
        
        
//     }
    int minimumTotal(vector<vector<int>>& triangle) {
      
//       Space Optimization :
      
        int n=triangle.size();
        vector<int> front(n,0);
        vector<int> curr(n,0);
        
        for(int j=0;j<n;j++)
            front[j]=triangle[n-1][j];
        
        for(int i=n-2;i>=0;i--)   //Loops run inverse of the function calls to recursion
        {
            for(int j=i;j>=0;j--)   //Key is to start from i due to the triangle property
            {
                if(i==n-1)
                    front[j]=triangle[i][j];
                else
                {
                    int left=INT_MAX,right=INT_MAX;
                    if(i<n-1)     left=front[j];
                    if(i<n-1 && j<n-1)     right=front[j+1];
                    curr[j]=triangle[i][j] + min(left,right);
                }
            }
            front=curr;
        }
        return front[0];
    }
};
