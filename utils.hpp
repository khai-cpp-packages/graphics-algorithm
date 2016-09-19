#if !defined(_INCLUDE_UTILS_HPP)
#define _INCLUDE_UTILS_HPP 20160919

template <class A, class B>
struct Pair {
  A a;
  B b;
  Pair () {}
  Pair (A va) : a(va) {}
  Pair (B vb) : b(vb) {}
  Pair (A va, B vb) : a(va), b(vb) {}
};

template <class Value>
void swap2v (Value & a, Value & b) {
  Value c = a;
  a = b;
  b = c;
}

template <class Value>
Value min2v (Value a, Value b) {
  return a < b ? a : b;
}

template <class Value>
Value max2v (Value a, Value b) {
  return a > b ? a : b;
}

#endif // _INCLUDE_UTILS_HPP
