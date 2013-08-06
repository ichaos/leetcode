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
        map<string, int> dis;
        
        if (start == end) {
            //vector<string>
            return ret;
        }
        int level1 = 1;
        int level2 = 0;
        //int length = 0;
        queue<string> q;
        q.push(start);
        int distance = 1;
        dis[start] = 0;
        dict.insert(end);
        bool find = false;
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
                        if (dis[tmp] < distance && (dis[t] == 0 || dis[t] >= distance)) {
                            if (path[t].empty())
                                q.push(t);
                            level2++;
                            dis[t] = distance;
                            cout << tmp << " -> " << t << endl;
                            path[t].push_back(tmp);
                        }
                    }
                    if (end == t) { //find one
                        find = true;
                    }
                }
            }
            
            if (level1 == 0) {
                //length++;
                if (find) {
                    vector<string> cur;                        
                    findPath(path, end, cur, ret);
                    return ret;
                }
                distance++;
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
    //"hot","cog","dot","dog","hit","lot","log"
    //"red", "tax", ["ted","tex","red","tax","tad","den","rex","pee"]   
    dict.insert("ted");
    dict.insert("pee");
    dict.insert("tex");
    dict.insert("red");
    dict.insert("tax");
    dict.insert("tad");
    dict.insert("den");
    dict.insert("rex");

    vector<vector<string> > ret = s.findLadders("red", "tax", dict);
    for (int i = 0; i < ret.size(); i++) {

        for (int j = 0; j < ret[i].size(); j++) {
            cout << ret[i][j] << " ";
        }
        cout << endl;
    }

}