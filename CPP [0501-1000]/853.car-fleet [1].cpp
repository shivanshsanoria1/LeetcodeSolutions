class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) { // T.C.=O(n*logn), S.C.=O(n)
        int n=position.size();
        vector<pair<int, int>> vec(n); // {position, velocity}
        for(int i=0; i<n; i++)
            vec[i] = {position[i], speed[i]};
        sort(vec.begin(), vec.end()); // sort by position

        stack<pair<int, int>> st; // {position, velocity}
        // push the last car's position and velocity in stack
        st.push({vec[n-1].first, vec[n-1].second});
        int groups = 1; // initially only last car is in a group
        for(int i=n-2; i>=0; i--)
        {
            int p1 = vec[i].first, v1 = vec[i].second; // car1
            auto [p2, v2] = st.top(); // car2
            // car1 can never catch upto car2 before car2 reaches target
            if(v1 <= v2 || (float)(target - p1)/v1 > (float)(target - p2)/v2)
            {
                while(!st.empty()) // empty the stack
                    st.pop();
                groups++; // ith car is in a new group
                st.push({p1, v1}); // push car1's position and velocity in stack
            }
        }
        return groups;
    }
};
/*
# assume  -->-- car1 -->-- car2 -->-- target
# v1 <= v2: car1 can never catch upto car2
# v1 > v2: car1 may catch upto car2 before car2 reaches target
# let t1 = (target - p1)/v1: time taken by car1 to reach target 
# let t2 = (target - p2)/v2: time taken by car2 to reach target 
# t1 <= t2: car1 will catch upto car2 before car2 reaches target
# t1 > t2: car1 cannot catch upto car2 before car2 reaches target
*/