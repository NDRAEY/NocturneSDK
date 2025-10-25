# NocturneSDK
NocturneOS SDK - modular toolkit for working with compilers that doesn't implement a support for NocturneOS.

It includes:
- Nocturne LibC (standard C library)
- Nocturne LibM (standard math library)
- Nocturne-CC (compiler wrapper)

# Installation
```bash
cmake -B build .
cmake --build build/
sudo cmake --install build/
```

After installation you'll find libraries, header files and Nocturne-CC at `/usr/local/nocturneos/`.

> [!IMPORTANT]
> Be sure to add `/usr/local/nocturneos/bin` to your `$PATH` and restart your shell to apply your changes.

# Usage
Run `nocturneos-cc.py --help` to view Nocturne-CC usage.

## Examples

Compile single file to the program:
```bash
nocturneos-cc.py main.c -o myprogram
```

Compile single file to the object file:
```bash
nocturneos-cc.py -c main.c -o myprogram
```
