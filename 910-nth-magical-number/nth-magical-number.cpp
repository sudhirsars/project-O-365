class Solution {
public:

    int nthMagicalNumber(int n, int a, int b) {
        const int  m=1e9+7;
         long long g=__gcd(a,b);
         long long l=(a*b)/g;

        auto check=[&](long long mid){
            long long x=mid/a,y=mid/b;
            long long k=x+y-(mid/l);
            return k<n;
        };
        long long s=1,e=1e18,ans=1;
        while(s<=e){
            long long mid=s+(e-s)/2;
            if(check(mid)){
                ans=mid;
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        ans++;
        return ans%m;
        
    }
};
