class Solution {
private:
    // returns majority element and its freq
    pair<int, int> findMajorityElement(vector<int>& nums){
        unordered_map<int, int> mp;
        for(int num: nums)
            mp[num]++;

        for(auto [num, freq]: mp)
            if(freq*2 > nums.size())
                return {num, freq};

        return {-1, -1};
    }

public:
    // T.C.=O(n), S.C.=O(n)
    int minimumIndex(vector<int>& nums) {
        auto [majority, majorityFreq] = findMajorityElement(nums);

        int n=nums.size();
        // freq of 'majority' in left-partition [0, i]
        int freqLeft = 0;
        // freq of 'majority' in right-partition [i+1, n-1]
        int freqRight = majorityFreq;

        for(int i=0; i<n-1; i++)
        {
            if(nums[i] != majority)
                continue;
            
            freqLeft++;
            freqRight--;

            if(freqLeft*2 > i+1 && freqRight*2 > n-i-1)
                return i;
        }

        return -1;
    }
};
/*
# the element which is the majority-element in nums[] 
  must also be the majority-element in left and right partitions
# num of elements in left-partition [0, i] = i-0+1 = i+1
# num of elements in right-partition [i+1, n-1] = (n-1) - (i+1) + 1 = n-i-1

# prerequisite: [169. majority-element]
*/