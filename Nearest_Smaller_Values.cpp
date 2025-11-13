#include <iostream>

// Required headers for ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

// Use the namespace for pb_ds
using namespace __gnu_pbds;

// Define the ordered_set type
// int: the type of data stored
// null_type: map-like behavior (if you wanted a map, you'd use a value type here)
// less<int>: the comparison function
// rb_tree_tag: the tree structure to use (Red-Black Tree)
// tree_order_statistics_node_update: policy to enable order statistics
typedef tree<int, null_type, std::less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    ordered_set s;

    s.insert(10);
    s.insert(20);
    s.insert(5);
    s.insert(15);

    // s is now {5, 10, 15, 20}

    // Find the k-th element (0-indexed)
    // find_by_order(k): returns an iterator to the k-th element
    std::cout << "The 2nd element (index 1) is: " << *s.find_by_order(1) << std::endl; // Output: 10
    std::cout << "The 4th element (index 3) is: " << *s.find_by_order(3) << std::endl; // Output: 20

    // Find the number of elements strictly less than a value
    // order_of_key(x): returns the number of items strictly smaller than x
    std::cout << "Number of elements less than 12: " << s.order_of_key(12) << std::endl; // Output: 2 (since 5 and 10 are < 12)
    std::cout << "Number of elements less than 5: " << s.order_of_key(5) << std::endl;   // Output: 0

    return 0;
}