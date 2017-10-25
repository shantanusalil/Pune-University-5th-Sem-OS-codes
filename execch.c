#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int binary_search(int ar[],int start,int end,int key)
{
	int mid;
	if(start<end)
	{
		mid=(start+end)/2;
		if(key==ar[mid])
			return mid;
		else if(key<ar[mid])
			return binary_search(ar,start,mid,key);
		else
			return binary_search(ar,mid+1,end,key);
	}
	return -1;
}

int main(int argc,char *argv[])
{
	int ch,i;
	int key,count=0 ;
	int ar[34];
	for(i=0;argv[i+1]!=NULL;i++)
	{
			ar[i]=atoi(argv[i+1]);
			count++;
	}
	printf("\nEnter the key to be Searched::");
	scanf("%d",&key);
	int ans=binary_search(ar,0,count,key);
	if(ans==-1)
		printf("\nKey not found!!!");
	else
		printf("\nElement found at position %d\n",ans);
	return 0;
}