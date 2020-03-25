typedef long long ll;

ll fac[nn], ifac[nn];

ll expo(ll n, ll r){
    n %= mod;
    ll res = 1;
    while(r){
        if(r & 1) res = (res * n) % mod;
        n = (n * n) % mod;
        r >>= 1;
    }
    return res;
}

void init(){
    fac[0] = 1;
    for(int i=1; i<nn; i++)
        fac[i] = fac[i-1] * i % mod;
    
    ifac[nn-1] = expo(fac[nn-1], mod-2);
    for(int i = nn-2; i >= 0; i--)
        ifac[i] = ifac[i+1] * (i+1) % mod;                 // 1/n! =  (1/(n+1)!) * (n+1)                 
}

ll ncr(ll n, ll r){
    if(n < r || r < 0 || n < 0) return 0;
    if(n==r || r==0) return 1;
    //return (fac[n] * expo(fac[r], mod-2) % mod * expo(fac[n-r], mod-2) % mod);
    return fac[n] * ifac[r] % mod * ifac[n-r] % mod;
}


// O(n^2)

ll dp[nn][nn];

void indp(){
    for(int i=0; i<nn; i++){
        for(int j=0; j<=i; j++){
            if(! i || ! j) dp[i][j] = 1;
            else{
                dp[i][j] = ( dp[i-1][j-1] + dp[i-1][j] ) % mod;
            }
        }
    }
}

// O(r)

ll ncrr(ll n, ll r){
    r = min(r, n-r);
    ll ans = 1;

    for(int i = 1; i <= r; i++){
        // ans *= (n-r+i);
        // ans /= i;
        // avoid overflow (can still overflw)
        ll h = __gcd(n-r+i, (ll)i);
        ll x = (n-r+i)/h, y = i/h;
        ans *= x;
        ans /= y;
    }
    return ans;
}

// Using Bit (Lucas Theorem) (mod prime, mod small)
// non prime mod => Chinese remainder Theorem
// calculate inverse of any mod => (extended euclid)
