class Solution {
private:
    // num -> { index }
    unordered_map<int, vector<int>> mp;

public:
    Solution(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++)
            this->mp[nums[i]].push_back(i);
        
        // use the current time as seed for random generator 
        srand(time(0));
    }
    
    int pick(int target) {
        // size of array containing the indexes of each occurence
        // of 'target' in the original input array 'nums'
        int N = this->mp[target].size();
        // get a random value in range [0, N-1] (both inclusive)
        int randIdx = rand() % N;
        // return the index value at the generated random index
        return this->mp[target][randIdx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */