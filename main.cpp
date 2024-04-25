#pragma once
#include <iostream>
#include <vector>
#include "Classes/Soap.cpp"
#include "Classes/User.cpp"
#include "Classes/Shop.cpp"
#include "Classes/LiquidSoap.cpp"
#include "Classes/LaundrySoap.cpp"
#include "Classes/ShavingSoap.cpp"
#include "Classes/HandSoap.cpp"



int main(){
    Soap *f = new Soap("dove","floreen",10);
    Soap *p = new Soap("dskdfksdf","dsklfdksf",20);
    Soap *k = new Soap("dskdfksdf","dsklfdksf",20);
    Soap *j = new Soap("floreen","dove",19.1);
    liquidSoap *le = new liquidSoap("red", "cringe",15);
    User m("fdfds", "slfksdf",20.02,p);
    Shop shopify;
    shopify.addSoap(f);
    shopify.addSoap(p);
    shopify.addSoap(k);
    shopify.addSoap(j);
    shopify.addSoap(le);
    shopify.chooseSoap(&m);
    m.useSoap();
    m.useSoap();
    m.useSoap();
    m.useSoap();
    m.useSoap();
    m.useSoap();
    le->makeBubble();
    le->makeBubble();
    le->makeBubble();
    le->makeBubble();
    le->makeBubble();
    le->makeBubble();
    le->makeBubble();
    le->makeBubble();
    le->makeBubble();
    le->makeBubble();
    m.selectedSoap();
    std::cout<<p->getPerc()<<std::endl;
    std::cout<<p->getPrice();
}