class Solution {
private:
    bool areSimilar(const string& s1, const string& s2){
        int diff = (s1[0] - s2[0] + 26) % 26;
        for(int i=1; i<s1.length(); i++)
            if((s1[i] - s2[i] + 26) % 26 != diff)
                return false;

        return true;
    }

public:
    // T.C.=O(), S.C.=O(n)
    long long countPairs(vector<string>& words) {
        int n = words.size();
        int m = words[0].size();
        long long int count = 0;
        // {idx of group-representative, group-size}
        vector<pair<int, int>> groups(n, {-1, 0});
        int groupId = -1;

        for(int i=0; i<n; i++){
            bool isMatchFound = false;
            for(auto& [idx, groupSize]: groups){
                if(idx == -1)
                    break;
                
                if(areSimilar(words[i], words[idx])){
                    count += groupSize;
                    groupSize++;
                    isMatchFound = true;
                    break;
                }
            }

            if(!isMatchFound)
                groups[++groupId] = {i, 1};
        }

        return count;
    }
};

/*
# the idea is to group similar words into their own groups
# we don't actually care about all the words in a group
# we just need to know the size of group and the value of a word
  which would act as the group representative
# if the curr word matches a group-representative, 
  then it can be paired up with each word in that group
# but if the curr word doesn't match any group-representative, 
  then it will become the group-representative itself
*/