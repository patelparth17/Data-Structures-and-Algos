// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

// A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

// Example 1:

// Input: digits = "23"
// Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

class Solution {
public:
    void fun(int ind,string &s,vector<string> &ans,string digits)
    {
        int n=digits.length();
        if(ind==n)
        {
            ans.push_back(s);
            return;
        }
        
      //try input "729" for better understanding.
        string k="";      //here the gist of the problem is to process the letters of the next index in the recursive call and not the main call.
        
            if(digits[ind]=='2')
                k="abc";
            else if(digits[ind]=='3')
                k="def";
            else if(digits[ind]=='4')
                k="ghi";
            else if(digits[ind]=='5')
                k="jkl";
            else if(digits[ind]=='6')
                k="mno";
            else if(digits[ind]=='7')
                k="pqrs";
            else if(digits[ind]=='8')
                k="tuv";
            else
                k="wxyz";
        
        int m=k.length();
        for(int i=0;i<m;i++)    //For each letter of the formed string, make the recursive call.
        {
            s+=k[i];
            fun(ind+1,s,ans,digits);
            s.pop_back();
        }
       
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length()==0)
            return ans;
        string s="";
        fun(0,s,ans,digits);
        return ans;
    }
};
