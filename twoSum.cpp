/**
 * Two sum
 */
class Solution {
public:
        vector<int> twoSum(vector<int> &numbers, int target) {
                // Start typing your C/C++ solution below
                // DO NOT write int main() function

                //build up a hashtable to quick qurey
                map<int, int> fastquery;
                for (int i = 0; i < numbers.size(); i++) {
                        if (fastquery.find(numbers[i]) == fastquery.end())
                                fastquery[numbers[i]] = i;
                }

                //sort this array first
                sort(numbers.begin(), numbers.end());
                //find the answer
                vector<int> res;
                for (int i = 0; i < numbers.size(); i++) {
                        if (numbers[i] + numbers[i] < target) {
                                if (fastquery.find(target - numbers[i]) != fastquery.end()) {
                                        int a = fastquery[numbers[i]];
                                        int b = fastquery[target - numbers[i]];
                                        if (a < b) {
                                                res.push_back(a + 1);
                                                res.push_back(b + 1);
                                        } else {
                                                res.push_back(b + 1);
                                                res.push_back(a + 1);
                                        }
                                        return res;
                                }
                        } else if (numbers[i] + numbers[i] == target) {
                                res.push_back(fastquery[numbers[i]] + 1);
                                res.push_back(fastquery[numbers[i]] + 2);
                                return res;
                        }
                }
        }
};
