class Solution {
private:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[3] < b[3];
    }

public:
    // T.C.=O(n*log(n)), S.C.=O(n)
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();

        vector<vector<int>> robots;
        for(int i=0; i<n; i++)
        {
            vector<int> robot(4);

            robot[0] = positions[i];
            robot[1] = directions[i] == 'R' ? 1 : -1;
            robot[2] = healths[i];
            robot[3] = i;

            robots.push_back(robot);
        }

        // sort in increasing order of position
        sort(robots.begin(), robots.end());

        // contains indexes of elements in robots[]
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            // robots moving in right direction are simply pushed in stack
            if(robots[i][1] == 1)
            {
                st.push(i);
                continue;
            }

            // at this point curr-robot is moving in left-direction

            // robot at stack-top is destroyed and the 
            // health of curr-robot is decremented by 1 in each step
            while(!st.empty() && robots[i][2] > robots[st.top()][2])
            {
                robots[st.top()][2] = 0;
                robots[i][2]--;
                st.pop();
            }

            // curr-robot will not collide with anyone else
            if(st.empty())
                continue;

            // curr-robot is destroyed and health of robot at stack-top is decrementd by 1
            if(robots[i][2] < robots[st.top()][2])
            {
                robots[i][2] = 0;
                robots[st.top()][2]--;
            }
            // both the curr-robot and robot at stack-top are destroyed
            else // robots[i][2] == robots[st.top()][2]
            {
                robots[i][2] = 0;
                robots[st.top()][2] = 0;
                st.pop();
            }
        }

        // sort in increasing order of original index 
        sort(robots.begin(), robots.end(), cmp);

        // add the robots whose health > 0 in ans[]
        vector<int> ans;
        for(int i=0; i<n; i++)
            if(robots[i][2] > 0)
                ans.push_back(robots[i][2]);

        return ans;
    }
};
// collision happens when robot at stack-top and curr-robot 
// are moving in right and left directions respectively