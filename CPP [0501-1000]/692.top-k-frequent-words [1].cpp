class Solution {
private:
    struct MyCmp{
        bool operator() (const pair<int,string>& x, const pair<int,string>& y)
        {
            if(x.first == y.first)
                return x.second > y.second;
            return x.first < y.first;
        }
    };
    
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp; //string -> freq
        for(string s: words) //find freq of each string
            mp[s]++;
        priority_queue< pair<int,string>, vector<pair<int,string>>, MyCmp > pq; //priority queue with FIFO using comparator
        for(auto it: mp) //push freq -> string in priority queue
            pq.push({it.second,it.first});
        vector<string> ans;
        while(k--) //take out k elements from priority queue
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};