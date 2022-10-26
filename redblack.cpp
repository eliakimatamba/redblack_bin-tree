//This is a program for the implementation of the Red Black Tree implementation in C++ (RB-Tree).

#include<iostream>
#include "redblack.h"


int main()
{
    int ch,x=0;
    rbTree Obj;
    do
    {
        cout<<"\n\t ******THIS IS THE RB TREE(RED BLACK TREE.***** " ;
        cout<<"\n 1. Do you want to insert the tree? ";
        cout<<"\n 2. Do you want to remove a NODE from the Tree?";
        cout<<"\n 3. Do you want to search for an Element In the Tree?";
        cout<<"\n 4. You want to output/display a tree? ";
        cout<<"\n 5. Want to exit " ;
        cout<<"\nEnter the number representing your choice.:\n ";
        cin>>ch;
        switch(ch)
        {
            case 1 : Obj.insert();
                cout<<"\nNode Inserted.\n";
                break;
            case 2 : Obj.del();
                break;
            case 3 : Obj.search();
                break;
            case 4 : Obj.disp();
                break;
            case 5 : x=1;
                break;
            default : cout<<"\nEnter a Valid Choice.";
        }
        cout<<endl;

    }while(x!=1);
    return 1;
}