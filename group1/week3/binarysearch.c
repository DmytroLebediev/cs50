#include <stdio.h>
#include <cs50.h>
#include <ctype.h>

void sort(int count, int numbers[]);
void mergesort(int left, int right, int numbers[],int buffer[]);
void print(int size, int array[]);
bool find (int findcount, int findarray[], int findnumber);
bool binarysearch(int bleft, int bright, int bcount, int barray[], int bnumber);

int main(int count, string argument[])
{
   if(count <= 1)
   {
      return 1;
   }
   int n[count-1];
   
   for(int i = 1; i < count; i++)
   {
       n[i - 1] = atoi(argument[i]);
   }
   sort(count-1, n);
   print(count-1, n);
   
   printf("Please enter integer number: ");
   int find_number = GetInt();
   if (find(count-1, n, find_number))
   {
       printf("Found!\n");
   }
   else
   {
       printf("Sorry, not found! :(\n");
   }
}

void sort(int count, int numbers[])
{
    int k[count];
    mergesort(0, count, numbers, k);
}

void mergesort(int left, int right, int numbers[], int buffer[])
{
    // if array to sort is one item long
    // then we have sorted list
    if(right - left == 1)
    {
        return;
    }
    int mid = (right + left) / 2;           // find where to divide the array
    mergesort(left, mid , numbers, buffer); // sort left part of the array
    mergesort(mid, right, numbers, buffer); // sort right part of the array
    
    int indexleft = left;
    int indexright = mid;
    // merge two sorted parts of the array into buffer
    for (int b = left; b < right; b++)
    {
        if(indexleft == mid                                                         // if there's nothing left in the left part
            || (indexright < right && numbers[indexright] < numbers[indexleft]))    // or there are still some items in the rigth part and there're less then the left ones 
        {
            buffer[b] = numbers[indexright];
            indexright++;
        }
        else
        {
            buffer[b] = numbers[indexleft];
            indexleft++;
        }
    }
    // copy sorted portion of the buffer back
    // to the original array
    for(int k = left; k < right; k++)
    {
        numbers[k] = buffer[k];
    }
}

void print(int size, int array[])
{   
    for(int i = 0; i < size; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");
}

bool find(int findcount, int findarray[], int findnumber)
{
    return binarysearch(0, findcount, findcount, findarray, findnumber);
}

bool binarysearch(int bleft, int bright, int bcount, int barray[], int bnumber)
{
    if ((bright - bleft) == 1)
    {
        return (barray[bleft] == bnumber);
    }
    int mid = (bright + bleft) / 2;
    // if middle number in the array of numbers is right what we are looking for
    if(barray[mid] == bnumber)
    {
        return true;
    }
    else
    {
        if (bnumber < barray[mid])
        {
            // if number we are looking for is less than the middle number
            // we are searching in the left part within numbers all less
            // than the middle one
            return binarysearch(bleft, mid, bcount, barray, bnumber);
        }
        else
        {
            // if number we are looking for is less than the middle number
            // othewise we are searching in the right part within numbers all
            // greater than the middle one
            return binarysearch(mid, bright, bcount, barray, bnumber);
        }
    }
}
