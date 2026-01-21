#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <unordered_map>

using namespace std;

class Sorting{
private:
    // ------------ Bubble-sort | START ------------ //
    // T.C.=O(n^2), S.C.=O(1) | Stable | In-place
    static void bubbleSort(vector<int>& nums){
        int n = nums.size();
        
        for(int i=0; i<n-1; i++){
            bool isSwapped = false;
    
            for(int j=0; j<n-i-1; j++)
                if(nums[j] > nums[j+1]){
                    swap(nums[j], nums[j+1]);
                    isSwapped = true;
                }
    
            if(!isSwapped)
                break;
        }
    }
    // ------------ Bubble-sort | END ------------ //
    
    // ------------ Selection-sort | START ------------ //
    // T.C.=O(n^2), S.C.=O(1) | Unstable | In-place
    static void selectionSort(vector<int>& nums){
        int n = nums.size();
        
        for(int i=0; i<n-1; i++){
            int minVal = nums[i];
            int idx = i;
    
            for(int j=i+1; j<n; j++)
                if(nums[j] < minVal){
                    minVal = nums[j];
                    idx = j;
                }
                
            if(idx != i)
                swap(nums[i], nums[idx]);
        }
    }
    // ------------ Selection-sort | END ------------ //
    
    // ------------ Insertion-sort | START ------------ //
    // T.C.=O(n^2), S.C.=O(1) | Stable | In-place
    static void insertionSort(vector<int>& nums){
        int n = nums.size();
        
        for(int i=1; i<n; i++){
            for(int j=i; j>0; j--){
                if(nums[j-1] > nums[j])
                    swap(nums[j-1], nums[j]);
                else
                    break;
            }
        }
    }

    // ------------ Insertion-sort | END ------------ //
    
    // ------------ Merge-sort | START ------------ //
    static void merge(vector<int>& nums, int left, int mid, int right){
        vector<int> temp1;
        for(int i = left; i <= mid; i++)
            temp1.push_back(nums[i]);
    
        vector<int> temp2;
        for(int i = mid + 1; i <= right; i++)
            temp2.push_back(nums[i]);
    
        int i=0, j=0;
        int k = left;
    
        for(; i < temp1.size() && j < temp2.size(); k++){
            if(temp1[i] <= temp2[j]){
                nums[k] = temp1[i];
                i++;
            }else{
                nums[k] = temp2[j];
                j++;
            }
        }
    
        for(;i < temp1.size(); i++, k++)
            nums[k] = temp1[i];
    
        for(;j < temp2.size(); j++, k++)
            nums[k] = temp2[j];
        
    }
    
    // T.C.=O(n*log(n)), S.C.=O(n) | Stable | Not In-place
    static void mergeSort(vector<int>& nums, int left, int right){
        if(left >= right)
            return;
    
        int mid = left + (right - left)/2;
    
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
    
        merge(nums, left, mid, right);
    }
    // ------------ Merge-sort | END ------------ //
    
    // ------------ Heap-sort | START ------------ //
    // make the heap (rooted at i) valid and 
    // containing the elements in index window [0, n)
    static void heapify(vector<int>& nums, int n, int i){
        int left = 2*i + 1;
        int right = 2*i + 2;
        
        int idx = i;
        
        if(left < n && nums[left] > nums[idx])
            idx = left;
        if(right < n && nums[right] > nums[idx])
            idx = right;
        
        // curr node is already the largest so heap is valid
        if(idx == i)
            return;
        
        // swap the curr node val with the max among the left and right child
        swap(nums[i], nums[idx]);
        // check for the heap rooted at idx
        heapify(nums, n, idx);
    }
    
    // T.C.=O(n*log(n)), S.C.=O(log(n)) | Unstable | In-place
    static void heapSort(vector<int>& nums){
        int n = nums.size();
        
        // build the initial max-heap by calling
        // heapify on all the non-leaf nodes
        for(int i=n/2-1; i>=0; i--)
            heapify(nums, n, i);
        
        for(int i=n-1; i>0; i--){
            // swap the max element (index 0) with 
            // the last unsorted element (index i)
            swap(nums[0], nums[i]);
            heapify(nums, i, 0);
        }
    }
    // ------------ Heap-sort | END ------------ //

    // ------------ Heap-sort (iterative) | START ------------ //
    // make the heap (rooted at i) valid and 
    // containing the elements in index window [0, n)
    static void heapify_iterative(vector<int>& nums, int n, int i){
        while(2*i+1 < n){
            int left = 2*i + 1;
            int right = 2*i + 2;
            
            int idx = i;
            
            if(nums[left] > nums[idx])
                idx = left;
            if(right < n && nums[right] > nums[idx])
                idx = right;
            
            // curr node is already the largest so heap is valid
            if(idx == i)
                break;
            
            // swap the curr node val with the max among the left and right child
            swap(nums[i], nums[idx]);
            
            i = idx;
        }
    }
    
