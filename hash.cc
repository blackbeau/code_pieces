#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;


typedef gp_hash_table<int, int, hash<int>, equal_to<int>, direct_mod_range_hashing<int>, linear_probe_fn<>,
                      hash_standard_resize_policy<hash_prime_size_policy, hash_load_check_resize_trigger<true>, true>>
    gp;


struct custom_hash {
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return x ^ FIXED_RANDOM;
    }
};


unordered_map<int, int, custom_hash> freq;


