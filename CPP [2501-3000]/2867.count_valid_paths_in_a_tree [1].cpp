class Solution {
private:
    vector<bool> sieveOfEratosthenes(int n){
        vector<bool> isPrime(n+1, true);
        isPrime[0] = false;
        isPrime[1] = false;

        for(int p=2; p*p <= n; p++)
        {
            if(!isPrime[p])
                continue;
            for(int m = p*p; m <= n; m += p)
                isPrime[m] = false;
        }

        return isPrime;
    }

    // returns the num of visited nodes starting from the 'curr' node 
    // marks each node visited with 'compId'
    int dfs(vector<vector<int>>& graph, vector<bool>& isPrime, vector<int>& compIds, int compId, int curr, int parent){
        if(isPrime[curr])
            return 0;

        compIds[curr] = compId;
        int count = 1;

        for(int nei: graph[curr])
            if(nei != parent)
                count += dfs(graph, isPrime, compIds, compId, nei, curr);
        
        return count;
    }

public:
    // T.C.=O(n*log(logn))
    long long countPaths(int n, vector<vector<int>>& edges) {
        // build graph
        vector<vector<int>> graph(n+1);
        for(vector<int>& edge: edges)
        {
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        // tells if the ith num is prime or not
        vector<bool> isPrime = sieveOfEratosthenes(n);
        // component-id to which the ith node belongs
        // (prime nodes belong to component-id = -1)
        vector<int> compIds(n+1, -1);
        // size of the component with component-id 'i'
        vector<int> compSize;

        int compId = 0;

        for(int i=1; i<=n; i++)
            // run dfs() only for non-prime and non-visited nodes
            if(!isPrime[i] && compIds[i] == -1)
            {
                int size = dfs(graph, isPrime, compIds, compId, i, -1);
                compSize.push_back(size);
                compId++;
            }

        long long int count = 0;

        for(int i=2; i<=n; i++)
        {
            if(!isPrime[i])
                continue;

            // component size of the neighbours of a prime-node
            vector<int> compSizeNei;

            for(int nei: graph[i])
                if(!isPrime[nei])
                    compSizeNei.push_back(compSize[compIds[nei]]);

            // sum of the size of each neighbouring component 
            long long int sum1 = 0;
            // sum of the square of size of each neighbouring component 
            long long int squareSum1 = 0;

            for(int size: compSizeNei)
            {
                sum1 += size;
                squareSum1 += (long long int)size*size;
            }
            
            // sum of the size of each neighbouring component taking 2 at a time
            long long int sum2 = (sum1*sum1 - squareSum1) / 2;

            count += sum1 + sum2;
        }

        return count;
    }
};
/*
# here, O(V + E) = O(n + n-1) = O(n)

# observing the example with 4 terms:
# (a + b + c + d)^2 = (a^2 + b^2 + c^2 + d^2) + 2*(ab + ac + ad + bc + bd + cd)
# In general:
  (S1)^2 = (Ss1) + 2*(S2)
  S2 = ((S1)^2 - (Ss1)) / 2
# S1: sum of each term
  S2: sum of each term taking 2 at a time
  Ss1: sum of square of each term
*/