class Solution {
public:
    // T.C.=O(), S.C.=O(1)
    vector<int> sequentialDigits(int low, int high) {
        string digs = "123456789";
        int lenLow = to_string(low).length();
        int lenHigh = to_string(high).length();
        vector<int> ans;
        for(int i=lenLow; i<=lenHigh; i++)
        {
            int left = 0, right = i-1;
            while(right < 9)
            {
                int num = stoi(digs.substr(left, right - left + 1));
                if(num > high)
                    break;
                if(num >= low)
                    ans.push_back(num);
                left++;
                right++;
            }
        }
        return ans;
    }
};