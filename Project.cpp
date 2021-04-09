#include<iostream>
#include<string.h>
#include<stdlib.h>>
#include<stdio.h>
using namespace std;
struct node{
    int id;
    char name[50];
    char qua[30];
    char addrs[50];
    char city[30];
    char jobtitle[30];
    int salary;
    char date[30];
    node *prev,*next;
};

class employee{
private:
    node *head;
    char ch;

public:
    employee(){
        head = NULL;
    }
    void add_first(){
        node *temp = new node;
        cout<<"\n\t\t Enter Employee ID:";
        cin>>temp->id;
        fflush(stdin);
        cout<<"\n\t\t Enter the name of the employee:";
        cin.getline(temp->name,50);
        fflush(stdin);

        cout<<"\n\t\t Enter the qualification of the employee:";
        cin.getline(temp->qua,30);
        fflush(stdin);

        cout<<"\n\t\t Enter the address of the employee:";
        cin.getline(temp->addrs,50);
        fflush(stdin);

        cout<<"\n\t\t Enter the city of the employee:";
        cin.getline(temp->city,30);
        fflush(stdin);

        cout<<"\n\t\t Enter the job title of the employee:";
        cin.getline(temp->jobtitle,30);
        fflush(stdin);

        cout<<"\n\t\t Enter the salary of the person:";
        cin>>temp->salary;
        fflush(stdin);

        cout<<"\n\t\t Enter the joining date of the employee:";
        cin.getline(temp->date,30);
        fflush(stdin);


        temp->next = head;
        temp->prev = NULL;
        if(head!=NULL){
            head->prev = NULL;

        }
        head=temp;
        cout<<"\n\t\tRecord Added successfully"<<endl;
    }
    void add_last(){
        if(head == NULL){
            cout<<"\n\t\tList is empty"<<endl;
            cout<<"\n\t\tDo you want to add a new record\n\tPress Y or N:"<<endl;
            cin>>ch;
            if(ch=='Y'|| ch == 'y'){
                add_first();
                return;
            }

        }
        else{
            node *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            node *newer = new node;
            cout<<"Enter employee id:"<<endl;
            cin>>newer->id;
            fflush(stdin);

            cout<<"Enter name of employee"<<endl;
            cin.getline(newer->name,50);
            fflush(stdin);

            cout<<"Enter qualification of the employee"<<endl;
            cin.getline(newer->qua,30);
            fflush(stdin);

            cout<<"Enter the address of the employee"<<endl;
            cin.getline(newer->addrs,50);
            fflush(stdin);

            cout<<"Enter the current city of the employee"<<endl;
            cin.getline(newer->city,30);
            fflush(stdin);

            cout<<"Enter the job title of the employee"<<endl;
            cin.getline(newer->jobtitle,30);
            fflush(stdin);

            cout<<"Enter the salary if the employee"<<endl;
            cin>>newer->salary;
            fflush(stdin);

            cout<<"Enter the date of joining"<<endl;
            cin.getline(newer->date,30);
            fflush(stdin);

            newer->next = NULL;
            temp->next = newer;
            newer->prev = temp;


        }

    }
    void add_after(){
        if(head==NULL){
            cout<<"\n\t\tList is Empty"<<endl;
            cout<<"\n\t\tAdd a new record\n\tPress Y or N";
            cin>>ch;
            if(ch=='Y'||ch=='y'){
                add_first();
                return;
            }


        }
        else{
            int val;
            cout<<"Enter the id after which you want to add a new record";
            cin>>val;
            bool flag = false;
            node *temp = head;
            node *p;
            while(temp!=NULL){
                if(temp->id == val){
                    node *newer = new node;
                    cout<<"Enter employee id:"<<endl;
                    cin>>newer->id;
                    fflush(stdin);

                    cout<<"Enter name of employee"<<endl;
                    cin.getline(newer->name,50);
                    fflush(stdin);

                    cout<<"Enter qualification of the employee"<<endl;
                    cin.getline(newer->qua,30);
                    fflush(stdin);

                    cout<<"Enter the address of the employee"<<endl;
                    cin.getline(newer->addrs,50);
                    fflush(stdin);

                    cout<<"Enter the current city of the employee"<<endl;
                    cin.getline(newer->city,30);
                    fflush(stdin);

                    cout<<"Enter the job title of the employee"<<endl;
                    cin.getline(newer->jobtitle,30);
                    fflush(stdin);

                    cout<<"Enter the salary if the employee"<<endl;
                    cin>>newer->salary;
                    fflush(stdin);

                    cout<<"Enter the date of joining"<<endl;
                    cin.getline(newer->date,30);
                    fflush(stdin);

                    if(temp->next!=NULL){
                        newer->next = temp->next;
                        newer->prev = temp;
                        p = temp->next;
                        p->prev = newer;
                        temp->next = newer;
                    }
                    else{
                        newer->next = temp->next;
                        newer->prev = temp;
                        temp->next = newer;
                    }
                    flag = true;

                }
                temp = temp->next;
            }
            if(flag == false){
                cout<<"\n\t\tId not found"<<endl;
            }
        }
    }
    void del(){
        if(head == NULL){
            cout<<"\n\t\tList is empty"<<endl;
            cout<<"\n\t\tAdd a new record\n\tPress Y or N:";
            cin>>ch;
            if(ch=='y'|| ch=='Y'){
                add_first();
                return;
            }
        }
        else{
           int val;
           cout<<"\n\t\tEnter employee id which you want to delete:";
           cin>>val;
           node *temp = head;
           if(val == 1){
            head = temp->next;
           }
           for(int i = 0;i<val-2;i++){
            temp = temp->next;
           }
           node *temp1,*temp2;
           temp1 = temp->prev;
           temp2 = temp->next;
           temp->next = temp2->next;
           delete temp2;
           cout<<"Record Deleted Successfully"<<endl;

    }
    }

