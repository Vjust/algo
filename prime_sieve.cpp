#include <iostream>
#include <vector>

using std::cout;
using std::vector;
using std::endl;
using std::fill;


#define RandomAccessIterator typename
#define Integer typename


template <Integer N>
N val_at_index (N i) {
  return (i + i + 3);
}

template <Integer N>
N index_for_val (N v) {
  return (v-3)/2;
}
template <Integer N>
N get_index_square (N i) {
  return  2 * i * (i + 3) + 3;
}


template <RandomAccessIterator I, Integer N>
void mark_sieve (I first, I last, N factor) {

  int i(0);
  cout << "mark_sieve : call args : factor " << factor << endl;
  
  // assert (first != last)
  *first = false;
  while (last - first > factor) {    
    first = first + factor;
    *first = false;
    cout << "mark_sieve : marked non-prime " << i << endl;
    ++i;
  }
}

template <RandomAccessIterator I, Integer N>
void sift0 (I first , N n) {
  std::fill(first, first + n, true);
  N i(0);
  N index_square(3);
  while (index_square < n) {
    if (first[i]) {
      mark_sieve (first + index_square,
		  first + n,
		  i + i + 3);
    }
    ++i;
    index_square = get_index_square (i);
    //    index_square = 2 * i (i + 3) + 3;
  }
}

template <RandomAccessIterator I, Integer N>  
void print_sieve(I first, N n) {
  N i(0);
  cout << 2;
  while (i < n) {
    if (*first) {
      cout << " " << val_at_index(i);
    }
    ++first;
    ++i;
  }
  cout << endl;
}

int main() {    
    std::vector<int> v(500);
    sift0(v.begin(), 50);
    cout << "sift0(begin(v), 50):\n";
    print_sieve(v.begin(), 50);
}
