class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) { // T.C.=O(n), S.C.=O(n)
        vector<int> ans;
        stack<int> st; // contains only +ive value asteroids 
        for(int ast: asteroids)
        {
            // push the +ive value asteroids in stack
            if(ast > 0)
            {
                st.push(ast);
                continue;
            }
            // pop all the +ive value asteroids with value < abs(curr -ive asteroid)
            while(!st.empty() && st.top() < abs(ast))
                st.pop();
            // curr -ive value asteroid survives
            if(st.empty())
            {
                ans.push_back(ast);
                continue;
            }
            // curr -ive value does not asteroid survive
            // equal value +ive asteroid is destroyed
            if(st.top() == abs(ast))
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
        return ans;
    }
};
/*
# +ive: right direction
# -ive: left direction
# only asteroids of the form (+, -) will collide
# asteroids of the form (+, +), (-, -), (-, +) will never collide
*/