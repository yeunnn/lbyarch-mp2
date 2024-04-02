# LBYARCH Machine Project

This repository contains a implementation of the SAXPY operation (A*X + Y), a fundamental linear algebra computation used in various scientific and engineering applications. The project showcases two versions of the SAXPY kernel: one written in C Language and another in x86-64 assembly language, both designed to leverage their computational efficiency on the said SAXPY operation.

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

## (C) Screenshots of the Program Output with Correctness Check
content here

## (x86-x64) Screenshots of the Program Output with Correctness Check
content here

## Contribution
This project was made in partial fulfillment of the requirements for the course LBYARCH by:
- Argamosa, Daniel Cedric S.
- Donato, Adriel Joseph Y.
