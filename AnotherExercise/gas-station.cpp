#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int LengthRoad,GasStation;
    pair<int, int> P[10000];
    
    while(true){
        scanf("%d %d",&LengthRoad,&GasStation);
        if(LengthRoad == 0) break;
        for(int i = 0,LocationGasStation,Radius;i < GasStation;++i){
            scanf("%d %d",&LocationGasStation,&Radius);
            P[i] = make_pair(LocationGasStation - Radius,LocationGasStation + Radius);
        }
        sort(P,P + GasStation);
        int pos = 0,aux,i = 0,ans = GasStation;
        while(pos < LengthRoad){
            aux = pos;
            while(i < GasStation && P[i].first <= pos)  aux = max(aux,P[i++].second);
            if(aux == pos) break;
            pos = aux;
            --ans;
        }
        printf("%d\n",pos < LengthRoad ? -1 : ans);
    }
    
    return 0;
}