#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void selection_sort(int *a,int n)
{
        int min;
        for(int i = 0; i < n - 1; ++i)
        {
                min = i;
                for(int j = i + 1; j < n; ++j)
                {
                        if(a[j] < a[min])
                        {
                                min = j;
                        }
                }
                swap(&a[i],&a[min]);
        }
}

void swap(int *a,int *b)
{
        int temp = *a;
        *a = *b;
        *b = temp;
}

void bubble_sort(int *a,int n)
{
        for(int i = 0; i < n - 1; ++i)
        {
                for(int j = 0; j < n - 1 - i; ++j)
                {
                        if(a[j + 1] < a[j])
                        {
                                swap(&a[j],&a[j + 1]);
                        }
                }
        }
}

void insertionSort(int *a,int n)
{
        for(int i = 0; i < n; ++i)
        {
                insert(a,i,a[i]);
        }
}

void insert(int *a,int l,int element)
{
        int i = l - 1;
        while(i >= 0 && element < a[i])
        {
                a[i + 1] = a[i];
                i = i - 1;
        }
        a[i + 1] = element;
}

void mergeSort(int *a,int l,int r)
{
        if(l < r)
        {
                int mid = (l + r) / 2;
                mergeSort(a,l,mid);
                mergeSort(a,mid + 1,r);
                merge(a,l,r,mid);
        }
}

void merge(int *a,int l,int h,int mid)
{
        int b[mid * 2];
        int i = l;
        int j = mid + 1;
        int k = l;
        while(i <= mid && j <= h)
        {
                if(a[i] < a[j])
                {
                        b[k] = a[i];
                        ++k;
                        ++i;
                }
                else
                {
                        b[k] = a[j];
                        ++k;
                        ++j;
                }
        }
        while(i <= mid)
        {
                b[k] = a[i];
                ++k;
                ++i;
        }
        while(j <= h)
        {
                b[k] = a[j];
                ++k;
                ++j;
        }

        for(i = l; i < k; ++i)
        {
                a[i] = b[i];
        }
}

void quickSort(int *a,int l,int r)
{
        if(l < r)
        {
                int m = partition(a,l,r);
                quickSort(a,l,m-1);
                quickSort(a,m+1,r);
        }
}

int partition(int *a,int l,int r)
{
        int i;
        int j;
        int pivot = a[l];
        i = l;
        j = r + 1;
        do
        {
                do i = i + 1; while(a[i] < pivot);
                do j = j - 1; while(a[j] > pivot);
                swap(&a[i],&a[j]);
        }
        while(i < j);

        swap(&a[i],&a[j]);
        swap(&a[l],&a[j]);
        return j;
}
