class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) { //T.C.=O(n) , S.C.=O(n)
        int j=0;
        stack<int> st;
        for(int i=0; i<pushed.size(); i++)
        {
            st.push(pushed[i]);
            while(!st.empty() && st.top()==popped[j]) //keep popping elements from stack until stack top and popped[j] become unequal
            {
                st.pop();
                j++;
            }
        }
        return st.empty() ? true : false;
    }
};