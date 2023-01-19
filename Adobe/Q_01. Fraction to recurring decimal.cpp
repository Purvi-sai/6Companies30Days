class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(!numerator) return "0";
        string ans = "";
        if (numerator > 0 ^ denominator > 0) ans += '-';
        long n = labs(numerator), d = labs(denominator);
        long div = n / d;
        long r = n % d;
        ans += to_string(div);
        
        if(r == 0) return ans;
        
        ans += '.';
        unordered_map<long, int> umap;
        while(r != 0){
            if(umap.find(r) != umap.end()){
                int pos = umap[r];
                ans.insert(pos, "(");
                ans += ')';
                break;
            }
            else{
                umap[r] = ans.length();
                r *= 10;
                div = r / d;
                r = r % d;
                ans += to_string(div);
            }
        }
        return ans;
    }
};
