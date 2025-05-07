# TEMPLATE CONTAINERS, ITERATORS, ALGORITHMS

## STL Components
* Containers: Data structures storing collections of objects.
* Algorithms: Functions performing operations on data within a container
  * find()
  * max_element()
* Iterator: Objects acting like pointers, giving access to elements within cointainers and linking algos to them
  * begin() & end() return STL iterators (technically STL container member funcs not iterators themselves)
* Function Objects: Objects that can be called like funcs, mostly used to customize algorithms

## Ex00
* Func template that searches for the first occurance of a given integer within a standard sequence container (e.g. vector or list). The funct takes the container and an int value as inputs and returns an iterator to the found element or exception throw for errors.
* Assosiatice containers store values assosiated with keys instead of index

## Ex01
* Span class used as a container to store a fixed max number (N) of ints.
* Longest Span = The largest difference between any two nbs within the span.
* Shortest Span = The smallest difference between any two nbs withing the span.

## Ex02
* std::stack uses an underlying container (e.g. std::deque by default) which has begin() and end() but the std::stack adapter hides these from its public interface on purpose, making it uniterable on it's own.
* Functions begin() & end() return iterators to the beginning and end of the container
