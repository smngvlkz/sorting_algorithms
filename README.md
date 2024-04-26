## 0X1B. C - Sorting Algorithms & Big O

Implementations of various sorting algorithms in C. The goal of this ALX project is to understand the workings of different sorting algorithms and their time and space complexities.

## About

The project includes the following sorting algorithms:

- Bubble Sort
- Insertion Sort
- Selection Sort
- Quick Sort
- Shell Sort
- Cocktail Shaker Sort
- Counting Sort
- Merge Sort
- Heap Sort
- Radix Sort
- Bitonic Sort
- Quick Sort Hoare
- Card Sorting

Each algorithm is implemented as a function in C, and the repository includes a main file for each algorithm to test its functionality.

## Getting Started

To use these sorting algorithms, you need to have GCC (GNU Compiler Collection) installed on your machine.

## Usage

To compile and run any of the algorithms, use the following commands:

```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 <main-file.c> <sort-function-file.c> print_array.c -o <outputfile>
./<outputfile>
```
## Algorithms

* Bubble Sort 
A simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order. The pass through the list is repeated until the list is sorted.

* Insertion Sort 
A sorting algorithm that builds the final sorted array one item at a time. It is much less efficient on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort.

* Selection Sort 
A sorting algorithm that improves on the bubble sort by making only one exchange for every pass through the list.

* Quick Sort
A divide and conquer algorithm. It creates two empty arrays to hold elements less than the pivot value and elements greater than the pivot value, and then recursively sort the sub arrays.

* Shell Sort
Mainly a variation of Insertion Sort. In insertion sort, we move elements only one position ahead. When an element has to be moved far ahead, many movements are involved. The idea of shell sort is to allow exchange of far items.

* Cocktail Shaker Sort
A variation of Bubble sort. Like bubble sort, Cocktail Sort is also a comparison based algorithm. It differs from bubble sort in the fact that bubble sort only sorts in one direction (up the list), while cocktail sort sorts in both directions (up and down the list) on each pass through the list.

* Counting Sort 
A sorting algorithm that sorts the elements of an array by counting the number of occurrences of each unique element in the array. The count is stored in an auxiliary array and the sorting is done by mapping the count as an index of the auxiliary array.

* Merge Sort
A divide and conquer algorithm that was invented by John von Neumann in 1945. It divides the input array into two halves, calls itself for the two halves, and then merges the two sorted halves.

* Heap Sort
A comparison based sorting technique based on Binary Heap data structure. It is similar to selection sort where we first find the maximum element and place the maximum element at the end. We repeat the same process for the remaining elements.

* Radix Sort
A non-comparative integer sorting algorithm that sorts data with integer keys by grouping keys by the individual digits which share the same significant position and value.

* Bitonic Sort
A classic parallel algorithm for sorting. Bitonic sort does O(n Log 2n) comparisons. The number of comparisons done by Bitonic sort are more than popular sorting algorithms like Merge Sort [ does O(nLogn) comparisons], but Bitonice sort is better for parallel implementation because we always compare elements in predefined sequence and the sequence of comparison doesn’t depend on data. Therefore it is suitable for implementation in hardware and parallel processor array.

* Quick Sort Hoare
A variant of Quick Sort that uses the Hoare partition scheme. The pivot is always the last element of the partition being sorted.

* Card Sorting
The sort_deck function sorts a deck of cards. The deck must contain exactly 52 cards, each represented by a node in a doubly linked list. Each node contains a card, which has a value and a kind (the suit). The function sorts the deck in ascending order, first by kind, in the order Spades, Hearts, Clubs, and Diamonds, and then by value, from Ace to King.
