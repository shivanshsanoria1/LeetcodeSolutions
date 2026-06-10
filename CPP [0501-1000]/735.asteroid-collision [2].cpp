class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) { // T.C.=O(n), S.C.=O(n)
        vector<int> ans;
        stack<int> st; // contains only -ive value asteroids 
        for(int i=asteroids.size()-1; i>=0; i--)
        {
            // push the -ive value asteroids in stack
            if(asteroids[i] < 0)
            {
                st.push(asteroids[i]);
                continue;
            }
            // pop all the -ive value asteroids with abs value < curr +ive asteroid value
            while(!st.empty() && abs(st.top()) < asteroids[i])
                st.pop();
            // curr +ive value asteroid survives
            if(st.empty())
            {
                ans.push_back(asteroids[i]);
                continue;
            }
            // curr +ive value does not asteroid survive
            // equal value -ive asteroid is destroyed
            if(abs(st.top()) == asteroids[i])
                st.pop();
        }
        int idx = ans.size(); // index after the last index
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        // reverse the elements added from stack
        reverse(ans.begin() + idx, ans.end());
        // reverse the entire array
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
/*
# +ive: right direction
# -ive: left direction
# only asteroids of the form (+, -) will collide
# asteroids of the form (+, +), (-, -), (-, +) will never collide
*/