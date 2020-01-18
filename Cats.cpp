//Make a class of objects called “Cat”, and instantiate several objects of type cat (probably in an array).  Cats only need to have an integer ID and a string Name.  Implement a parallel merge sort algorithm in MPI that will sort your array of cats ascending or descending by ID or Name (these can be user selected).  The number of objects can’t be guaranteed to be any particular number, but for our purposes assume it’s not insanely large so it won’t have out of memory problems etc.  Show testing with full output for 11 elements.  Test on a larger number (maybe a few 10’s of thousands) to see the performance speedup.  

#include <string>
#include <iostream>
#include <stdlib.h>
#include <mpi.h>

using namespace std;

/*---------------------------class-----------------------------*/

class CATS {
public:
    string CatName,Catid;
public:
    CATS()
    {
        Catid = "";
        CatName = "";
    }

    void virtual input() = 0;

    void virtual output() = 0;
};


class Popular : public CATS{
public:
    Popular(const string& name, const string& id)
    {
        CatName = name;
        Catid = id;
    }
    virtual void input()
    {
        return;
    }
    virtual void output()
    {
        return;
    }
};

/*--------------------merge for name --------------------------*/

void mergeName(CATS *a[], int low, int mid, int high) {

    int p1 = low;
    int p2 = mid + 1;
    CATS ** merged = (CATS**)malloc(sizeof(CATS*) * (high - low + 1)); 
    int p = 0;
    while(p1 < mid + 1 && p2 < high + 1)
    {
        if(a[p1]->CatName > a[p2]->CatName)
        {
            merged[p] = a[p2];
            p2++;
        }
        else
        {
            merged[p] = a[p1];
            p1++;
        }
        p++;
    }

    while(p1 < mid + 1)
    {
        merged[p++] = a[p1++];
    }

    while(p2 < high + 1)
        merged[p++] = a[p2++];

    for(int i = 0;i < (high - low + 1); i++)
    {
        a[low + i] = merged[i];
    }

    free(merged);
}

/*-------------------------merge for id------------------------*/

void mergeid(CATS *a[], int low, int mid, int high) {

    int p1 = low;
    int p2 = mid + 1;
    CATS ** merged = (CATS**)malloc(sizeof(CATS*) * (high - low + 1));
    int p = 0;
    while(p1 < mid + 1 && p2 < high + 1)
    {
        if(a[p1]->Catid > a[p2]->Catid)
        {
            merged[p] = a[p2];
            p2++;
        }
        else
        {
            merged[p] = a[p1];
            p1++;
        }
        p++;
    }

    while(p1 < mid + 1)
    {
        merged[p++] = a[p1++];
    }

    while(p2 < high + 1)
        merged[p++] = a[p2++];

    for(int i = 0;i < (high - low + 1); i++)
    {
        a[low + i] = merged[i];
    }

    free(merged);
}

/*----------------------merge sort for name--------------------*/
void merge_sort_name(CATS *a[], int low, int high) {
    int mid;
    if (low < high) {
        mid = low + (high - low) / 2;
        merge_sort_name(a, low, mid);
        merge_sort_name(a, mid + 1, high);
        mergeName(a, low, mid, high);
    }
}

/*---------------------merge sort for id-----------------------*/
void merge_sort_id(CATS *a[], int low, int high) {
    int mid;
    if (low < high) {
        mid = low + (high - low) / 2; //avoid overflow
        merge_sort_id(a, low, mid);
        merge_sort_id(a, mid + 1, high);
        mergeid(a, low, mid, high);
    }
}

/*------------------------MAIN FUNCTION-------------------------*/

int main(int argc,char *argv[]) {
    CATS *CATS_Obj[100];
    int n = 0, choose,size=0,rank=0;
    // just to test the mergesort
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    CATS* c1 = new Popular("Tom","1256");
    CATS* c2 = new Popular("Romeo","4589");
    CATS* c3 = new Popular("Luna","9654");
    CATS* c4 = new Popular("Max","7894");
    CATS* c5 = new Popular("Leo","2548");
    CATS* c6 = new Popular("Kitty","7485");
    CATS* c7 = new Popular("pink","9685");
    CATS* c8 = new Popular("Tiger","9173");
    CATS* c9 = new Popular("Simba","8472");
    CATS* c10 = new Popular("Maggie","0120");
    CATS* c11 = new Popular("Koko","7893");

    CATS_Obj[n++] = c1;
    CATS_Obj[n++] = c2;
    CATS_Obj[n++] = c3;
    CATS_Obj[n++] = c4;
    CATS_Obj[n++] = c5;
    CATS_Obj[n++] = c6;
    CATS_Obj[n++] = c7;
    CATS_Obj[n++] = c8;
    CATS_Obj[n++] = c9;
    CATS_Obj[n++] = c10;
    CATS_Obj[n++] = c11;

    if(rank == 0)
    {
      cout << "\n1.Sort by name";
      cout << "\n2.Sort by id";
      cout << endl << endl;
      cout << "\nChoose category: ";
      cin >> choose;
    }
    MPI_Bcast(&choose,1, MPI_INT, 0, MPI_COMM_WORLD);
        switch (choose)
        {
            //skip the case 1, 2
            case 1:
                merge_sort_name(CATS_Obj, 0, n - 1);
                break;
            case 2:
                merge_sort_id(CATS_Obj, 0, n - 1);
                break;
            default:
                cout << "\nNot recognized value!" << endl;
        }
        if(rank == 0)
        {
          for(int i = 0; i < n; ++i)
              cout<<CATS_Obj[i]->CatName<< "\t" << CATS_Obj[i]->Catid <<endl;
        }


        delete c1;
        delete c2;
        delete c3;
        delete c4;
        delete c5;
        delete c6;
        delete c7;
        delete c8;
        delete c9;
        delete c10;
        delete c11;
      MPI_Finalize();
    return 0;
}
