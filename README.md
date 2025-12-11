# Dictionary System

A simple bidirectional dictionary (Spanish ↔ Portuguese) implemented using an AVL tree for efficient word storage and lookup.
The system automatically loads words from a `.txt` file on startup and updates the file when new words are added.

## Features

* 🔄 **Bidirectional translation** (Spanish → Portuguese and Portuguese → Spanish)
* 🌲 **AVL tree structure** for balanced and efficient searches
* 📄 **Automatic file handling:** words are read from and saved to a `.txt` file
* ⌨️ **Command-line interface** for adding and searching words

## How to Run

1. **Clone the repository:**

   ```bash
   git clone git@github.com:r-vilela/Dictionary.git
   ```

2. **Enter the project folder:**

   ```bash
   cd Dictionary
   ```

3. **Compile the project:**

   ```bash
   gcc main.c AVL/avl.c Dict/dict.c -IAVL/ -IDict/ -o main
   ```

4. **Run the program:**

   ```bash
   ./main
   ```

## Project Structure

```
.
├── main.c
├── AVL/
│   ├── avl.c
│   └── avl.h
├── Dict/
│   ├── dict.c
│   └── dict.h
└── dadosPort.txt   (automatically read/written)
└── dadosSpan.txt   (automatically read/written)
```

## Requirements

* GCC or any C-compatible compiler
* Standard C libraries (no external dependencies)

## Notes

* Ensure that the `dadosPort.txt` and `dadosSpan.txt` file is in the project root.
* The program will create the file automatically if it does not exist.
