#ifndef __SORT_H__

typedef int KeyType;

typedef struct
{
    KeyType key;
}DataType;

void insertSort(DataType a[], int n);
void shellSort(DataType a[], int n, int d[], int numOfD);
void selectSort(DataType a[],int n);


//直接排序
void insertSort(DataType a[], int n)
{
    int i,j;
    DataType temp;

    for(i=0;i<n;i++)
    {
        for(j=i;j>0;j--)
        {
            if(a[j].key < a[j-1].key)
            {
                temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            }
            else
                break;
        }
    }
}

//希尔排序
void shellSort(DataType a[], int n, int d[], int numOfD)
{
    int i,j,k,m;
    int decade;
    DataType temp;

    for(i=0; i<numOfD;i++)
    {
        decade = d[i]; //分组间隔
        for(j=0;j<decade;j++)  //共decade个小组
        {
            //组内是直接排序
            for(k=j; k<n-decade+j; k=k+decade)
            {
                for(m=k+decade; m>j; m=m-decade)
                {
                    if(a[m].key < a[m-decade].key)
                    {
                        temp = a[m-decade];
                        a[m-decade] = a[m];
                        a[m] = temp;
                    }
                    else
                        break;
                }
            }
        }
    }
}


//直接选择排序
void selectSort(DataType a[],int n)
{
    DataType minData,temp;
    int i,j,index;

    for(i=0;i<n-1;i++)
    {
        minData = a[i];
        index = i;
        for(j=i+1;j<n;j++)
        {
            if(a[j].key < minData.key)
            {
                minData = a[j];
                index = j;
            }
        }

        if(index != i)  //当前元素就是最小元素的时候不需要交换
        {
            temp = a[i];
            a[i] = minData;
            a[index] = temp;
        }

    }

}


#endif // __SORT_H__

