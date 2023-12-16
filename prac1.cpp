#include <iostream>
#include <cstring>
using namespace std;

struct Student
{
    int rollNo;
    char name[50];
    float sgpa;
};

void swapNo(Student& a, Student& b)
{
    Student temp = a;
    a = b;
    b = temp;
}
void bubblesort(Student s[], int n)
{
    for(int i=0; i < n-1; i++)
    {
        for (int j=0; j < n-i-1; j++)
        {
            if( s[j].rollNo > s[j+1].rollNo)
            {
                swapNo(s[j], s[j+1]);
            }
        }
    }
}

void search(Student s[], int n, float target)
{
    bool found = false;
    
    cout<<"Students with SGPA : "<<target << "\n";
    
    for(int i; i<n; ++i)
    {
        if( s[i].sgpa == target)
        {
            cout<<"Roll no: " << s[i].rollNo << "\tName : " << s[i].name << "\tSGPA : " << s[i].sgpa << endl;
            found = true;
        }
    }
    
    if(!found)
    {
        cout<< "No student found with SGPA" << target << endl; 
    }
}


void sortAlphabetically(Student s[], int n)
{
    for (int i = 1; i < n; ++i)
    {
        Student key = s[i];
        int j = i-1;
        
        while( j >= 0 && strcmp(s[j].name, key.name) > 0)
        {
            s[j+1] = s[j];
            --j;
        }
        s[j+1] = key;
    }
}

int main()
{
    const int maxsize  = 100;
    
    Student s[maxsize];
    
    int n, choice;
    float target;
    
    cout<< "Enter the numebr of students : ";
    cin >> n;
    
    cout<< "===============================================================\n";
    
    for(int i=0; i<n; i++)
    {
        cout<< "Enter details for student :" << i+1 << "\n";
        
        cout<< "Roll no : ";
        cin>>s[i].rollNo;
        
        cout<<"Name : ";
        cin.ignore();
        cin.getline(s[i].name, sizeof(s[i].name));
        
        cout<<"SGPA : ";
        cin>>s[i].sgpa;
        
    }
    do
    {
        cout<< "===============================================================\n";
        
        cout << "\nChoose an operation:\n";
        
        cout << "1. Roll Call List (sort by Roll No)\n";
        cout << "2. Search by SGPA\n";
        cout << "3. Arrange Alphabetically (sort by Name)\n";
        cout << "4. Exit\n";
        
        cout<< "===============================================================\n";
        
        cout << "Enter your choice: ";
        cin>> choice;
        
        
        switch(choice)
        {
            case 1:
                bubblesort(s,n);
                cout<<"Roll call list (sorted by roll no)\n";
                for(int i; i<n; ++i)
                {
                    cout<<"Roll no : "<< s[i].rollNo << "\tName : " << s[i].name << "\tSGPA : " << s[i].sgpa << endl;
                }
                cout<< "===============================================================\n";
                break;
                
            case 2:
                 cout << "Enter the target SGPA to search: ";
                 cin >> target;
                 search(s,n,target);
                 cout<< "===============================================================\n";
                 break;
                 
            case 3:
                sortAlphabetically(s,n);
                cout << "List arranged alphabetically (sorted by Name):\n";
                for(int i=0; i<n; ++i)
                {
                    cout<<"Roll no : "<< s[i].rollNo << "\tName : " << s[i].name << "\tSGPA : " << s[i].sgpa << endl;  
                }
                cout<< "===============================================================\n";
                break;
             
            case 4:
                 cout << "Exiting program.\n";
                 cout<< "===============================================================\n";
                break;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    }
    while(choice != 4);
    return 0;
}
