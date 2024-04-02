# LBYARCH Machine Project

This repository contains a implementation of the SAXPY operation (A*X + Y), a fundamental linear algebra computation used in various scientific and engineering applications. The project showcases two versions of the SAXPY kernel: one written in C Language and another in x86-64 assembly language, both designed to leverage their computational efficiency on the said SAXPY operation.

## Specifications

Write the kernel in (1) C program and (2) x86-x64 assembly language. The kernel is to perform SAXPY (A*X + Y) Function

- Input: Scalar variable n (integer) contains the length of the vector. Scalar variable A is a single-precision float. Vectors X, Y and Z are single-precision float.
  - In the analysis, the following values were done:
    - Scalar variable n would be of **2^20, 2^24,** and **2^28**
    - Scalar variable A is set to 2.00
    - Vectors X and Y are set to a random single-precision float

- Process:  Z[i] = A * X[i] + Y[i]

- Output: Store result in vector Z. Display the result of 1st ten elements of vector Z for all versions of kernel (i.e., C and x86-x64).

## Comparative Execution Time and Short Analysis of the Performance of the Kernels

#### Debug Mode Results
| Vector Size | C Execution Time (Average) (ms) | x86-64 Execution Time (Average) (ms) |
| :---------- | :------------------------------ | :----------------------------------- |
| 2^20        | 1.581363 ms                   |  0.491210 ms                       |
| 2^24        | 24.641193 ms                   |  8.364230 ms                       |
| 2^28        | 393.734213 ms                   |  136.502927 ms                       |

#### Release Mode Results
| Vector Size | C Execution Time (Average) (ms) | x86-64 Execution Time (Average) (ms) |
| :---------- | :------------------------------ | :----------------------------------- |
| 2^20        | 0.203467 ms                   |  0.495867 ms                       |
| 2^24        | 7.444783 ms                   |  8.420507 ms                       |
| 2^28        | 126.606820 ms                   |  144.489690 ms                       |

## (C and x86-x64) Screenshots of the Program Output with Correctness Check
### Debug Mode
![debug output1](img/debug1.png)
![debug output2](img/debug2.png)
![debug output3](img/debug3.png)
![debug output1](img/debug1.png)
![debug output4](img/debug4.png)
![debug output5](img/debug5.png)
---------------------
### Release Mode
![release output1](img/release1.png)
![release output2](img/release2.png)
![release output3](img/release3.png)
![release output4](img/release4.png)
![release output5](img/release5.png)
---------------------

## Contribution
This project was made in partial fulfillment of the requirements for the course LBYARCH by:
- Argamosa, Daniel Cedric S.
- Donato, Adriel Joseph Y.
