#include <iostream> 

#include </home/administrator/23329/sorting.cpp>>

int main() 

{ 

    SE SE11; 

    SE11.Accept(); 

    cout<<"SE11"<<endl; 

    SE11.Display(); 

    int choice; 

    cout<<"\n"; 

    

    int yes = 1; 

    while(yes == 1) 

    { 

    cout<<"\nOperation\n1.  Sort by Roll numbers (Bubble sort)\n2.  Sort by name (Insertion sort)\n3.  Search student by sgpa (Linear search)\n4.  Sort by student sgpa (Quicksort)\n5.  Search by name (Binary search)\n6. Exit\n"; 

        cout<<"Enter your choice : "; 

        cin>>choice; 

        switch(choice) 

        { 

            case 1: SE11.Bubble(); 

                cout<<"\nSorted database : "<<endl; 

                SE11.Display(); 

                break; 

            case 2:SE11.insertion(); 

                cout<<"Sorted database : "<<endl; 

                SE11.Display(); 

                break; 

            case 3: SE11.Linear(); 

                break; 

            case 4:SE11.callQS(); 

                cout<<"Sorted database : "<<endl; 

                SE11.Display(); 

                break; 

            case 5:SE11.insertion(); 

                SE11.binary();     

                break;         

            default : cout<<"Inalid input !";   

            case 6: 

            exit(0); 

            cout<<endl; 

        } 

          

    }   

    return 0; 

}
