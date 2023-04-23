Copyright 2023 Maria Sfiraiala (maria.sfiraiala@stud.acs.upb.ro)

# Almost Without Gigel - Project1

### `feribot.cpp`

#### Description

The task can be reduced to calculating the maximum sum between all K partitions of an array constructed in such a way that their sum is minimal.

We'll approach this new problem using binary search:

1. We set the left part of the interval as the maximum sum of the partition on the corner case when `K == weights.size()`.
In other words, when there are as many partitions as elements, the answer to our problem is the maximum element in the array.

1. We set the right part of the interval as the maximum sum of the partition on the corner case when `K == 1`.
In other words, when there is only one partition, the answer to our problem is the sum of the array.

1. We check whether mid meets all the conditions to become the solution:

   * We construct partitions by adding as many elements from the array to the current sum.

   * When the partition sum becomes greater that mid, we start a new sum, for a new partition.

   * We check whether the number of partitions is proper (it's ok to have less partitions than K, since we'll further decrease mid in the binary search algorithm).

#### Complexity

| Complexity | Task1 |
|------------|-------|
| Time | O(n * log(sum_array - max_array)) |
| Space | O(1) |

### `nostory.cpp`

#### Description

**Task1**

Since we have as many moves as we wish, we'll simply maximize the result by sorting one array descendingly and one ascendingly.
This way we won't have maximums from one array "shadowing" (eliminating from the sum) the ones from the other array.

**Task2**

As mentioned for **Task1**, when choosing what numbers to move from one array to another or inside the same array, we must do so the maximums (the greatest N elements from `a` and `b`) don't shadow each other.

We'll achieve this by keeping an array with maximums and one with minimums for each pair.
At this point, the 2 given arrays don't exist anymore and we'll picture the task just through pairs:

* We sort the array of maximums increasingly and the array of minimums decreasingly.

* We start to decide what elements will make it to the sum.

* As long as we have moves to make and the i-nth minimum is greater than its pair from the maximum array, we'll choose the mimimum and add it to the array.

* Otherwise, we choose the element from the maximum array.

#### Complexity

| Complexity | Task1 | Task2 |
|------------|-------|-------|
| Time | O(n * logn) | O(n * logn) |
| Space | O(1) | O(n) |

### `sushi.cpp`

#### Description

All the three tasks of this problem, can be reduced to the Knapsack algorithm, by regarding the sum of the grades given by the friends for each dish as the price of the object and the dish price as the weight of the object.
The knapsack limit weight can be regarded as the number of friends multiplied by how much they are willing to pay.

**Task1**

The classic Knapsack algorithm, inspired by the [PA lab demo](https://ocw.cs.pub.ro/courses/pa/laboratoare/laborator-03#rucsac).

**Task2**

In order to still reduce this task to the Knapsack algorithm, we've doubled the dishes in both the sum of grades array and in the price list.
This way, we can choose one dish, once, twice or even never, and still apply the same algorithm as for the first task.

**Task3**

We've applied the same approach as in **Task2** in order to reduce the problem and used a second matrix, besides `dp` to keep the previous solution for the total number of dishes the friends will ask for.

Following this idea, for a given (j, i, cap) state of the loop, the indeces signify:

* j = we've used j elements until now

* i = we choose the i-th element

* cap = the knapsack has cap capacity

#### Complexity

| Complexity | Task1 | Task2 | Task3 |
|------------|-------|-------|-------|
| Time | O(m * x * n) | O(m * x * n) | O(m * x * $n^2$) |
| Space | O(m * x * n) | O(m * x * n) | O(m * x * n) |

### `semnale.cpp`

#### Description

We've used dynamic programming and a `dp` matrix in order to get the desired result for both tasks.

For a given (i, j) state of the loop, `dp[i][j]` stores how many signals can be generated with i zeros and j ones.

**Task1**

We've first set the base cases:

* We can construct 1 signal with 0 ones and however many zeros, so we've set the first column to 1.

* We can construct 1 signal with 0 zeros and 1 one, so we've set dp[0][1] to 1; the rest of the first line is zeroed at allocation as we cannot have more than 1 one consecutively.

* We can now construct the solution: the current element (or signal) can be extended either by suffixing the previous signal with 0 or by suffixing the one before the previous one with 01, as we cannot risk adding 1 by itself.

**Task2**

We've first set the base cases:

* We can construct 1 signal with 0 ones and however many zeros, so we've set the first column to 1.

* We can construct i + 1 signals with 1 ones and however many zeros, so we've set the second column to i + 1.

* We can construct 1 signal with 0 zeros and 1 one, so we've set dp[0][1] to 1.
We can construct 1 signal with 0 zeros and 2 ones, so we've set dp[0][2] to 1; the rest of the first line is zeroed at allocation as we cannot have more than 2 ones consecutively.

* We can now construct the solution: the current element (or signal) can be extended either by suffixing the previous signal with 0 or by suffixing the one before the previous one with 01 or the one before that with 011, as we cannot risk adding 11 by itself.

#### Complexity

| Complexity | Task1 | Task2 |
|------------|-------|-------|
| Time | O(x * y) | O(x * y) |
| Space | O(x * y) | O(x * y) |

### `badgpt.cpp`

#### Description

* We've read 2 elements in a loop: first the character, then the number of instances for the character.

* If the character was either 'n' or 'u', we've used Fibonacci to get the number of variations the character introduces.
For each 'n' or 'u' character, let n be their number of instances in the string, the variation of the original string gets multiplied by the n-th Fibonacci number.

* We also had to come up with a fast algorithm to get the n-th Fibonacci element, an approach that would fit in the O(logn) complexity class.
The algorithm is based on the observation that, by knowing fibonacci(n - 1) and fibonacci(n) we can easily get fibonacci(2n) and fibonacci(2n + 1):

   fibonacci(n) = fibonacci(n)

   fibonacci(n + 1) = fibonacci(n) + fibonacci(n - 1)

   fibonacci(n + 2) = fibonacci(n + 1) + fibonacci(n) = 2 * fibonacci(n) + fibonacci(n - 1)

   fibonacci(n + 3) = fibonacci(n + 2) + fibonacci(n + 1) = 3 * fibonacci(n) + 2 * fibonacci(n - 1)

   . \
   . \
   . 

   fibonacci(n + k) = fibonacci(n) * fibonacci(k + 1) + fibonacci(n - 1) * fibonacci(k)

   fibonacci(2n + 1) = fibonacci(n) * fibonacci(n + 2) + fibonacci(n - 1) * fibonacci(n + 1)

* Following this idea, the Fibonacci algorithm that was implemented is of O(logn) time complexity and avoids using matrix multiplication.

#### Complexity

| Complexity | Task1 |
|------------|-------|
| Time | O(G * logL) |
| Space | O(1) |
