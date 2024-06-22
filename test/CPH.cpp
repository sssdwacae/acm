//删除大于平均值的数
#include<iostream>
#include<iomanip>
using namespace std;
int main()
{  int a[30],i,j,n;  
   double avg,s=0.0;
   cout<<"请输入欲输入数的个数:";     
cin>>n;
   cout<<"请输入"<<n<<"个数:";
   for(i=0;i<n;i++) 
	   cin>>a[i]; 
/**************************/
   for(i=0;i<n;i++)
	   s=s+a[i];
   avg=s/n;
   j=0;
   for(i=0;i<n;i++)
   {
	   
	   if(a[i]<=avg)
	   {
		   a[j]=a[i];
		   j++;
	   }
   }
   for(i=0;i<j;i++)
	   cout<< " 低于平均值"<<avg<<"的有："<<a[i]<<endl;
/**************************/
}