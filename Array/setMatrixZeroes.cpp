// Leetcode q no. - 73

// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// 1st Approach - with extra space
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {  // T.C. - O(m*n*(m+n)) & S.C. - O(m*n)
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> visited = matrix;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    for(int k=0; k<m; k++){  // fill whole row with 0s
                        visited[i][k] = 0;
                    }
                    for(int k=0; k<n; k++){   // fill whole column with 0s
                        visited[k][j] = 0;
                    }
                }
            }
        }
        
        // update original matrix
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                matrix[i][j] = visited[i][j];
            }
        }
    }
};

// 2nd Approach - using unordered set
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {  // T.C. - O(m*n) & S.C. - O(m+n)
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_set<int> r;    // store row index
        unordered_set<int> c;    // store column index
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == 0){
                    r.insert(i);
                    c.insert(j);
                } 
            }
        }
        for(auto x : r) {
            for(int j=0; j<n; j++){   //fill the row with zeroes
                matrix[x][j] = 0;
            }
        }

        for(auto x : c) {
            for(int i=0; i<m; i++){   //fill the column with zeroes
                matrix[i][x] = 0;
            }   
        }

        return ;

    }
};

// 3rd Approach - optimized approach
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {   // T.C. -o(m*n) & S.C. - O(1)
        int n = matrix.size();
        int m = matrix[0].size();
        bool flag1 = false, flag2 = false;
        for(int i=0; i<n; i++){     // rows
            if(matrix[i][0] == 0){
                flag1 = true;
                break;
            }
        }
        for(int j=0; j<m; j++){      // columns
            if(matrix[0][j] == 0){
                flag2 = true;
                break;
            }
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(flag1 == true){
            for(int i=0; i<n; i++){
                matrix[i][0] = 0;
            }
        }
        if(flag2 == true){
            for(int j=0; j<m; j++){
                matrix[0][j] = 0;
            }
        }
    }
};