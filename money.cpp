#include "money.h"
Money::Money()
{
    money_num=0;
    money[1]=650;
    money[2]=1195;
    money[3]=2010;
    money[4]=3095;
    money[5]=4450;
    money[6]=6075;
    money[7]=7970;
    money[8]=10135;
    money[9]=12570;
    for(int i = 10; i <= 100; ++ i) {
        money[i]=money[i-1] + 2705;
    }
}
