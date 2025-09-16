class Solution {
public:
    // T.C.=O(n + 200), S.C.=O(200)
    int smallestAbsent(vector<int>& nums) {
        int n = nums.size();
        int avg = 0;
        for(int num: nums)
            avg += num;
        
        // floor val of avg
        avg = avg/n;

        vector<bool> isPresent(201, false);
        int offset = 100;
        for(int num: nums)
            isPresent[num + offset] = true;
        
        for(int i=max(1, avg+1); i<=100; i++)
            if(!isPresent[i + offset])
                return i;

        return 101;
    }
};