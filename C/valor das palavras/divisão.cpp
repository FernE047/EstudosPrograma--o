#include<stdio.h>
int main(){
	int vin,dig;
	vin=27;
	scanf("%d",&dig);
	printf("%d/%d\n",dig,vin);
	printf("%d*%d=%d\n",vin,dig/vin,(vin*(dig/vin)));
	printf("%d\n",(dig-(vin*(dig/vin))));
}
