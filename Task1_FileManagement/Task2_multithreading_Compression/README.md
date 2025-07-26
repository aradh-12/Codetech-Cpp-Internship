# Task 2: Multithreaded File Compression Tool (C++)

## Problem Statement:
Build a C++ program that can compress text files using Run-Length Encoding (RLE) and utilizes multithreading to improve performance.

---

##  Features:
-  Uses **multiple threads** to process different parts of a file in parallel.
-  Simple file read/write using `fstream`.
- Implements **Run-Length Encoding (RLE)** for compression.
-  Demonstrates parallelism for better performance.

---

##  Technologies Used:
- C++17
- `fstream`
- `thread` library
- `mutex` for safe concurrent writes

---

##  Folder Structure:
Task2_Multithreading_Compression/
├── main.cpp
├── README.md
└── input.txt


---

## How to Run:

### 1️. Compile:
```bash
g++ main.cpp -o compressor -pthread
2️.Run:
./compressor
 
 
 Sample input.txt:

aaabbbcc
dddddd
eeeffggg
hhiiijjj
kkklllmmm
The output will be saved in a file named compressed.txt.

Optional Extension Ideas:

Add decompression logic to reverse RLE
Measure performance using <chrono>
Compress multiple files using more threads
---
