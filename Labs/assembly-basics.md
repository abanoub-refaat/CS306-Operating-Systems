# ⚙️ Assembly Basics For The Operating System (CS306) Course

**Before starting this tutorial, install the [emu8086](https://emu8086-microprocessor-emulator.en.softonic.com/download) to help you practice alongside the provided code segments.**

---

## Understanding Registers

In assembly language, registers are small storage locations inside the CPU that help perform operations quickly. Think of them as super-fast variables that the processor can access instantly.

### Main Registers in 8086

The 8086 microprocessor has several types of registers, each with a specific purpose. Let’s go over the most commonly used ones:

### 1️⃣ General-Purpose Registers

These are used for arithmetic operations, data storage, and transfers. Each of them is **16-bit** but can be accessed as **two separate 8-bit registers** (high and low).

| Register                  | Purpose                                              | High(8-bit) | Low (8-bit) |
| ------------------------- | ---------------------------------------------------- | ----------- | ----------- |
| **AX** (Accumulator)      | Used in arithmetic and I/O operations                | AH          | AL          |
| **BX** (Base Register)    | Often used for memory addressing                     | BH          | BL          |
| **CX** (Counter Register) | Used in loops and string operations                  | CH          | CL          |
| **DX** (Data Register)    | Used in multiplication, division, and I/O operations | DH          | DL          |

> 📝 **NOTE**:
> You can access the full 16-bit register (e.g., `AX`) or just the high (`AH`) or low (`AL`) 8-bit part depending on what you need.

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

## 📌 The `MOV` Instruction

Now that we learned about the registers in the previous section we can use the MOV function to "copy" some bytes to a specific register. in the provided code we are copying the value of 1234 in Hexadecimal (that's what the H means) to the register AX.

you can learn more about Hexadecimal using this link: [**What is Hexadecimal Numbering?**](https://www.techtarget.com/whatis/definition/hexadecimal)

```assembly

MOV AX, 1234H ; assigning the value of 1234H to the register AX

```

> 📝 **NOTE**:
> Assembly is not a case-sensitive language (ax is the same as Ax and AX).

```assembly

MOV BH, AH ; assigning the ah value to bh register

```

We can also copy some value in the location of some register by using the square bracket as in the following example

```assembly

MOV CX, 1234H ; copying the value 1234H into CX

MOV [BX], CX  ; copying the value of CX into the position of the register BX.

```

---

## 📌 Arithmetic Operations (ADD, SUB, MUL, and DIV)

Assembly provides some basic functions for arithmetic operations lets explore each one and see how it works.

### 1️⃣ The `ADD` Instruction

```assembly
ORG 100H

    MOV AX, 1520H

    MOV SI, 0300H

    MOV [SI], 3040H

    ADD AX, [SI] ; AX = 3040H + 1520H

RET
```

> 📝 **NOTE**:
> `ORG` is a directive that tells the assembler to set the starting address of the code to 100 hexadecimal (256 in decimal). This is typically used when creating `.COM` files in MS-DOS.

In the previous example, we are adding the value in the location of the register `SI` with the value of `AX` and the result is added to the register `AX`.

### 2️⃣ The `SUB` Instruction

```assembly
ORG 100H

    MOV AX, 1234H

    MOV DX, 5678H

    SUB DX, AX ; DX = 5678H - 1234 H

RET
```

In this example, we are initializing both AX and DX with initial values of 1234H and 5678H respectively, and then subtracting the value of DX from the value of AX and storing the answer in DX. (Notice that the `ADD` and `SUB` are similar so we don't have to talk much about them).

### 3️⃣ The `MUL` Instruction

```assembly
ORG 100H

    MOV BX, 3

    MOV AX, 3

    MUL Bx ; AX = AX * BX
RET
```

The `MUL` instruction works in a different way than the `ADD` instruction since it only accepts unary attributes and not binary as in the `ADD` or `SUB`.

> So, the following will not work:

```assembly

MUL AX, 1234H ; will not work

```

We also can notice that the multiplication happen in `AX` and the value is also stored in the register `AX` so we can make the conclusion that `MUL BX` is the same as `AX = AX * BX`.

### 4️⃣ The `DIV` Instruction

```assembly
ORG 100H

    MOV AX, 4

    MOV BL, 2

    DIV BL

RET
```

The `DIV` instruction work in a similar way as the `MUL` instruction, it divides the value of the parameter by the value in the register `AX`, but there is a catch.

- When the operand is a **byte** (8-bit operand):

`DIV BL` is the same as `AL = AX / BL` and if there were any reminders its value will be stored in `AH`.

- When the operand is a **Word** (16-bit operand):

`DIV BL` will be the same as `AL: DL = AL / BL` and the remainder will be in the `DX` register.

### 5️⃣ `INC` and `DEC` Instructions

`INC` and `DEC` are as the names suggest increment/decrement a register value by 1. and they are very useful when computing the One's Complement for a binary value which we can use to get the Two's complement for a binary value which we will see at the end of this section.

```assembly
ORG 100H

  MOV AL, 4

  INC AL ; AL = 5

  MOV BL, 2

  DEC BL ; BL = 1

RET
```

### 6️⃣ The `NEG` Instruction

The `NEG` instruction is used to get the negative of a value

```assembly

ORG 100H

  MOV AL, 23

  NEG AL ; AL = -23

RET

```

### 🔶 Calculating One’s and Two’s Complement for a Binary Number

```assembly
ORG 100H

MOV AL, 10101111B  ; Load AL with binary number
MOV BL, AL         ; Store original value in BL

; One’s complement (invert all bits)
NOT AL

; Two’s complement (one’s complement + 1)
INC AL

; Alternative way to get two’s complement
NEG BL             ; NEG does NOT +1, it negates the value

RET
```

### 🔹 Explanation

1. **One’s Complement** – `NOT AL` inverts all bits of `AL`.
2. **Two’s Complement** – `INC AL` adds 1 to the one’s complement.
3. **Alternative Method** – `NEG BL` directly negates the original value in `BL`, achieving the same result as two’s complement.

---

## 📌 Defining Variables in Assembly

In assembly we have two ways for defining variables each one has its own instructions that are straight forward and easy to use.

### 1️⃣ `DB` and `DW` Instructions

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

> 📝 **Note**:
> we are defining the variables after the `RET` instruction and this is required since defining them else were will not work.

### 2️⃣ `EQU` Instruction

```assembly
ORG 100H

  MOV AL, VALUE
  ADD AL, 5
  MOV result, AL

RET
VALUE EQU 10  ; Define a constant VALUE with 10
result DB ?   ; will be assigned later
```

`EQU` is short for **Equate**, and it is used to define constant values that cannot be changed during program execution. Unlike `DB` and `DW`, which allocate memory, `EQU` simply assigns a name to a constant value at assembly time and it can be used inside of the `ORG-RET` block.

In the previous code block, we:

1. Defined `VALUE` as `10` using `EQU`.
2. Moved `VALUE` into `AL` and added `5` to it.
3. Stored the result in the `result` variable.

> 📝 **Note**:  
> Since `EQU` does not allocate memory, `VALUE` is not stored in RAM but is replaced by `10` wherever used in the code.

---

## 📌 Logical Operators (`AND`, `OR`, `XOR`, `XCHG`, and `NOT`)

We can use the logical operators `AND`, `OR`, and `XOR` on binary numbers to manipulate their values.

### `AND` - Bitwise AND

```assembly
MOV AL, 11001100b  ; Load AL with 11001100
AND AL, 10101010b  ; Perform AND with 10101010
; Result in AL: 10001000
```

The `AND` instruction keeps only the bits that are `1` in both operands.

### `OR` - Bitwise OR

```assembly
MOV AL, 11101100b  ; Load AL with 11101100
OR  AL, 10101010b  ; Perform OR with 10101010
; Result in AL: 11101110
```

The `OR` instruction sets bits to `1` if either operand has a `1`.

### `XOR` - Bitwise XOR

```assembly
MOV AL, 11001100b  ; Load AL with 11001100
XOR AL, 10101010b  ; Perform XOR with 10101010
; Result in AL: 01100110
```

The `XOR` instruction sets bits to `1` **only if the bits differ** between operands.

### `XCHG` - Exchange Values

```assembly
MOV AL, 12H  ; AL = 12H
MOV AH, 34H  ; AH = 34H
XCHG AL, AH  ; Exchange AL and AH
; Result: AL = 34H, AH = 12H
```

The `XCHG` instruction swaps the values of two registers.

### `NOT` - Bitwise NOT

```assembly
ORG 100H

MOV AL, 11001100B  ; Load AL with 11001100
NOT AL             ; Invert bits, AL = 00110011B

RET
```

The `NOT` instruction inverts every bit, changing `1` to `0` and vice versa.

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

---

## 📌 Indirect Memory Indexing

Indirect memory indexing in assembly refers to accessing memory locations using a register as an index. The effective address is determined by adding an offset to the value stored in a register.

```assembly
ORG 100H

MOV SI, offset arr  ; Load the address of arr into SI
INC SI              ; Increment SI by 1 (SI now points to arr[1])
MOV AL, [SI + 2]    ; Load the value at address (SI + 2) into AL

RET

arr DB 1, 2, 3, 4   ; Define an array of bytes
```

### 🔹 Explanation

1. **Load Address** – `MOV SI, offset arr` stores the address of `arr` in the `SI` register.
2. **Increment SI** – `INC SI` increases `SI` by 1, so now `SI` points to `arr[1]` (the second element).
3. **Access Memory with Offset** – `MOV AL, [SI + 2]` loads the value at `arr[3]` (since `SI` was pointing at `arr[1]`, adding 2 moves to `arr[3]`).

---

## 📌 LOOPS in Assembly

Loops in assembly are defined using a label (loop name) and the `LOOP` instruction. The `CX` register acts as the loop counter, so to specify the number of iterations, we load `CX` with the desired count.

```assembly
ORG 100h

LEA SI, marks     ; Load the address of marks into SI

MOV CX, 3         ; Set the loop counter to 3

lp:               ; Loop label
    ADD AL, [SI]  ; Add the value at SI to AL
    INC SI        ; Move to the next element
LOOP lp           ; Decrement CX and repeat until CX = 0

; Store the sum
MOV sum, AL

RET

marks DB 60, 80, 90  ; Define an array of marks
sum DB ?             ; Variable to store the sum
```

### 🔹 Explanation

1. **Initialize SI** – `LEA SI, marks` loads the address of `marks` into `SI`.
2. **Set Loop Counter** – `MOV CX, 3` sets the loop to iterate 3 times.
3. **Loop Execution** – Inside the loop, we:
   - Add the current element in `marks` to `AL`.
   - Increment `SI` to move to the next element.
   - Use `LOOP lp`, which decrements `CX` and jumps back if `CX > 0`.
4. **Store the Sum** – After the loop, `MOV sum, AL` stores the total sum.

---

Here’s an improved version of your section with a clearer explanation, improved grammar, and better formatting:

---

## 📌 Conditional Statements: The `CMP` and `JMP` Instructions

In this section, we will learn about conditional statements in Assembly using the `CMP` instruction, followed by various conditional `JMP` instructions.

### Understanding `CMP` and `JMP`

The `CMP` (Compare) instruction compares two values by subtracting one from the other, **without storing the result**. Instead, it updates the processor's flags, which determine the flow of execution using conditional jump instructions (`JMP`).

In Assembly, numbers can be **unsigned** or **signed**, and each type has its own set of jump instructions to handle conditions correctly.

---

### 1️⃣ **Conditional Jumps for Unsigned Numbers**

For **unsigned numbers**, we have the following conditional jump instructions:

| Instruction            | Meaning                                                                 |
| ---------------------- | ----------------------------------------------------------------------- |
| `JA` (Jump Above)      | Jump if the first operand is **greater** than the second.               |
| `JB` (Jump Below)      | Jump if the first operand is **less** than the second.                  |
| `JE` (Jump Equal)      | Jump if the values are **equal**.                                       |
| `JNE` (Jump Not Equal) | Jump if the values are **not equal**.                                   |
| `JC` (Jump Carry)      | Jump if there was a **carry** (useful for detecting unsigned overflow). |
| `JNC` (Jump No Carry)  | Jump if there was **no carry**.                                         |

---

### 🔹 Example: Finding the Maximum and Minimum of Two Numbers

```assembly
ORG 100h

LEA SI, arr      ; Load the address of arr into SI
MOV AL, [SI]     ; Load first element (arr[0]) into AL
INC SI           ; Move SI to the next element
MOV BL, [SI]     ; Load second element (arr[1]) into BL

CMP AL, BL       ; Compare AL with BL
JA greater       ; If AL > BL, jump to 'greater'

MOV max, BL      ; Otherwise, store BL as max
MOV min, AL      ; Store AL as min
JMP done         ; Skip 'greater' label

greater:
    MOV max, AL  ; If AL > BL, store AL as max
    MOV min, BL  ; Store BL as min

done:
RET

arr DB 5, 10     ; Define an array with two elements
max DB ?         ; Variable to store the maximum value
min DB ?         ; Variable to store the minimum value
```

### 🔹 Explanation

1. **Load the Numbers**

   - `SI` is initialized to point to `arr`.
   - The first number (`arr[0] = 5`) is loaded into `AL`.
   - `SI` is incremented, and the second number (`arr[1] = 10`) is loaded into `BL`.

2. **Compare Values**

   - `CMP AL, BL` subtracts `BL` from `AL` **without storing the result** but sets the flags accordingly.
   - If `AL > BL`, the `JA greater` instruction jumps to the `greater` label.

3. **Store Max and Min Values**
   - If `AL` is **not greater** than `BL`, `BL` is the maximum, and `AL` is the minimum.
   - If `AL > BL`, we jump to `greater` and assign `AL` as the maximum.
   - The `done` label ensures a clean exit.

### 2️⃣ **Conditional Jumps for signed Numbers**

For **signed numbers**, we have the following conditional jump instructions:

| Instruction            | Meaning                                                                 |
| ---------------------- | ----------------------------------------------------------------------- |
| `JG` (Jump Greater)    | Jump if the first operand is **greater** than the second.               |
| `JL` (Jump Below)      | Jump if the first operand is **less** than the second.                  |
| `JE` (Jump Equal)      | Jump if the values are **equal**.                                       |
| `JNE` (Jump Not Equal) | Jump if the values are **not equal**.                                   |
| `JC` (Jump Carry)      | Jump if there was a **carry** (useful for detecting unsigned overflow). |
| `JNC` (Jump No Carry)  | Jump if there was **no carry**.                                         |

They work the same way as the unsigned but the difference is in the way bits are treated in the registers so we don't have to give an example for this one it is the same as the last example.

---

## 📌 External Libraries: The `println` Function

In Assembly, printing output to the screen typically requires low-level interactions with system interrupts. However, when using **emu8086**, we can simplify this process by utilizing an **external library** called `emu8086.inc`, which provides convenient functions like `println`.

The `println` function is **not a built-in assembly instruction** but rather a macro provided by `emu8086.inc`. It allows us to print strings easily without handling interrupts manually.

### ✅ **Example: Printing "Hello, World!"**

```assembly
ORG 100h
    println 'Hello, World!'
RET
```

### 🔹 Explanation

1. `ORG 100h` – Defines the starting address of the program (standard for `.COM` programs in **emu8086**).
2. `println 'Hello, World!'` – Prints the string `"Hello, World!"` to the screen.
3. `RET` – Returns execution control, signaling the program's end.

> 📝 **Note**:
>
> - The `println` function only works in emu8086 and is part of `emu8086.inc`.
> - If you attempt to run this on a different assembler (e.g., MASM, NASM), you will need to use DOS interrupts like `INT 21H` instead.

---

## 🎯 Conclusion

Throughout this tutorial, we explored key concepts in **8086 Assembly language**, including:

✅ **Working with Memory Register** (`AX`, `SI` ... etc)  
✅ **Moving values to registers** (`MOV` instuctin)  
✅ **Arithmetic Operations** (`ADD`, `DIV` ... etc)  
✅ **Defining Variables** (`DB`, `DW`, and `EQU`)  
✅ **Logical and Bitwise Operations** (`AND`, `OR`, `XOR`, `XCHG`, `NOT`)  
✅ **Memory Access Methods** (Direct and Indirect Addressing)  
✅ **Loops and Conditional Jumps** (`LOOP`, `CMP`, `JMP`)  
✅ **Working with External Libraries** (`println` in emu8086)

By applying these techniques, you can create more complex Assembly programs that interact with memory, perform computations, and even print output. Assembly is a **powerful and low-level language**, and mastering it helps build a deep understanding of how computers work at the hardware level.

🚀 **Next Steps**: To further strengthen your Assembly skills, try writing programs that:

- **Perform arithmetic calculations** (addition, subtraction, multiplication, and division).
- **Manipulate strings and arrays** (reversing, sorting, or searching).
- **Interact with system interrupts** for input/output operations.

🔗 **Recommended Learning Resources**:

- [emu8086 Documentation](http://www.emu8086.com/)
- [x86 Assembly Language Guide](https://cs.brown.edu/courses/cs033/docs/guides/x86-assembly.pdf)

Keep coding, and enjoy your journey into low-level programming! 🔥