    void show(){
        if(head == NULL){
            cout<<"\n\t\tList is empty"<<endl;
            cout<<"\n\t\tDo you want to add a record\n\tPress Y or N :";
            cin>>ch;
            if(ch=='Y' || ch=='y'){
                add_first();
                return;
            }
        }
        else{
            node *temp = head;
            while(temp != NULL){
                cout<<"\n\t\tInformation of the Employee:"<<endl;
                cout<<"\n\t\t ID:"<<temp->id<<endl;
                cout<<"\n\t\t Name:"<<temp->name<<endl;
                cout<<"\n\t\tQualification:"<<temp->qua<<endl;
                cout<<"\n\t\tJob Title:"<<temp->jobtitle<<endl;
                cout<<"\n\t\tSalary:"<<temp->salary<<endl;
                cout<<"\n\t\tStarting Date:"<<temp->date<<endl;

                temp = temp->next;
            }
        }
    }

    void searching(){
        if(head == NULL){
            cout<<"\n\t\tList is empty"<<endl;
            cout<<"\n\t\tDo you want to add a record\n\tPress Y or N :";
            cin>>ch;
            if(ch=='Y' || ch=='y'){
                add_first();
                return;
            }

    }
    else{
        int val;
        cout<<"Enter the ID you want to search:";
        cin>>val;
        node *temp = head;
        bool flag = false;
        while(temp != NULL){
            if(temp->id == val){
                cout<<"Records Are:"<<endl;

                cout<<"\n\t\tInformation of the Employee:"<<endl;
                cout<<"\n\t\t ID:"<<temp->id<<endl;
                cout<<"\n\t\t Name:"<<temp->name<<endl;
                cout<<"\n\t\tQualification"<<temp->qua<<endl;
                cout<<"\n\t\tJob Title"<<temp->jobtitle<<endl;
                cout<<"\n\t\tSalary"<<temp->salary<<endl;
                cout<<"\n\t\tStarting Date"<<temp->date<<endl;

                flag = true;

            }

            temp  = temp->next;
        }
        if(flag == false){
            cout<<"Record not found:"<<endl;
        }
    }
    }
    void update(){
        if(head == NULL){
            cout<<"\n\t\tList is empty"<<endl;
            cout<<"\n\t\tDo you want to add a record\n\tPress Y or N :";
            cin>>ch;
            if(ch=='Y' || ch=='y'){
                add_first();
                return;
            }

    }
    else{
        int val;
        cout<<"\n\t\tEnter the ID you want to update: ";
        cin>>val;
        node *temp = head;
        while(temp!=NULL){
            if(temp->id == val){
                    cout<<"Enter employee id:"<<endl;
                    cin>>temp->id;
                    fflush(stdin);

                    cout<<"Enter name of employee"<<endl;
                    cin.getline(temp->name,50);
                    fflush(stdin);

                    cout<<"Enter qualification of the employee"<<endl;
                    cin.getline(temp->qua,30);
                    fflush(stdin);

                    cout<<"Enter the address of the employee"<<endl;
                    cin.getline(temp->addrs,50);
                    fflush(stdin);

                    cout<<"Enter the current city of the employee"<<endl;
                    cin.getline(temp->city,30);
                    fflush(stdin);

                    cout<<"Enter the job title of the employee"<<endl;
                    cin.getline(temp->jobtitle,30);
                    fflush(stdin);

                    cout<<"Enter the salary if the employee"<<endl;
                    cin>>temp->salary;
                    fflush(stdin);

                    cout<<"Enter the date of joining"<<endl;
                    cin.getline(temp->date,30);
                    fflush(stdin);


            }
            temp = temp->next;
        }
    }
    }
};
int main(){
    employee e;
    int option;
    cout<<"Select an option: "<<endl;
    cout<<"0: Exit"<<endl;
    cout<<"1: Add first node"<<endl;
    cout<<"2: Add last node"<<endl;
    cout<<"3: Add after a node"<<endl;
    cout<<"4: Delete a node"<<endl;
    cout<<"5: Show all the node"<<endl;
    cout<<"6: Search a particular node"<<endl;
    cout<<"7: Update a node node"<<endl;

    do
    {
        cout<<"Enter your choice :";
        cin>>option;
        switch(option){
        case 1:
            e.add_first();
            break;
        case 2:
            e.add_last();
            break;
        case 3:
            e.add_after();
            break;
        case 4:
            e.del();
            break;

        case 5:
            e.show();
            break;

        case 6:
            e.searching();
            break;

        case 7:
            e.update();
            break;
        }
    } while (option !=0);


return 0;
}
