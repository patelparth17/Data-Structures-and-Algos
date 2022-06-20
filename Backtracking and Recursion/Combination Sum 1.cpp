// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

// It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

 

// Example 1:

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.
// Example 2:

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]

class Solution {
public:
    void fun(int ind,int n,vector<int> &ds,vector<vector<int>> &ans,vector<int> candidates,int target)
    {
        if(ind==n)
        {
            if(target==0)
            {
                ans.push_back(ds);  //print the data structure as it contains all the elements of the target.
            }
            return;
        }
        
        if(candidates[ind]<=target)
        {
            ds.push_back(candidates[ind]);      //This can be a potential member as it's value is less than target, push it into a data structure.
            fun(ind,n,ds,ans,candidates,target-candidates[ind]);    //Repetition : As repetition is allowed, call for the same index again.
            ds.pop_back();                      //As this value is processes alongwith it's children, pop it from the data structure.
        }

        
        fun(ind+1,n,ds,ans,candidates,target);      //No repetition : Now look for those indices which do not contain the index element 
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n=candidates.size();
        fun(0,n,ds,ans,candidates,target);
        return ans;
    }
};
