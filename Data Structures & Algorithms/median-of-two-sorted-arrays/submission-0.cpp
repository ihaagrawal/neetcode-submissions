class Solution {
public:

    void heaps(vector<int>& nums, priority_queue<int>& mx, priority_queue<int, vector<int>, greater<int>>& mn){
        for(int x : nums){
            mx.push(x);
            mn.push(mx.top());
            mx.pop();

            if(mn.size() > mx.size()){
                mx.push(mn.top());
                mn.pop();
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        priority_queue<int> mx; // max heap
        priority_queue<int, vector<int>, greater<int>> mn; // min heap

        heaps(nums1, mx, mn);
        heaps(nums2, mx, mn);

        if(mx.size() > mn.size()) return (double)mx.top();
        return ((double) mx.top() + (double)mn.top()) / 2.0;
    }
};
