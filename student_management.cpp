#include<iostream>
#include<string>

using namespace std;

class Node{
public:
    int ID;
    int Marks;
    string Name;
    string Department;
    Node *Next;
};

//Global variable storing the head of the list
Node *head = new Node();

// Checks if the student is in the list.
bool check(int x){
    if(!head){
        return false;
    }

    Node *t = new Node();
    t = head;

    while(t){
        if(t->ID == x)
            return true;

        t = t->Next;
    }

    return false;
}

// Inserts student in the linked list.
void insert_info(int ID, int Marks, string Name, string Department){
    if(check(ID)){
        cout << "The Student with this record already exists.\n";
        return;
    }

    //Creating a new node to add into the list.

    Node *t = new Node();
    t->ID = ID;
    t->Marks = Marks;
    t->Name = Name;
    t->Department = Department;
    t->Next = NULL;

    //inserts student at the beginning
    if(head == NULL || head->ID >= t->ID){
        t->Next = head;
        head = t;
    }

    //inserts student at the middle or end
    else{
        Node *c = head;
        while(c->Next != NULL && c->Next->ID < t->ID){
            c = c->Next;
        }
    }

    cout << "Record Inserted Sucessfully \n";

}

//Searches for the student in the list using the ID.
void search(int ID){
    if(!head){
        cout << "No Such Record Available.\n";
        return;
    }

    else{
        Node *t = head;
        while(t){
            if(t->ID == ID){
                cout << "ID Number\t" << t->ID << endl;
                cout << "Name\t\t" << t->Name << endl;
                cout << "Department\t" << t->Department << endl;
                cout << "Marks\t\t" << t->Marks << endl;
                return;
            }
            t = t->Next;
        }

        if(t == NULL){
            cout << "No Record Available.\n";
        }
    }
}

//Deletes student information if the info is present in the list.
int delete_info(int ID){
    Node *t = head;
    Node *p = NULL;

    if(t && t->ID == ID){
        head = t->Next;
        delete t;

        cout << "Record Deleted.\n";
        return 0;
    }

    while(t && t->ID != ID){
        p = t;
        t = t->Next;
    }

    if(!t){
        cout << "Record does not exist.\n";
        return -1;
    }    
    p->Next = t->Next;

    delete t;

    cout << "Record Sucessfully deleted.\n";
    return 0;
}

//Displays the students' info
void show_info(){
    Node *p = head;
    if(p == NULL){
        cout << "No record Available.\n";
        return;
    }

    else{
        cout << "Index\tName\tDepartment\tMarks\n";

        while(p != NULL){
            cout << p->ID << "\t"
                 << p->Name << "\t"
                 << p->Department << "\t"
                 << p->Marks << endl;
            p = p->Next;
        }
    }
}

int main(){

    head = NULL;
    string Name, Department;
    int ID, Marks;
 
    // Menu-driven program
    while (true) {
        cout << "\n\t\tWelcome to Student Record "
                "Management System\n\n\tPress\n\t1 to "
                "create a new Record\n\t2 to delete a "
                "student record\n\t3 to Search a Student "
                "Record\n\t4 to view all students "
                "record\n\t5 to Exit\n";
        cout << "\nEnter your Choice\n";
        int Choice;
 
        // Enter Choice
        cin >> Choice;
        if (Choice == 1) {
            cout << "Enter Name of Student\n";
            cin >> Name;
            cout << "Enter ID Number of Student\n";
            cin >> ID;
            cout << "Enter Course of Student \n";
            cin >> Department;
            cout << "Enter Total Marks of Student\n";
            cin >> Marks;
            insert_info(ID, Marks, Name, Department);
        }
        else if (Choice == 2) {
            cout << "Enter ID Number of Student whose "
                    "record is to be deleted\n";
            cin >> ID;
            delete_info(ID);
        }
        else if (Choice == 3) {
            cout << "Enter ID Number of Student whose "
                    "record you want to Search\n";
            cin >> ID;
            search(ID);
        }
        else if (Choice == 4) {
            show_info();
        }
        else if (Choice == 5) {
            exit(0);
        }
        else {
            cout << "Invalid Choice "
                 << "Try Again\n";
        }
    }
    return 0;
}