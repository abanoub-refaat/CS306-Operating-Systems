# ⚙️ Assembly Basics For The Operating System (CS306) Course

Before starting this tutorial be sure to install the [emu8086](https://emu8086-microprocessor-emulator.en.softonic.com/download) to help you practice alongside with the provided code segments.

---

## Table of contents

- [⚙️ Assembly Basics For The Operating System (CS306) Course](#️-assembly-basics-for-the-operating-system-cs306-course)
  - [Table of contents](#table-of-contents)
  - [🏗️ Understanding Registers](#️-understanding-registers)
    - [Main Registers in 8086](#main-registers-in-8086)
    - [1️⃣ General-Purpose Registers](#1️⃣-general-purpose-registers)
    - [2️⃣ Segment Registers](#2️⃣-segment-registers)
    - [3️⃣ Special-Purpose Registers](#3️⃣-special-purpose-registers)
  - [📌 The MOV Instruction](#-the-mov-instruction)
  - [📌 Arithmetic Operations (ADD, SUB, MUL, and DIV)](#-arithmetic-operations-add-sub-mul-and-div)
    - [1️⃣ The ADD Instruction](#1️⃣-the-add-instruction)
    - [2️⃣ The SUB Instruction](#2️⃣-the-sub-instruction)
    - [3️⃣ The MUL Instruction](#3️⃣-the-mul-instruction)
    - [4️⃣ The DIV Instruction](#4️⃣-the-div-instruction)
  - [📌 Defining Variables in Assembly](#-defining-variables-in-assembly)
    - [1️⃣ DB and DW Instructions](#1️⃣-db-and-dw-instructions)

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

## 📌 The MOV Instruction

Now that we learned about the registers in the previous section we can use the MOV function to "copy" some bytes to a specific register. in the provided code we are copying the value of 1234 in Hexadecimal (thats what the H means) to the register AX.
you can learn more about Hexadecimal using this link: [**What is Hexadecimal Numbering?**](https://www.techtarget.com/whatis/definition/hexadecimal)

```assembly
MOV AX, 1234H ; assigning the value of 1234H to the register AX
```

📝 **NOTE**: Assembly is not a case-sensitive language (ax is the same as Ax and AX).

```assembly
MOV BH, AH ; assigning the ah value to bh register
```

We can also copy some value in the location of some register by using the square bracket as in the following example

```assembly
MOV CX, 1234H ; copying the value 1234H into CX
MOV [BX], CX  ; copying the value of CX into the position of the register BX.
```

---

## 📌 Arithmetic Operations (ADD, SUB, MUL, and DIV)

Assebly provides some basic functions for arithmetic operations lets explore each one and see how it works.

### 1️⃣ The ADD Instruction

```assembly
ORG 100H
    MOV AX, 1520H
    MOV SI, 0300H
    MOV [SI], 3040H
    ADD AX, [SI] ; AX = 3040H + 1520H
RET
```

📝 **NOTE**: `ORG` is a directive that tells the assembler to set the starting address of the code to 100 hexadecimal (256 in decimal). This is typically used when creating `.COM` files in MS-DOS.

In the previous example we are adding the value in the location of the register `SI` with the value of `AX` and the result is added to the register `AX`.

### 2️⃣ The SUB Instruction

```assembly
ORG 100H
    MOV AX, 1234H
    MOV DX, 5678H
    SUB DX, AX ; DX = 5678H - 1234 H
RET
```

In this example we are initializing both AX and DX with initia values of 1234H and 5678H respectivly, and then subtracting the value of DX from the value of AX and storing the answer in DX. (Notice that the `ADD` and `SUB` are semillar so we don't have to talk much about them).

### 3️⃣ The MUL Instruction

```assembly
ORG 100H
    MOV BX, 3
    MOV AX, 3
    MUL Bx ; AX = AX * BX
RET
```

The `MUL` instruction works in a different way than the `ADD` instuction since it only accept unary attribute and not binary as in the `ADD` or `SUB`.
So, the following will not work:

```assembly
MUL AX, 1234H ; will not work
```

We also can notice that the multiplication happend in `AX` and the value is also stored in the register `AX` so we can make the conclution that `MUL BX` is the same as `AX = AX * BX`.

### 4️⃣ The DIV Instruction

```assembly
ORG 100H
    MOV AX, 4
    MOV BL, 2
    DIV BL
RET
```

The `DIV` instruction work in a simmilar way as the `MUL` instruction, it divides the value of the parameter by the value in the register `AX`, but there is a catch.

- When the operand is a **byte** (8-bit operand):
  `DIV BL` is the same as `AL = AX / BL` and if there was any reminders its value will be stored in `AH`.
- When the operand is a **Word** (16-bit operand):
  `DIV BL` will be the same as `AL:DL = AL / BL` and the reminder will be in the `DX` register.

---

## 📌 Defining Variables in Assembly

In assembly we have two ways for defining varibles each one has its own instruction that are straight forward and easy to use.

### 1️⃣ DB and DW Instructions

```assembly
ORG 100H
    MOV AL, var1
    MOV BL, var2
    MUL BL
    MOV answer, AL
RET
var1 DB 00000001B
var2 DB 00000010B
answer DB ? ; will be assigned later
```

`DB` is a short for **Define Byte** and `DW` is short for **Define Word** and it goes without saying what is the difference between the two of them.
In the previous code block we are declaring two variables `var1` and `var2` and assigning them the values 1 and 2 respectivly but in binary, and we are defining a third varaiable called `answer` that has no initial value and we are telling the assembler that by using the question mark instade of the value `answer DB ?`.

📝 **Note**: we are defining the variables after the `RET` instruction and this is requierd since defining them else were will not wrok.
