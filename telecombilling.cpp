#include <iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>

using namespace std;
class customercare
{
  string phonenumber;
    string name;
    string adress;
    public:
   void newrecord();
   void display();
   void list();
};


void customercare::newrecord(void)
{
    ofstream fin;
    fin.open("Billing.txt",ios::app);
    cout<<"Enter your phonenumber : ";
    fin<<":";
    cin>>phonenumber;
    fin<<phonenumber;
     fin<<":";
    cout<<"Enter  Name : ";
    cin>>name;
    fin<<name<<" ";
    cout<<"Enter Adress : ";
    cin>>adress;
    fin<<adress<<endl;
    fin.close();
}

void customercare::display()
{  
    string x;
   string y;
   int f;
   int data;
   float bill,tax;

cout<<"Enter phone number : ";
cin>>x;
ifstream obj("Billing.txt",ios::in);
while(getline(obj,y,':') && !obj.eof())
    {
     if(x==y)
    {
        obj>>y;
        cout<<"Name :"<<y<<endl;
        obj>>y;
        cout<<"Adress :"<<y<<endl;
        cout<<"\nNumber of Calls made : ";
        cin>>f;
        cout<<"Total data used : ";
        cin>>data;
        bill=2*f+0.20*data;
        cout<<"Each call cost  2 Rupee \n Data 0.20paisa per Mb \n Rental charges 100"<<endl;
        cout<<"                bill="<<bill<<endl;
        tax=.23*f;
        cout<<"                Tax : "<<tax<<endl;
        cout<<"  Totalbill =  bill  +  tax  +   rentalcharges  = "<<bill+tax+100<<endl;
         break;
    }
    }
    if(obj.eof())
    {
    	cout<<"\n\n                                    No record found "<<endl;
	}
   obj.close();
}


void customercare::list()
{ char ch;
    fstream fin;
    fin.open("Billing.txt");
    if(fin.eof())
    {
    	cout<<"No Customer Records"<<endl;
	}
	else
	{
    while(!fin.eof())
{
       fin.get(ch);
    cout<<ch;
}
fin.close();
}
}




int main()
{ 
    int n;
    int k;
    customercare customer1;
    do{  
    	 system("cls");
    	     cout<<"***********************************************************************************************************************\n**********************************************TELEPHONE BILLING SYSTEM*************************************************\n***********************************************************************************************************************"<<endl;

         cout<<"                                              1-> NewRecord  \n\n\n                                              2-> Display Record \n\n\n                                              3-> RecordList\n\n\n                                              4-> Quit \n\nEnter Your Choice "<<endl;
        cin>>k;
     switch(k)
    {
        case 1:
         system("cls");
         cout<<"                                     Create Record"<<endl;
        customer1.newrecord();
        break;
     case 2:
         system("cls");
        cout<<"                                       Display Record"<<endl;
        customer1.display();
        break;
    case 3:
    	 system("cls");
    	 cout<<"                                      Customer List"<<endl;
        customer1.list();
        break;
    case 4:
    	break;
    	default :
    		cout<<"Incorrect Input \n\n";
    		break;
    }
    cout<<"   Enter 1 to continue to main menu";
     cin>>n;
    }
    while(n==1);
    return 0;
}

