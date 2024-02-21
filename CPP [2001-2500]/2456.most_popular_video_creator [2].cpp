class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        // creator -> {total views, views of highest rated video, id of highest rated video}
        unordered_map<string, tuple<long long int, int, string>> mp;

        for(int i=0; i<creators.size(); i++)
        {
            if(mp.find(creators[i]) != mp.end()) // creator already exists
            {
                int& maxVideoViews = get<1>(mp[creators[i]]);
                string& videoId = get<2>(mp[creators[i]]);
                // new video with max views found
                if(views[i] > maxVideoViews)
                {
                    // update the max video views
                    maxVideoViews = views[i];
                    // update the video id
                    videoId = ids[i];
                }
                // another video with max views found and has lexicographically
                // smaller id than the previous video
                else if(views[i] == maxVideoViews && ids[i] < videoId)
                    // update the video id
                    videoId = ids[i];
            }
            else // new creator
                // assign the first video views and id to its creator
                mp[creators[i]] = make_tuple(0, views[i], ids[i]);

            // add curr video views to the creator's total views
            get<0>(mp[creators[i]]) += views[i];
        }

        vector<vector<string>> ans;
        int maxViews = 0;
        for(auto [creator, tup]: mp)
        {
            long long int totalViewsOfCreator = get<0>(tup);
            string maxViewVideoId = get<2>(tup);
            // new max views creator found
            if(totalViewsOfCreator > maxViews)
            {
                // update the max views
                maxViews = totalViewsOfCreator;
                // clear the final creators list
                ans.clear();
                // add this creator to ans
                ans.push_back({creator, maxViewVideoId});
            }
            // another max views creator found
            else if(totalViewsOfCreator == maxViews)
                // add this creator to ans
                ans.push_back({creator, maxViewVideoId});
        }

        return ans;
    }
};
// using tuple