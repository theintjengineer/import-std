/*
 * Module Partition Interface Unit [PIU]
 */

export module utils:random;
import std;

export namespace utils::random {
    constexpr std::string part_name{"utils::random"};
    void print_partition_name();
}

/*
- we need `import std;` here
- PIUs can't directly their primary module interface unit's imports
- here we need import std; for std::string, for instance.
*/