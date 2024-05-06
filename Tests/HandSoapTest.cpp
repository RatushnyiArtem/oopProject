#pragma once
#include <iostream>
#include <cassert>
#include <vector>
#include "../Classes/Soap.cpp"
#include "../Classes/HandSoap.cpp"

bool testGetColor(){
    handSoap *f = new handSoap("pink", "deltion", 24.4);
    std::string actualColor = f->getColor();
    assert("pink" == actualColor);
    return true;
}

bool testGetBrand(){
    handSoap *f = new handSoap("pink", "deltion", 24.4);
    std::string actualBrand = f->getBrand();
    assert("deltion" == actualBrand);
    return true;
}

bool testGetPrice(){
    handSoap *f = new handSoap("pink", "deltion", 24.4);
    double actualPrice = f->getPrice();
    assert(24.4 == actualPrice);
    return true;
}

bool testUse(){
        handSoap *f = new handSoap("pink", "deltion", 24.4);
        double percBefore = f->getPerc();
        f->use();
        double percAfter = percBefore - 1.009;
        percBefore = f->getPerc();
        assert(percBefore == percAfter);
        return true;  
}

bool testException(){
        try{
                handSoap *f = new handSoap("pink", "deltion", 24.4);
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