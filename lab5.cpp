#include <iostream>
#include <math.h>
#define SIZE 5
using namespace std;

class Row
{
    public:
    void InputRow();
    void OutputRow();
    friend void SortInRowsDescending(Row vector[]);
    friend void ArithmeticMeansInColumns(Row vector[]);
    
    private:
    int elementsOfRow[SIZE];
};

void merge (int leftArray[], int leftLenght, int rightArray[], int rightLenght, int sourceArray[]);
void mergeSort(int array[], int arrayLenght);

int main()
{
    Row array[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        array[i].InputRow();
    }
    cout<<"\nSource matrix"<<endl;
    for(int i = 0; i < SIZE; i++)
    {
        array[i].OutputRow();
        cout << endl;
    }
    SortInRowsDescending(array);
    cout<<"\nSorted matrix"<<endl;
    for(int i = 0; i < SIZE; i++)
    {
        array[i].OutputRow();
        cout << endl;
    }
    ArithmeticMeansInColumns(array);
}

void merge (int leftArray[], int leftLenght, int rightArray[], int rightLenght, int sourceArray[])
{
    int i = 0, j = 0, k = 0;

    while(i < leftLenght || j < rightLenght)
    {
        if (i < leftLenght && j < rightLenght)
        {
            if (leftArray[i] > rightArray[j])
            {
                sourceArray[k] = leftArray[i];
                i++;
                k++;
            }
            else
            {
                sourceArray[k] = rightArray[j];
                j++;
                k++;
            }
        }
        else if (i >= leftLenght)
        {
            sourceArray[k] = rightArray[j];
            j++;
            k++;
        }
        else if (j >= rightLenght)
        {
            sourceArray[k] = leftArray[i];
            i++;
            k++;
        }
    }
}

void mergeSort(int array[], int arrayLenght)
{
    int leftLenght, rightLenght;
    if (arrayLenght%2 == 0)
    {
        leftLenght = arrayLenght/2;
        rightLenght = arrayLenght/2;
    }
    else
    {
        leftLenght = arrayLenght/2;
        rightLenght = arrayLenght/2 + 1;
    }

    int leftArray[leftLenght];
    int rightArray[rightLenght];
    for (int i = 0; i < leftLenght; i++)
    {
        leftArray[i] = array[i];
    }
    for (int j = 0; j < rightLenght; j ++)
    {
        rightArray[j] = array[leftLenght + j];
    }

    if (arrayLenght == 2)
    {
        merge (leftArray, leftLenght, rightArray, rightLenght, array);
    }
    else if (arrayLenght == 3)
    {
        mergeSort(rightArray, rightLenght);
        merge (leftArray, leftLenght, rightArray, rightLenght, array);
    }
    else
    {
        mergeSort(leftArray, leftLenght);
        mergeSort(rightArray, rightLenght);
        merge (leftArray, leftLenght, rightArray, rightLenght, array);
    }
}

void Row::InputRow()
{
    for(int i = 0; i < SIZE; i++)
    {
        cin >> this->elementsOfRow[i];
    }
}

void Row::OutputRow()
{
    for(int i = 0; i < SIZE; i++)
    {
        cout << this->elementsOfRow[i]<<"\t";
    }
    cout << endl;
}

void SortInRowsDescending(Row vector[])
{
    for (int i = 0; i < SIZE; i++)
    {
        mergeSort(vector[i].elementsOfRow, SIZE);    
    }
}

void ArithmeticMeansInColumns(Row vector[])
{
    double arithmeticMean = 0;
    int sumOfElementsInColumn = 0;
    double productOfArithmeticMeans = 1;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            sumOfElementsInColumn += vector[j].elementsOfRow[i];
        }
        arithmeticMean = sumOfElementsInColumn / SIZE;
        cout << "Arimethic mean in column" << i + 1 << " = " << arithmeticMean << endl;
        productOfArithmeticMeans *= arithmeticMean;
    }
    double geometricMean = pow(productOfArithmeticMeans, 1.0/SIZE);
    cout << "Geomtric mean = " << geometricMean << endl;
}