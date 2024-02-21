class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end(), greater<int>());
        int ans = 0;
        for(int i=0; i<tasks.size(); i += 4)
            ans = max(ans, processorTime[i/4] + tasks[i]);
        return ans;
    }
};