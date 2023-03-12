/*
  @Source: geeksforgeeks.com

*/
#include <stdio.h>
#include <math.h>
#define mod 1000000llu;
typedef long long int llu;

using namespace std;

int modExp(llu a, llu b){
  llu res = 1;
  if(a == 0 && b == 0) return 1;
  else if(b == 1) return a;
  while(b > 0) {
    if(b & 1) res = (res*a) % mod;
    b >>= 1;
    a = (a*a) % mod;
  }
  return res;
}

int main() {
  llu a,b,res, d1 = 0, d = 0;
  scanf("%llu %llu", &a, &b);
  d1 = 1 + (log10(a) * b);
  res = modExp(a,b) % mod;
  if(res == 0) d++;
  else d = 1 + log10(res);

  if( d < 6 && d1 >= 6) {
    for(int i = 0; i < 6 - d ; i++) printf("0");
    printf("%llu", res);
  }
  else printf("%llu", res);
}