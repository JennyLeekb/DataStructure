#ifndef __SORT_H__

typedef int KeyType;

typedef struct
{
    KeyType key;
}DataType;

void insertSort(DataType a[], int n);


//≤Â»Î≈≈–Ú
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

#endif // __SORT_H__

