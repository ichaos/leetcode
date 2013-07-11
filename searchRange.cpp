class Solution {
private:
    int findLeft(int A[], int n, int ti) {
        int i = 0;
        int j = ti;
        
        while (i < j) {
            int mid = (i + j) / 2;
            if (A[mid] == A[ti]) {
                //if (j - i == 1) return i;
                j = mid - 1;
            } else if (A[mid] < A[ti]) {
                i = mid + 1;
            } else {
                //impossible
            }
        }
        return (j >= 0 && A[j] == A[ti]) ? j : j + 1;
    }
    
    int findRight(int A[], int n, int ti) {
        int i = ti;
        int j = n - 1;
        
        while (i < j) {
            int mid = (i + j) / 2;
            if (A[mid] == A[ti]) {
                i = mid + 1;
            } else if (A[mid] > A[ti]) {
                j = mid - 1;
            } else {
                //impossible
            }
        }
        return (A[i] == A[ti]) ? i : i - 1;
    }
    
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> v;
        if (n < 1) {
            v.push_back(-1);
            v.push_back(-1);
            return v;
        }
        
        int i = 0;
        int j = n - 1;
        
        while (i <= j) {
            int mid = (i + j) / 2;
            
            if (A[mid] == target) {
                v.push_back(findLeft(A, n, mid));
                v.push_back(findRight(A, n, mid));
                return v;
            }
            
            if (A[mid] > target) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        
        if (v.empty()) {
            v.push_back(-1);
            v.push_back(-1);
        }
        return v;
    }
};