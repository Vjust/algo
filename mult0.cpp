#include <iostream>
#include <vector>
#include "ch03.h"

int multiply0(int, int);
int multiply1(int, int);
int mult3(int, int, int);
long mult3l(long, long, long);
int count_one_bits(int);

static int times_called =0;

int main(int argc, char *argv[]) {
  int n, a;
  int nl, al;
  int repeat ;
  if (argc < 2) {
      std::cout << "Usage cmd arg1 arg2" << std::endl;
      exit (-1);
    }

  std::cout << argc << std::endl;

  if (argc == 4) {
    nl = atol(argv[1]);
    al = atol(argv[2]);
    repeat=100;
    for (;repeat > 0; --repeat) {
      std::cout << "mult3 =" << mult3(0,nl,al) << std::endl;
    }
  }
  else {
    n = atoi(argv[1]);
    a = atoi(argv[2]);
  
    std::cout << "mult0 = " << multiply0(n,a) << std::endl;
    std::cout << "mult1 =" << multiply1(n,a) << std::endl;
    std::cout << "one bits n = " << count_one_bits(n) << std::endl;
  }

}

bool odd(int n) { return n & 0x1 ; }
int half(int n) { return n >> 1; }

bool oddl(long n) { return n & 0x1 ; }
long halfl(long n) { return n >> 1; }


int multiply0(int n, int a) {
  if (n == 1) return a;
  return multiply0(n-1, a) + a;
}

int multiply1(int n , int a) {
  if (n == 1) return a;
  int result = multiply1 (half (n), a + a);
  if (odd (n)) result = result + a;
  return result;

  
}


int mult3(int r, int n, int a) {

  if (odd(n)) {
    r = r + a;
    if ( n==1) 
      return r;
  }

    
    n = half(n);
    a = a + a;
    return mult3(r, n,  a);
}


long mult3l(long r, long n, long a) {

  if (oddl(n)) {
    r = r + a;
    if ( n==1) 
      return r;
  }

    
    n = halfl(n);
    a = a + a;
    return mult3l(r, n,  a);
}


/*
  given a number n, count the 1s in its binary representation
 */
int count_one_bits(int n) {
  if (n == 0) return 0;
  if (odd(n) ) {
    return 1 + count_one_bits (n >> 1);
  }
  else 
      return count_one_bits (n>>1);
}
