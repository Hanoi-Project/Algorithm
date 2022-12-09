#include <stdio.h>
#include <string.h>
#define swap(x,y,t) ((t)=(x), (x)=(y), (y)=(t))
int list[100];
int p(int list[], int left,int right)
{
    int pivot,temp,low,high;
    low = left;
    high= right+1;
    pivot=list[left];
    do
    {
        do
        {
            low++;
        }while(list[low]<pivot && low<=right);
        do
        {
            high--;
        }while(list[high]>pivot);

        if(low<high)
        {
            swap(list[low],list[high],temp);
        }
    }while(low<high);
    swap(list[left],list[high],temp);
    return high;
}

void q(int list[], int left,int right)
{
    if(left<right)
    {
        int a=p(list, left, right);
        q(list,left,a-1);
        q(list,a+1,right);
    }
}

int main()
{
	int n, i, lenght=0;
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &list[i]);
	}
    for(i=0;list[i]!=0;i++)	lenght++;
    q(list,0,lenght-1);
    printf("  ����ǥ\n");
    for(i=0; i<lenght; i++)
    {
    	if(list[i]==list[i-1]) printf("%d��    \t\t%d��\n",i, list[i-1]);
        else printf("%d��    \t%d��\n",i+1, list[i]);
    }
    return 0;
}
