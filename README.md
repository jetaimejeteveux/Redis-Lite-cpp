# Redis Lite C++

A lightweight Redis-like in-memory key-value store server implemented in C++.

## Features

- In-memory key-value store with string data type
- Basic Redis commands: SET, GET, DEL
- Thread-safe operations
- TCP server for client communication (future plan)
- Comprehensive logging (future plan)
- Persistence support (future plan)

## Building

### Prerequisites

- C++17 compatible compiler
- CMake 3.10+
- GNU Make or similar build tool

### Compilation

```bash
mkdir build
cd build
cmake ..
make
```

### Running the test

```bash
make
./bin/redis-lite-tests
```
