class Solution {
public:
    // T.C.=O(n + 1000), S.C.=O(1000)
    bool canBeEqual(vector<int>& target, vector<int>& arr) { 
        vector<int> freq(1001, 0);

        for(int num: arr)
            freq[num]++;

        for(int num: target)
            if(--freq[num] < 0)
                return false;

        for(int i=1; i<=1000; i++)
            if(freq[i] != 0)
                return false;
        
        return true;
    }
};