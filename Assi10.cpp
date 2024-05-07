/* Read the marks obtained by students of second year in an online examination of Particular subject. Find 
out maximum and minimum marks obtained in that subject. Use heap data structure. Analyses the algorithm. */


#include<iostream>
using namespace std;
#define max 20
class heap
{
    public:
    int n;
    int a[max];
    void MAX_HEAPIFY(int a[],int i,int n) /*This function is responsible for maintaining the max-heap property.
                                             It ensures that a node and its children satisfy the max-heap condition.*/
    {
        int l,r,largest,loc;
        l=2*i;
        r=(2*i+l);

        if((l<=n)&&a[l]>a[i])
            largest=l;

        else
            largest=i;

        if((r<=n)&&(a[r]>a[largest]))
            largest=r;

        if(largest!=i)
        {
            loc=a[i]; //delet
            a[i]=a[largest];
            a[largest]=loc;
            MAX_HEAPIFY(a,largest,n);
        }
    }
    /*This function builds a max-heap from an array. It starts from the last non-leaf node and calls MAX_HEAPIFY for
     each node to ensure that the entire array satisfies the max-heap property.*/
    void BUILD_MAX_HEAP(int a[],int n)
    {
        for(int k=n/2;k>=1;k--)
        {
            MAX_HEAPIFY(a, k, n);
        }
    }
   /*This function sorts the array of marks using heap sort.
It first builds a max-heap from the array using BUILD_MAX_HEAP.
Then, it iteratively extracts the maximum element from the heap (which is the root) and places 
it at the end of the array. After each extraction, it maintains the max-heap property using MAX_HEAPIFY.*/
    void HEAPSORT(int a[], int n)
    {
        BUILD_MAX_HEAP(a,n);
        int i, temp;
        for ( i = n ;i >= 2;i--)
        {
            temp = a[i]; //delete maximum element from the root.
            a[i] = a[1];
            a[1] = temp;
            MAX_HEAPIFY(a,1,i - 1);
        }
    }
    void accept()
    {
        cout<<"\nEnter the number of students: "<<endl;
        cin>>n;
        cout<<"\nEnter the marks of the students: "<<endl;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        HEAPSORT(a,n);
    }
    void display()
    {
        cout<<"\n*** SORTED MARKS ***"<<endl;
        for (int i = 1; i <= n ;i++)
        {
            cout<<a[i]<<endl;
        }
    }

    void displayMax()
    {
        cout<<"\nMaximum marks obtained are:"<<a[n];
    }

    void displayMin()
    {
    cout<<"Minimum marks obtained are:"<<a[1];
    }

    void header()
    {
        int ch;
        while(1)
        {
            cout<<endl<<"\n===========Menu==========";
            cout<<endl<<" 1. Read marks of the student ";
            cout<<endl<<" 2.Display Min heap";
            cout<<endl<<" 3.Find Max Marks";
            cout<<endl<<" 4.Find Min Marks";
            cout<<endl<<" 5.Exit";
            cout<<endl<<"\nEnter Choice: "; cin>>ch;
            switch(ch)
            {
            case 1:
                accept();
                break;
            case 2:
                display();
                break;
            case 3:
                displayMax();
                break;
            case 4:
                displayMin();
                break;
            case 5:
                cout<<"\nThanks for using this Program !!\n";
                exit(0);
            }
        }
    }
};
int main()
{
    heap h;
    h.header();
    return 0;
}