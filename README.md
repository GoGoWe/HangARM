# HangARM

An implementation of Hangman for ARM Cortex CPUs.

Repository: https://github.com/GoGoWe/HangARM/commits/master

# Build Instruction

Create the build:
 - with CMake presets:
   ```cmake --preset arm-cortex-m4```
 - classic:
   ```cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=toolchain.cmake```

Build:
 - with CMake Presets:
  ```cmake --build --preset arm-cortex-m4```
 - classic:
   ```cmake --build build```