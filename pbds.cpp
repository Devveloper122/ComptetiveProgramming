
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
typedef tree<long long, null_type, less<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds; 

// 1). Basic functions:

//     find_by_order(k): returns the iterator of the kth element (0 based indexing) in the set.         O(logn)
//     order_of_key(k) : It returns number of elements strictly less than k.                            O(logn)

//     in normal ordered functions such as st.find(), all work but in multiordered
//     set some functions don't work such as st.find(key) and st.erase(key) there 
//     we have to use iterator instead of passing key.


//     https://codeforces.com/blog/entry/88193

// 2). to use duplicates elements in pbds change {less} -> {less_equal} in above code.
//     this will change behaviour of 2 functions:

//     a). st.erase() will not work.
//     b). st.lower_bound() & st.upper_bound() will exchange there properties.

//     now to erase any element from set use st.erase(st.upper_bound(element)).
        
