class Solution {
public:
    int cnt_ch[26];

    int characterReplacement(string s, int k) {
        int st = 0;
        int en = 0;
        int ret = 0;
        int max_ch = -1;

        while(en < s.size()) {
            cnt_ch[s[en]-'A']++;
            if(max_ch < cnt_ch[s[en]-'A'])
                max_ch = cnt_ch[s[en]-'A'];
            if(en-st+1-max_ch > k) {
                cnt_ch[s[st]-'A']--;
                st++;
            }
            if(ret <= en-st+1) {
                ret = en-st+1;
            }
            en++;
        }
        return (ret);
    }
};