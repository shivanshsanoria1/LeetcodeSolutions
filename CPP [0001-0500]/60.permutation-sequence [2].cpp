class Solution {
public:
    void factorial(vector<int>& fact) //calculates factorial from 0 to (n-1)
    {
        fact[0]=1;
        for(int i=1; i<fact.size(); i++)
            fact[i]= i*fact[i-1];
    }
    
    void solve(int n, int k, vector<bool>& dig,  vector<int>& fact, string& ans)
    {
        if(n==0)
            return;
        if(k==0) //add all the unvisited digits to the ans string in descending order
        {
            for(int i=dig.size()-1; i>=1; i--)
            {
                if(dig[i] == true) //skip the visited digits
                    continue;
                dig[i]=true; //mark the curr digit as visited
                ans+=to_string(i);
            }
            return;
        }
        int group_size= fact[n-1];
        int comp_groups= k / group_size; //num of complete groups
        int incomp_group= k % group_size; //size of incomplete group
        if(incomp_group != 0) //there is an incomplete group
            comp_groups++;
        for(int i=1; i<dig.size(); i++)
        {
            if(dig[i]==true) //skip the visited digits
                continue;
            comp_groups--;
            if(comp_groups == 0)
            {
                dig[i]=true; //mark the curr digit as visited
                ans+=to_string(i);
                break;
            }
        }
        solve(n-1,incomp_group,dig,fact,ans);
    }
    
    string getPermutation(int n, int k) {
        vector<bool> dig(n+1,false); //to store visited digits
        string ans="";
        vector<int> fact(n); //to store factorial from 0 to (n-1)
        factorial(fact);
        solve(n,k,dig,fact,ans);
        return ans;
    }
};