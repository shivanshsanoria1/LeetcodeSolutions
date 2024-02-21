class Solution {
public:
    int minimumPushes(string word) {
        int groups = word.length() / 8;
        int lastGroupCount = word.length() % 8;
        return 8*groups*(groups + 1) / 2 + lastGroupCount * (groups + 1);
    }
};