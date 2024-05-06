#pragma once
#include <iostream>
#include <cassert>
#include <vector>
#include "../Classes/Soap.cpp"
#include "../Classes/ShavingSoap.cpp"

bool testGetColor(){
    shavingSoap *f = new shavingSoap("red", "dolt", 13.4);
    std::string actualColor = f->getColor();
    assert("red" == actualColor);
    return true;
}

bool testGetBrand(){
    shavingSoap *f = new shavingSoap("red", "dolt", 13.4);
    std::string actualBrand = f->getBrand();
    assert("dolt" == actualBrand);
    return true;
}

bool testGetPrice(){
    shavingSoap *f = new shavingSoap("red", "dolt", 13.4);
    double actualPrice = f->getPrice();
    assert(13.4 == actualPrice);
    return true;
}

bool testUse(){
        shavingSoap *f = new shavingSoap("red", "dolt", 13.4);
        double percBefore = f->getPerc();
        f->use();
        double percAfter = percBefore - 1.12;
        percBefore = f->getPerc();
        assert(percBefore == percAfter);
        return true;  
}

bool testException(){
        try{
                shavingSoap *f = new shavingSoap("red", "dolt", 13.4);
                do{
                        f->use();
                }while(f->getPerc()>0);
        } catch(std::overflow_error& err){
                assert(std::string(err.what()) == std::string("Can't use it, because you already use all Soap"));
        }
        return true;
}

int main(){
    std::cout<<testGetColor()<<std::endl;
    std::cout<<testGetBrand()<<std::endl;
    std::cout<<testGetPrice()<<std::endl;
    std::cout<<testUse()<<std::endl;
    std::cout<<testException()<<std::endl;
}