// Selection Sort Algorithm

class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {  // T.C. - O(n^2) & S.C. - O(1)
        int n = arr.size();
        
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                if(arr[i] > arr[j]) swap(arr[i], arr[j]);
            }
        }
    
    }
};