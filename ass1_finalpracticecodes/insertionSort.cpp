#include <iostream>
using namespace std;

class InsertionSort
{
private:
    int *arr;
    int size;

public:
    InsertionSort(int n)
    {
        this->size = n;
        arr = new int[size];
    }

    void inputArray()
    {
        cout << "Enter elements of array :";
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }
    int insertionSort()
    {
        for (int i = 1; i < size; i++)
        {
            int temp = arr[i];
            int j = i-1;
            for (; j >= 0; j--)
            {
                if (arr[j] > temp)
                {
                    arr[j + 1] = arr[j];
                }
                else
                {
                    break;
                }
            }
            arr[j+1] =  temp;
        }
        cout<<"Sorted array is :";
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};
int main()
{
    int n;
    cout<<"ENTER SIZE OF ARRAY: ";
    cin>>n;
    InsertionSort insertionsort(n);
    insertionsort.inputArray();
    insertionsort.insertionSort();

    return 0;
}