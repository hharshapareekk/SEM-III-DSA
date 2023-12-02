#include <iostream>
using namespace std;

class BinarySearch
{
private:
    int *arr;
    int size;

public:
    BinarySearch(int n)
    {
        this->size = n;
        arr = new int[size];
    }
    void inputArray()
    {
        cout << "enter elements for your array:";
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }
    int binarySearch(int key)
    {
        int low = 0;
        int high = size - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] == key)
            {
                return mid + 1;
            }
            else if (arr[mid] < key)
            {
                low = mid + 1;
            }
            else if (arr[mid] > key)
            {
                high = mid - 1;
            }
        
        }
        return -1;

    }
};

int main()
{
    int n,key;
    cout<<"enter size and key :";
    cin>>n>>key;
    BinarySearch binarysearch(n);
    binarysearch.inputArray();
    int result = binarysearch.binarySearch(key);

    if (result != -1)
        cout << "Key found at postion " << result << ".\n";
    else
        cout << "Key not found.\n";
    return 0;
}