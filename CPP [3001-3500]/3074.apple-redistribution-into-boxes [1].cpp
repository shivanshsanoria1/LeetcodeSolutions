class Solution {
public:
    // T.C.=O(n + m*logm), S.C.=O(1)
    // n: size of apple[], m: size of capacity[]
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int appleSum = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), greater<int>());

        int capacitySum = 0;
        int boxCount = 0;
        for(int i=0; i<capacity.size() && capacitySum < appleSum; i++)
        {
            capacitySum += capacity[i];
            boxCount++;
        }
        return boxCount;
    }
};