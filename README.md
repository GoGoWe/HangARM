HangARM

# Build Instruction

Erstellen des Build:
 - Mittels CMake Presets:
   ```cmake --preset arm-cortex-m4```
 - Klassisch:
   ```cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=toolchain.cmake```

Bauen:
 - Mittels CMake Presets:
  ```cmake --build --preset arm-cortex-m4```
 - Klassisch:
   ```cmake --build build```