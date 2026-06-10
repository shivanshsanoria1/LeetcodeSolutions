class Solution {
public:
    void factors(int n, vector<int>& facts)
    {
        for(int i=1; i*i<=n; i++)
            if(n % i == 0)
            {
                facts.push_back(i);
                if(i != n/i)
                    facts.push_back(n/i);
            }
    }
    
    int commonFactors(int a, int b) {
        vector<int> facts_a, facts_b;
        factors(a,facts_a);
        factors(b,facts_b);
        int count=0;
        for(int i=0; i<facts_a.size(); i++)
            for(int j=0; j<facts_b.size(); j++)
                if(facts_a[i] == facts_b[j])
                    count++;
        return count;
    }
};