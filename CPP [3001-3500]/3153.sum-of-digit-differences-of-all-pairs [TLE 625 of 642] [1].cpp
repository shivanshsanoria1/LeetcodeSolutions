class Solution {
private:
    // returns the num of positions where 
    // the digits of num1 and num2 don't match
    int getDigitDiffCount(int num1, int num2){
        string s1 = to_string(num1);
        string s2 = to_string(num2);

        int count = 0;
        
        for(int i=0; i<s1.length(); i++)
            if(s1[i] != s2[i])
                count++;
        
        return count;
    }

public:
    // T.C.=O(n^2), S.C.=O(1)
    long long sumDigitDifferences(vector<int>& nums) {
        int n=nums.size();
        long long int count = 0;

        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                count += getDigitDiffCount(nums[i], nums[j]);
        
        return count;
    }
};