//============================================================================
// Name        : matrixU.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "person.hpp"
using namespace std;

void printperson(Person &person, string varname)
{
    cout << varname << ":" << endl;
    cout << person.get_name()<<endl;
    cout << person.get_adresse()<<endl;
}

void printstudent(Student &student, string varname)
{
    printperson(student, varname);
    cout << student.get_matrnr()<<endl;
}

void printarbeiter(Arbeiter &arbeiter, string varname)
{
    printperson(arbeiter, varname);
    cout << arbeiter.get_arbeit()<< endl;
    cout << arbeiter.get_gehalt()<< endl;
}

int main()
{
    Person personA;
    Person personB("hawara", "daham");

    printperson(personA, "personA");
    printperson(personB, "personB");

    personA.umtaufen("anderer hawara");
    personA.umziehen("a daham");
    printperson(personA, "personA");

    cout << "\n\n";


    Student studentA;
    Student studentB("aaa", "bbb straße", 100);

    printstudent(studentA, "studentA");
    printstudent(studentB, "studentB");

    studentA.umtaufen("studibaer");
    studentA.umziehen("bei da mama");
    studentA.einschreiben(100000);
    studentB.einschreiben(10);
    printstudent(studentA, "studentA");
    printstudent(studentB, "studentB");

    cout << "\n\n";


    Arbeiter arbeiterA;
    Arbeiter arbeiterB("wastl", "im 10.");
    Arbeiter arbeiterC("fritz fantom", "kanal", 99999, "krimineller");

    printarbeiter(arbeiterA, "arbeiterA");
    printarbeiter(arbeiterB, "arbeiterB");
    printarbeiter(arbeiterC, "arbeiterC");

    arbeiterB.anstellen("studienassistent", 1);
    arbeiterC.kuendigen();
    printarbeiter(arbeiterB, "arbeiterB");
    printarbeiter(arbeiterC, "arbeiterC");

    return 0;
}
