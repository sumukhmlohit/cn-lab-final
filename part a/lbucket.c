#include<stdio.h>

int queue[200];
int bcap=0,orate=0,iter=0;
int stop=1,idata,bdata=0;

int iterations[200],incoming[200],bucket[200],outgoing[200],dropped[200];

int drop;
void main()
{
printf("Enter bucket capacity\n");
scanf("%d",&bcap);

printf("Enter output rate\n");
scanf("%d",&orate);


while(stop!=0)
{ iter++;
drop=0;
printf("Enter incoming data\n");
scanf("%d",&idata);

if(idata+bdata<orate)
{
printf("%d has been processed\n",idata);
bdata=bdata+idata-orate;

}

else if(idata+bdata-orate<=bcap)
{
printf("%d",bdata);
printf("%d has been processed\n",orate);
bdata=idata+bdata-orate;
}

else
{
    int bdata0=bdata;
printf("%d has been processed\n",orate);
bdata=bcap;
printf("%d has been dropped\n",bdata0+idata-orate-bcap);
drop=bdata0+idata-orate-bcap;
}
printf("Bucket data is %d\n",bdata);

iterations[iter]=iter;
incoming[iter]=idata;
outgoing[iter]=orate;
bucket[iter]=bdata;
dropped[iter]=drop;
int i=0;

printf("Iterations Incoming_Data Outgoing_Data Bucket_Data Data_dropped \n");
for(i=1;i<=iter;i++)
{   
    printf("%d            %d             %d              %d            %d\n",iterations[i],incoming[i],outgoing[i],bucket[i],dropped[i]);
    
}

printf("Enter 0 to stop");
scanf("%d",&stop);
}

while(bdata!=0)
{
    iter++;
     iterations[iter]=iter;
    if(bdata>=5)
    {bdata=bdata-orate;
    printf("%d has been processed\n",orate);
    }
    else
    {
        printf("%d has been processed\n",bdata);
    bdata=0;
    }
 int i;
 iterations[iter]=iter;
incoming[iter]=idata;
outgoing[iter]=orate;
bucket[iter]=bdata;
dropped[iter]=drop;
    printf("Iterations Incoming_Data Outgoing_Data Bucket_Data Data_dropped \n");
for(i=1;i<=iter;i++)
{   
    printf("%d            %d             %d              %d            %d\n",iterations[i],incoming[i],outgoing[i],bucket[i],dropped[i]);
    
}       
}

}
