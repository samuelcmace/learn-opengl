# learn-opengl
Following along with Ben Cook's OpenGL course on Udemy.

## Requirements
You should be able to run this code on both Windows and Linux (assuming the PC has an up-to-date graphics card and driver).

You will need a C++ compiler (such as MSVC or GCC) and the CMake build system. All other libraries should be included in the project source code and statically linked during compilation.

## Linux Build Instructions
```
mkdir build
cd build
cmake ..
make -j$(nproc)
```