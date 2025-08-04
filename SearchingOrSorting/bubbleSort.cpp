// Buuble sort Algorithm

class Solution {
  public:
    void bubbleSort(vector<int>& arr) {  // T.C. - O(n^2) & S.C. - O(1)
        int n = arr.size();
        bool flag = false;
        for(int i=0; i<n-1; i++) {
            for(int j=0; j<n-i-1; j++) {
                if(arr[j] > arr[j+1]) {
                    swap(arr[j], arr[j+1]);
                    flag = true;
                }
                if(!flag) break;
            }
        }
        return;
    }
};