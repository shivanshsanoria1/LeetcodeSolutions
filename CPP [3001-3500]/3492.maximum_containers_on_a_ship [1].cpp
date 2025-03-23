class Solution {
public:
    // T.C.=O(1), S.C.=O(1)
    int maxContainers(int n, int w, int maxWeight) {
        return min(n*n, maxWeight / w);
    }
};