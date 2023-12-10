Troy Lopez (lopeztr)

Assignment 5 Writeup - Recursion and Linked Lists

I'm not sure if this is supposed to cover both parts of the assignment, so just in case I'm covering both of them here.

---------------------------------------

Part 1: Recursion

This program implements a recursive solution to the common discrete math stair climbing problem.
A staircase of size n can be ascended in steps of 3, 2, or 1 at a time. We need to find the number of different ways to climb a staircase.
This program works by taking the height of the staircase and finding the number of ways to make a staircase with
sizes n -1, -2, and -3. This works recursively to sum up each option. The subtraction is like taking a step of that size.
From what I've found, for any staircase larger than size 28 or so, the program takes a very long time to run, and for anything much larger
the integer used to store output overflows. This could be avoided through some differnt types or some weird math,
but is out of scope for this assignment.

-----------------------------------------

Part 2: Linked List
This program just implements a homebrew version of the linked list class. The list is singly linked.
Users can use all of the standard data manipulation functions such as pushback or remove, as well as sort ascendingly or descendingly.
Lists can be scaled to meet whatever size is needed, and are dynamically allocated.

Part 2.a: Merge sort explanation:
Recursive merge sort works by first splitting the list into a bunch of smaller lists, and then reassembling them in order. The list is first recursively split down into single nodes.
Then, each sublist is compared, starting at the head. The lowest value is taken from the 2 heads, and the comparison is run again. This creates a sorted sublist. Each of these sorted sublists
are merged again and again until eventually there is just 1 big list with the original size that has been sorted.
For the descending sort, I was too busy to do the extra credit so I just call the sort ascending function and then invert the list order.
Because of the nature of the sublist method, merge sort follows an O(nlog(n)) complexity. N doubling only adds 2n + 1 step in the algorithm, which is much more efficient than most other algs.
Increasing n increases the time the algorithm takes near-linearly, hence the logalinear label. Additionally, this method always works in the same fashion, making best and worse case
complexity identical.

------------------------------------------

How to run the code:

Note this is written assuming the user knows very little about linux commands as per the assignment.

assuming you are already in this directory. just run "./runme.sh". This is a script I wrote to automatically
clean up any partially made files, and then recompile and run each program (using makefiles). Eeach program will run interactively in the terminal.
You will need to press enter when prompted to continue through the programs.

Alternatively, use "cd/linked_list;make clean; make; valgrind linklist;" to test the linked list and "cd/recursion;make clean; make; valgrind recur"
to test recursion. To get back to the main directory between programs just use "cd .."

-------------------------------------------

Extra credit:

If you used "runme.sh" earlier your name is at the top of this file.

sort_ascending uses merge sort, which is always O(nlog(n)) since it scales at a rate of n times the natural log of n. The logarithm comes from the "divide and conquer" method, where a new significant level of division is added for every time n doubles.

sort_descending uses merge sort and then takes a second pass over the array to swap positions around, adding a coefficent but not substantially channging the runtime, making it also O(nlog(n))