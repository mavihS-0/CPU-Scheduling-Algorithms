# CPU Scheduling Algorithms

This repository contains implementations of various pre-emptive and non pre-emptive CPU scheduling algorithms with **DIFFERENT** arrival times in C.

## Table of Contents

- [Introduction](#introduction)
- [Authors](#authors)
- [Algorithms](#algorithms)
  - [First-Come, First-Serve (FCFS)](#first-come-first-serve-fcfs)
  - [Shortest-Job-First (SJF)](#shortest-job-first-sjf)
  - [Priority Scheduling](#priority-scheduling)
  - [Round Robin](#round-robin)
- [Usage](#usage)
- [Contributing](#contributing)

## Introduction

In a computer system, the CPU scheduler determines which process gets to use the CPU at any given time. The scheduler selects a process from the ready queue and allocates the CPU to it. CPU scheduling is an essential component of an operating system, as it affects system performance and responsiveness.

This repository contains implementations of different CPU scheduling algorithms. The algorithms work on the principle of creating an infinite while loop to get the gantt chart. These can be used as a reference or for educational purposes.

## Authors

- [@mavihS-0](https://www.github.com/mavihS-0)

## Algorithms

### First-Come, First-Serve (FCFS)

The first-come, first-serve (FCFS) algorithm is the simplest CPU scheduling algorithm. It works on the principle of "first come, first served." The process that arrives first in the ready queue is allocated the CPU first.

### Shortest-Job-First (SJF)

The shortest-job-first (SJF) algorithm selects the process with the shortest burst time. This algorithm can be implemented in both non-preemptive and preemptive modes.

### Priority Scheduling

The priority scheduling algorithm assigns a priority to each process and selects the process with the highest priority for execution. This algorithm can also be implemented in both non-preemptive and preemptive modes.

### Round Robin

The round-robin (RR) algorithm is a preemptive scheduling algorithm that allocates a fixed time slice to each process in a cyclic order. If a process does not complete its execution in the allotted time slice, it is preempted and added to the end of the ready queue.

## Usage

To run the implementations in this repository, you need to have GCC installed on your computer.

## Contributing

Contributions to this repository are welcome. If you want to add a new implementation or improve an existing one, please create a pull request.

