/*
        1345. Jump Game IV
    Given an array of integers arr,
        you are initially positioned at the first index of the array.

        In one step you can jump from index i to index:

        i + 1 where: i + 1 < arr.length.
        i - 1 where: i - 1 >= 0.
        j where: arr[i] == arr[j] and i != j.
        Return the minimum number of steps to reach the last index of the array.

        Notice that you can not jump outside of the array at any time.
        Example 1:
                Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
                Output: 3
        Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9.
                Note that index 9 is the last index of the array.

        Example 2:
                Input: arr = [7]
                Output: 0
        Explanation: Start index is the last index. You do not need to jump.

        Example 3:
                Input: arr = [7,6,9,6,9,6,9,7]
                Output: 1
        Explanation: You can jump directly from index 0 to index 7 which is last
   index of the array.

        Constraints:
                1 <= arr.length <= 5 * 104
                -108 <= arr[i] <= 108

        bruhh I need to change to tabs, neovim btw
 */
#include <stdio.h>
#include <stdlib.h>

int *check_repetitive(int to_check, int index, int *av, int size) {
  int cc = 0;
  int number_of_possible_j_jumps = 0;
  while (cc < size) {
    if (av[cc] == to_check && cc != index)
      number_of_possible_j_jumps++;
    cc++;
  }
  if (number_of_possible_j_jumps == 0)
    return (NULL);
  int *indexes_of_j = calloc(number_of_possible_j_jumps, sizeof(int));
  cc = 0;
  int saving_j = 0;
  while (cc < size) {
    if (av[cc] == to_check && cc != index) {
      indexes_of_j[saving_j] = cc;
      saving_j++;
    }
    cc++;
  }
  indexes_of_j[saving_j] = '\0';
  return (indexes_of_j);
}

int count_minimal(int *arr, int size, int index, int counter) {
  if (index != 0) {
    int *j_jump = check_repetitive(arr[index], index, arr, size);
    if (j_jump != NULL) {
      free(j_jump);
    }
    // count_minimal(arr, size, index, counter);
  }
  return (counter);
}

// it would make sense to start from the last index
// then finding the path, some funky recursion would be fun
int minJumps(int *arr, int arrSize) {
  if (arr == NULL || arrSize == 0)
    return (-1);
  else if (arrSize == 1)
    return (0);
  return (count_minimal(arr, arrSize, arrSize - 1, 0));
}

void test(int *example, int to_check, int start_index, int size) {
  int *test = check_repetitive(to_check, start_index, example, size);
  if (test != NULL) {
    printf("Indexes are at:");
    for (int i = 0; test[i] != '\0'; i++)
      printf(" %d", test[i]);
    printf("\n");
    free(test);
  }
}

int main(void) {
  printf("Broken test, so value is negative -> %d\n", minJumps(NULL, 0));
  int example_one[] = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};
  int example_two[] = {1};
  int example_three[] = {7, 6, 9, 6, 9, 6, 9, 7};
  printf("Should be 3, but it's -> %d\n", minJumps(example_one, 9));
  printf("Testing a function check_repetitive below on example_three\n");
  test(example_one, example_one[9], 9, 10);
  test(example_two, example_two[0], 0, 1);
  test(example_three, example_three[7], 7, 8);
  return (0);
}
