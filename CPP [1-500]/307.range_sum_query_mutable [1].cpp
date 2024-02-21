class SegTree{
private:
    vector<int> seg; //vector to hold values of segment tree
    
public:
    SegTree(){ //default constructor
        
    }
    
    SegTree(vector<int>& nums){
        int n=nums.size();
        seg.resize(4*n,0); //max size of segment tree for n elements is 4n
        buildTree(nums,0,0,n-1); //for root node i=0, left=0, right=n-1
    }
    
    void buildTree(vector<int>& nums, int i, int left, int right){
        if(left == right)
        {
            seg[i]= nums[left];
            return;
        }
        int mid=(left+right)/2;
        buildTree(nums,2*i+1,left,mid); //left segment from 'left' to 'mid'
        buildTree(nums,2*i+2,mid+1,right); //right segment from 'mid+1' to 'right'
        seg[i]= seg[2*i+1] + seg[2*i+2];
    }
    
    void updateTree(int i, int left, int right, int index, int val){ //update 'val' at 'index'
        if(index < left || index > right) //no overlap
            return;
        if(left == right && left == index) //total overlap
        {
            seg[i]= val;
            return;
        }
        //partial overlap
        int mid= (left+right)/2;
        updateTree(2*i+1,left,mid,index,val); //left segment from 'left' to 'mid'
        updateTree(2*i+2,mid+1,right,index,val); //right segment from 'mid+1' to 'right'
        seg[i]= seg[2*i+1] + seg[2*i+2];
    }
    
    int queryTree(int i, int left, int right, int qleft, int qright)
    {
        if(qleft <= left && qright >= right) //total overlap, ie, [qleft,qright] is contained within [left,right]
            return seg[i];
        if(qright < left || qleft > right) //no overlap
            return 0;
        //partial overlap
        int mid= (left+right)/2;
        int left_sum= queryTree(2*i+1,left,mid,qleft,qright); //left segment from 'left' to 'mid'
        int right_sum= queryTree(2*i+2,mid+1,right,qleft,qright); //right segment from 'mid+1' to 'right'
        return left_sum + right_sum;
    }
};


class NumArray {
private:
    SegTree st;
    int n; //size of input vector
    
public:
    NumArray(vector<int>& nums) { //T.C.=O(n)
        this->st= SegTree(nums);
        this->n= nums.size();
    }
    
    void update(int index, int val) { //T.C.=O(logn)
        st.updateTree(0,0,n-1,index,val);
    }
    
    int sumRange(int qleft, int qright) { //T.C.=O(logn)
        return st.queryTree(0,0,n-1,qleft,qright);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */