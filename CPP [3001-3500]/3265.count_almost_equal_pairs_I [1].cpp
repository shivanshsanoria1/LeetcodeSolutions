class Solution {
private:
    bool areAlmostEqual(int n1, int n2){
        if(n1 == n2)
            return true;

        // convert the nums n1 and n2 to string
        string s1 = to_string(n1);
        string s2 = to_string(n2);

        // finding the num of leading-zeros needed 
        // to make the strings equal in length
        int leadingZerosCount = abs((int)s1.length() - (int)s2.length());
        string leadingZeros = string(leadingZerosCount, '0');

        // append leading-zeros to the smaller string
        // to make the strings equal in length
        if(s1.length() < s2.length())
            s1 = leadingZeros + s1;
        else if(s1.length() > s2.length())
            s2 = leadingZeros + s2;

        // both strings s1 and s2 must have the same chars
        vector<int> freq(10, 0);
        for(char ch: s1)
            freq[ch - '0']++;
        for(char ch: s2)
            freq[ch - '0']--;

        for(int i=0; i<=9; i++)
            if(freq[i] != 0)
                return false;

        // only 2 mismatches are allowed so that the chars 
        // at those 2 positions can be swapped 
        // to make the strings s1 and s2 equal
        int mismatches = 0;
        for(int i=0; i<s1.length(); i++)
            if(s1[i] != s2[i])
                mismatches++;

        return mismatches == 2;
    }

public:
    // T.C.=O(n^2), S.C.=O(1)
    int countPairs(vector<int>& nums) {
        int n=nums.size();
        int count = 0;
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(areAlmostEqual(nums[i], nums[j]))
                    count++;
        
        return count;
    }
};