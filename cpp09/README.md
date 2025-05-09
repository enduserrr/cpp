# STL

## Ex00 Bitcoin Exchange


## Ex01 RPN
### Reverse Polish Notation
A.k.a postfix notation
* **RPN** is a mathematical notation where every operator follows all of its operands.
* It's evaluated using a stack and eliminates the need for parentheses and operator precedence rules, simplifying parsing for computers.
* **Example:** (3 + 4) * 5" becomes "3 4 + 5 *


## Ex02 PmergeMe
Sorts a sequence of positive integers using merge-insert algorithm (Ford-Johnson algorithm) using two different containers comparing the sorting time of the two.

### Ford-Johnsnon Algorithm
**Ford-Johnsnon Algorithm** is a comparison sort algorithm designed to perform sorting with a minimal number of comparisons, especially optimal for smaller lists.

### How It Works
* Groups elements into pairs and sorts each pair.
* Recursively sorts the larger elements of these pairs to form a main sorted chain.
* Inserts the remaining smaller elems into THE main chain efficiently using binary insertion, often in an order optimized by Jacobsthal numbers to reduce worst-case comparisons.

### Jacobsthal Numbers
* **Jacobsthal numbers** are an integer sequence defined by the recurrence relation: J(n) = J(n-1) + 2 * J(n-2), with initial values J(0) = 0 and J(1) = 1.
* Appears often in combinatorial problems, like optimizing insertion points in Ford-Johnson sort algorithms.