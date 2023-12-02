#include <iostream>
using namespace std;
class BubbleSort
{
    private:
        int* arr;
        int size;
    public:
        BubbleSort(int n)
        {
            this->size=n;
            arr = new int[size];
        }
    void inputArray()
    {
        cout<<"Enter elements for your Array: ";
        for(int i=0;i<size;i++)
        {
            cin>>arr[i];
        }
    }

    int bubbleSort()
    {
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size-i;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    swap(arr[j],arr[j+1]);
                    
                }
                
            }
            
        }
        cout<<"Your Sorted Array is :";
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};
int main()
{
    cout<<"enter size for your array :";
    int n;
    cin>>n;
    BubbleSort bubblesort(n);
    bubblesort.inputArray();
    bubblesort.bubbleSort();
}