# 🧮 Arbitrary Precision Calculator — Unlimited Integer Arithmetic in C

![Language](https://img.shields.io/badge/Language-C-blue.svg)
![Concept](https://img.shields.io/badge/Concept-Data%20Structures-orange.svg)
![Build](https://img.shields.io/badge/Build-GCC-green.svg)

The **Arbitrary Precision Calculator** is a command-line application written in **C** that performs arithmetic operations on integers of **unlimited size**.  
It overcomes the limitations of standard C data types (`int`, `long`, `long long`) by representing numbers using **Doubly Linked Lists** and processing them digit by digit.

This project was developed as part of **Data Structures training** while pursuing the  
**Emertxe Certified Embedded Professional (ECEP)** course.

---

## ❓ Why This Project?

C provides fast and efficient primitive data types, but they come with fixed size limits:
- `int` → typically 32-bit  
- `long / long long` → typically 64-bit  

These limits make it impossible to handle very large integers required in advanced computations.  
This project demonstrates how **Data Structures** can be used to remove such limitations by implementing arithmetic logic manually.

---

## 🚀 Key Features

- Supports **arbitrary-length integers**
- Arithmetic operations supported:
  - ➕ Addition  
  - ➖ Subtraction  
  - ✖️ Multiplication  
  - ➗ Division  
  - ➗ Modulus
- Handles **positive and negative numbers**
- Automatically removes **leading zeros**
- Modular and structured C implementation
- Command-line based execution

---

## 🧱 Data Structure Used

### 🔹 Doubly Linked List

Each digit of a number is stored in a node of a **Doubly Linked List**.

**Why Doubly Linked List?**
- Enables **bidirectional traversal**
- Allows easy movement from:
  - **LSB → MSB** for carry/borrow handling
  - **MSB → LSB** for printing and comparison
- Simplifies subtraction, division, and modulus operations
- Efficient insertion and deletion of digits during computation

---

## 🧠 Logic Overview

### 🔹 Sign Handling
- Input signs (`+` / `-`) are processed separately
- Arithmetic is performed on absolute values
- Final sign is determined based on operator rules

### 🔹 Digit-wise Computation
- Operations are performed digit by digit
- Carry and borrow are handled explicitly
- Memory is dynamically allocated and freed

### 🔹 Leading Zero Removal
- Extra leading zeros are removed after each operation
- Ensures clean output (e.g., `000123` → `123`)

---

## 🛠 Installation & Compilation

### Compile
```bash
gcc *.c -o apc
```

### Run
```bash
./apc <num1> <operator> <num2>
```

---

## ▶️ Usage Examples

```bash
./apc 123456789123456789 + 987654321987654321
./apc -999999999 * 888888888
./apc 1000000000000 / 25
./apc 123456789 % 1000
```

---

## 📂 Code Structure

| File | Description |
|----|----|
| `main.c` | Program entry point and input handling |
| `add.c` | Addition logic |
| `sub.c` | Subtraction logic |
| `mul.c` | Multiplication logic |
| `div.c` | Division and modulus logic |
| `list.c` | Doubly Linked List operations |
| `header.h` | Data structures and function prototypes |

---

## 🎯 Learning Outcomes

- Strong understanding of **Data Structures**
- Hands-on experience with **Doubly Linked Lists**
- Advanced pointer manipulation in C
- Manual implementation of arithmetic algorithms
- Improved problem-solving and algorithmic thinking

---

## 👤 Author

**Omkar Ashok Sawant**  
Pursuing *Emertxe Certified Embedded Professional (ECEP)*  
Embedded Systems & Linux Programming Enthusiast  

---

## 📌 Note

This project is developed for **educational and learning purposes**, focusing on core Data Structure concepts and low-level arithmetic logic.
