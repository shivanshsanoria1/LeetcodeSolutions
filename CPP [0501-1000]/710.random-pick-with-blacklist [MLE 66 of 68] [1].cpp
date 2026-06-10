class Solution {
private:
    unordered_set<int> s;
    vector<int> nums;

public:
    Solution(int n, vector<int>& blacklist) {
        this->s.clear();
        this->nums.clear();

        for(int i=0; i<n; i++)
            this->s.insert(i);

        for(int num: blacklist)
            this->s.erase(num);
        
        for(int num: s)
            this->nums.push_back(num);
        
        srand(time(0));
    }
    
    int pick() {
        int randIdx = rand() % nums.size();
        return nums[randIdx];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */