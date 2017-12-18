/*
 * person.cpp
 *
 *  Created on: 18.01.2017
 *      Author: Lukas
 */

#include "person.hpp"
#include <string>

Person::Person():name("noname"), adresse("obdachlos")
{
}
Person::Person(std::string name, std::string adresse):name(name), adresse(adresse)
{
}

std::string Person::get_name()
{
    return name;
}
std::string Person::get_adresse()
{
    return adresse;
}
void Person::umtaufen(std::string name)
{
    this->name = name;
}
void Person::umziehen(std::string adresse)
{
    this->adresse = adresse;
}


Student::Student():matrikelnummer(0)
{
}
Student::Student(std::string name, std::string adresse, unsigned int matrikelnummer):
        Person(name, adresse), matrikelnummer(matrikelnummer)
{
}
unsigned int Student::get_matrnr()
{
    return matrikelnummer;
}
void Student::einschreiben(unsigned int matrikelnummer)
{
    if(this->matrikelnummer != 0)
    {
        this->matrikelnummer = matrikelnummer;
    }
}

Arbeiter::Arbeiter():gehalt(0), arbeit("arbeitslos")
{
}
Arbeiter::Arbeiter(std::string name, std::string adresse):
        Person(name, adresse), gehalt(0), arbeit("arbeitslos")
{
}
Arbeiter::Arbeiter(std::string name, std::string adresse, unsigned int gehalt, std::string arbeit):
        Person(name, adresse), gehalt(gehalt), arbeit(arbeit)
{
}
void Arbeiter::kuendigen()
{
    gehalt = 0;
    arbeit = "arbeitslos";
}
void Arbeiter::anstellen(std::string arbeit, unsigned int gehalt)
{
    this->arbeit = arbeit;
    this->gehalt = gehalt;
}
unsigned int Arbeiter::get_gehalt()
{
    return gehalt;
}
std::string Arbeiter::get_arbeit()
{
    return arbeit;
}
