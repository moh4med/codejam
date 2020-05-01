#include <bits/stdc++.h>

using namespace std;
// This functions finds all primes smaller than limit
// using simple sieve of eratosthenes. It stores found
// primes in vector prime[]
vector<long long >allPrime;
void simpleSieve(long long limit, vector<long long> &prime)
{
    bool mark[limit + 1];
    memset(mark, false, sizeof(mark));

    for (long long i = 2; i <= limit; ++i)
    {
        if (mark[i] == false)
        {
            // If not marked yet, then its a prime
            prime.push_back(i);
            for (long long j = i; j <= limit; j += i)
                mark[j] = true;
        }
    }
}

// Finds all prime numbers in given range using
// segmented sieve
void primesInRange(long long low, long long high)
{
    // Comput all primes smaller or equal to
    // square root of high using simple sieve
    long long limit = floor(sqrt(high)) + 1;
    vector<long long> prime;
    simpleSieve(limit, prime);

    // Count of elements in given range
    long long n = high - low + 1;

    // Declaring boolean only for [low, high]
    bool mark[n + 1];
    memset(mark, false, sizeof(mark));

    // Use the found primes by simpleSieve() to find
    // primes in given range
    for (long long i = 0; i < prime.size(); i++)
    {
        // Find the minimum number in [low..high] that is
        // a multiple of prime[i] (divisible by prime[i])
        long long loLim = floor(low / prime[i]) * prime[i];
        if (loLim < low)
            loLim += prime[i];
        if (loLim == prime[i])
            loLim += prime[i];
        /* Mark multiples of prime[i] in [low..high]: 
			We are marking j - low for j, i.e. each number 
			in range [low, high] is mapped to [0, high - low] 
			so if range is [50, 100] marking 50 corresponds 
			to marking 0, marking 51 corresponds to 1 and 
			so on. In this way we need to allocate space only 
			for range */
        for (long long j = loLim; j <= high; j += prime[i])
            mark[j - low] = true;
    }

    // Numbers which are not marked in range, are prime
    for (long long i = low; i <= high; i++)
        if (!mark[i - low]){
            allPrime.push_back({i});
        }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int totalCases;
    cin >> totalCases;
    for (int caseNum = 1; caseNum <= totalCases; caseNum++)
    {
        long long a, b, p;
        cin >> a >> b >> p;
        primesInRange(a,b);
        // for (int i = 0; i < allPrime.size(); i++)
        // {
        //    cout<<i<<" "<<allPrime[i]<<endl;
        // }
        
    }

    return 0;
}
