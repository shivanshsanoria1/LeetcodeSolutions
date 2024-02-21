class Solution {
public:
    bool checkIfPangram(string sentence) {
        string alpha="abcdefghijklmnopqrstuvwxyz";
        for(int i=0; i<26; i++)
        {
            bool flag=false;
            for(int j=0; j<sentence.size(); j++)
                if(alpha[i]==sentence[j])
                {
                    flag=true;
                    break;
                }
            if(flag==false)
                return false;
        }
        return true;
    }
};