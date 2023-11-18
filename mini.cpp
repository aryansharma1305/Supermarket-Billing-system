#include <iostream>
#include <fstream>
using namespace std;
class shopping
{
    private:
        int pcode;
        float price;
        float dis;
        string pname;
    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();

};
void shopping::menu()
{
    m:
    int choice;
    string email;
    string password;
    cout<<"\t\t\t\t__________________________________________________\n";
    cout<<"\t\t\t\t__________________________________________________\n";
    cout<<"\t\t\t\t                 Supermarket main menu            \n";
    cout<<"\t\t\t\t__________________________________________________\n";
    cout<<"\t\t\t\t__________________________________________________\n";
    cout<<"\t\t\t\t|  1) Administrator     |\n";
    cout<<"\t\t\t\t|                       |\n";
    cout<<"\t\t\t\t|  2) Buyer             |\n";
    cout<<"\t\t\t\t|                       |\n";
    cout<<"\t\t\t\t|  2) Exit              |\n";
    cout<<"\n\t\t\t     Please Select!";
    cin>>choice;
    
    switch (choice)
    {
        case 1:
        cout<<"\t\t\t Please login \n";
        cout<<"\t\t\t Enter email   \n";
        cin>>email;
        cout<<"\t\t\t Password      \n";
        cin>>password;

        if(email=="robby@email.com" && password=="robby@123")
        {
            administrator();
        }
        else{
            cout<<"Invalid email/password";

        }
        break;
    
    case 2:
    {
        buyer();
    }
    case 3:
    {
        exit(0);
    }
    default:{
        cout<<"Please select from the given options";
    }
    goto m;}
}


void shopping:: administrator()
{
    m:
    int choice;

    cout<<"\n\n\n\\t\t\t Administrator menu";
    cout<<"\n\t\t\t_______________1)Add the product______";
    cout<<"\n\t\t\t                                     ";
    cout<<"\n\t\t\t_______________2)Modify the product______";
    cout<<"\n\t\t\t                                      ";
    cout<<"\n\t\t\t_______________3)Delete the product______";
    cout<<"\n\t\t\t                                      ";
    cout<<"\n\t\t\t_______________4) Back to main menu______";

    cout<<"\n\t\t\t Please enter your choice";
    cin>>choice;
    
    switch(choice)
    {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;
        default:
        cout<<"Invalid choice!";
    }
    goto m;

}
void shopping:: buyer()
{
    m:
    int choice;
    cout<<"\t\t\t  Buyer \n";
    cout<<"\t\t\t                \n";
    cout<<"\t\t\t1) Buy product\n";
    cout<<"\t\t\t                \n";
    cout<<"\t\t\t2) Go back      \n";
    cout<<"\t\t\t Enter your choice: ";
    cin>>choice;

    switch(choice)
    {
        case 1:
            receipt();
            break;
        case 2:
            menu();
        default:
            cout<<"Invalid choice";
    }
    goto m;
    
}

void shopping::add()
{
    m:
    fstream data;

    int c;
    int token=0;
    float p;
    float d;
    string n;
    cout<<"\n\n\t\t\t Add new product";
    cout<<"\n\n\t\t\t Product code of the product";
    cin>>pcode;
    cout<<"\n\n\t\t\t Name of the product";
    cin>>pname;
    cout<<"\n\n\t\t\t Price of the product";
    cin>>price;
    cout<<"\n\n\t\t\t Discount on product";
    cin>>dis;

    data.open("database.txt",ios::in);

    if(!data)
    {
        data.open("database.txt",ios::app|ios::out);
        data<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;

        while(!data.eof())
        {
            if(c==pcode)
            {
                token++;

            }
            data>>c>>n>>p>>d;
        }
        data.close();
    }
    if(token==1)
        goto m;
    else{
        data.open("database.txt",ios::app|ios::out);
        data<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
        data.close();

    }
    cout<<"\n\n\t\t\t Record Inserted";

}
void shopping::edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\n\n\t\t Modify the record";
    cout<<"\n\n\n\t\t Product code:";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\nFIle doesnt exist";
    }
    else{
        data1.open("database1.txt", ios::app|ios::out);

        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\n\t\t Product new code:";
                cin>>c;
                cout<<"\n\n\t\t Name of the product";
                cin>>n;
                cout<<"\n\n\t\t price : ";
                cin>>p;
                cout<<"\n\n\t\t Discount: ";
                cin>>d;
                data1<<"  "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\n\t\t\t Record edited ";
                token++;

            }
            else {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n\t\t Record not found sorry!";
        }
    }
}
void shopping::rem()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\n\t Delete Product";
    cout<<"\n\n\n\t Product code";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"File doesnt exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\n\t Product deleted succesfully";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");

        if(token==0)
        {
            cout<<"\n\n\n Record not found";
        }
    }
}

void shopping::list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n___________________\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n___________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}
void shopping::receipt()
{
    m:
    fstream data;
    int arrc[100];
    int arrq[100];
    string choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t RECEIPT";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"n\n\n Empty database";
    }
    else{
        data.close();

        list();
        cout<<"\n_______________________________________\n";
        cout<<"\n_______________________________________\n";
        cout<<"\n            Place the order            \n";
        cout<<"\n_______________________________________\n";
        cout<<"\n_______________________________________\n";
        do
        {
            cout<<"\n\n Enter product code:";
            cin>>arrc[c];
            cout<<"\n\nEnter the product quantity:";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i])
                {
                    cout<<"Duplicate product code. Please try again!";
                    goto m;
                    }
                }
                c++;
                cout<<"\n\n Do you want to buy another product? If yes then press y else no";
                cin>>choice;
            }
            while(choice =="y");
            cout<<"\n\n\n\t\t_______________________RECEIPT________________\n";
            cout<<"\nProduct no\t Product name \t product quantity\t price\t Amount\t Amount with discount\n";

            for(int i=0;i<c;i++)
            {
                data.open("database.txt",ios::in);
                data>>pcode>>pname>>price>>dis;
                while(!data.eof())
                {
                    if(pcode==arrc[i])
                    {
                        amount=price*arrq[i];
                        dis=amount-(amount*dis/100);
                        total=total+dis;
                        cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t\t"<<dis;
                    }
                    data>>pcode>>pname>>price>>dis;
                }
            }
            data.close();
        }
        cout<<"\n\n___________________________________";
     cout<<"n\n Total amount : "<<total;
 }


int main()
{
    shopping s;
    s.menu();
}
