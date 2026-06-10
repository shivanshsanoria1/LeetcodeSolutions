class Solution {
public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n=values.size();

        // max-heap; {value, label}
        priority_queue<pair<int, int>> pq;
        for(int i=0; i<n; i++)
            pq.push({values[i], labels[i]});
        
        // label -> freq
        unordered_map<int, int> mp;
        int sum = 0;
        while(!pq.empty() && numWanted > 0)
        {
            auto [value, label] = pq.top();
            pq.pop();

            mp[label]++;
            if(mp[label] <= useLimit)
            {
                sum += value;
                numWanted--;
            }
        }

        return sum;
    }
};