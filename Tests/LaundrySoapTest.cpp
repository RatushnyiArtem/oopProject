#pragma once
#include <iostream>
#include <cassert>
#include <vector>
#include "../Classes/Soap.cpp"
#include "../Classes/LaundrySoap.cpp"

bool testGetColor(){
    laundrySoap *f = new laundrySoap("orange", "demi", 20.4);
    std::string actualColor = f->getColor();
    assert("orange" == actualColor);
    return true;
}

bool testGetBrand(){
    laundrySoap *f = new laundrySoap("orange", "demi", 20.4);
    std::string actualBrand = f->getBrand();
    assert("demi" == actualBrand);
    return true;
}

bool testGetPrice(){
    laundrySoap *f = new laundrySoap("orange", "demi", 20.4);
    double actualPrice = f->getPrice();
    assert(20.4 == actualPrice);
    return true;
}

bool testLaundry(){
        laundrySoap *f = new laundrySoap("orange", "demi", 20.4);
        double percBefore = f->getPerc();
        f->doLaundry(8);
        double percAfter = percBefore - 1.01;
        percBefore = f->getPerc();
        assert(percBefore == percAfter);
        f->doLaundry(20);
        percAfter = percBefore - 1.2;
        percBefore = f->getPerc();
        assert(percBefore == percAfter);
        f->doLaundry(60);
        percAfter = percBefore - 1.85;
        percBefore = f->getPerc();
        assert(percBefore == percAfter);
        try{
            f->doLaundry(0);
        } catch(std::logic_error& err){
            assert(std::string(err.what()) == std::string("You must choose how many clothes (it can't be negative or zero)!"));
        }
        return true;  
}

bool testExceptionUse(){
        try{
                laundrySoap *f = new laundrySoap("orange", "demi", 20.4);
                f->use();
        } catch(std::logic_error& err){
                assert(std::string(err.what()) == std::string("Can't use it, it burns. Try do laundry with it."));
        }
        return true;
}



int main(){
    std::cout<<testGetColor()<<std::endl;
    std::cout<<testGetBrand()<<std::endl;
    std::cout<<testGetPrice()<<std::endl;
    std::cout<<testLaundry()<<std::endl;
    std::cout<<testExceptionUse()<<std::endl;
}