#include <stdio.h>
#include <stdlib.h>
int desenha(int o[10], int nop){
    printf("%d%d%d\n%d%d%d\n%d%d%d\n\n total:%d\n",o[1],o[2],o[3],o[4],o[5],o[6],o[7],o[8],o[9],nop);
}

int main()
{
    int a[10]={0,0,0,0,0,0,0,0,0,0};
    int total,a1,a2,a3,a4,a5,a6,a7,a8,a9;
    for(a1=1;a1<=9;a1++){
        a[a1]=1;
        for(a2=1;a2<=9;a2++){
            if(a[a2]==0){
                a[a2]=2;
                for(a3=1;a3<=9;a3++){
                    if(a[a3]==0){
                        a[a3]=3;
                        for(a4=1;a4<=9;a4++){
                            if(a[a4]==0){
                                a[a4]=4;
                                total++;
                                for(a5=1;a5<=9;a5++){
                                    if(a[a5]==0){
                                        a[a5]=5;
                                        total++;
                                        for(a6=1;a6<=9;a6++){
                                            if(a[a6]==0){
                                                a[a6]=6;
                                                total++;
                                                for(a7=1;a7<=9;a7++){
                                                    if(a[a7]==0){
                                                        a[a7]=7;
                                                        total++;
                                                        for(a8=1;a8<=9;a8++){
                                                            if(a[a8]==0){
                                                                a[a8]=8;
                                                                total++;
                                                                for(a9=1;a9<=9;a9++){
                                                                    if(a[a9]==0){
                                                                        a[a9]=9;
                                                                        total++;
                                                                        desenha(a,total);
                                                                        a[a9]=0;
                                                                    }
                                                                }
                                                            a[a8]=0;
                                                            }
                                                        }
                                                    a[a7]=0;
                                                    }
                                                }
                                            a[a6]=0;
                                            }
                                        }
                                        a[a5]=0;
                                    }
                                }
                                a[a4]=0;
                            }
                        }
                        a[a3]=0;
                    }
                }
                a[a2]=0;
            }
        }
        a[a1]=0;
    }
    printf("%d",total);
    system("pause");
}

