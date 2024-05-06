#pragma once
#include <iostream>
#include <cassert>
#include <vector>
#include "../Classes/Soap.cpp"
#include "../Classes/User.cpp"
#include "../Classes/Shop.cpp"

bool testAddSoap(){
    Shop shopify;
    Soap *p = new Soap("red", "dove", 9.4);
    shopify.addSoap(p);
    std::vector<Soap*> testElements;
    testElements.push_back(p);
    assert(testElements == shopify.getSoap());
    return true;
    
}

bool testChoosingSoap(){
    Shop shopify;
    Soap *p = new Soap("red", "dove", 9.4);
    Soap *t = new Soap("black", "ahava", 15);
    Soap *f = new Soap("orange", "keyday", 22);
    Soap *j = new Soap("white", "haan", 18);
    Soap *k = new Soap("green", "klion", 20.03);
    User m("John", "Neyman",20.02,p);
    shopify.addSoap(p);
    shopify.addSoap(t);
    shopify.addSoap(f);
    shopify.addSoap(j);
    shopify.addSoap(k);
    shopify.chooseSoap(&m);
    shopify.getSoap();
    //assume that we want to get ahava
    std::vector<Soap*> testElements;
    testElements.push_back(t);
    assert(testElements == shopify.getSoap());
    return true;
}

int main(){
    std::cout<<testAddSoap()<<std::endl;
    std::cout<<testChoosingSoap();
}