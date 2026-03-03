class Solution {
public:
long long fun(vector<int>&piles, int n, int speed){
     if(speed == 0) return INT_MAX; 
    long long h = 0;
    for(int i = 0; i < n; i++) {
        h = h + piles[i]/speed;
        if(piles[i]%speed!= 0){
            h++;
        }
}
return h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int res = -1;
        while(low<=high){
            int mid = (low+high)/2;
            long long hours = fun(piles, n, mid);
            if(hours>h){
                low = mid+1;
            }
            else{
                res = mid;
                high = mid -1;
            }
        }
        return res;
    }
};