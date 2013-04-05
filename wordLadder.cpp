/**
 * Test case:
 *  "a", "c", ["a", "b, "c"]
   
"hot", "dog", ["hot","dog"] 0   0   
   
"hot", "dog", ["hot","dog","dot"]   0   3   
   
"hot", "dot", ["hot","dot","dog"]   1   2   
   
"hot", "dog", ["hot","cog","dog","tot","hog","hop","pot","dot"] 0   3   
   
"hot", "dog", ["hot","dog","cog","pot","dot"]   0   3   
   
"hit", "cog", ["hot","cog","dot","dog","hit","lot","log"]   0   5   
   
"hit", "cog", ["hot","hit","cog","dot","dog"]   0   5   
   
"red", "tax", ["ted","tex","red","tax","tad","den","rex","pee"] 0   4   
   
"lost", "cost", ["most","fist","lost","cost","fish"]    1   2   
   
"lost", "miss", ["most","mist","miss","lost","fist","fish"] 0   4   
   
"leet", "code", ["lest","leet","lose","code","lode","robe","lost"]  0   6   
   
"talk", "tail", ["talk","tons","fall","tail","gale","hall","negs"]
 */
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (start == end) return 1;
        int slen = start.size();
        unordered_map<string, pair<int, int> > results;
        queue<string> q;
        q.push(start);
        results[start] = make_pair(1, 0);
        while (!q.empty()) {
            string cur = q.front();            
            q.pop();
            results[cur].second = 1;
            unordered_map<string, pair<int, int> >::iterator it;// = results.find(cur);
            //find all variations by one transformation                      
            for (int i = 0; i < slen; i++) {
                for (int j = 0; j < 26; j++) {
                    if (cur[i] - 'a' == j) continue;
                    
                    string var = cur;
                    var.replace(i, 1, 1, 'a' + j);
                    if (dict.find(var) == dict.end()) continue;
                    if (var == end) {
                        return results[cur].first + 1;
                    }
                    //check var
                    it = results.find(var);
                    if (it != results.end()) {
                        if (it->second.second == 1)
                            continue;
                        if (it->second.first > results[cur].first + 1) {
                            it->second.first = results[cur].first + 1;
                        }
                    } else {
                        results[var] = make_pair(results[cur].first + 1, 0);
                    }     
                    q.push(var);
                }                
            }
        }
        return 0;
    }    
};