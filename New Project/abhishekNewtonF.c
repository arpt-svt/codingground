#include<stdio.h>
int fact(int n)
{
int f=1;
while(n!=0)
{
f=f*n;
n--;
}
return f;
}
int diff(float a[],int n)
{
int i;
for(i=0;i<n-1;i++)
a[i]=a[i+1]-a[i];
return (n-1);
}
float calc_u(float u,int n)
{
int i;
float prdt=u;
if(n==1)
return prdt;
for(i=1;i<n;i++)
{
 prdt=prdt*(u-i);
}
return prdt;
}
int main()
{
int i,n,loc;
float x[10],y[10],item,Y,temp;

printf("ENTER NO. OF TERMS:");
scanf("%d",&n);
printf("\nENTER ARGUMENTS:");
for(i=0;i<n;i++)
scanf("%f",&x[i]);
printf("\nENTER ENTITIES:");
for(i=0;i<n;i++)
scanf("%f",&y[i]);
printf("\nENTERED DATA:\nX\t\tY");
for(i=0;i<n;i++)
printf("\n%f\t%f",x[i],y[i]);
printf("\nENTER X TO CALCULATE Y:");
scanf("%f",&item);
Y=y[0];
loc=n;
for(i=1;i<=n;i++)
{
loc=diff(y,loc);
temp=y[0];
Y=Y+(calc_u(((item-x[0])/(x[1]-x[0])),i)*temp)/fact(i);
}
printf("\nY INTERPOLATE:%f",Y);
return 0;
}
