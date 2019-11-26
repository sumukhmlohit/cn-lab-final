#include<stdio.h>

int queue[200];
int bcap=0,orate=0,iter=0;
int stop=1,idata,bdata=0;


void main()
{
printf("Enter bucket capacity");
scanf("%d",&bcap);

printf("Enter output rate");
scanf("%d",&orate);


while(stop!=0)
{ iter++;
printf("Enter incoming data");
scanf("%d",&idata);

if(idata<orate)
{
printf("%d has been processed",idata);
}

else if(idata+bdata-orate<=bcap)
{
printf("%d has been processed",orate);
bdata=idata+bdata-orate;
}

else
{
printf("%d has been processed",orate);
bdata=bcap;
printf("%d has been dropped",bdata+idata-orate-bcap);
}
printf("Bucket data is %d",bdata);
printf("Enter 0 to stop");
scanf("%d",&stop);
}


}
