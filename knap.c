#include<stdio.h>
#include<stdlib.h>
int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int knapSack(int n,int C,int w[],int v[])
{
    //If total capacity or toal number of items is zero, return 0
    if((n==0)||(C==0))
    {
        return 0;
    }
    //If a particular item's weight is greater than knapsack's capacity, ignore it
    if(w[n-1]>C)
    {
        return knapSack(n-1,C,w,v);
    }
    // Return max(Item included,Item not included)
    else
    {
        return max(knapSack(n-1,C-w[n-1],w,v)+v[n-1],knapSack(n-1,C,w,v));
    }
}
int main(int argc,char* argv[]){
    int n,C,w[1000],v[1000],i,j,k,l;
    scanf("%d",&n);
    scanf("%d",&C);
    for(i=0;i<n;i++)
    {
        scanf("%d",&w[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&v[i]);
    }
    printf("%d",knapSack(n,C,w,v));
    
return 0;
}
