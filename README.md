# N-Queens Puzzle - Optimization Techniques

## Overview
The `N Queens` puzzle is a classic puzzle in chess, going back to 1848. The goal is to try to place the queens on a chessboard so that none of them are attacking any of the other.
More information about the puzzle can be found on [Wikipedia](https://en.wikipedia.org/wiki/Eight_queens_puzzle). 
Or you can watch [this video](https://youtu.be/jPcBU0Z2Hj8) to get a better understanding of the problem.

In this project, we will explore different optimization techniques use backtracking, local search, and genetic algorithms to solve the n-queens puzzle.
While the examples in documentation focuses on the 8-queens version, you can apply these techniques to solve the puzzle for different board sizes.

## Table of Contents
- [Problem Statement](#problem-statement)
  - [Computational Complexity](#computational-complexity)
    - [Brute-Force](#brute-force)
    - [Possible Optimization](#possible-optimization)
- [Setup Environment](#setup-environment)
  - [Docker](#docker)
  - [Local Environment](#local-environment)
- [Optimization Techniques](#optimization-techniques)
  - [Backtracking Technique (Baseline)](#backtracking-technique-baseline)


## Problem Statement

The `eight queens` puzzle is a classic puzzle in chess, going back to 1848. The goal is to try to place eight queens on a chessboard so that none of them are attacking any of the other.

*Ps. The queen can move as far as she likes vertically, horizontally or diagonally. which mean we can't place two queens in the same row, column, or diagonal.* S*o on a normal chessboard (8 x 8) we can't put nine or more queens. Eight is the maximum.*

*A single queen threatening the squares on the board (marked in red)*
![A *single queen threatening*](assets/queen_threatens.svg)


Our task here is to find all such configurations of queens on the *(8 x 8)* board. There are 92 possible configurations.

### Computational Complexity

Let's first understand and represented the problem mathematically to get a better understanding of problem computational complexity.

There are 92 solutions to the *8 x 8* problem. Many of these are reflections and rotations of some of the others, and if we de-duplicate against this, purists state that there are only 12 distinct solutions (92 does not divide equally by 12 because many of the reflections and rotations of a pure solutions are not unique).

All fundamental solutions are presented below:
![All fundamental solutions (12 distinct solutions)](assets/solutions.png)

#### **Brute-Force**

[Brute-force computational techniques](https://en.wikipedia.org/wiki/Brute-force_search) could be the first possible mechanism we think of where blindly trying the eight queens in every possible location. This is a really dumb idea and computationally so expensive, but would calculate all possible combinations Using [Combinations Calculator nCr](https://www.calculatorsoup.com/calculators/discretemathematics/combinations.php) :

$$ C(n, r) = ({n \over r}) = {n! \over (r!(n-r)!)} $$

$$ C(64, 8) = {64! \over (8!(64 - 8)!)} = 4,426,165,368 $$

Imagine having to test 4,426,165,368 combinations. If we can process 50,000 combinations per second that's going to take our computer over 24 hours to complete the task. ouch!

#### Possible Optimization

- By applying a simple rule that to put each queen on a separate row, and this massively reduces the number of possibilities.

$$ P(n,n) = n^n $$

$$ P(8,8) = 8^8 = 16,777,216 $$

- Similarly, there can be only one queen per column, and this reduces the possibilities even further. The problem can be trimmed down to an analogous problem of generating [permutations](https://en.wikipedia.org/wiki/Permutation) of the 8 queens, which can then be checked for diagonal attacks.

$$ n! = 8! = 40,320 $$

This is a much more manageable number. However, checking each permutation is still computationally expensive. We can do better by using a heuristic approach.

### Setup Environment

Feel free to use any of the following methods to run the application locally.

#### Docker

This application is shipped with the Docker Compose environment and requires Docker to be installed locally and running.
If you're not familiar with Docker or don't have it locally, please reach out to 
[the official website](https://www.docker.com) to get the latest version and installation instructions.

Once you have Docker up and running please perform the following command to start the application:

```shell
docker-compose up # or make up
```

As soon as you are done with the test assignment you can stop the application:

```shell
docker-compose down --rmi all #or make down
```

This will stop the application and remove containers & network.

#### Local environment

- python >= 3.8
- pip >= 20.2.4

Once you have the requirements installed, please perform the following commands to start the application:

```shell
pip install -r requirements.txt
```

## Optimization Techniques

### Backtracking Technique (Baseline) 

>Backtracking is a systematic algorithmic technique for finding solutions to problems that involve finding
an arrangement of elements satisfying certain constraints. It explores the search space by incrementally
building candidates and backtracking when a dead-end or invalid solution is encountered.
Unlike heuristic methods, backtracking does not use heuristics or approximate techniques to guide the search process. Instead, it exhaustively explores the entire search space by considering all possible combinations, making it more computationally expensive for large problem instances.

```shell
python backtracking.py --n-queen 8
```

```
N-Queens Backtracking Algorithm
==========================
Dimension: 8
Number of solutions: 92
Execution time: 2 ms
╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗
║ ♛ ║   ║   ║   ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║ ♛ ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║   ║   ║   ║ ♛ ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║   ║ ♛ ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║ ♛ ║   ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║   ║   ║ ♛ ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║ ♛ ║   ║   ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║ ♛ ║   ║   ║   ║   ║
╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝
```

```shell
python hill_climbing.py --n-queen 8
```

```
Initial position: [4, 7, 6, 0, 3, 5, 2, 1], fitness: 21
Found better solution: [4, 7, 0, 0, 3, 5, 2, 1], Fitness: 24
Found better solution: [4, 4, 0, 0, 3, 5, 2, 1], Fitness: 25
Found better solution: [6, 4, 0, 0, 3, 5, 2, 1], Fitness: 26
Found better solution: [6, 4, 7, 0, 3, 5, 2, 1], Fitness: 27
Hill Climbing returned: [6, 4, 7, 0, 3, 5, 2, 1], Fitness: 27
N-Queens Hill Climbing Algorithm
==========================
Dimension: 8
Best Fitness: 27
Best Fitness Percentage: 96.42857142857143
Best Representation: [6, 4, 7, 0, 3, 5, 2, 1]
Execution time: 26 ms

╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗
║   ║   ║   ║   ║   ║   ║ ♛ ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║ ♛ ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║   ║   ║   ║ ♛ ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║ ♛ ║   ║   ║   ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║ ♛ ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║   ║ ♛ ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║ ♛ ║   ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║ ♛ ║   ║   ║   ║   ║   ║   ║
╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝
```

#### Simulated Annealing Algorithm

>Simulated annealing is a heuristic algorithm that is used for global search problems. It is inspired by the process of annealing in metallurgy, where a metal is heated to a high temperature and then slowly cooled to increase its strength. The algorithm starts with an initial solution and iteratively makes small changes to it. If the new solution is better than the previous one, it is always accepted. If the new solution is worse than the previous one, it is accepted with a probability that depends on the difference between the new and the previous solution. The probability decreases as the algorithm progresses, and the temperature parameter is reduced. The algorithm terminates when the temperature reaches a minimum value.


```shell
python simulated_annealing.py --n-queen 8
```

```
N-Queens Simulated Annealing Algorithm
==========================
Dimension: 8
Best Fitness: 28
Best Fitness Percentage: 100.0
Best Representation: [4, 6, 1, 3, 7, 0, 2, 5]
Execution time: 459 ms

╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗
║   ║   ║   ║   ║ ♛ ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║   ║   ║ ♛ ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║ ♛ ║   ║   ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║ ♛ ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║   ║   ║   ║ ♛ ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║ ♛ ║   ║   ║   ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║ ♛ ║   ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║   ║ ♛ ║   ║   ║
╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝

```text
N-Queens Genetic Algorithm
==========================
Dimension: 8
Population size: 100
Generations: 1000
Duration: 1537 ms
==========================
Best fitness: 28
Best fitness percentage: 100.0
Best representation: [5, 1, 6, 3, 2, 7, 4, 0]
Worst fitness: 28
Worst representation: [5, 1, 6, 3, 2, 7, 4, 0]
Mean fitness: 28.0
==========================
Selection operator: fps
Mutate operator: swap_mutation
Crossover operator: cycle_xo
╔═══╦═══╦═══╦═══╦═══╦═══╦═══╦═══╗
║   ║   ║   ║   ║   ║ ♛ ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║ ♛ ║   ║   ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║   ║   ║ ♛ ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║ ♛ ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║ ♛ ║   ║   ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║   ║   ║   ║ ♛ ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║   ║   ║   ║   ║ ♛ ║   ║   ║   ║
╠═══╬═══╬═══╬═══╬═══╬═══╬═══╬═══╣
║ ♛ ║   ║   ║   ║   ║   ║   ║   ║
╚═══╩═══╩═══╩═══╩═══╩═══╩═══╩═══╝
```