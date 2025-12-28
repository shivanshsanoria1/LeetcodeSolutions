// https://www.geeksforgeeks.org/problems/union-find/1

class Solution
{
private:
    int findUltimateParent(int parent[], int curr){
        if(curr == parent[curr])
            return curr;
            
        parent[curr] = findUltimateParent(parent, parent[curr]);
        return parent[curr];
    }
    
public:
    //Function to merge two nodes a and b.
    void union_(int a, int b, int parent[], int rank[]) 
    {
        //code here
        int ultPar_a = findUltimateParent(parent, a);
        int ultPar_b = findUltimateParent(parent, b);
        
        if(ultPar_a == ultPar_b)
            return;
            
        if(rank[ultPar_a] < rank[ultPar_b])
            parent[ultPar_a] = ultPar_b;
        else if(rank[ultPar_a] > rank[ultPar_b])
            parent[ultPar_b] = ultPar_a;
        else
        {
            parent[ultPar_a] = ultPar_b;
            rank[ultPar_b]++;
        }
    }
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int a, int b, int parent[], int rank[])
    {
        //code here
        return findUltimateParent(parent, a) == findUltimateParent(parent, b);
    }
};