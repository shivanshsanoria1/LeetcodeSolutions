class Solution {
public:
    // T.C.=O(n + 100), S.C.=O(100)
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        // num -> freq
        vector<int> freq(101, 0);
        for(int num: nums)
            freq[num]++;
        
        const int INF = int(1e9);
        // freq -> smallest num with this freq
        vector<int> minNum(101, INF);
        for(int i=0; i<=100; i++)
            if(freq[i] > 0 && minNum[freq[i]] == INF)
                minNum[freq[i]] = i;
        
        int min1 = INF, min2 = INF;
        for(int i=0; i<=100; i++){
            if(minNum[i] < min1){
                min2 = min1;
                min1 = minNum[i];
            }else if(minNum[i] < min2)
                min2 = minNum[i];
        }
        
        vector<int> ans(2, -1);
        if(min1 != INF && min2 != INF){
            ans[0] = min1;
            ans[1] = min2;
        }

        return ans;
    }
};