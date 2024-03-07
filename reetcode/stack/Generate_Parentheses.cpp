// Generate_Parentheses

class Solution {
public:
    // bool is_valid(string str) {
    //     stack<char> stk;
    //     for(auto el:str) {

    //         if(el=='(')
    //             stk.push(el);
    //         else {  //el==')'
    //             if(!stk.empty() && stk.top() == '(')
    //                 stk.pop();
    //             else
    //                 return (false);
    //         }
    //     }
    //     if(stk.empty())
    //         return (true);
    //     else
    //         return (false);
    // }
    void generate(int n, int open, int close, string str, vector<string>& ret) {
        if(open==n && close==n) {
            ret.push_back(str);
            return ;
        }
        if(open<n)
            generate(n,open+1,close,str+"(",ret);
        if(open>close)
            generate(n,open,close+1,str+")",ret);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        // n개의 ()의 모든 조합을 만들어야한다.
        // n=2: ()(), (())
        // ( 2개, )2개의 모든 조합은 4!개이지만, stack이 텅비면 well-formed parentheses이다.
        // 1.O(n!)
        // string data = "";
        // for(int i=0; i<n; i++)
        //     data+="(";
        // for(int i=0; i<n; i++)
        //     data+=")";
        // do {
        //     if(is_valid(data))
        //         ret.push_back(data); 
        // } while(next_permutation(data.begin(), data.end()));
        // return (ret);
        // 2. O(2^n)
        generate(n,0,0,"",ret);
        return (ret);
    }
};