#include <iostream>
using namespace std;
typedef long long ll;

ll mod_exp(ll base, ll exp, ll mod) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int n, m;
    ll q;
    cin >> n >> m >> q;
    
    // Total number of sequences
    ll total_sequences = mod_exp(1LL << m, n, q);

    // Calculate the number of sequences where bitwise AND of any non-empty subsequence is not 1
    ll exclusion_count = 0;
    ll power_of_two = 1;
    for (int i = 0; i < m; ++i) {
        power_of_two = (power_of_two * 2) % q;
    }
    ll valid_numbers = power_of_two - 1; // Numbers less than 2^m but not necessarily containing 1 as a bit
    
    exclusion_count = mod_exp(valid_numbers, n, q);
    
    // Valid sequences count
    ll valid_sequences = (total_sequences - exclusion_count + q) % q;
    cout << valid_sequences << endl;
    return 0;
}
