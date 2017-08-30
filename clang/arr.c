#include<stdio.h>
int main()
{
  //same to arr[5] = {5, 10, 2, 5, 0};
  int arr[5]={5, 10,2,5};
 
  printf("%d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
  //there is no index out of bound check at all
  printf("%d\n", arr[-2]);

  //too many initializers for ‘int [2]’
  //int arr2[2] = {10, 20, 30, 40, 50};
  int arr2[2] = {10, 20};
  //arr2 + 4 is the same as arr, which mean arr is 16 bytes larger than arr2
  //stack allocation from down to up?
  printf("%d %d %d %d %d\n", arr2[0], arr2[1], arr2[2], arr2[3], arr2[4]);
 
  printf("%lx %lx\n", arr, arr2);
  printf("%d %d\n", sizeof(arr), sizeof(arr2));
  return 0;
}
