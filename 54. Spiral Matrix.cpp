class Solution {
public:
    
    void traverse(int type, int row, int col , vector<vector<int>>& matrix, vector<int> &result,int** isVisit) {
        if(row < 0 || row > matrix.size() || col < 0 || col > matrix[0].size() || isVisit[row][col] != 0) return;
        if(type == 0) {
            int i = col;
            for(; i < matrix[0].size(); ++i) {
                 if(isVisit[row][i] == 0) {
                    isVisit[row][i] = 1;
                result.push_back(matrix[row][i]);
                }
            }
            return traverse((type+1) % 4, row+1, i, matrix, result, isVisit);
            
        } else if(type == 1) {
            int i = row;
            for(; i < matrix.size() ; ++i) {
                
                if(isVisit[i][col] == 0) {
                    result.push_back(matrix[i][col]);
                isVisit[i][col] = 1;
                }
            }
            return traverse((type+1) % 4, i, col-1, matrix, result, isVisit);
        } else if(type == 2) {
            int i = col;
            for(; i >= 0 ; --i) {
                if(isVisit[row][i] == 0) {
                    isVisit[row][i] = 1;
                result.push_back(matrix[row][i]);
                }
                
            }
            return traverse((type+1) % 4, row-1, i, matrix, result, isVisit);
        } else {
            int i = row;
            for(; i >= 0; --i) {
                if(isVisit[i][col] == 0) {
                    result.push_back(matrix[i][col]);
                    isVisit[i][col] = 1;
                }
                
            }
            return traverse((type+1) % 4, i, col+1, matrix, result, isVisit);
        }
    }
    
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> result;
        int** a = new int*[row];
        for(int i = 0; i < col; ++i)
            a[i] = new int[col];
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                a[i][j] = 0;
            }
        }
        traverse(0, 0, 0, matrix, result,  a);
        return result;
    }
};