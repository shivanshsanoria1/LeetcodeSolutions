class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int sum=0;
        vector<int> vec(101,0);
        for(int i=0; i<nums.size(); i++)
            vec[nums[i]]++;
        for(int i=1; i<101; i++)
            if(vec[i] == 1)
                sum+=i;
        return sum;
    }
};