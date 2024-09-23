#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void display(int *arr, int count) {
  for (int i = 0; i < count; ++i) {
    if (i != 0) printf(" ");
    printf("%d", *(arr+i));
  }
  printf("\n");
}

void memory() {
  int cnt = 10;
  //! 内存分配
  // malloc
  int *arr = (int *)malloc(cnt * sizeof(int));
  display(arr, cnt);
  // calloc; 分配内存并设置为 0
  int *arr2 = (int *)calloc(cnt, sizeof(int));
  display(arr, cnt);
  // realloc
  arr = (int *)realloc(arr, cnt * 2 * sizeof(int));
  display(arr, cnt * 2);
  int arr3[10];
  printf("%ld, %ld, %ld\n", sizeof(arr3), sizeof(arr), sizeof(arr2));
  //! 内存释放
  // free
  free(arr);
  free(arr2);
  //! 内存操作
  // memset
  memset(arr2, 0xf, cnt * sizeof(int));
  display(arr2, cnt);
  // memcpy
  memcpy(arr, arr2, cnt * sizeof(int));
  display(arr, cnt * 2);
  // memmove
  //! memmove 和 memcpy 类似，可以处理重叠内存，优先使用 memcpy
  memmove(arr + cnt, arr, 5 * sizeof(int));
  display(arr, cnt * 2);
} /** output
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
40, 8, 8
252645135 252645135 252645135 252645135 252645135 252645135 252645135 252645135 252645135 252645135
252645135 252645135 252645135 252645135 252645135 252645135 252645135 252645135 252645135 252645135 0 0 0 0 0 0 0 0 0 0
252645135 252645135 252645135 252645135 252645135 252645135 252645135 252645135 252645135 252645135 252645135 252645135 252645135 252645135 252645135 0 0 0 0 0
*/

void define_arr() {
  int arr[10] = {1, 2, 3, 4, 5};
  int arr2[5] = {1};
  int arr3[] = {1, 2, 3};
  display(arr, 10);
  display(arr2, 5);
  display(arr3, 3);
} /** output
1 2 3 4 5 0 0 0 0 0
1 0 0 0 0
1 2 3
*/

int main() {
  memory();
  define_arr();
  return 0;
}
