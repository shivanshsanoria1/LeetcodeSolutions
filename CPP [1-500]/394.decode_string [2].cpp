class Solution {
public:
    string decodeString(string s) {
        string ans="";
        stack<char> st;
        for(char ch: s)
        {
            if(ch == ']')
            {
                string str=""; //stores the alphabets in the most internal brackets in each step
                while(st.top() != '[') //while the stack top is not '['
                {
                    str += st.top(); //keep on popping and adding char from stack into the string str
                    st.pop();
                }
                st.pop(); //pop the '['
                reverse(str.begin(),str.end()); //reverse the string str to get the most internal string formed in each step

                string num=""; //stores the number of times string str is to be repeated
                while(!st.empty() && st.top() >= '0' && st.top() <= '9') //while stack top is a digit
                {
                    num += st.top(); //keep on popping and adding the digits from stack into the string num
                    st.pop();
                }
                reverse(num.begin(),num.end()); //reverse the string num to get the correct number
                int n= stoi(num); //convert string num into an integer n

                while(n--) //add all the char of string str back into the stack n times
                    for(char t: str)
                        st.push(t);
            }
            else //push any char except ']' in the stack
                st.push(ch);
        }
        while(!st.empty()) //empty the stack into the string ans
        {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end()); //reverse the string ans
        return ans;
    }
};