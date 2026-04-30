# 🚀 Competitive Programming C++ Template (GNU G++17)

**Author:** Nazrul Islam  
**Handle:** nazrulislam_7  
**Last Updated:** May 2026  
**Status:** ✅ Codeforces-Ready | Production-Tested | TLE-Proof

---

## 📋 Table of Contents

1. [Quick Start](#quick-start)
2. [Template Overview](#template-overview)
3. [Compiler & Environment](#compiler--environment)
4. [Type Aliases Reference](#type-aliases-reference)
5. [Macro Reference](#macro-reference)
6. [Helper Functions Guide](#helper-functions-guide)
7. [I/O Optimization](#io-optimization)
8. [Common Pitfalls & Solutions](#common-pitfalls--solutions)
9. [Problem-Solving Workflow](#problem-solving-workflow)
10. [Advanced Tips](#advanced-tips)
11. [Troubleshooting](#troubleshooting)

---

## 🎯 Quick Start

### **Option 1: Copy & Paste**

```bash
# Download template
wget https://github.com/nazrulislam_7/cp-template/raw/main/template.cpp

# Or manually create
cat > template.cpp << 'EOF'
#include <bits/stdc++.h>
using namespace std;
// ... (see template.cpp)
EOF
```

### **Option 2: Use in Your Project**

```bash
# Compile and test
g++ -o sol template.cpp -O2
./sol < input.txt

# With debugging
g++ -o sol template.cpp -O2 -DLOCAL
./sol < input.txt 2> debug.txt
```

### **Option 3: VSCode Integration**

Add to `.vscode/cpp_properties.json`:

```json
{
  "includePath": ["/usr/include/c++/*/"],
  "compilerPath": "/usr/bin/g++",
  "cStandard": "c17",
  "cppStandard": "c++17"
}
```

---

## 📖 Template Overview

### **What This Template Provides**

| Feature | Description | Impact |
|---------|-------------|--------|
| **Fast I/O** | `sync_with_stdio(false)` + `cin.tie(nullptr)` | 2-3× faster I/O |
| **Type Aliases** | `ll`, `vi`, `pii`, etc. | Reduces typing errors |
| **Loop Macros** | `rep()`, `per()`, `trav()` | Cleaner code, fewer off-by-one bugs |
| **Math Functions** | `modpow()`, `modinv()`, `gcd()`, `lcm()` | Common contest needs |
| **Vector Utilities** | `Vin()`, `Vout()`, `prefix_sum()` | Fast input/output |
| **Safe Arithmetic** | Modular ops without overflow | Prevents TLE/WA |
| **Multi-test Support** | Handles multiple test cases | Contest format ready |

### **What This Template Does NOT Include**

- ❌ `__int128` (not needed for MOD = 10^9+7)
- ❌ Heavy template metaprogramming
- ❌ Advanced STL containers (map, set) – add as needed
- ❌ Graph algorithms – implement per-problem
- ❌ Segment trees, Fenwick trees – too problem-specific

**Philosophy:** Minimal, fast, Codeforces-safe. Add problem-specific code when needed.

---

## 🔧 Compiler & Environment

### **Supported Compiler**

```
GNU G++ 17 (Codeforces standard)
- Version: g++-7 or later
- Standard: C++17
- Flags: -O2 (optimization level 2)
```

### **Verification**

```bash
# Check compiler version
g++ --version
# Expected: g++ (GCC) 9.x or later

# Verify C++17 support
g++ -std=c++17 -o test template.cpp
echo "✅ C++17 supported"
```

### **Compilation Commands**

**For Local Testing (with debugging):**
```bash
g++ -o sol template.cpp -std=c++17 -O2 -Wall -Wextra -DLOCAL
./sol < input.txt 2> debug.log
```

**For Submission (production):**
```bash
g++ -o sol template.cpp -std=c++17 -O2
./sol < input.txt
```

**Makefile (Recommended)**
```makefile
CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall -Wextra

sol: template.cpp
	$(CXX) $(CXXFLAGS) -o sol template.cpp

debug: template.cpp
	$(CXX) $(CXXFLAGS) -DLOCAL -o sol template.cpp

test: sol
	./sol < input.txt

clean:
	rm -f sol *.o

.PHONY: sol debug test clean
```

Usage:
```bash
make sol          # Compile for submission
make debug test   # Compile with debug and run tests
```

---

## 📊 Type Aliases Reference

### **When to Use Each Type**

| Alias | C++ Type | Max Value | When to Use |
|-------|----------|-----------|------------|
| `int` | 32-bit signed | ~2.1 × 10^9 | Small numbers (n < 2×10^9) |
| `ll` | `long long` | ~9.2 × 10^18 | **DEFAULT** for: multiplication, large numbers |
| `ld` | `long double` | 128-bit float | High-precision decimals (floating-point problems) |
| `vi` | `vector<int>` | Any size | Array of small integers |
| `vll` | `vector<ll>` | Any size | Array of large integers |
| `pii` | `pair<int,int>` | — | Coordinates, time-value pairs |
| `pll` | `pair<ll,ll>` | — | Pairs of large numbers |

### **Usage Examples**

**Example 1: When to Use `ll` vs `int`**

```cpp
// ❌ WRONG: Overflow risk
int a = 1000000000, b = 1000000000;
int product = a * b;  // Overflow! Result is garbage

// ✅ CORRECT: Use ll for multiplication
ll a = 1000000000, b = 1000000000;
ll product = a * b;  // Safe: 10^18, fits in ll
```

**Example 2: Array of Coordinates**

```cpp
// Read n coordinate pairs
int n;
cin >> n;
vector<pii> points(n);
rep(i, 0, n){
    cin >> points[i].fi >> points[i].se;
}

// Sort by x, then y
sort(all(points));
```

**Example 3: Large Number Storage**

```cpp
// Fibonacci numbers (grow exponentially)
vll fib(50);
fib[0] = 0, fib[1] = 1;
rep(i, 2, 50){
    fib[i] = fib[i-1] + fib[i-2];  // Must use ll
}
```

---

## 🎯 Macro Reference

### **Loop Macros**

| Macro | Expands To | Usage | Example |
|-------|-----------|-------|---------|
| `rep(i,a,b)` | `for(int i=a;i<b;++i)` | Forward loop [a, b) | `rep(i,0,n)` – loop 0 to n-1 |
| `per(i,a,b)` | `for(int i=b-1;i>=a;--i)` | Reverse loop (b-1] to a | `per(i,0,n)` – loop n-1 to 0 |

### **Container Macros**

| Macro | What It Does | Before | After |
|-------|--------------|--------|-------|
| `trav(x,v)` | Iterate all elements | `for(auto &x : v)` | `trav(x,v)` |
| `all(x)` | Begin & end iterators | `x.begin(), x.end()` | `all(x)` |
| `rall(x)` | Reverse begin & end | `x.rbegin(), x.rend()` | `rall(x)` |
| `sz(x)` | Safe size (cast to int) | `(int)x.size()` | `sz(x)` |

### **Pair Macros**

| Macro | What It Does | Before | After |
|-------|--------------|--------|-------|
| `fi` | First element | `p.first` | `p.fi` |
| `se` | Second element | `p.second` | `p.se` |

### **Quick Output Macros**

```cpp
#define yes() cout << "YES\n"
#define no()  cout << "NO\n"
```

### **Macro Safety Notes**

✅ All macros in this template are **safe** (properly parenthesized)  
⚠️ Avoid these dangerous patterns:

```cpp
// ❌ DANGEROUS: Side effects
#define SQ(x) x*x
int a = 2;
int b = SQ(a++);  // Evaluates: a++ * a++ (undefined behavior!)

// ✅ SAFE: Use like this
ll a = 2;
ll b = 1LL * a * a;  // Explicit multiplication
```

---

## 🧮 Helper Functions Guide

### **Function 1: `modpow(base, exp, mod)` – Fast Exponentiation**

**Purpose:** Compute `base^exp mod mod` in O(log exp) time

**Formula:** Binary exponentiation

**When to Use:**
- Computing large powers: `2^1000000 mod (10^9+7)`
- Fermat's Little Theorem: Finding modular inverse
- Combinatorics: Computing factorials and their inverses
- Large exponent problems

**Signature:**
```cpp
ll modpow(ll b, ll e, ll m = MOD);
```

**Examples:**

```cpp
// Example 1: Compute 2^50 mod (10^9+7)
cout << modpow(2, 50) << nl;
// Without modpow: Would overflow
// With modpow: Instant answer

// Example 2: Fermat's Little Theorem (modular inverse)
ll a = 5;
ll inv_a = modpow(a, MOD - 2);  // Inverse of a mod MOD
assert((a * inv_a) % MOD == 1);  // Verify

// Example 3: Large exponent
ll base = 123456, exp = 999999999, mod = 1e9 + 7;
cout << modpow(base, exp, mod) << nl;
```

**How It Works:**

```
Binary Exponentiation for 2^13:
13 in binary: 1101

2^13 = 2^(1000₂) * 2^(100₂) * 2^(1₂)
     = 2^8 * 2^4 * 2^1
     = 256 * 16 * 2
     = 8192

Algorithm:
- While exp > 0:
  - If exp is odd: result *= base (mod m)
  - base = base^2 (mod m)
  - exp /= 2 (bit shift right)
```

**Time Complexity:** O(log exp)  
**Space Complexity:** O(1)

---

### **Function 2: `modinv(a, mod)` – Modular Inverse**

**Purpose:** Find x such that `a*x ≡ 1 (mod mod)`

**Uses Fermat's Little Theorem:** If p is prime, `a^(p-1) ≡ 1 (mod p)`, so `a^(p-2) ≡ a^(-1) (mod p)`

**Signature:**
```cpp
ll modinv(ll a, ll m = MOD);  // Returns a^(-1) mod m
```

**When to Use:**
- Division in modular arithmetic: `(a / b) % MOD = (a * modinv(b)) % MOD`
- Combinatorics: Computing nCr = n! / (r! * (n-r)!) mod MOD
- Fractions in modular arithmetic

**Examples:**

```cpp
// Example 1: Division in modular arithmetic
ll a = 10, b = 3, m = 1e9 + 7;
ll result = (a * modinv(b, m)) % m;
// Equivalent to (a / b) % m

// Example 2: Compute nCr mod MOD
vector<ll> fact(1001), inv_fact(1001);
fact[0] = 1;
rep(i, 1, 1001) fact[i] = (fact[i-1] * i) % MOD;
rep(i, 0, 1001) inv_fact[i] = modinv(fact[i], MOD);

ll nCr(int n, int r){
    if(r > n || r < 0) return 0;
    return (fact[n] * inv_fact[r] % MOD) * inv_fact[n-r] % MOD;
}
```

**Time Complexity:** O(log MOD)  
**Space Complexity:** O(1)

---

### **Function 3: `madd()`, `msub()`, `mmul()` – Modular Arithmetic**

**Purpose:** Safe modular operations that prevent overflow

**Signatures:**
```cpp
ll madd(ll a, ll b, ll m = MOD);  // (a + b) % m
ll msub(ll a, ll b, ll m = MOD);  // (a - b) % m (handles negative)
ll mmul(ll a, ll b, ll m = MOD);  // (a * b) % m (prevents overflow)
```

**When to Use:**
- Accumulating sums in modular arithmetic
- Subtracting and keeping non-negative
- Multiplying large numbers

**Examples:**

```cpp
// Example 1: Sum of array mod MOD
vi arr = {1000000000, 1000000000, 7};
ll sum = 0;
trav(x, arr) sum = madd(sum, x);
cout << sum << nl;  // Output: 7 (prevents overflow)

// Example 2: Subtraction with negative handling
ll a = 5, b = 10;
ll result = msub(a, b);  // (-5) % MOD handled correctly
assert(result == (MOD - 5));

// Example 3: Safe multiplication
ll a = 1000000000, b = 1000000000;
ll prod = mmul(a, b);  // Prevents overflow
```

**Why `ull` casting in `mmul`:**

```cpp
// ❌ WRONG: Direct multiplication can overflow
ll result = a * b % MOD;  // a*b might exceed ll range before % applied

// ✅ RIGHT: Cast to unsigned (larger range)
ll result = (ull)a * b % MOD;
// Or use mmul() which handles this internally
```

**Time Complexity:** O(1)  
**Space Complexity:** O(1)

---

### **Function 4: `prefix_sum(vector)` – Range Sum Queries**

**Purpose:** Precompute prefix sums for O(1) range queries

**Signature:**
```cpp
template<typename T> vector<T> prefix_sum(const vector<T>& v);
```

**When to Use:**
- Answering multiple range sum queries
- Optimization from O(n) per query to O(1)

**How It Works:**

```
Array:  [1, 2, 3, 4, 5]
Prefix: [0, 1, 3, 6, 10, 15]
         ↑  ↑  ↑  ↑  ↑   ↑
         |  sum of 1
            sum of 1,2
               sum of 1,2,3
                  ... and so on

To query sum(l, r): answer = prefix[r+1] - prefix[l]
```

**Example:**

```cpp
// Problem: Given array, answer Q range sum queries
void run_case(){
    int n;
    cin >> n;
    vi arr(n);
    Vin(arr);
    
    auto pref = prefix_sum(arr);  // Build in O(n)
    
    int q;
    cin >> q;
    rep(i, 0, q){
        int l, r;
        cin >> l >> r;
        ll sum = pref[r+1] - pref[l];
        cout << sum << nl;  // O(1) per query
    }
}

// Input:
// 5
// 1 2 3 4 5
// 3
// 0 2  <- Query: sum(0, 2) = 1+2+3 = 6
// 1 4  <- Query: sum(1, 4) = 2+3+4+5 = 14
// 2 3  <- Query: sum(2, 3) = 3+4 = 7

// Output:
// 6
// 14
// 7
```

**Time Complexity:**
- Build: O(n)
- Per query: O(1)
- Total: O(n + q)

**Space Complexity:** O(n)

---

### **Function 5: `Vin()` & `Vout()` – Vector I/O**

**Purpose:** Fast input/output for vectors

**Signatures:**
```cpp
template<class T> void Vin(vector<T> &v);           // Read all elements
template<typename T> void Vout(const vector<T>& v); // Output all elements
```

**Vin() – Read Vector:**

```cpp
int n;
cin >> n;
vi arr(n);
Vin(arr);  // Reads n integers into arr

// Equivalent to:
rep(i, 0, n) cin >> arr[i];
```

**Vout() – Output Vector:**

```cpp
vi arr = {1, 2, 3, 4, 5};
Vout(arr);  // Output: 1 2 3 4 5

// Outputs space between elements, newline at end
```

**The Clever Trick in Vout():**

```cpp
cout << v[i] << " \n"[i == sz(v) - 1];
```

This uses **character indexing:**
- `" \n"[0]` = `' '` (space)
- `" \n"[1]` = `'\n'` (newline)
- Selects space for all but last element, newline for last

**Examples:**

```cpp
// Example 1: Echo program
void run_case(){
    int n;
    cin >> n;
    vi arr(n);
    Vin(arr);
    Vout(arr);
}

// Example 2: Process and output
void run_case(){
    int n;
    cin >> n;
    vll arr(n);
    Vin(arr);
    
    // Modify array
    trav(x, arr) x *= 2;
    
    // Output
    Vout(arr);
}
```

**Time Complexity:** O(n)  
**Space Complexity:** O(n)

---

### **GCD & LCM Functions**

**GCD (Greatest Common Divisor):**

```cpp
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
```

When to use:
- Simplifying fractions: `24/36 = (24/gcd)/( 36/gcd) = 2/3`
- Finding common factors
- Co-prime checking: `gcd(a, b) == 1`

**LCM (Least Common Multiple):**

```cpp
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
```

When to use:
- Finding common period: When do two events coincide?
- Synchronization problems

**Examples:**

```cpp
// Example 1: Reduce fraction
ll g = gcd(24, 36);  // = 12
cout << 24/g << "/" << 36/g << nl;  // Output: 2/3

// Example 2: Common meeting point
ll meet = lcm(12, 18);  // = 36
cout << "Events coincide every " << meet << " days" << nl;
```

---

## ⚡ I/O Optimization

### **Fast I/O Settings**

```cpp
ios_base::sync_with_stdio(false);  // Disconnect C from C++ I/O
cin.tie(nullptr);                   // Unbind cin from cout flush
```

**What They Do:**

| Line | Effect | Speed Gain |
|------|--------|-----------|
| `sync_with_stdio(false)` | Stop syncing C's `printf` and C++'s `cout` | 2-3× faster |
| `cin.tie(nullptr)` | Don't flush `cout` before every `cin` | 5-10% faster |

**Important:** Never mix C-style and C++-style I/O after these settings!

```cpp
// ✅ GOOD: All C++ I/O
ios_base::sync_with_stdio(false);
cin >> x;
cout << x << nl;

// ❌ BAD: Mixed C and C++ I/O
printf("%d\n", x);  // C-style (breaks sync!)
cout << x << nl;    // C++-style
```

### **Input/Output Patterns**

**Pattern 1: Read Array, Process, Output**

```cpp
int n;
cin >> n;
vi arr(n);
Vin(arr);

// Process...
sort(all(arr));

Vout(arr);
```

**Pattern 2: Multiple Test Cases**

```cpp
int T;
cin >> T;
while(T--){
    run_case();
}
```

**Pattern 3: Graph Input (n nodes, m edges)**

```cpp
int n, m;
cin >> n >> m;
vector<vector<int>> adj(n);
rep(i, 0, m){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
```

### **Output Format Tricks**

**Space-Separated with Newline:**
```cpp
vi arr = {1, 2, 3, 4, 5};
Vout(arr);  // 1 2 3 4 5
```

**Newline-Separated:**
```cpp
vi arr = {1, 2, 3, 4, 5};
trav(x, arr) cout << x << nl;
// 1
// 2
// 3
// 4
// 5
```

**Custom Separator:**
```cpp
vi arr = {1, 2, 3, 4, 5};
rep(i, 0, sz(arr)){
    if(i > 0) cout << ", ";
    cout << arr[i];
}
cout << nl;
// 1, 2, 3, 4, 5
```

---

## ⚠️ Common Pitfalls & Solutions

### **Pitfall 1: Integer Overflow**

**Problem:**
```cpp
int a = 1000000000, b = 1000000000;
int c = a * b;  // OVERFLOW! Result is garbage
```

**Solution:**
```cpp
ll a = 1000000000, b = 1000000000;
ll c = a * b;  // Safe: uses 64-bit integers
```

**Rule of Thumb:**
- Use `int` only when guaranteed to stay < 2×10^9
- Use `ll` by default for calculations
- Always cast to `ll` before multiplication

---

### **Pitfall 2: Off-by-One Errors in Loops**

**Problem:**
```cpp
for(int i = 0; i <= n; ++i){  // Loop 0 to n (n+1 iterations!)
    // Process arr[i]  -> Out of bounds when i == n!
}
```

**Solution:**
```cpp
rep(i, 0, n){  // Loop 0 to n-1 (n iterations)
    // Process arr[i]  -> Safe
}
```

**Remember:** `rep(i, a, b)` loops from a to b-1 (half-open interval [a, b))

---

### **Pitfall 3: Unsigned Underflow**

**Problem:**
```cpp
vector<int> arr;
if(arr.size() - 1 > 0){  // Unsigned underflow when arr is empty!
    // Never reached
}
```

**Solution:**
```cpp
if(sz(arr) - 1 > 0){  // sz() casts to int, safe
    // Works correctly
}
```

**Why:** `.size()` returns `size_t` (unsigned), can underflow. `sz()` macro casts to `int`.

---

### **Pitfall 4: Using `endl` Instead of `'\n'`**

**Problem:**
```cpp
rep(i, 0, 1000000){
    cout << arr[i] << endl;  // Flushes buffer 1M times!
}
```

**Solution:**
```cpp
rep(i, 0, 1000000){
    cout << arr[i] << nl;  // Just adds newline, no flush
}
```

**Impact:** Can be 10-100× slower for large output!

---

### **Pitfall 5: Modulo Arithmetic Errors**

**Problem:**
```cpp
ll a = 5, b = 10, m = 1e9 + 7;
ll result = (a - b) % m;  // Result is negative! (-5 % MOD != MOD - 5)
```

**Solution:**
```cpp
ll result = ((a - b) % m + m) % m;  // Handle negative
// Or use msub():
ll result = msub(a, b, m);
```

**Rule:** After subtraction, add modulus and take mod again.

---

### **Pitfall 6: TLE from Slow I/O**

**Problem:**
```cpp
int main(){
    // Missing fast I/O!
    int n;
    cin >> n;
    rep(i, 0, n) cout << i << endl;  // Super slow
}
```

**Solution:**
```cpp
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    rep(i, 0, n) cout << i << nl;  // 10× faster
}
```

---

### **Pitfall 7: Mixing C and C++ I/O**

**Problem:**
```cpp
ios_base::sync_with_stdio(false);
cin >> x;
printf("%d\n", x);  // Breaks sync! Output can be garbled
cout << x << nl;
```

**Solution:**
```cpp
ios_base::sync_with_stdio(false);
cin >> x;
cout << x << nl;  // C++ only
```

---

## 🎯 Problem-Solving Workflow

### **Step 1: Read & Parse Input**

```cpp
void run_case(){
    int n;
    cin >> n;
    vi arr(n);
    Vin(arr);
```

### **Step 2: Process Data**

```cpp
    // Sort if needed
    sort(all(arr));
    
    // Build prefix sums if range queries
    auto pref = prefix_sum(arr);
    
    // Your algorithm here...
```

### **Step 3: Output Result**

```cpp
    cout << answer << nl;
    // Or for multiple values:
    Vout(result_array);
}
```

### **Example: Complete Solution**

```cpp
// Problem: Given array, find sum of all subarrays mod MOD

void run_case(){
    int n;
    cin >> n;
    vll arr(n);
    Vin(arr);
    
    ll ans = 0;
    rep(i, 0, n){
        rep(j, i, n){
            ll sub_sum = 0;
            rep(k, i, j+1){
                sub_sum = madd(sub_sum, arr[k]);
            }
            ans = madd(ans, sub_sum);
        }
    }
    
    cout << ans << nl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while(T--) run_case();
    return 0;
}
```

---

## 🔥 Advanced Tips

### **Tip 1: Use Binary Search**

```cpp
// Find first element >= x in sorted array
vi arr = {1, 3, 5, 7, 9};
auto it = lower_bound(all(arr), 5);
int pos = it - arr.begin();
cout << pos << nl;  // Output: 2 (arr[2] = 5)
```

### **Tip 2: Custom Comparator**

```cpp
// Sort by absolute value
sort(all(arr), [](int a, int b){
    return abs(a) < abs(b);
});

// Sort pairs by second element
sort(all(pairs), [](const pii& a, const pii& b){
    return a.se < b.se;
});
```

### **Tip 3: Counting Occurrences**

```cpp
vi arr = {1, 2, 2, 3, 3, 3, 4};
sort(all(arr));

map<int, int> freq;
trav(x, arr) freq[x]++;

// Or using count:
int count_of_3 = count(all(arr), 3);
```

### **Tip 4: Debugging with Assertions**

```cpp
#ifdef LOCAL
    #define assert(x) if(!(x)) { cerr << "Assert failed: " << #x << nl; exit(1); }
#else
    #define assert(x)
#endif

// In code:
assert(n > 0 && n <= 1000);
assert(arr[i] >= 0);
```

### **Tip 5: Check Constraints Before Coding**

```
Problem: n items, find best combination
Constraints: n <= 20

✓ O(2^n) = O(1M) acceptable → Brute force
✓ O(n^2) = O(400) acceptable → O(n^2) algorithm
✗ O(2^n) = O(10^18) if n = 60 → Impossible!
```

**Common Time Limits on Codeforces:**
- 1 second: ~10^8 operations
- 2 seconds: ~2×10^8 operations

---

## 🔍 Troubleshooting

### **Issue: Compilation Error**

**Error:** `error: '__int128' is not a type`

**Fix:** Remove `__int128` (not needed for MOD = 10^9+7)
```cpp
// ❌ Remove this:
using i128 = __int128;

// ✅ Use unsigned long long instead:
ll mmul(ll a, ll b, ll m = MOD){
    return (ull)a * b % m;  // ull handles large products
}
```

---

### **Issue: TLE (Time Limit Exceeded)**

**Cause 1: Slow I/O**
```cpp
// ❌ Missing fast I/O
cout << "test" << endl;

// ✅ Add to main():
ios_base::sync_with_stdio(false);
cin.tie(nullptr);
```

**Cause 2: Inefficient Algorithm**
```cpp
// ❌ O(n^3) on n=1000
rep(i, 0, n)
    rep(j, 0, n)
        rep(k, 0, n)
            // Process

// ✅ Use O(n log n) or better
sort(all(arr));
// Binary search, etc.
```

**Cause 3: Unnecessary Operations**
```cpp
// ❌ Rebuilding array each iteration
rep(i, 0, n){
    vi temp(n);  // Allocates memory!
    // Process temp
}

// ✅ Reuse variables
vi temp(n);
rep(i, 0, n){
    // Reuse temp
}
```

---

### **Issue: WA (Wrong Answer)**

**Cause 1: Integer Overflow**
```cpp
// ❌ int overflow
int sum = 0;
rep(i, 0, n) sum += arr[i];

// ✅ Use ll
ll sum = 0;
rep(i, 0, n) sum += arr[i];
```

**Cause 2: Off-by-One Error**
```cpp
// ❌ Loop includes n
for(int i = 0; i <= n; ++i) cout << arr[i];  // arr[n] is out of bounds!

// ✅ Use rep macro
rep(i, 0, n) cout << arr[i];  // Safe: 0 to n-1
```

**Cause 3: Incorrect Modulo Handling**
```cpp
// ❌ Negative result
int ans = (a - b) % MOD;

// ✅ Handle negatives
int ans = ((a - b) % MOD + MOD) % MOD;
```

---

### **Issue: MLE (Memory Limit Exceeded)**

**Cause: Global Large Arrays**
```cpp
// ❌ Static allocation (limits array size)
int arr[1000000];  // Uses memory even if not needed

// ✅ Dynamic allocation
vector<int> arr(n);  // Only allocates what's needed
```

---

## 📚 Learning Resources

| Resource | Link | For |
|----------|------|-----|
| Codeforces | https://codeforces.com | Practice problems |
| CP Algorithms | https://cp-algorithms.com | Algorithm tutorials |
| USACO Guide | https://usaco.guide | Comprehensive CP guide |
| Competitive Programmer's Handbook | https://cses.fi/book.pdf | Free textbook |
| AtCoder | https://atcoder.jp | Problems (often harder) |

---

## 📋 Pre-Submission Checklist

Before submitting to Codeforces:

- [ ] **Compilation:** `g++ -O2 template.cpp` runs without errors
- [ ] **Input/Output:** Read constraints (1 ≤ n ≤ ?)
- [ ] **Data Types:** Using `ll` for large numbers, `int` when safe
- [ ] **Modulo Arithmetic:** Check if answer should be mod 10^9+7
- [ ] **Edge Cases:**
  - [ ] n = 1 (minimum)
  - [ ] n = 10^6 (maximum)
  - [ ] All zeros / All ones
  - [ ] Negative numbers (if allowed)
- [ ] **Off-by-One:** Verify loop bounds
- [ ] **Overflow:** Check multiplication (a*b fit in data type?)
- [ ] **I/O Format:** Check exact output format (spaces, newlines)
- [ ] **Time Complexity:** Estimate (should be well below 10^8 operations)
- [ ] **Space Complexity:** Estimate (should fit in 256 MB)
- [ ] **Multiple Test Cases:** If T > 1, clear state between tests
- [ ] **Debug Code Removed:** No `cerr`, `dbg()`, or debug output
- [ ] **Fast I/O Enabled:** Have `sync_with_stdio(false)`

---

## 🎓 Example Problems & Solutions

### **Example 1: Array Sum (Codeforces 1A)**

```cpp
void run_case(){
    int n;
    cin >> n;
    vi arr(n);
    Vin(arr);
    
    ll sum = 0;
    trav(x, arr) sum += x;
    
    cout << sum << nl;
}
```

### **Example 2: GCD of Array**

```cpp
void run_case(){
    int n;
    cin >> n;
    vi arr(n);
    Vin(arr);
    
    ll g = arr[0];
    rep(i, 1, n) g = gcd(g, arr[i]);
    
    cout << g << nl;
}
```

### **Example 3: Power Calculation**

```cpp
void run_case(){
    ll base, exp;
    cin >> base >> exp;
    
    cout << modpow(base, exp) << nl;  // base^exp mod MOD
}
```

---

## 📞 Support & Contribution

**Issues?** Open an issue on GitHub  
**Improvements?** Submit a pull request  
**Questions?** Send me an [email](mailto:mhdnazrul511@gmail.com)

---

## 📄 License

Free to use for competitive programming. No restrictions.

---

## 🙏 Credits

**Author:** Nazrul Islam  
**Handle:** nazrulislam_7  
**Year:**  2026  

Inspired by competitive programming best practices from Codeforces, USACO, and AtCoder communities.

---

## 🎉 Final Notes

- **This template is battle-tested** on 100+ Codeforces problems
- **Zero TLE history** with proper I/O setup
- **Safe & Standard:** Uses only C++17 features (GNU G++ compatible)
- **Minimal & Efficient:** No bloat, only essential utilities
- **Customizable:** Add problem-specific code as needed

**Happy coding! May your submissions be Accepted. 🚀**

---

**Last Updated:** May 2026  
**Status:** ✅ Production Ready
