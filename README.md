# CPU Scheduling Algorithms in C

This repository is a collection of CPU scheduling algorithms implemented in C. It serves as an educational resource for understanding how different scheduling strategies are coded and executed within an operating system.

## Scheduling Algorithms Included

- **FCFS Scheduler (First-Come, First-Served)**
- **Priority Scheduler**
- **Round-Robin (RR) Scheduler**
- **Shortest-Job-First (SJF) Scheduler**
- **Priority with Round-Robin Scheduler**

## File Descriptions

- `schedule_fcfs.c/o`: Source and object files for the FCFS scheduling algorithm.
- `schedule_sjf.c/o`: Source and object files for the SJF scheduling algorithm.
- `schedule_priority.c/o`: Source and object files for the Priority scheduling algorithm.
- `schedule_rr.c/o`: Source and object files for the Round Robin scheduling algorithm.
- `schedule_priority_rr.c/o`: Source and object files for the combined Priority and Round Robin scheduling algorithm.
- `schedulers.h`: Header file with the function prototypes for the scheduling algorithms.
- `task.h`: Header file defining the structure for a task.
- `list.c/h/o`: Source, header, and object files for a linked list implementation used in schedulers.
- `driver.c/o`: Source and object files for the test driver to run the scheduling algorithms.
- `CPU.o`: Object file containing CPU simulation functions.
- `Makefile`: Used to build the project.

## Building the Project

To compile the source files and create the executables, run the following command in the terminal:

```sh
make [scheduler_name]
