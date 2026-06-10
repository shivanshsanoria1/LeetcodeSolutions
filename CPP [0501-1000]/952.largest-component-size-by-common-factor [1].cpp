class DisjointSet{
private:
    vector<int> parent;
    vector<int> size;

public:
    DisjointSet(int n){
        // initially every node has size 1
        this->size.resize(n, 1);

        this->parent.resize(n);
        // initially every node is the parent of itself
        for(int i=0; i<n; i++)
            this->parent[i] = i;
    }

    int findUltimateParent(int curr){
        if(curr == parent[curr])
            return curr;
        
        parent[curr] = findUltimateParent(parent[curr]);
        return parent[curr];
    }

    bool unionBySize(int a, int b){
        int ultPar_a = findUltimateParent(a);
        int ultPar_b = findUltimateParent(b);

        if(ultPar_a == ultPar_b)
            return false;

        if(size[ultPar_a] < size[ultPar_b])
        {
            parent[ultPar_a] = ultPar_b;
            size[ultPar_b] += size[ultPar_a];
        }
        else // size[ultPar_a] > size[ultPar_b]
        {
            parent[ultPar_b] = ultPar_a;
            size[ultPar_a] += size[ultPar_b];
        }

        return true;
    }
};

class Solution {
public:
    // T.C.=O(n*sqrt(m)), S.C.=O(m)
    // n: size of nums[], m: max element in nums[]
    int largestComponentSize(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());

        DisjointSet ds(maxNum + 1);

        for(int num: nums)
            for(int f=2; f*f <= num; f++)
                if(num % f == 0)
                {
                    ds.unionBySize(num, f);
                    ds.unionBySize(num, num/f);
                }
        
        // ultimate-parent -> freq
        unordered_map<int, int> mp;
        for(int num: nums)
            mp[ds.findUltimateParent(num)]++;
        
        int maxFreq = 0;
        for(auto [ultPar, freq]: mp)
            maxFreq = max(maxFreq, freq);

        return maxFreq;
    }
};