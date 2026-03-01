class Solution {
public:
    // T.C.=O(n + 100^2), S.C.=O(100)
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        vector<int> freq(101, 0);
        for(int num: nums)
            freq[num]++;
        
        for(int i=0; i<=100; i++){
            if(freq[i] == 0)
                continue;
            for(int j=i+1; j<=100; j++){
                if(freq[j] == 0)
                    continue;
                if(freq[i] != freq[j])
                    return {i, j};
            }
        }
        
        return {-1, -1};
    }
};