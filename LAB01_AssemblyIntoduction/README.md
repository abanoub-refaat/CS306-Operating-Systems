# ⚙️ Assembly Basics For The Operating System (CS306) Course

Before starting this tutorial be sure to install the [emu8086](https://emu8086-microprocessor-emulator.en.softonic.com/download) to help you practice alongside with the provided code.

---

## 🏗️ Understanding Registers

In assembly language, **registers** are small storage locations inside the CPU that help in performing operations quickly. Think of them as super-fast variables that the processor can access instantly.

### Main Registers in 8086

The 8086 microprocessor has several types of registers, each with a specific purpose. Let’s go over the most commonly used ones:

### 1️⃣ General-Purpose Registers

These are used for arithmetic operations, data storage, and transfers. Each of them is **16-bit** but can be accessed as **two separate 8-bit registers** (high and low).

| Register                  | Purpose                                              | High (8-bit) | Low (8-bit) |
| ------------------------- | ---------------------------------------------------- | ------------ | ----------- |
| **AX** (Accumulator)      | Used in arithmetic and I/O operations                | AH           | AL          |
| **BX** (Base Register)    | Often used for memory addressing                     | BH           | BL          |
| **CX** (Counter Register) | Used in loops and string operations                  | CH           | CL          |
| **DX** (Data Register)    | Used in multiplication, division, and I/O operations | DH           | DL          |

📝 **NOTE:** You can access the full 16-bit register (e.g., `AX`) or just the high (`AH`) or low (`AL`) 8-bit part depending on what you need.

### 2️⃣ Segment Registers

These registers help in **memory segmentation**, which means they define different sections of memory.

- **CS (Code Segment):** Holds the location of the executable program code.
- **DS (Data Segment):** Stores variables and data.
- **SS (Stack Segment):** Handles function calls and local variables.
- **ES (Extra Segment):** Used for additional data storage.

### 3️⃣ Special-Purpose Registers

Some registers have unique jobs:

- **SP (Stack Pointer):** Points to the top of the stack (used in function calls).
- **BP (Base Pointer):** Helps access function parameters and local variables.
- **SI (Source Index) & DI (Destination Index):** Used for operations like copying strings.

---

## 📌 The MOV function

Now that we learned about the registers in the previous section we can use the MOV function to "copy" some bytes to a specific register, in the provided code we are transferring the value of 1234 in Hexadecimal (thats what the H means) to the register AX.
you can learn more about Hexadecimal using this link: [**What is Hexadecimal Numbering?**](https://www.techtarget.com/whatis/definition/hexadecimal)

```assembly
MOV AX, 1234H ; assigning the value of 1234H to the register AX
```

📝 **NOTE**: Assembly is not a case-sensitive language (ax is the same as Ax and AX).

```assembly
MOV BH, AH ; assigning the ah value to bh register
```
