#ifndef __SORT_H__

typedef int KeyType;

typedef struct
{
    KeyType key;
}DataType;

#include "seqcqueue.h"

void insertSort(DataType a[], int n);
void shellSort(DataType a[], int n, int d[], int numOfD);
void selectSort(DataType a[],int n);
void heapSort(DataType a[], int n);
void bubleSort(DataType a[], int n);
void quickSort(DataType a[], int low, int high);
void mergeArr(DataType a[], int left, int mid, int right, DataType temp[]);
void mergeSort(DataType a[], int left, int right, DataType temp[]);
void radixSort(DataType a[], int n ,int m, int d);


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

//快速排序
void quickSort(DataType a[], int low, int high)
{
    int i = low, j = high;
    DataType temp = a[low];

    while(i<j)
    {
        //确保标准右边的值大于标准
        while(i<j && temp.key <= a[j].key) j--;

        if(i<j)  //当标准右边的值小于标准时，将不大于标准的值移动到标准左端
        {
            a[i] = a[j] ; //此时a[j].key < temp.key
            i++;
        }

        //确保标准左边的值小于标准
        while(i<j && temp.key > a[i].key) i++;

        if(i<j) //当标准左边的值大于标准时，将大于标准的值移动到标准的右边
        {
            a[j] = a[i];
            j--;
        }

        a[i] = temp; //将标准移动到恰当的位置（此时标准左边的值都小于标准，标准右边的值都大于标准）

        if(low < i)
            quickSort(a,low,i-1); //分别调整左边和右边
        if(i < high)
            quickSort(a,j+1,high);

    }

}


//归并排序
void mergeSort(DataType a[], int left, int right, DataType temp[])
{
    int mid = (left + right)/2 ;
    if(left < right)
    {
        mergeSort(a,left,mid,temp);  //先归并排序左边的
        mergeSort(a,mid+1,right,temp); //右边的
        mergeArr(a,left,mid,right,temp); //合并排序好的分组
    }

}


//合并分组
void mergeArr(DataType a[], int left, int mid, int right, DataType temp[])
{
    int i = left, j= mid+1;
    int k = 0;
    while(i<=mid && j<=right)
    {
        if(a[i].key <= a[j].key)
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while(i <= mid)
    {
        temp[k++] = a[i++];
    }

    while(j <= right)
    {
        temp[k++] = a[j++];
    }


    //将temp中的数组全部拷贝到原数组中
    k = 0;
    while(left <= right)
    {
        a[left++] = temp[k++];
    }
}


//基数排序
//n为元素个数 m为位数（例如124 的 m=3） d为进制数，十进制d=10
void radixSort(DataType a[], int n ,int m, int d)
{
    int i,j,k,p;
    int power = 1;
    SeqCQueue que[d];

    for(i=0;i<d;i++)
        initQueue(&que[i]);

    for(i=0; i<m; i++)
    {
        if(i==0) power = 1;
        else
            power = d*power;

        for(j=0; j<n; j++)  //入队列
        {
            k = ( (a[j].key/power) - d*(a[j].key/(power*d)) ); //m位上数
            appendQueue(&que[k],a[j]);
        }

        p = 0;
        for(j=0;j<d;j++)  //收集
        {
            while(queueNotEmpty(&que[j]))
                deleteQueue(&que[j], &a[p++]);
        }
    }

}


#endif // __SORT_H__

