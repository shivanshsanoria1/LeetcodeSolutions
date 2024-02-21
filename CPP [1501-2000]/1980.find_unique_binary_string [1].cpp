class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) { //n == nums.length == nums[i].length
        string ans="";
        int n=nums[0].length();
        for(int i=0; i<n; i++) //diagonalization
            ans+=nums[i][i]=='0' ? '1' : '0'; //flip the diagonal bits of each string to get a new string
        return ans;
    }
};