#include<iostream>
#include<cmath>
#include<limits.h>
using namespace std;

//global variable to keep track of moves taken
int g=0;

void Print(int puzzle[]){

    for(int i=0;i<9;i++)
    {
        if(i%3==0)
            cout<<"\n";
        if(puzzle[i]==-1)
            cout<<"_";
        else
            cout<<puzzle[i]<<" ";        
    }

    cout<<"\n\n";

}

void MoveLeft(int start[],int position)
{
    swap(start[position],start[position-1]);
}

void MoveRight(int start[],int position)
{
    swap(start[position],start[position+1]);
}

void MoveUp(int start[],int position)
{
    swap(start[position],start[position-3]);
}


void MoveDown(int start[],int position)
{
    swap(start[position],start[position+3]);
}

void Copy(int temp[],int real[])
{
    for(int i=0;i<9;i++)
    {
        temp[i] = real[i];
    }
}


/*
For every number find difference in position in goal state and inital state
Difference in vertical + difference in horizontal i.e Manhattan Distance
*/

int heuristic(int start[],int goal[]){
    int h=0;
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(start[i]==goal[j] && start[i]!=-1)
            {
                h+=abs((j-i)/3)+abs((j-i)%3);
            }
        }
    }

    return h+g;
}


void MoveTile(int start[],int goal[])
{
    int emptyAt=0;
    for(int i=0;i<9;i++)
    {
        if(start[i]==-1)
        {
            emptyAt = i;
            break;
        }
    }

    int t1[9],t2[9],t3[9],t4[9],f1=INT_MAX,f2=INT_MAX,f3=INT_MAX,f4=INT_MAX;
    Copy(t1,start);
    Copy(t2,start);
    Copy(t3,start);
    Copy(t4,start);

    int row = emptyAt/3;
    int col = emptyAt%3;

    if(col-1>=0)
    {
        MoveLeft(t1,emptyAt);
        f1=heuristic(t1,goal);
    }

    if(col+1<3)
    {
        MoveRight(t2,emptyAt);
        f2 = heuristic(t2,goal);
    }

    if(row+1<3)
    {
        MoveDown(t3,emptyAt);
        f3 = heuristic(t3,goal);
    }

    if(row-1>=0)
    {
        MoveUp(t4,emptyAt);
        f4  = heuristic(t4,goal);
    }

    //find least heuristic value
    if(f1<=f2 && f1<=f3 && f1<=f4)
    {
        MoveLeft(start,emptyAt);
    }
    else if(f2<=f1 && f2<=f3 && f2<=f4)
    {
        MoveRight(start,emptyAt);
    }
    else if(f3<=f1&& f3<=f2 && f3<=f4)
    {
        MoveDown(start,emptyAt);
    }
    else
    {
        MoveUp(start,emptyAt);
    }


}


void SolveEight(int start[],int goal[])
{
    g++;
    //MoveTile
    MoveTile(start,goal);
    Print(start);

    //Get heuristic value
    int f = heuristic(start,goal);
    if(f==g)
    {
        cout<<"Solved in "<<f<<" moves\n";
        return;
    }
    SolveEight(start,goal);
}

//cnt no.of inversion, if odd then unsolvable else solvable

bool solvable(int start[])
{
    int invrs=0;
    for(int i=0;i<9;i++)
    {
        if(start[i]<=1) continue;
        for(int j=i+1;j<9;j++){
        if(start[j]==-1) continue;
        if(start[i]>start[j]) invrs++;
    }
    }
    return invrs&1?false:true;
}

int main()
{
    int start[9];
    int goal[9];

    cout<<"Enter the start state(Enter -1 for empty) : ";
    for(int i=0;i<9;i++)
    {
        cin>>start[i];
    }

    cout<<"Enter the goal state(Enter -1 for empty) : ";
    for(int i=0;i<9;i++)
    {
        cin>>goal[i];
    }

    Print(start);
    if(solvable(start))
        SolveEight(start,goal);
    else    
        cout<<"Impossible to solve\n";


    return 0;
}