class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        vector<int> row={2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3}; //stores row num of each char
        for(int i=0; i<words.size(); i++)
        {
            string s=words[i];
            int start_row, curr_row;
            bool flag=true;
            if(s[0]>='a' && s[0]<='z') //0th char is lowercase
                start_row=row[s[0]-'a'];
            else                       //0th char is uppercase
                start_row=row[s[0]-'A'];
            for(int j=1; j<s.length(); j++)
            {
                if(s[j]>='a' && s[j]<='z') //curr char is lowercase
                    curr_row=row[s[j]-'a'];
                else                       //curr char is uppercase
                    curr_row=row[s[j]-'A'];
                if(curr_row != start_row) //consecutive chars. not on same row
                {
                    flag=false;
                    break;
                }

            }
            if(flag==true)
                ans.push_back(words[i]);
        }
        return ans;
    }
};