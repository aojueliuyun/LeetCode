#include<iostream>
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<array>
#include<stack>
#include<queue>
#include<deque>
#include<cctype>
#include<numeric>
#include<unordered_map>
using namespace std;

// 2018.7.21

// leetcode 204 countPrimes 

// question : How to get prime numbers ?
// answer:    traverse -----> O(n^2)
//             



// solution 1 : traverse 
// time: O(n^1.5)
// space: O(1)
class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        for (int i=2; i < n; i++)
            if (isPrime(i)) count ++;
        return count;
    }
    bool isPrime(int n) {
        for (int i = 2; i <= int(sqrt(n)); i ++) {
            if (n % i == 0) return false;
        }
        return true;
    }
}; 


// solution 2 : the Sieve of Eratosthenes 
// link : https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
// time: O(n*loglogn)   how to prove? 
// space: O(n)
class Solution2 {
public:
    int countPrimes(int n) {
        bool * primes = new bool[n];
        memset(primes, true, sizeof(bool)*n); // dynamic allocation, can not use sizeof(primes), header: <cstring>
        primes[0] = primes[1] = false;
        for (int i=2; i*i < n; i ++) {
            if (primes[i]) {
                for (int j=i*i; j < n; j+=i) primes[j] = false;
            }
        }
        int count = 0;
        for (int i=0; i < n; i++) {   
            if (primes[i]) count ++;
        }
        delete [] primes;
        return count;
    }
};


// solution 3 : the sieve of Euler ---------------> to be continued ... not right
// time: O(m)
// space: O(n) 
class Solution3 {
public:
    int countPrimes(int n) {
        bool * isprime = new bool[n];
        int * primes = new int [n];
        memset(isprime, true, sizeof(bool)*n);
        memset(primes, 0, sizeof(int)*n);
         isprime[0] = isprime[1] = false;
         int count = 0;
         for (int i=2; i*i < n; i ++) {
             if (isprime[i]) {
                 primes[count++] = i;
                 for (int j=0; j < count && i*primes[j] <= n; j ++) {
                     isprime[i*primes[j]] = false;
                     if (i % primes[j] == 0) break; // key point
                }
            }
        }
        delete [] isprime, primes;
        return count;
    }
};





int main()
{
    int n;
    Solution3 S;
    while (cin >> n) {
        cout << S.countPrimes(n) << endl;
    }

    return 0;
}

