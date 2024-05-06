#pragma once
#include <iostream>
#include <cassert>
#include "../Classes/Soap.cpp"
#include "../Classes/User.cpp"

bool testGetName(){
    Soap *p = new Soap("red", "dove", 9.4);
    User m("John", "Neyman",20.02,p);
    std::string actualName = m.getName();
    assert(actualName  == "John");
    return true;
}

bool testGetSurname(){
    Soap *p = new Soap("red", "dove", 9.4);
    User m("John", "Neyman",20.02,p);
    std::string actualSurname = m.getSurname();
    assert(actualSurname  == "Neyman");
    return true;
}

bool testGetMoney(){
    Soap *p = new Soap("red", "dove", 9.4);
    User m("John", "Neyman",20.02,p);
    double actualMoney = m.getMoney();
    assert(actualMoney  == 20.02);
    return true;
}

bool testGetSoap(){
    Soap *p = new Soap("red", "dove", 9.4);
    User m("John", "Neyman",20.02,p);
    Soap *t = m.returnSoap();
    assert(p->getBrand() == t->getBrand());
    assert(p->getColor() == t->getColor());
    assert(p->getPerc() == t->getPerc());
    assert(p->getPrice() == t->getPrice());
    delete p;
    return true;
}

bool testUseSoap(){
    Soap *p = new Soap("red", "dove", 9.4);
    User m("John", "Neyman",20.02,p);
    m.useSoap();
    double percentageOfSoap = p->getPerc();
    assert(percentageOfSoap == 98);
    return true;
}

int main(){
    std::cout<<testGetName()<<std::endl;
    std::cout<<testGetSurname()<<std::endl;
    std::cout<<testGetMoney()<<std::endl;
    std::cout<<testGetSoap()<<std::endl;
    std::cout<<testUseSoap()<<std::endl;
}