class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        priority_queue<int> pq; // max-heap
        for(int i=0; i<n; i++)
            pq.push(abs(nums1[i] - nums2[i]));
        
        int k = k1 + k2;
        while(k > 0 && !pq.empty())
        {
            int diff = pq.top();
            pq.pop();

            diff--;
            k--;

            if(diff > 0)
                pq.push(diff);
        }

        long long int sum = 0;
        while(!pq.empty())
        {
            int diff = pq.top();
            pq.pop();

            sum += (long long int)diff * diff;
        }

        return sum;
    }
};