#include<iostream>

int main() {

  int arr[4] = { 101, 202, 303, 404};
  
  int* ptr = arr;

  std::cout << ptr << "\n"<< &arr[0] << std::endl << std::endl;
  ptr++;
  std::cout << ptr << "\n"<< &arr[1] << std::endl;

  return 0;
}


/*
OUTPUT

0x7fff92327000
0x7fff92327000

0x7fff92327004
0x7fff92327004

*/
