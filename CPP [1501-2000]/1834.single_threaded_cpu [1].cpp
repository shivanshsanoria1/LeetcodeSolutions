class Solution {
public:
    typedef pair<int, int> PI;

    vector<int> getOrder(vector<vector<int>>& tasks) { // T.C.=O(n*logn), S.C.=O(n)
        vector<int> ans;
        int n = tasks.size();
        vector<vector<int>> sortedTasks; // to store the tasks sorted by ET
        for(int i=0; i<n; i++)
            sortedTasks.push_back({tasks[i][0], tasks[i][1], i}); // {ET, PT, index}
        sort(sortedTasks.begin(), sortedTasks.end()); // sort by ET
        priority_queue<PI, vector<PI>, greater<PI>> pq; // min-heap (by PT)
        long long int t = sortedTasks[0][0]; // start the curr time at the ET of 1st task in line
        int i=0;
        while(i < n)
        {
            // push the tasks with ET <= curr time in heap
            while(i<n && sortedTasks[i][0] <= t)
            {
                pq.push({sortedTasks[i][1], sortedTasks[i][2]}); // {PT, index}
                i++;
            }
            // there is no more task left in heap to process, 
            // so update the curr time with the ET of the next task in line
            if(pq.empty())
            {
                t = sortedTasks[i][0];
                continue;
            }
            // pop a task from heap to process
            auto curr = pq.top();
            pq.pop();
            t += curr.first; // update the curr time by the PT of the just processed task
            ans.push_back(curr.second);
        }
        // no more tasks are left in line, so process all the tasks present in the heap
        while(!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            ans.push_back(curr.second);
        }
        return ans;
    }
};
// tasks[i][0]: Enqueue time (ET)
// tasks[i][1]: Processing time (PT)