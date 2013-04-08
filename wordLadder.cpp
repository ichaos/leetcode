class Solution {
private:
    struct vertex {
        int d;
        int visited;
        //string data;
        vector<int> neighbour;        
    };
    
    bool isConnect(string a, string b) {
        int diffcnt = 0;
        if (a.size() != b.size()) return false;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i]) {
                if (diffcnt) return false;
                diffcnt++;
            }
        }
        return diffcnt == 1;
    }
    
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (isConnect(start, end)) return 2;
        vector<string> words;
        //dict.insert(start);
        for (unordered_set<string>::iterator it = dict.begin(); it != dict.end(); it++) {
            words.push_back(*it);
        }
        words.push_back(start);
        vector<vertex> graph(words.size());
        vertex *gp = graph.data();
        vertex *s;
        for (vector<string>::size_type i = 0; i < words.size(); i++) {
            //gp[i].data = words[i];
            //gp[i].d = 0;
            //gp[i].visited = 0;
            if (words[i] == start) s = gp + i;
            for (vector<string>::size_type j = i + 1; j < words.size(); j++) {
                if (isConnect(words[i], words[j])) {
                    gp[i].neighbour.push_back(j);
                    gp[j].neighbour.push_back(i);
                }
            }
        }
        
        queue<vertex *> q;
        q.push(s);
        
        while (!q.empty()) {
            vertex *v = q.front();
            q.pop();
            v->visited = 1;
            //if (isConnect(end, v->data)) return v->d + 2;
            for (int i = 0; i < v->neighbour.size(); i++) {
                int j = v->neighbour[i];
                if (gp[j].visited) continue;
                if (isConnect(end, words[j])) {
                    return v->d + 3;
                }
                gp[j].d = v->d + 1;
                q.push(gp + j);
            }
        }
        return 0;
    }
};