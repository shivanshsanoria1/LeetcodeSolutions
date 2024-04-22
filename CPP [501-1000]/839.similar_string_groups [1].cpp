class DisjointSet{
private:
    vector<int> parent;
    vector<int> size;

    int findUltimateParent(int curr){
        if(curr == parent[curr])
            return curr;
        
        parent[curr] = findUltimateParent(parent[curr]);
        return parent[curr];
    }

public:
    DisjointSet(int n){
        // initially every node has size 1
        this->size.resize(n, 1);

        this->parent.resize(n);
        // initially every node is the parent of itself
        for(int i=0; i<n; i++)
            this->parent[i] = i;
    }

    bool unionBySize(int a, int b){
        int ultPar_a = findUltimateParent(a);
        int ultPar_b = findUltimateParent(b);

        // a and b are already in the same component
        if(ultPar_a == ultPar_b)
            return false;

        if(size[ultPar_a] < size[ultPar_b])
        {
            parent[ultPar_a] = ultPar_b;
            size[ultPar_b] += size[ultPar_a];
        }
        else // size[ultPar_a] >= size[ultPar_b]
        {
            parent[ultPar_b] = ultPar_a;
            size[ultPar_a] += size[ultPar_b];
        }

        return true;
    }

    int getComponentmismatch(){
        unordered_set<int> s;

        for(int i=0; i<parent.size(); i++)
            s.insert(findUltimateParent(i));
        
        return s.size();
    }
};

class Solution {
private:
    bool areSimilar(string& s1, string& s2){
        int mismatch = 0;

        for(int i=0; i<s1.length(); i++)
        {
            if(s1[i] != s2[i])
                mismatch++;
            if(mismatch > 2)
                return false;
        }

        return mismatch == 0 || mismatch == 2;
    }

public:
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        DisjointSet ds(n);

        for(int i=0; i<n-1; i++)
            for(int j=i+1; j<n; j++)
                if(areSimilar(strs[i], strs[j]))
                    ds.unionBySize(i, j);
        
        return ds.getComponentmismatch();
    }
};