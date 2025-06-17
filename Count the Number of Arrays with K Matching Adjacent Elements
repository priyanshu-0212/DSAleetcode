class Solution {
public:   
        int countGoodArrays(int n, int m, int k) {
    const int MOD = 1e9 + 7;
    vector<long long> fact(n + 1, 1), invFact(n + 1, 1);

    auto modPow = [&](long long base, int exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = res * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return res;
    };

    for (int i = 1; i <= n; ++i)
        fact[i] = fact[i - 1] * i % MOD;
    invFact[n] = modPow(fact[n], MOD - 2);
    for (int i = n - 1; i >= 0; --i)
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;

    auto comb = [&](int a, int b) {
        if (b < 0 || b > a) return 0LL;
        return fact[a] * invFact[b] % MOD * invFact[a - b] % MOD;
    };

    long long res = comb(n - 1, k) * m % MOD * modPow(m - 1, n - 1 - k) % MOD;
    return (int)res;
}

};
