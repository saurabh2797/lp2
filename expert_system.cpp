#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int check_res(string a)
{
    if(a=="y")
    {
        return 1;
    }
    return 0;
}

void flu(string name)
{
    string res;

    //Asking questions for the flu
    cout<<"Hi "<<name<<" are you ready to take flu test ? ";
    cin>>res;
    if(res=="y")
    {
        cout<<"Good then you are ready to go... "<<endl;
        cout<<"Loading questions........"<<endl;
    }else{
        return;
    }

    int prob=0;
    cout<<"1] Do you have cold ? (y/n) : ";
    cin>>res;
    prob+=check_res(res);
    cout<<"2] What is your body temperature ? ";
    int temp=0;
    cin>>temp;
    if(temp>100){
        prob++;
    }
    cout<<"3] Do you feel weakness in body ? (y/n) : ";
    cin>>res;
    prob+=check_res(res);

    cout<<"4] Do you feel a headache ? (y/n) : ";
    cin>>res;
    prob+=check_res(res);

    if(prob>2)
    {
        cout<<"Yes, there are high chances that you are suffering from flu.\n Following are the remedies :\n";
        cout<<"1] Contact the doctor and follow proper medication\n";
        cout<<"2] Take rest for few days and don't go outside\n";
        cout<<"3] Eat healthy food..\n";
    }else if(prob<=2 && prob!=0)
    {
        cout<<"Take rest for few days.\n";
    }else{
        cout<<"You need not have to worry, you are healthy."<<endl;
    }
}

int main()
{

    cout<<"Hello , welcome to the medicure..."<<endl;
    string name="";
    int choice;
    cout<<"Enter your good name : ";
    cin>>name;
    cout<<"Hello "<<name<<" do you face any of the following issues ? \n1] Flu ";
    cin>>choice;

    switch(choice)
    {
        case 1:
            flu(name);
            break;

        default:
            exit(0);    
    }

    return 0;
}