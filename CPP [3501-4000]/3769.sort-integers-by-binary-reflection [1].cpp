class Solution {
private:
    string decToBinStr(int num){
        string binStr = "";
        for(; num > 0; num /= 2)
            binStr += to_string(num % 2);
        
        reverse(binStr.begin(), binStr.end());

        return binStr;
    }

    int binStrToRevInt(string binStr){
        int num = 0;
        int mul = 1;
        for(char bit: binStr){
            num += (bit - '0') * mul;
            mul *= 2;
        }

        return num;
    }

public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    vector<int> sortByReflection(vector<int>& nums) {
        // {reflected num, num}
        vector<pair<int, int>> pairs;
        for(int num: nums)
            pairs.push_back({binStrToRevInt(decToBinStr(num)), num});
        
        sort(pairs.begin(), pairs.end());

        vector<int> ans;
        for(auto [reflected, num]: pairs)
            ans.push_back(num);
        
        return ans;
    }
};