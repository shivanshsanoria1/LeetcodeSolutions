class Solution {
private:
    int getMappedNum(vector<int>& mapping, int num){
        if(num == 0)
            return mapping[0];

        int mappedNum = 0;
        int mul = 1;
        while(num > 0)
        {
            mappedNum += mul * mapping[num % 10];
            mul *= 10;
            num /= 10;
        }

        return mappedNum;
    }

public:
    // T.C.=O(n*log(n)), S.C.=O(1)
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        stable_sort(nums.begin(), nums.end(), [&](int a, int b){
            return getMappedNum(mapping, a) < getMappedNum(mapping, b);
        });

        return nums;
    }
};