// Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). 
// Find all possible paths that the rat can take to reach from source to destination. 
// The directions in which the rat can move are 'U'(up), 'D'(down), 'L' (left), 'R' (right). 
// Value 0 at a cell in the matrix represents that it is blocked and rat cannot move to it while value 1 at a cell in the matrix represents that rat can be travel through it.
// Note: In a path, no cell can be visited more than one time. If the source cell is 0, the rat cannot move to any other cell.

// Example 1:

// Input:
// N = 4
// m[][] = {{1, 0, 0, 0},
//          {1, 1, 0, 1}, 
//          {1, 1, 0, 0},
//          {0, 1, 1, 1}}
// Output:
// DDRDRR DRDDRR
// Explanation:
// The rat can reach the destination at 
// (3, 3) from (0, 0) by two paths - DRDDRR 
// and DDRDRR, when printed in sorted order 
// we get DDRDRR DRDDRR.

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i,int j,vector<vector<int>> &m,vector<string> &ans,string &path,int n)
    {
        if(i==n-1 && j==n-1)
        {
            ans.push_back(path);
            return;
        }
        
        //Down
        if(i+1<n && m[i+1][j]==1)
        {
            m[i][j]=0;          //Block the point as it should not be travelled again.
            path+="D";
            solve(i+1,j,m,ans,path,n);
            path.pop_back();    
            m[i][j]=1;          //Unblock the point.
        }
        
        //Left
        if(j-1>=0 && m[i][j-1]==1)
        {
            m[i][j]=0;
            path+="L";
            solve(i,j-1,m,ans,path,n);
            path.pop_back();
            m[i][j]=1;
        }
        
        //Right
        if(j+1<n && m[i][j+1]==1)
        {
            m[i][j]=0;
            path+="R";
            solve(i,j+1,m,ans,path,n);
            path.pop_back();
            m[i][j]=1;
        }
        
        //Up
        if(i-1>=0 && m[i-1][j]==1)
        {
            m[i][j]=0;
            path+="U";
            solve(i-1,j,m,ans,path,n);
            path.pop_back();
            m[i][j]=1;
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        string path="";
        
        if(m[0][0]==0)
        {
            path+="-1";
            ans.push_back(path);
        }
        
        else
        solve(0,0,m,ans,path,n);
        
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
