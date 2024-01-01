#define ll long long
class Solution {
public:
    int gcd(int a,int b){
        if(!b) return a;
        return gcd(b,a%b);
    }

    int lcm(ll a,ll b){
        ll temp = (a/gcd(a,b))*b;
        return temp>INT_MAX ? INT_MAX : temp;
    }
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        int l = 1; int r = INT_MAX;
        int lcm_val = lcm(divisor1,divisor2);
        while(l<=r){
            int mid = l+(r-l)/2;
            int a = mid - (mid/divisor1);
            int b = mid - (mid/divisor2);
            if(uniqueCnt1 <= a && uniqueCnt2<=b && uniqueCnt1+uniqueCnt2 <= (mid - (mid/lcm_val))){
                r = mid-1;
            }else l = mid+1;
        }
        return l;
    }
};