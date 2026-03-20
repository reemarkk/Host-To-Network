# HostToNetwork64

This program demonstrates how to convert a **64-bit integer from host byte order (little-endian)** to **network byte order (big-endian)** manually in C.

## Features

- Uses a **union** to access a 64-bit integer both as a number and as 8 individual bytes.  
- Swaps bytes to convert from **little-endian → big-endian**.  
- Prints both the **original** and **converted** values in hexadecimal.  
