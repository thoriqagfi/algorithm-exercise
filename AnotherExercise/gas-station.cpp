#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
  int L, G;
  pair<int, int> P[10000];
  while(true) {
    scanf("%d %d", &L, &G);
    for(int i = 0; i < G; i++) {
      int x, r;
      scanf("%d %d", &x, &r);
      P[i] = make_pair(x - r, x + r);
    }
    sort(P, P + G);
    if(L == 0) break;

    int temp = 0; bool flag = false;
    for(int i = 0; i < G; i++) {
      if( P[G-1].second < L) {
        flag = true;
        break;
      }
      else if(P[i] == P[0] || P[i] == P[G-1]) continue;
      else if( P[i].first <= P[i - 1].second && P[i].second >= P[i + 1].first && P[i-1].second >= P[i+1].first) ++temp;
    }
    printf("%d\n", flag ? -1 : temp);
  }

  return 0;
}