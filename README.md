# Host To Network
This program demonstrates how to manually convert 32-bit and 64-bit integers from host byte order (little-endian) to network byte order (big-endian) in C.
## Features
  Uses a union to access integers as both a full number and individual bytes.
  Converts integers by swapping bytes, supporting both 32-bit and 64-bit values.
  Includes multiple methods: union, bitmask/shift, and pointer-based swaps.
  Prints the original and converted values in hexadecimal for easy verification.
  Provides color-coded test output showing [PASS] or [FAIL] for comparisons between methods.
