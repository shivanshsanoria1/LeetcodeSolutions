class Solution {
public:
    // return true if s1 and s2 needs to be swapped
    bool compare(string& s1, string& s2) {
        return s1 + s2 >= s2 + s1 ? false : true;
    }

    string largestNumber(vector<int>& nums) {
        int zeros = 0;
        vector<string> strNums;
        for(int num: nums)
        {
            if(num == 0)
                zeros++;
            strNums.push_back(to_string(num));
        }
        int n=nums.size();
        // the case where all elements in array are 0
        if(zeros == n) 
            return "0";
        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(compare(strNums[i], strNums[j]))
                    swap(strNums[i], strNums[j]);
        string ans = "";
        for(string& str: strNums)
            ans += str;
        return ans;
    }
};