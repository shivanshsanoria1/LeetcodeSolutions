class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        vector<int> vec(26,0); //stores freq of char present in all strings in the array words
        for(char ch='a'; ch<='z'; ch++)
        {
            int min_count=INT_MAX;
            for(int i=0; i<words.size(); i++)
            {
                int count=0;
                for(int j=0; j<words[i].length(); j++)
                    if(words[i][j]==ch) //find freq of char ch in string words[i]
                        count++;
                min_count=min(min_count,count); //update the min freq of char ch
            }
            vec[ch-'a']=min_count;
        }
        for(int i=0; i<26; i++)
            while(vec[i]--)
            {
                string s="";
                s+=(char)(i+97);
                ans.push_back(s);
            }
        return ans;
    }
};