    // T.C.=O(n*log(n)), S.C.=O(1) | Unstable | In-place
    static void heapSort_iterative(vector<int>& nums){
        int n = nums.size();
        
        // build the initial max-heap by calling
        // heapify on all the non-leaf nodes
        for(int i=n/2-1; i>=0; i--)
            heapify_iterative(nums, n, i);
        
        for(int i=n-1; i>0; i--){
            // swap the max element (index 0) with 
            // the last unsorted element (index i)
            swap(nums[0], nums[i]);
            heapify_iterative(nums, i, 0);
        }
    }
    // ------------ Heap-sort (iterative) | END ------------ //
    
    typedef unordered_map<string, void(*)(vector<int>&)> Str_FnPtr;

    static const Str_FnPtr& getAlgoMap(){
        static const Str_FnPtr mp = {
            {"bubble", &bubbleSort},
            {"selection", &selectionSort},
            {"insertion", &insertionSort},
            {"merge", [](vector<int>& nums){
                    mergeSort(nums, 0, (int)nums.size() - 1);
                }
            },
            {"heap", &heapSort},
            {"heap_iterative", &heapSort_iterative}
        };
        
        return mp;
    }

public:
    bool enableLog;
    
    Sorting(){
        this->enableLog = true;
    }
    
    static void print(const vector<int>& nums){
        for(int num: nums)
            cout<<num<<" ";
        cout<<endl;
    }

    void runAlgo(vector<int>& nums, const string algoName){
        const auto& mp = getAlgoMap();
        
        auto itr = mp.find(algoName);

        if(itr == mp.end()){
            if(enableLog){
                cout<<"Invalid algo. name"<<endl;
                cout<<string(30, '-')<<endl<<endl;
            }
            return;
        }

        if(enableLog){
            cout<<"Before Sorting: ";
            print(nums);   
        }

        if(enableLog)
            cout<<"Running "<<algoName<<"-sort... "<<endl;

        itr->second(nums);

        if(enableLog){
            cout<<"After Sorting: ";
            print(nums);
            cout<<string(30, '-')<<endl<<endl;
        }

    }
    
    static vector<int> generateRandomVector(int n, int minVal, int maxVal){
        if(minVal > maxVal){
            cout<<"Min-value must be <= Max-value"<<endl;
            return {};
        }
        
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> distrib(minVal, maxVal);
        
        vector<int> nums;
        for(int i=0; i<n; i++)
            nums.push_back(distrib(gen));
            
        return nums;
    }
};

int main() {
    Sorting st;
    
    // vector<int> nums = { 9, 4, 3, 8, 10, 2, 5 };
    vector<int> nums = st.generateRandomVector(10, 1, 50);
    
    // st.runAlgo(nums, "bubble");
    // st.runAlgo(nums, "selection");
    // st.runAlgo(nums, "insertion");
    // st.runAlgo(nums, "merge");
    // st.runAlgo(nums, "heap");
    st.runAlgo(nums, "heap_iterative");
    
    return 0;
}

/*
void runAlgo(vector<int>& nums, string algo){
    if(enableLog){
        cout<<"Before Sorting: ";
        print(nums);   
    }
    
    if(algo == "bubble"){
        if(enableLog)
            cout<<"Running Bubble-sort..."<<endl;
        bubbleSort(nums);
    }else if(algo == "selection"){
        if(enableLog)
            cout<<"Running Selection-sort..."<<endl;
        selectionSort(nums);
    }else if(algo == "insertion"){
        if(enableLog)
            cout<<"Running Insertion-sort..."<<endl;
        insertionSort(nums);
    }else if(algo == "merge"){
        if(enableLog)
            cout<<"Running Merge-sort..."<<endl;
        mergeSort(nums, 0, (int)nums.size() - 1);
    }else if(algo == "heap"){
        if(enableLog)
            cout<<"Running Heap-sort..."<<endl;
        heapSort(nums);
    }else if(algo == "heap_iterative"){
        if(enableLog)
            cout<<"Running Iterative Heap-sort..."<<endl;
        heapSort_iterative(nums);
    }else{
        if(enableLog)
            cout<<"Invalid algo. name"<<endl;
        return;
    }
    
    if(enableLog){
        cout<<"After Sorting: ";
        print(nums);
        cout<<string(30, '-')<<endl<<endl;
    }
}
*/