#include <stdio.h>
using namespace std;

// Template Scanf pak Rully
int getNum(){
    int res = 0;
    char c;
    int b = 0;
    while(1){
        c = getchar_unlocked();
        if(c == '-') b = 1;
        if(c == ' ' || c == '\n') continue;
        else break;
    }
    if(c != '-') res = c - '0';
    while(1){
        c = getchar_unlocked();
        if(c >= '0' && c <= '9') res = 10 *  res + c - '0';
        else break;
    }
    if(b == 1) res *= -1;
    return res;
}

int main() {
  int k, t;
  t = getNum();
  while(t--) {
    int n=0;
    k = getNum();
    while(k > 0) {
      n++; k-=n;
    }
    if(k == 0) printf("%d %d\n", n-1, n);
    else printf("%d %d\n", n+k-1, n);
  }
  return 0;
}

/*
01  1 -> temp=1 k=0
02  2 -> temp=2 k=-1
12  3 -> temp=2 k=0
03  4 -> temp=3 k=-2
13  5 -> temp=3 k=-1
23  6 -> temp=3 k=0
04  7 -> temp=4 k=-3
*/