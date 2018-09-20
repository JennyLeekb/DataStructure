#ifndef __SORT_H__

typedef int KeyType;

typedef struct
{
    KeyType key;
}DataType;

void insertSort(DataType a[], int n);
void shellSort(DataType a[], int n, int d[], int numOfD);
void selectSort(DataType a[],int n);
void heapSort(DataType a[], int n);
void bubleSort(DataType a[], int n);


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


//调整非叶子节点h使得a[]满足最大堆，n为数组a中的元素个数
void createHeap(DataType a[], int n, int h)
{
   int i,j,flag;
   DataType temp;

   i = h;  //i为要建堆的二叉树的根结点
   j = 2*i+1;
   temp = a[i];
   flag = 0;

   while(j < n && flag != 1)
   {
       if(j<n-1 && a[j].key < a[j+1].key) j++;

       if(temp.key > a[j].key)
       {
           flag = 1;
       }
       else
       {
           a[i] = a[j];
           i = j;
           j = 2*i+1;
       }
   }

   a[i] = temp;

}

//把数组元素a[0]~a[n-1]初始化创建为最大堆
void initCreateHeap(DataType a[], int n)
{
    int i;

    for(i=(n-2)/2 ; i>=0; i--)
        createHeap(a,n,i);
}

//堆排序
void heapSort(DataType a[], int n)
{
    int i;
    DataType temp;

    initCreateHeap(a,n);

    for(i=n-1;i>0;i--)  //当前堆的个数每次递减1
    {
        temp = a[0];    //交换当前根结点和最后一个结点
        a[0] = a[i];
        a[i] = temp;

        createHeap(a,i,0); //重新调整根结点，使之满足最大堆
    }
}


//冒泡排序
void bubleSort(DataType a[], int n)
{
    int i,j;
    DataType temp;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j].key > a[j+1].key)
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}





#endif // __SORT_H__

