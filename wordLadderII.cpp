#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

class Solution {
private:
    void findPath(map<string, vector<string> > &path, string end, vector<string> cur, 
        vector<vector<string> > &ret) {
        cur.insert(cur.begin(), end);
        if (path.find(end) == path.end()) {
            ret.push_back(cur);
            return;
        }
        vector<string> prev = path[end];
        
        for (int i = 0; i < prev.size(); i++) {
            findPath(path, prev[i], cur, ret);
        }
    }
public:
    vector<vector<string> > findLadders(string start, string end, set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<string> > ret;
        set<string> pass;
        
        map<string, vector<string> > path;
        
        if (start == end) {
            //vector<string>
            return ret;
        }
        int level1 = 1;
        int level2 = 0;
        //int length = 0;
        queue<string> q;
        q.push(start);
        
        while (!q.empty()) {
            string tmp = q.front();
            q.pop();
            level1--;
            pass.insert(tmp);
            
            for (int i = 0; i < tmp.size(); i++) {
                for (int j = 0; j < 26; j++) {
                    string t = tmp;
                    t[i] = 'a' + j;                    
                    if (dict.find(t) != dict.end() && pass.find(t) == pass.end()) {
                        q.push(t);
                        level2++;
                        cout << tmp << " -> " << t << endl;
                        path[t].push_back(tmp);
                    }
                    if (end == t) { //find one
                        if (dict.find(t) == dict.end()) {
                            cout << tmp << " -> " << t << endl;
                            path[t].push_back(tmp);
                        }
                        vector<string> cur;                        
                        findPath(path, end, cur, ret);
                    }
                }
            }
            
            if (level1 == 0) {
                //length++;
                if (!ret.empty()) return ret;
                level1 = level2;
                level2 = 0;
            }
        }
        
        return ret;
    }
};

int main() {
    Solution s;
    set<string> dict;
    dict.insert("hot");
    dict.insert("hog");
    dict.insert("dot");
    dict.insert("dog");

    vector<vector<string> > ret = s.findLadders("hot", "dog", dict);
    for (int i = 0; i < ret.size(); i++) {

        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }

}