#include <stdio.h>
#define swap(x,y,t) ((t)=(x), (x)=(y), (y)=(t))
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
    int list[6]={32,17,4,52,29,45};
    q(list,0,5);
    int i;
    for(i=0; i<6; i++)
    {
        printf("%d ",list[i]);
    }
    return 0;
}