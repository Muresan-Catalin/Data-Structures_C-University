#include <iostream>
#include <string.h>

using namespace std;

struct elev{
    int age;
    char name[100];
    char dob[100];
};

int main()
{
    elev arr[150];
    char s[100];
    int n, varsta;
    cin>>n;

    for(int i = 0; i<n; i++){

        cout<<"Nume ";
        cin.get();
        cin.getline(s, 100);
        strcpy(arr[i].name, s);

        cout<<endl<<"varsta: ";
        cin>>varsta;
        arr[i].age = varsta;


        cout<<endl<<"dob: ";
        cin.get();
        cin.getline(s, 100);
        strcpy(arr[i].dob, s);
    }

    cout<<endl;
    for(int i = 0; i<n; i++){
        cout<<arr[i].name<<endl;
        cout<<arr[i].age<<endl;
        cout<<arr[i].dob<<endl;
        cout<<endl;
    }

    return 0;
}
