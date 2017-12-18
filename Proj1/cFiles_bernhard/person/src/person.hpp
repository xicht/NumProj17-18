/*
 * person.hpp
 *
 *  Created on: 18.01.2017
 *      Author: Lukas
 */

#ifndef PERSON_HPP_
#define PERSON_HPP_

#include <string>

class Person
{
public:
    Person();
    Person(std::string name, std::string adresse);

    std::string get_name();
    std::string get_adresse();
    void umtaufen(std::string name);
    void umziehen(std::string adresse);

private:
    std::string name;
    std::string adresse;
};

class Student:public Person
{
public:
    Student();
    Student(std::string name, std::string adresse, unsigned int matrikelnummer);

    unsigned int get_matrnr();
    void einschreiben(unsigned int matrikelnummer);

private:
    unsigned int matrikelnummer;
};

class Arbeiter:public Person
{
public:
    Arbeiter();
    Arbeiter(std::string name, std::string adresse);
    Arbeiter(std::string name, std::string adresse, unsigned int gehalt, std::string arbeit);

    void kuendigen();
    void anstellen(std::string arbeit, unsigned int gehalt);
    unsigned int get_gehalt();
    std::string get_arbeit();


private:
    unsigned int gehalt;
    std::string arbeit;
};


#endif /* PERSON_HPP_ */
