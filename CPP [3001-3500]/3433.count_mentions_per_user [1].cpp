class Solution {
private:
    static bool cmp(vector<string>& a, vector<string>& b){
        int time_a = stoi(a[1]);
        int time_b = stoi(b[1]);

        return (time_a == time_b && a[0] != b[0]) ? a[0] == "OFFLINE" : time_a < time_b;
    }

    void updateCounts(vector<int>& mentionCounts, string& ids){
        string curr = "";
        ids += " ";

        for(char ch: ids)
        {
            if(ch == ' ')
            {
                int id = stoi(curr.substr(2));
                curr = "";
                mentionCounts[id]++;
            }
            else
                curr += ch; 
        }

        ids.pop_back();
    }

public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        // sort in increasing order of timestamps and 
        // sort all the OFFLINE events before all the MESSAGE events for the same timestamp
        sort(events.begin(), events.end(), cmp);
        // time at which the ith user became ONLINE
        vector<int> onlineTimes(numberOfUsers, 0);
        // num of times the ith user is mentioned
        vector<int> mentionCounts(numberOfUsers, 0);
        // num of events where ALL the users were mentioned
        int allCount = 0;

        for(vector<string>& event: events)
        {
            int time = stoi(event[1]);

            if(event[0] == "OFFLINE")
            {
                int id = stoi(event[2]);
                onlineTimes[id] = time + 60;
                continue;
            }

            // event[0] == "MESSAGE"

            string ids = event[2];
            if(ids == "ALL") // all the users
                allCount++;
            else if(ids == "HERE") // online users
            {
                for(int i=0; i<numberOfUsers; i++)
                    if(onlineTimes[i] <= time)
                        mentionCounts[i]++;
            }
            else // only particular users
                updateCounts(mentionCounts, ids);
        }

        if(allCount > 0)
            for(int& mentionCount: mentionCounts)
                mentionCount += allCount;

        return mentionCounts;
    }
};