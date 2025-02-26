# About
This repo shows how to use `import std;` together with C++20 Modules using CMake, clang++, and Ninja [ft. `vcpkg`].
## Project Structure
It has 
- `kk` module in the core lib split into interface \[`kk.cppm`] and implementation [`kk.cc`] files
- `utils` module in the lib utils, split into the primary module \[`utils.cppm`] + its implementation file \[`utils.cc`] as well as a module partition \[`utils-random.cppm`] + its implementation file \[`utils-random.cc`], so you can see different ways of using modules. Yes, it's a random partition, no particular meaning; you can rename it to `utils-part.cppm/utils-part.cc` if you want
- `main.cc` uses the `kk` module and the `std` library; `kk` is statically linked to the `utils` module


# Requirements \[or basically what I am using haha]
## [LLVM](https://github.com/llvm/llvm-project/)
- [clang 20.1.0-rc](https://github.com/llvm/llvm-project/releases/tag/llvmorg-20.1.0-rc2)
## [CMake](https://cmake.org)
- [CMake 4.0.0-rc2](https://cmake.org/download/) 
- you can use the 3.31 version, but make sure to, in the root `CMakeLists.txt`, change
```cmake
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "a9e1cf81-9932-4810-974b-6eccaf14e457")
```
to
```cmake
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "0e5b6991-d74f-4b3d-a41c-cf096e0b2508")
```
Also see [Kitware's Post](https://www.kitware.com/import-std-in-cmake-3-30/)
## [Ninja](https://github.com/ninja-build/ninja/)
- [ninja 1.12.1](https://github.com/ninja-build/ninja/releases/tag/v1.12.1)
## [vcpkg](https://vcpkg.io/en/)
- download and use instructions: [Microsoft Learn](https://learn.microsoft.com/en-us/vcpkg/get_started/get-started?pivots=shell-bash)
- I don't really use vcpkg here since I'm not using any 3rd-party dependency, since this is just a sort of template, but you can, on your project's root, do:
`vcpkg add port nlohmann-json` for instance, then use CMake's `find_package(...)` corresponding command and carry on from there. `vcpkg` will tell you how the `find_package()` command is to look like once it's finished building the library.

# Build Notes\|Instructions
- I am on Ubuntu 24.04 \[haven't touched Windows these days], but the CMakePresets file has instructions|workflow presets for Windows as well; it should work with minor changes \[for instance, if you're using MSVC instead of `clang-cl`]

- I have all these tools in my `$PATH` environment variable \[cmake, vcpkg, ninja, clang++, etc.]. Again, just for test purposes, something like:
```bash
export TOOLS_DIR=$HOME/dev-tools
export VCPKG_ROOT=$TOOLS_DIR/vcpkg
export CMAKE_ROOT=$TOOLS_DIR/cmake
export LLVM_ROOT=$TOOLS_DIR/llvm
export PATH=$LLVM_ROOT/bin:$VCPKG_ROOT:$CMAKE_ROOT/bin:$PATH
```
- One of the flags I pass to the compiler is `-stdlib=libc++` \[see the CMake Presets file]; therefore, you have to: 
`export LD_LIBRARY_PATH=$LLVM_ROOT/lib/x86_64-unknown-linux-gnu:$LD_LIBRARY_PATH`, otherwise it'll only find GCC's standard library. If you don't want to have this in your shell file \[e.g. `~/.bashrc`], you can just set these variables to your current session and perform your tests, play around, ...

# Building
`cmake workflow lnx-config-build-dbg --fresh`

https://github.com/user-attachments/assets/66eb3525-d7b5-4f1b-996e-f419abb88f09
# Running
`./build/lnx-debug-C/bin/main`
# Remarks
- Yes, I'm using bleeding-edge versions of CMake and clang. However, I had tried it with both CMake and clang++ stable versions and it works; so, you can use CMake 3.31.6 and [Clang 19.1.7](https://github.com/llvm/llvm-project/releases/tag/llvmorg-19.1.7) if you want to.
- Yes, I know, it'd be nice to have `vcpkg` as a git submodule instead of installing in on our machines like this project does, but this is not the goal of this project\[I just mean to use C++20 and `import std;` with CMake, clang and Ninja]. If you're just learning how to work with these tools first, before contributing to projects, with many devs, etc., it's okay to have vcpkg locally on your machine. I, for instance, have mine here. 
- Regarding C++20 Modules, there's also submodules \[which are just basic primary modules, but hinting to some structure information via its naming ], **private module fragment**, and so on, that I didn't want to touch upon, because I didn't want to make this too complicated.
- If you need help downloading the tools, building the project or even understanding how it's set up, feel free to contact me at our [C++ Discord Group](https://discord.gg/RAxWbgR3qM) and I'll gladly help you out.
- I'm just a learner. This might not be the best setup, but could serve as something for you to start with. Feel free to suggest improvements. Thank you.