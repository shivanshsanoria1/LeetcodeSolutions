class Solution {
public:
    string removeDuplicateLetters(string s) {
        string ans="";
        int n=s.length();
        vector<bool> vec(26,false); //keeps track of char present in stack
        vector<int> freq(26,0); //stores freq of char in the string s
        stack<char> st;
        for(int i=0; i<n; i++)
            freq[s[i]-'a']++; //increment freq of curr char
        for(int i=0; i<n; i++)
        {
            freq[s[i]-'a']--; //decrement the freq of curr char
            if(vec[s[i]-'a'] == false) //curr char is not present in stack
            {
                vec[s[i]-'a']=true; //mark the curr char as visited
                while(!st.empty() && st.top() > s[i] && freq[st.top()-'a'] > 0) //keep popping elements from stack until
                { //stack is non empty and stack top char > curr char and freq of stack top char is > 0
                    vec[st.top()-'a']=false; //mark the curr char as unvisited
                    st.pop();
                }
                st.push(s[i]); //push curr char in stack
            }
        }
        while(!st.empty()) //empty the stack in a string
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }