template <RandomAccessIterator I, Integer N>
void mark_sieve(I first, I last, N factor) {
  *first = false;
  while (last - first > factor) {
    first = first + factor;
    *first = false;
  }
}

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
    index_square = 2 * i (i* 3) + 3;
  }
}
