struct vertex {
        int d;
        int visited;
        //string data;
        vector<int> neighbour; 
        vertex(): d(INT_MAX), visited(0) {
            
        }
    };

class vertex_comparison {
    public:
        vertex_comparison() {}
           
        bool operator() (const vertex *l, const vertex *r) const {
            return l->d <= r->d;
        }
    };

class Solution {
private:    
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
    
    bool myCmp(vertex *a, vertex *b) {
        return a->d <= b->d ? true : false;
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
        words.push_back(end);
        vector<vertex> graph(words.size());
        vertex *gp = graph.data();
        vertex *s, *e;
        for (vector<string>::size_type i = 0; i < words.size(); i++) {
            //gp[i].data = words[i];
            //gp[i].d = 0;
            //gp[i].visited = 0;
            if (words[i] == start) s = gp + i;
            if (words[i] == end) e = gp + i;
            for (vector<string>::size_type j = i + 1; j < words.size(); j++) {
                if (isConnect(words[i], words[j])) {
                    gp[i].neighbour.push_back(j);
                    gp[j].neighbour.push_back(i);
                }
            }
        }
        
        s->d = 1;
        
        set<vertex *, vertex_comparison> q;
        q.insert(s);
        
        while (!q.empty() && e->visited == 0) {
            vertex *v = *q.begin();
            q.erase(q.begin());
            v->visited = 1;
            if (v->d == INT_MAX) return 0;
            //if (isConnect(end, v->data)) return v->d + 2;
            for (int i = 0; i < v->neighbour.size(); i++) {
                int j = v->neighbour[i];                   
                if (gp[j].d > v->d + 1) {
                    q.erase(gp + j);
                    gp[j].d = v->d + 1;
                    q.insert(gp + j);
                }                
            }
        }
        if (e->visited) return e->d;
        return 0;
    }
};