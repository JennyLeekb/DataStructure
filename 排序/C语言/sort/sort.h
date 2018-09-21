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


//ֱ������
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

//ϣ������
void shellSort(DataType a[], int n, int d[], int numOfD)
{
    int i,j,k,m;
    int decade;
    DataType temp;

    for(i=0; i<numOfD;i++)
    {
        decade = d[i]; //������
        for(j=0;j<decade;j++)  //��decade��С��
        {
            //������ֱ������
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


//ֱ��ѡ������
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

        if(index != i)  //��ǰԪ�ؾ�����СԪ�ص�ʱ����Ҫ����
        {
            temp = a[i];
            a[i] = minData;
            a[index] = temp;
        }
    }

}


//������Ҷ�ӽڵ�hʹ��a[]�������ѣ�nΪ����a�е�Ԫ�ظ���
void createHeap(DataType a[], int n, int h)
{
   int i,j,flag;
   DataType temp;

   i = h;  //iΪҪ���ѵĶ������ĸ����
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

//������Ԫ��a[0]~a[n-1]��ʼ������Ϊ����
void initCreateHeap(DataType a[], int n)
{
    int i;

    for(i=(n-2)/2 ; i>=0; i--)
        createHeap(a,n,i);
}

//������
void heapSort(DataType a[], int n)
{
    int i;
    DataType temp;

    initCreateHeap(a,n);

    for(i=n-1;i>0;i--)  //��ǰ�ѵĸ���ÿ�εݼ�1
    {
        temp = a[0];    //������ǰ���������һ�����
        a[0] = a[i];
        a[i] = temp;

        createHeap(a,i,0); //���µ�������㣬ʹ֮��������
    }
}


//ð������
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

//��������
void quickSort(DataType a[], int low, int high)
{
    int i = low, j = high;
    DataType temp = a[low];

    while(i<j)
    {
        //ȷ����׼�ұߵ�ֵ���ڱ�׼
        while(i<j && temp.key <= a[j].key) j--;

        if(i<j)  //����׼�ұߵ�ֵС�ڱ�׼ʱ���������ڱ�׼��ֵ�ƶ�����׼���
        {
            a[i] = a[j] ; //��ʱa[j].key < temp.key
            i++;
        }

        //ȷ����׼��ߵ�ֵС�ڱ�׼
        while(i<j && temp.key > a[i].key) i++;

        if(i<j) //����׼��ߵ�ֵ���ڱ�׼ʱ�������ڱ�׼��ֵ�ƶ�����׼���ұ�
        {
            a[j] = a[i];
            j--;
        }

        a[i] = temp; //����׼�ƶ���ǡ����λ�ã���ʱ��׼��ߵ�ֵ��С�ڱ�׼����׼�ұߵ�ֵ�����ڱ�׼��

        if(low < i)
            quickSort(a,low,i-1); //�ֱ������ߺ��ұ�
        if(i < high)
            quickSort(a,j+1,high);

    }

}


//�鲢����
void mergeSort(DataType a[], int left, int right, DataType temp[])
{
    int mid = (left + right)/2 ;
    if(left < right)
    {
        mergeSort(a,left,mid,temp);  //�ȹ鲢������ߵ�
        mergeSort(a,mid+1,right,temp); //�ұߵ�
        mergeArr(a,left,mid,right,temp); //�ϲ�����õķ���
    }

}


//�ϲ�����
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


    //��temp�е�����ȫ��������ԭ������
    k = 0;
    while(left <= right)
    {
        a[left++] = temp[k++];
    }
}


//��������
//nΪԪ�ظ��� mΪλ��������124 �� m=3�� dΪ��������ʮ����d=10
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

        for(j=0; j<n; j++)  //�����
        {
            k = ( (a[j].key/power) - d*(a[j].key/(power*d)) ); //mλ����
            appendQueue(&que[k],a[j]);
        }

        p = 0;
        for(j=0;j<d;j++)  //�ռ�
        {
            while(queueNotEmpty(&que[j]))
                deleteQueue(&que[j], &a[p++]);
        }
    }

}


#endif // __SORT_H__

