// Leetcode q no. - 852

// You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
// Return the index of the peak element.

// Binary search Approach
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {   // T.C. - O(logn) & S.C. - O(1)
        int n = arr.size();
        int low = 1;
        int high = n-2;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;

            if(arr[mid] < arr[mid-1]) high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
};