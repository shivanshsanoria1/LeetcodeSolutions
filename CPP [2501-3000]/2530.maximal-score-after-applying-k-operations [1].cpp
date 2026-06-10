class Solution {
public:
    // T.C.=O((n + k)*log(n)), S.C.=O(n)
    long long maxKelements(vector<int>& nums, int k) {
        // max-heap
        priority_queue<int> pq(nums.begin(), nums.end());
        long long int score = 0;

        while(k--)
        {
            int maxVal = pq.top();
            pq.pop();

            score += maxVal;

            if(maxVal == 1)
                return score + k;
            
            pq.push(maxVal/3 + (maxVal % 3 == 0 ? 0 : 1));
        }

        return score;
    }
};

// ceil(x/3) = x/3 + (x % 3 == 0 ? 0 : 1)