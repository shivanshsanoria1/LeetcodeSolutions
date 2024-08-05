class Solution {
private:
    // returns true if there is an element in nums[] 
    // in range [qStart, qEnd]
    bool isFound(vector<int>& nums, int qStart, int qEnd){
        int left = 0, right = nums.size()-1;

        while(left <= right)
        {
            int mid = left + (right - left)/2;

            if(nums[mid] < qStart)
                left = mid + 1;
            else if(nums[mid] > qEnd)
                right = mid - 1;
            else
                return true;
        }

        return false;
    }

public:
    // T.C.=O(l + n*log(l) + q*n*log(l)), S.C.=O(l)
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        vector<vector<int>> serverTimes(n+1);
        for(vector<int>& log: logs)
        {
            int id = log[0];
            int time = log[1];
            serverTimes[id].push_back(time);
        }

        for(vector<int>& times: serverTimes)
            sort(times.begin(), times.end());
        
        vector<int> ans;
        for(int query: queries)
        {
            int qStart = query - x;
            int qEnd = query;
            
            // servers that did not receive any requests in time [start, end]
            int zeros = n;
            for(int id=1; id<=n; id++)
                if(isFound(serverTimes[id], qStart, qEnd))
                    zeros--;
            
            ans.push_back(zeros);
        }

        return ans;
    }
};