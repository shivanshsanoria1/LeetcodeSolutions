class Solution {
public:
    string modify(string s) //returns reverse of modified string
    {
        string str="";
        stack<char> st;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]!='#') //push the non # chars. into stack
                st.push(s[i]);
            else if(!st.empty()) //check if stack is empty
                st.pop();
        }
        while(!st.empty()) //pop char from stack and add to ans
        {
            str+=st.top();
            st.pop();
        }
        return str;
    }
    
    bool backspaceCompare(string s, string t) {
        string s1=modify(s);
        string t1=modify(t);
        int n1=s1.length(), n2=t1.length();
        if(n1!=n2) //modified strings not of equal length
            return false;
        for(int i=0; i<n1; i++)
            if(s1[i]!=t1[i])
                return false;
        return true;
    }
};