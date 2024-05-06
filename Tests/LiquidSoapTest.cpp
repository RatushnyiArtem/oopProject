#pragma once
#include <iostream>
#include <cassert>
#include <vector>
#include "../Classes/Soap.cpp"
#include "../Classes/LiquidSoap.cpp"

bool testGetColor(){
    liquidSoap *f = new liquidSoap("white", "folt", 15.4);
    std::string actualColor = f->getColor();
    assert("white" == actualColor);
    return true;
}

bool testGetBrand(){
    liquidSoap *f = new liquidSoap("white", "folt", 15.4);
    std::string actualBrand = f->getBrand();
    assert("folt" == actualBrand);
    return true;
}

bool testGetPrice(){
    liquidSoap *f = new liquidSoap("white", "folt", 15.4);
    double actualPrice = f->getPrice();
    assert(15.4 == actualPrice);
    return true;
}

bool testUse(){
        liquidSoap *f = new liquidSoap("white", "folt", 13.4);
        double percBefore = f->getPerc();
        f->use();
        double percAfter = percBefore - 1.9;
        percBefore = f->getPerc();
        assert(percBefore == percAfter);
        return true;  
}

bool testMakeBubble(){
        liquidSoap *f = new liquidSoap("white", "folt", 13.4);
        double percBefore = f->getPerc();
        f->makeBubble();
        double percAfter = percBefore - 5;
        percBefore = f->getPerc();
        assert(percBefore == percAfter);
        return true;  
}

bool testExceptionUse(){
        try{
                liquidSoap *f = new liquidSoap("white", "folt", 15.4);
                do{
                        f->use();
                }while(f->getPerc()>0);
        } catch(std::overflow_error& err){
                assert(std::string(err.what()) == std::string("Can't use it, because you already use all Soap"));
        }
        return true;
}

bool testExceptionMakeBubble(){
        try{
                liquidSoap *f = new liquidSoap("white", "folt", 15.4);
                do{
                        f->makeBubble();
                }while(f->getPerc()>0);
        } catch(std::overflow_error& err){
                assert(std::string(err.what()) == std::string("Ooops, I can't... You used all Soap already"));
        }
        return true;
}

int main(){
    std::cout<<testGetColor()<<std::endl;
    std::cout<<testGetBrand()<<std::endl;
    std::cout<<testGetPrice()<<std::endl;
    std::cout<<testUse()<<std::endl;
    std::cout<<testMakeBubble()<<std::endl;
    std::cout<<testExceptionUse()<<std::endl;
    std::cout<<testExceptionMakeBubble()<<std::endl;
}