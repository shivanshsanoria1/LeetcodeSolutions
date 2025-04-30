class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        vector<bool> visited(n, false);
        queue<int> q;
        // video -> freq
        unordered_map<string, int> mp;

        visited[id] = true;
        q.push(id);

        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int curr = q.front();
                q.pop();

                if(level == 0)
                {
                    for(string& video: watchedVideos[curr])
                        mp[video]++;
                    continue;
                }

                for(int nei: friends[curr])
                {
                    if(visited[nei])
                        continue;
                    visited[nei] = true;
                    q.push(nei);
                }
            }
            level--;
        }

        // {freq, video}
        vector<pair<int, string>> pairs;
        for(auto [video, freq]: mp)
            pairs.push_back({freq, video});

        sort(pairs.begin(), pairs.end());

        vector<string> ans;
        for(auto [freq, video]: pairs)
            ans.push_back(video);

        return ans;
    }
};