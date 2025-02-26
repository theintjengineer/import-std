/*
 * Module Implementation Unit
 */

module utils;

namespace utils {
    void hello() {
        std::println("Hello from utils!");
    }
}

/*
- no need for `import std;` here
- in the module impl. unit we can use utils.cppm's `import std;`
- we need import std; for std::println()
*/
