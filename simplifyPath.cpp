/**
 * Simplify Path
 * Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
 */
class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = path.size();
        stack<string> s;
        string ret;
        if (n < 1) return ret;
        
        s.push("/");
        int i = 1;
        while (i < n) {
            //find next directory
            string next;
            while (i < n) {
                next += path[i];
                i++;
                if (path[i - 1] == '/') {
                    break;
                }
            }
            
            if (next == "/" || next == "./" || next == ".") {
                continue;
            } else if (next == "../" || next == "..") {
                if (s.size() > 1)
                    s.pop();
            } else {
                s.push(next);
            }
        }
        
        while (!s.empty()) {
            ret = s.top() + ret;
            s.pop();
        }
        if (ret.size() > 1 && ret[ret.size() - 1] == '/') ret.resize(ret.size() - 1);
        return ret;
    }
};