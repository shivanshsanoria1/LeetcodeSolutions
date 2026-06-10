class Solution {
private:
    bool isSequential(int n){
        int prev = -1;
        while(n > 0)
        {
            if(prev != - 1 && n % 10 != prev - 1)
                return false;
            prev = n % 10;
            n /= 10;
        }
        return true;
    }

public:
    // T.C.=O(10*(high - low)), S.C.=O(1)
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=low; i<=high; i++)
            if(isSequential(i))
                ans.push_back(i);
        return ans;
    }
};