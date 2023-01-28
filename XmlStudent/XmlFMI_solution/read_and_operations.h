#ifndef XMLFMI_READ_AND_OPERATIONS_H
#define XMLFMI_READ_AND_OPERATIONS_H

#include <iostream>
#include <fstream>
#include "Student.h"
#include "parse.h"
using namespace std;

Student students[30];
int position, studentPos = 0;

char* readKey(const char* source)
{
    char* key = new char[200];

    ifstream inFile(source);
    inFile.seekg(position, ios::beg);

    int i = 0;
    char a;
    while(true)
    {
        inFile.get(a);

        if(a == '<')
            continue;
        if(a == '>' || a == '\\')
        {
            key[i] = '\0';
            break;
        }

        key[i] = a;
        i++;
    }

    position = inFile.tellg();
    return key;
}

char* readValue(const char* source)
{
    char* value = new char[200];

    ifstream inFile(source);
    inFile.seekg(position, ios::beg);

    int i = 0;
    char a;
    while(true)
    {
        inFile.get(a);

        if(a == '<')
        {
            do
                inFile >> a;
            while(a != '>');
        }
        if(a == '>')
        {
            value[i] = '\0';
            break;
        }

        value[i] = a;
        i++;
    }

    position = inFile.tellg();

    return value;
}

void read(const char* source)
{
    ifstream inFile(source);
    position = 1;

    inFile.seekg(0, ios::end);
    size_t length = inFile.tellg();
    inFile.seekg(0, ios::beg);

    while(!inFile.eof())
    {
        if(position > length - 1)
            break;

        char a;
        inFile >> a;
        char* key;
        char* value;

        key = readKey(source);
        inFile.seekg(position);

        if(!strcmp(key, "student")) {
            value = readValue(source);
            inFile.seekg(position, ios::beg);

            if(strcmp(key, "name") != 0)
                students[studentPos].name = value;

            if(strcmp(key, "gender") != 0)
                students[studentPos].gender = value;

            if(strcmp(key, "email") != 0)
                students[studentPos].email = value;

            if(strcmp(key, "age") != 0)
                students[studentPos].age = parseInt(value);

            if(strcmp(key, "fn") != 0)
                students[studentPos].fn = parseInt(value);

            if(strcmp(key, "grade") != 0)
                students[studentPos].grade = parseDouble(value);

            if(strcmp(value, "student") != 0)
                studentPos++;
        }
    }
}

void operations(const char* source)
{
    char choice[20];
    cout << "Choose operation: edit, sort, print or save:" << endl;
    cin >> choice;

    ifstream inFile(source);

    if(strcmp(choice, "edit") != 0)
    {
        int student_fn;
        cout << "Write the faculty number of the student whose information you want to edit:" << endl;
        cin >> student_fn;

        char information[25];
        cout << "Write which student's information you want to edit:" << endl;
        cin >> information;

        char value[25];
        cout << "Write the new name you want:" << endl;
        cin.ignore();
        cin.getline(value, 25);

        int student_number = 0;
        for(int i = 0; i < studentPos; i++)
            if(students[i].fn == student_fn)
                student_number = i;

        if(strcmp(information, "name") != 0)
            students[student_number].name = value;

        if(strcmp(information, "gender") != 0)
            students[student_number].gender = value;

        if(strcmp(information, "email") != 0)
            students[student_number].email = value;

        if(strcmp(information, "age") != 0)
            students[student_number].age = parseInt(value);

        if(strcmp(information, "fn") != 0)
            students[student_number].fn = parseInt(value);

        if(strcmp(information, "grade") != 0)
            students[student_number].grade = parseDouble(value);

        cout << "Operation successfully executed!" << endl;
        operations(source);
    }
    else if(strcmp(choice, "sort") != 0)
    {
        int idx = 0;
        for (int i = 0; i < studentPos; i++) {
            for (int j = i + 1; j < studentPos; j++) {

                if (students[i].name[idx] > students[j].name[idx]) {
                    swap(students[j], students[i]);
                    idx = 0;
                }
                else if (students[i].name[idx] == students[j].name[idx]) {
                    idx++;
                    j--;
                }
                else if (students[i].name[idx] < students[j].name[idx]) {
                    idx = 0;
                }
            }
        }
    }
    else if(strcmp(choice, "print") != 0)
    {
        for(int i = 0; i < studentPos; i++)
        {
            cout << "-- Student -- " << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Email: " << students[i].email << endl;
            cout << "Gender: " << students[i].gender << endl;
            cout << "Grade: " << students[i].grade << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "Faculty Number: " << students[i].fn << endl;
            cout << endl;
        }
        operations(source);
    }
    else if(strcmp(choice, "save") != 0)
    {
        ofstream outFile(source);

        for (int i = 0; i < studentPos; i++)
        {
            outFile << "<student>" << endl;
            outFile << '\t' << "<name>" << students[i].name << "</name>" << endl;
            outFile << '\t' << "<fn>" << students[i].fn << "</fn>" << endl;
            outFile << '\t' << "<age>" << students[i].age << "</age>" << endl;
            outFile << '\t' << "<gender>" << students[i].gender << "</gender>" << endl;
            outFile << '\t' << "<email>" << students[i].email << "</email>" << endl;
            outFile << '\t' << "<grade>" << students[i].grade << "</grade>" << endl;
            outFile << "</student>" << endl;
            outFile << endl;
        }
    }
}

#endif //XMLFMI_READ_AND_OPERATIONS_H
