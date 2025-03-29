# Brainfuck Compiler 🚀

A **Brainfuck** to **x86-64 GNU AT&T Assembly** compiler written in **C++17**. This compiler translates Brainfuck code into assembly and generates an executable file. It runs on **Linux** and **macOS (Intel chips only)**.

## Features 🎯
- Reads Brainfuck code from a file
- Compiles it to **x86-64 GNU AT&T Assembly**
- Outputs an executable file
- Simple command-line interface
- Example programs included

## Installation & Usage 🛠️

### Prerequisites
- **Linux/macOS (Intel only)**
- **GCC or Clang with C++17 support**
- **Make**

> **Note:** If `g++` is missing, install it using:  
> - **Ubuntu/Debian**: `sudo apt install g++`  
> - **Arch Linux**: `sudo pacman -S gcc`  
> - **macOS**: `brew install gcc`  
> - **Fedora**: `sudo dnf install gcc-c++`  

### Building the Compiler ⚙️
To build the compiler, simply run:
```sh
make
```
This will generate an executable called **brainf**.

### Running the Compiler 🚀
You can compile a Brainfuck program using:
```sh
./brainf -f <input_file> -o <output_file>
```
Or using long options:
```sh
./brainf --filename <input_file> --output <output_file>
```
If you provide only the input file, the output file will be named **program** by default:
```sh
./brainf <input_file>
```

### Example 📌
```sh
./brainf examples/mandelbrot.b -o mandelbrot_exec
chmod +x mandelbrot_exec
./mandelbrot_exec
```

## Example Brainfuck Programs 🧠
This repository includes three Brainfuck programs in the `examples/` folder:

| Program | Description | Credits |
|---------|------------|---------|
| `mandelbrot.b` | Mandelbrot set generator | [copy.sh](https://copy.sh/brainfuck/prog/mandelbrot.b) |
| `triangle.bf` | Sierpinski triangle drawing | [copy.sh](https://copy.sh/brainfuck/prog/triangle.bf) |
| `tic_tac_toe.bf` | Playable Tic-Tac-Toe game | [mitxela](https://github.com/mitxela/bf-tic-tac-toe) |

These are **not** original works of this repository's creator.

## License 📜
This project is open-source and licensed under the **MIT License**.

---
✨ Happy Compiling! 🚀

