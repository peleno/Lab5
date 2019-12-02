#include <iostream>
#include <math.h>
using namespace std;
#define n 5
class row
{
    public:
    void InputRow();
    void OutputRow();
    friend void SortInRowsDescending(row vector[]);
    friend void fAndF(row vector[]);
    
    private:
    int elementsOfRow[n];
};

void merge (int array1[], int len1, int array2[], int len2, int array[]);
void mergeSort(int array[], int len);

int main()
{
    row array[n];
    array[0].InputRow();
    cout<<"Source matrix"<<endl;
    array[0].OutputRow();
    cout << endl;
    SortInRowsDescending(array);
    cout<<"Sorted matrix"<<endl;
    array[0].OutputRow();
    cout << endl;
    fAndF(array);
}

void merge (int array1[], int len1, int array2[], int len2, int array[])
{
    int i = 0, j = 0, k = 0;

    while(i < len1 || j < len2)
    {
        if (i < len1 && j < len2)
        {
            if (array1[i] > array2[j])
            {
                array[k] = array1[i];
                i++;
                k++;
            }
            else
            {
                array[k] = array2[j];
                j++;
                k++;
            }
        }
        else if (i >= len1)
        {
            array[k] = array2[j];
            j++;
            k++;
        }
        else if (j >= len2)
        {
            array[k] = array1[i];
            i++;
            k++;
        }
    }
}

void mergeSort(int array[], int len)
{
    int len1, len2;
    if (len%2 == 0)
    {
        len1 = len/2;
        len2 = len/2;
    }
    else
    {
        len1 = len/2;
        len2 = len/2 + 1;
    }

    int array1[len1];
    int array2[len2];
    for (int i = 0; i < len1; i++)
    {
        array1[i] = array[i];
    }
    for (int j = 0; j < len2; j ++)
    {
        array2[j] = array[len1 + j];
    }

    if (len == 2)
    {
        merge (array1, len1, array2, len2, array);
    }
    else if (len == 3)
    {
        mergeSort(array2, len2);
        merge (array1, len1, array2, len2, array);
    }
    else
    {
        mergeSort(array1, len1);
        mergeSort(array2, len2);
        merge (array1, len1, array2, len2, array);
    }
}

void row::InputRow()
{
    for(int i = 0; i < n; i++)
    {
        cin>>this->elementsOfRow[i];
    }
}

void row::OutputRow()
{
    for(int i = 0; i < n; i++)
    {
        cout << this->elementsOfRow[i]<<"\t";
    }
    cout << endl;
}

void SortInRowsDescending(row vector[])
{
    for (int i = 0; i < n; i++)
    {
        mergeSort(vector[i].elementsOfRow, n);    
    }
}

void fAndF(row vector[])
{
    double arithmeticMean = 0;
    int sum = 0;
    double product = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += vector[j].elementsOfRow[i];
        }
        arithmeticMean = sum / n;
        cout << "in column" << i + 1 << ":" << arithmeticMean << endl;
        product *= arithmeticMean;
    }
    double geom = pow(product, 0.2);
    cout << "geom = " << geom << endl;
}