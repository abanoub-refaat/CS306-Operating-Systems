# ⚙️ Assembly Basics For The Operating System (CS306) Course

Before starting this tutorial, install the [emu8086](https://emu8086-microprocessor-emulator.en.softonic.com/download) to help you practice alongside the provided code segments.

---

## 📖 Table of contents

- [⚙️ Assembly Basics For The Operating System (CS306) Course](#️-assembly-basics-for-the-operating-system-cs306-course)
  - [📖 Table of contents](#-table-of-contents)
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
    - [5️⃣ INC and DEC Instructions](#5️⃣-inc-and-dec-instructions)
    - [6️⃣ The NEG Instruction](#6️⃣-the-neg-instruction)
  - [📌 Defining Variables in Assembly](#-defining-variables-in-assembly)
    - [1️⃣ DB and DW Instructions](#1️⃣-db-and-dw-instructions)
  - [📌 Logical Operators (AND, OR, XOR, XCHG and NOT)](#-logical-operators-and-or-xor-xchg-and-not)
  - [📌 Declaring array in Assembly](#-declaring-array-in-assembly)
    - [Direct and Indirect Memory indexing Locations](#direct-and-indirect-memory-indexing-locations)
  - [📌 LOOPS in Assembly](#-loops-in-assembly)
  - [🎯 Important Application](#-important-application)
    - [📍 Calculating One's and Two's Complement for a Binary Number](#-calculating-ones-and-twos-complement-for-a-binary-number)

## 🏗️ Understanding Registers

In assembly language, registers are small storage locations inside the CPU that help perform operations quickly. Think of them as super-fast variables that the processor can access instantly.

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

Now that we learned about the registers in the previous section we can use the MOV function to "copy" some bytes to a specific register. in the provided code we are copying the value of 1234 in Hexadecimal (that's what the H means) to the register AX.
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

Assembly provides some basic functions for arithmetic operations lets explore each one and see how it works.

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

In the previous example, we are adding the value in the location of the register `SI` with the value of `AX` and the result is added to the register `AX`.

### 2️⃣ The SUB Instruction

```assembly
ORG 100H
    MOV AX, 1234H
    MOV DX, 5678H
    SUB DX, AX ; DX = 5678H - 1234 H
RET
```

In this example, we are initializing both AX and DX with initial values of 1234H and 5678H respectively, and then subtracting the value of DX from the value of AX and storing the answer in DX. (Notice that the `ADD` and `SUB` are similar so we don't have to talk much about them).

### 3️⃣ The MUL Instruction

```assembly
ORG 100H
    MOV BX, 3
    MOV AX, 3
    MUL Bx ; AX = AX * BX
RET
```

The `MUL` instruction works in a different way than the `ADD` instruction since it only accepts unary attributes and not binary as in the `ADD` or `SUB`.
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
  `DIV BL` is the same as `AL = AX / BL` and if there were any reminders its value will be stored in `AH`.
- When the operand is a **Word** (16-bit operand):
  `DIV BL` will be the same as `AL: DL = AL / BL` and the remainder will be in the `DX` register.

### 5️⃣ INC and DEC Instructions

`INC` and `DEC` are as the names suggest increament/decrement a register value by 1. and they are very usefull when computing the One's Complement for a binary value which we can use to get the Two's compement for a binary value.
(for the full implementation see section [🎯 Important Application](#-important-application)).

```assembly
ORG 100H
  MOV AL, 4
  INC AL ; AL = 5

  MOV BL, 2
  DEC BL ; BL = 1
RET
```

### 6️⃣ The NEG Instruction

The `NEG` instruction is used to get the negative of a value

```assembly
ORG 100H
  MOV AL, 23
  NEG AL ; AL = -23
RET
```

---

## 📌 Defining Variables in Assembly

In assembly we have two ways for defining variables each one has its own instructions that are straight forward and easy to use.

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
In the previous code block, we declared two variables `var1` and `var2`, and assigned them the values 1 and 2 respectively but in binary, we defined a third variable called `answer` that has no initial value and we tells the assembler that by using the question mark instead of the value `answer DB ?`.

📝 **Note**: we are defining the variables after the `RET` instruction and this is requierd since defining them else were will not wrok.

---

## 📌 Logical Operators (AND, OR, XOR, XCHG and NOT)

We can use the logical operators `AND`, `OR` , and `XOR` on binary numbers to manipulate its values

```assembly
MOV al, 11001100b  ; Load AL with 11001100
AND al, 10101010b  ; Perform AND with 10101010
; Result in AL: 10001000
```

AND (`AND al, value`): Performs a bitwise AND, keeping only the bits that are `1` in both operands.

```assembly
MOV al, 11101100b  ; Load AL with 11001100
OR  al, 10101010b   ; Perform OR with 10101010
; Result in AL: 11101110
```

OR (`OR al, value`): Performs a bitwise OR, setting bits to `1` if either operand has a `1`.

```assembly
MOV al, 11001100b  ; Load AL with 11001100
XOR al, 10101010b  ; Perform XOR with 10101010
; Result in AL: 01100110
```

XOR (`XOR al, value`): Performs a bitwise XOR, setting bits to 1 **only if the bits differ**.

```assembly
MOV AL, 12H
MOV AH, 34H
XCHG AL, AH ; AX = 3412H
```

XCHG (`XCHG AL, AH`) will, as the name suggests, exchange the values of `AL` and `AH` so, at fist `AX = 1234H` and after the exchange `AX = 3412H`.

```assembly
ORG 100H
  MOV AL, 11001100B
  NOT AL ; 00110011B
RET
```

NOT (`NOT AL`) acts the same as the logical NOT gate which will revert the binary value of a number from `1` to `0` and vice versa.

---

## 📌 Declaring array in Assembly

As in declaring variables we declare the array after the `RET` instruction and the only difference between them is that we list the array values separated by a `,` as seen in the following code snippet:

```assebmly
OEG 100H
  MOV AL, var1[0]
  MOV BX, var2[2] ; moves two memory locations
RET
; defining an array
var1 DB 12H, 23H, 34H, 56H
var2 DW 12H, 23H, 34H, 56H
```

At first, var2 has the first value (so we should move it with the index to get the rest).
With the introduction of the array, we will have an important concept to address which is "Direct and Indirect Memory indexing Locations" and we will discuss it in the following section.

### Direct and Indirect Memory indexing Locations

Indirect memory indexing in assembly refers to accessing memory locations using a register as an index. The effective address is determined by adding an offset to the value stored in a register.

```assembly
ORG 100H
  MOV SI, offset arr ; Load the address of arr into SI
  INC SI             ; Increment SI by 1 (SI now points to arr[1])
  MOV AL, [SI + 2]   ; Load the value at address (SI + 2) into AL
RET
arr DB 1, 2, 3, 4  ; Define an array of bytes
```

At first we are loading the address of the `arr` into the register `SI` and then we increase the value of `SI` so now `SI` points to `arr[1]` and then we have loaded the location of `[SI + 2]` which is in essence `arr[2]` into the register `AL`.

---

## 📌 LOOPS in Assembly

we can define loops in assembly using an initial loop name and the `LOOP` instruction and the index of the loop is the `CX` register so whenever we need to specify the number of iteraions the loop will take we use the `CX` insturction as in the following code block:

```assembly
ORG 100h
LEA SI, marks

MOV CX, 3 ;set the counter register to 3

lp:   ; the loop name
    ADD al, [SI]
    INC SI
LOOP lp ; iterate over the lp block.

; store the sum
MOV sum, AL

RET
marks DB  60, 80, 90
sum DB ?
```

## 🎯 Important Application

### 📍 Calculating One's and Two's Complement for a Binary Number

```assembly
ORG 100H
  MOV AL, 10101111B
  MOV BL, AL
  ; one's complement
  NOT AL

  ; two's complement = one's complement + 1
  INC AL
  NEG BL
RET
```
