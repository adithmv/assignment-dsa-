# Hospital Patient Priority Queue

This assignment answers the hospital severity-score question using C. A higher severity score means higher priority.

## Submission files

| Required item | File |
| --- | --- |
| Source code | [assignment.c](assignment.c) |
| Input data | [input.txt](input.txt) |
| Executed output | [output.txt](output.txt) |
| Intermediate trace tables | [trace_table.md](trace_table.md) |
| Time and space complexity | [complexity_analysis.md](complexity_analysis.md) |
| Performance comparison | [comparison_table.md](comparison_table.md) |
| Final conclusion | [conclusion.md](conclusion.md) |

## Input

```text
45 72 30 90 65 50 85
```

These scores are stored directly in the C program. The input file records the given dataset; no keyboard input or file redirection is needed.

## Compile and run

With GCC:

```text
gcc -std=c11 -Wall -Wextra -pedantic assignment.c -o assignment
./assignment
```

On Windows PowerShell, compile with `-o assignment.exe` and run `.\assignment.exe`.

The program was compiled and executed on Windows using Tiny C Compiler 0.9.27:

```text
tcc -Wall -Werror assignment.c -o assignment.exe
.\assignment.exe
```

One program performs Max Heap insertion, Heap Sort, and Quick Sort. The source contains no comments. Comparisons count severity comparisons only; swaps count exchanges between different positions.

Both sorts produce `[30, 45, 50, 65, 72, 85, 90]`. The highest-priority patient has severity 90. A maintained Max Heap is the suitable choice for continuous patient arrivals and immediate access to the highest priority.

## Submission link

[GitHub repository](https://github.com/adithmv/assignment-dsa-)
