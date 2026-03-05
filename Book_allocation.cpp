class Solution {
  public:
  bool fun(vector<int> &books,int n, int limit, int stud){
      int k = 1;
      int pages = 0;
      for(int i = 0; i<n; i++){
          if(pages+books[i]<=limit){
              pages = pages + books[i];
          }
          else{
              k++;
              pages = books[i];
              if(k>stud)return false;
          }
      }
      return true;
  }
    int findPages(vector<int> &arr, int k) {
       int n = arr.size(); // code here
        if(n<k){
            return -1;
        }
        int low = 0,high = 0;
        for(int i = 0;i<n;i++){
            low = max(low, arr[i]);
            high = high+arr[i];
        }
            int res = -1;
            while(low<=high){
                int mid = (low+high)/2;
                if(fun(arr,n,mid,k)){
                    res = mid;
                    high = mid-1;
                }
                else{
                    low = mid +1;
                }
            }
            return res;
        }
};
