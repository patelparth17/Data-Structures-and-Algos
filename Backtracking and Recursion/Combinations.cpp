// Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].

// You may return the answer in any order.

 

// Example 1:

// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]

class Solution {
public:
    void fun(int k,int n,vector<int> &ds,vector<vector<int>> &ans)
    {
        if(n<k)     //This is an invalid condition so return if it occurs.
            return;
        if(k==0)    //Push the ds into the ans vector when you hit k.
        {
            ans.push_back(ds);
            return;
        }
        ds.push_back(n);
        fun(k-1,n-1,ds,ans);    //decrease k if the element is taken in the ds.
        
        ds.pop_back();
        fun(k,n-1,ds,ans);      //do not decrease k when the element is not taken in the ds.
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> ds;
        
        fun(k,n,ds,ans);
        
        return ans;
    }
};
