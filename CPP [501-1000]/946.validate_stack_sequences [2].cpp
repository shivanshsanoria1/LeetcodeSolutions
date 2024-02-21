class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) { //T.C.=O(n) , S.C.=O(1)
        int n=pushed.size(), j=0, top=-1; //top==-1 means stack is empty, idea is to use pushed[] as stack
        for(int i=0; i<n; i++)
        {
            pushed[++top]=pushed[i];
            while(top!=-1 && pushed[top]==popped[j])
            {
                top--;
                j++;
            }
        }
        return top==-1 ? true : false;
    }
};