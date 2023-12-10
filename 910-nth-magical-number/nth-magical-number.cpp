class Solution {
public:

    int nthMagicalNumber(int n, int a, int b) {

         const int  m=1e9+7;
         long long g=__gcd(a,b);
         long long l=(a*b)/g;
         auto check=[&](long long mid)
         {
             long long x=mid/a,y=mid/b;
             long long k=x+y-(mid/l);
                
               
                 return k<n;
         };

         long long low=1,high=1e18,ans=1;
         while(low<=high)
         {
             long long mid=(low+(high-low)/2);
             if(check(mid))
             {
                 ans=mid;
                 low=mid+1;
             }
             else 
              high=mid-1;
         }
         return (ans+1)%m;


         
        
    }
};