/* To find the missing no. of n natural numbers.
using A^A = 0 and A^0=A */
#include <iostream>
#define F(i,a,n) for(int i=a;i<n;i++)
using namespace std;

int main()
{
   int arr[100]={1,2,3,4,5,6,7,8,10};
   int a,b,n = 9;
   F(i,0,n)
   a^=arr[i];
   F(i,1,n+2)
   b^=i;
   cout<<(a^b)<<endl;
   return 0;
}

