#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int main(){
    int LengthRoad,GasStation, LocationGasStation,Radius;
    pair<int, int> P[10000];
    while(true){
        scanf("%d %d",&LengthRoad,&GasStation);
        if(LengthRoad == 0) break;
        for(int i = 0;i < GasStation;++i){
            scanf("%d %d",&LocationGasStation,&Radius);
            P[i] = make_pair(LocationGasStation - Radius,LocationGasStation + Radius);
        }
        int pos = 0,aux,i = 0,eliminate = 0;

        while(pos < LengthRoad){
            aux = pos;
            while(i < GasStation && P[i].first <= pos) aux = max(aux,P[i++].second);
            if(aux == pos) break;
            pos = aux;
            ++eliminate;
        }
        printf("%d\n",pos < LengthRoad ? -1 : GasStation - eliminate);
    }
    return 0;
}