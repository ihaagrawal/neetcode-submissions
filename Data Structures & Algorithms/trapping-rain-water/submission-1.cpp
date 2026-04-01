class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        if(n == 0) return 0;

        int l = 0, r = n-1;
        int lmax = h[l], rmax = h[r];
        int total = 0;

        while(l < r){
            if(lmax < rmax){
                l++;
                lmax = max(lmax, h[l]);
                total += lmax - h[l];
            }else{
                r--;
                rmax = max(rmax, h[r]);
                total += rmax - h[r];
            }
        }

        return total;
    }
};
