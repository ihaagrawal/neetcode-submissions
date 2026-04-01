class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> l(n, 0), r(n, 0);

        int lmax = h[0];
        for(int i=0;i<n;i++){
            l[i] = lmax;
            lmax = max(lmax, h[i]);
        }

        int rmax = h[n-1];
        for(int i=n-1;i>=0;i--){
            r[i] = rmax;
            rmax = max(rmax, h[i]);
        }

        int total = 0;
        for(int i=0;i<n;i++) total += max(min(l[i], r[i]) - h[i], 0);

        return total;
    }
};
