#include <math.h>

long long findNb(long long m)
{
  /* knowing 1^3+2^3+...+n^3 == (n^2*(n+1)^2)/4
  then m = (n^2*(n+1)^2)/4
  then n^2+n - 2*sqrt(m) = 0 -> n = (-1 + sqrt(1+8*sqrt(m)))/2*/
  long double n = (-1 + sqrtl((1+8 * sqrtl(m))))/2;
  if (n - (long long)n == 0) return n;
  return -1;
}