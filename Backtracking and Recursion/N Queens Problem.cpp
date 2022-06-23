// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

 

// Example 1:


// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
// Example 2:

// Input: n = 1
// Output: [["Q"]]

class Solution {
public:
    
//      Recursion method :
    
//     bool isSafe(int row,int col,int n,vector<string> board)
//     {
//         int dupcol=col;
//         int duprow=row;
        
//         while(dupcol>=0)     //Check for queens present in the left of row
//         {
//             if(board[duprow][dupcol]=='Q')
//                 return false;
//             dupcol--;
//         }
        
//         dupcol=col;
//         duprow=row;
        
//         while(dupcol>=0 && duprow>=0)    //Check for queens present in the upper left diagonal of row
//         {
//             if(board[duprow][dupcol]=='Q')
//                 return false;
//             dupcol--;
//             duprow--;
//         }
        
//         dupcol=col;
//         duprow=row;
        
//         while(dupcol>=0 && duprow<n)   //Check for queens present in the lower right diagonal of row
//         {
//             if(board[duprow][dupcol]=='Q')
//                 return false;
//             dupcol--;
//             duprow++;
//         }
//         return true;
//     }
//     void solve(int col,int n,vector<string> &board,vector<vector<string>> &ans)
//     {
//         if(col==n)
//         {
//             ans.push_back(board);
//             return;
//         }
        
//         for(int row=0;row<n;row++)
//         {
//             if(isSafe(row,col,n,board))
//             {
//                 board[row][col]='Q';   //If the Queen is safe to place,place it.
//                 solve(col+1,n,board,ans);  //call for the next columns
//                 board[row][col]='.';   //Remove the placed Queen which is a backtracking step.
//             }
//         }
//     }
    
    //Mapping method to reduce the TC :
    
    void solve(int col,int n,vector<int> &leftrow,vector<int> &lowerdiagonal,vector<int> &upperdiagonal,vector<string> &board,vector<vector<string>> &ans)
    {
        if(col==n)
        {
            ans.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(leftrow[row]==0 && lowerdiagonal[row+col]==0 && upperdiagonal[n-1 + col-row]==0) // Indicates there is no queen present in the left, lower left diagonal and upper left diagonal of the row 
            {
                leftrow[row]=1;
                lowerdiagonal[row+col]=1;
                upperdiagonal[n-1 + col-row]=1;
                board[row][col]='Q';    //Push the queen into the board and set all previous conditions to true.
                solve(col+1,n,leftrow,lowerdiagonal,upperdiagonal,board,ans);   //Now check for other columns
                leftrow[row]=0;         //Now remove the queen from the board and reset all the conditions to false.
                lowerdiagonal[row+col]=0;
                upperdiagonal[n-1+ col-row]=0;
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        
        for(int i=0;i<n;i++)
            board[i]=s;
        
        vector<int> leftrow(n,0),lowerdiagonal(2*n-1,0),upperdiagonal(2*n-1,0);
        solve(0,n,leftrow,lowerdiagonal,upperdiagonal,board,ans);
        return ans;
    }
};
