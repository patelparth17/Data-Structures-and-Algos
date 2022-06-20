class Solution {
public:
    void fun(int ind,int n,vector<int> &ds,vector<vector<int>> &ans,vector<int> candidates,int target)
    {
        if(ind==n)
        {
            if(target==0)
            {
                ans.push_back(ds);
            }
            return;
        }
        
        if(candidates[ind]<=target)
        {
            ds.push_back(candidates[ind]);
            fun(ind,n,ds,ans,candidates,target-candidates[ind]);
            ds.pop_back();
        }
        
        fun(ind+1,n,ds,ans,candidates,target);
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int n=candidates.size();
        fun(0,n,ds,ans,candidates,target);
        return ans;
    }
};