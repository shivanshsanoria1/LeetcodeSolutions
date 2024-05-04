class SegmentTree{
private:
    // vector to hold values of segment tree
    vector<int> seg; 
    
public:
    // default constructor
    SegmentTree(){ 
        
    }
    
    SegmentTree(vector<int>& nums){
        int n=nums.size();
        // max size of segment tree for n elements is 4n
        seg.resize(4*n, 0); 

        // root node at index i=0 and in range [0, n-1]
        buildTree(nums, 0, 0, n-1); 
    }
    
    void buildTree(vector<int>& nums, int i, int left, int right){
        if(left == right)
        {
            seg[i] = nums[left];
            return;
        }

        int mid = (left + right) / 2;
        // left-segment at index (2*i + 1) in range [left, mid]
        buildTree(nums, 2*i + 1, left, mid); 
        // right-segment at index (2*i + 2) in range [mid + 1, right]
        buildTree(nums, 2*i + 2, mid + 1, right); 

        // curr-segment val = left-segment val + right-segment val 
        seg[i] = seg[2*i + 1] + seg[2*i + 2];
    }
    
    // update value at index 'idx' with 'val'
    void updateTree(int i, int left, int right, int idx, int val){ 
        // no overlap
        if(idx < left || idx > right) 
            return;

        // total overlap
        if(left == right) 
        {
            seg[i] = val;
            return;
        }

        // partial overlap
        int mid = (left + right) / 2;
        // left-segment at index (2*i + 1) in range [left, mid]
        updateTree(2*i + 1, left, mid, idx, val); 
        // right-segment at index (2*i + 2) in range [mid + 1, right]
        updateTree(2*i + 2, mid + 1, right, idx, val); 

        // curr-segment val = left-segment val + right-segment val 
        seg[i] = seg[2*i + 1] + seg[2*i + 2];
    }
    
    int queryTree(int i, int left, int right, int qleft, int qright){
        // no overlap
        if(qright < left || right < qleft) 
            return 0;

        // total overlap, ie, [left, right] is contained within [qleft, qright]
        if(qleft <= left && right <= qright) 
            return seg[i];

        // partial overlap
        int mid = (left + right) / 2;
        // left-segment at index (2*i + 1) in range [left, mid]
        int leftSum = queryTree(2*i + 1, left, mid, qleft, qright); 
        // right-segment at index (2*i + 2) in range [mid + 1, right]
        int rightSum = queryTree(2*i + 2, mid + 1, right, qleft, qright); 

        return leftSum + rightSum;
    }
};


class NumArray {
private:
    SegmentTree segTree;
    int n; // size of input vector
    
public:
    NumArray(vector<int>& nums) {
        this->segTree = SegmentTree(nums);
        this->n = nums.size();
    }
    
    // T.C.=O(logn)
    void update(int index, int val) { 
        segTree.updateTree(0, 0, n-1, index, val);
    }
    
    // T.C.=O(logn)
    int sumRange(int qleft, int qright) {
        return segTree.queryTree(0, 0, n-1, qleft, qright);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */