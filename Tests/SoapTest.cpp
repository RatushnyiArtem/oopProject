#pragma once
#include <iostream>
#include <cassert>
#include "../Classes/Soap.cpp"

// class SoapTests{
//     const std::string color = "red";
//     const std::string brand = "dove";
//     double percentage = 100.0;
//     double price = 9.4;
// };

bool testColor() {
        Soap *p = new Soap("red", "dove", 9.4);
        std::string colorActual = p->getColor();
        assert(colorActual == "red");
        return true;    
}

bool testBrand() {
        Soap *p = new Soap("red", "dove", 9.4);
        std::string brandActual = p->getBrand();
        assert(brandActual == "dove");
        return true;    
}
bool testPrice() {
        Soap *p = new Soap("red", "dove", 9.4);
        double priceActual = p->getPrice();
        assert(priceActual == 9.4);
        return true;  
}
bool testPercentage() {
        Soap *p = new Soap("red", "dove", 9.4);
        double percActual = p->getPerc();
        assert(percActual == 100);
        return true;  
}
bool testUse(){
        Soap *p = new Soap("red", "dove", 9.4);
        double percBefore = p->getPerc();
        p->use();
        double percAfter = percBefore - percBefore*0.012;
        percBefore = p->getPerc();
        assert(percBefore == percAfter);
        return true;  
}

int main(){
    std::cout<<testColor()<<std::endl;
    std::cout<<testBrand()<<std::endl;
    std::cout<<testPrice()<<std::endl;
    std::cout<<testPercentage()<<std::endl;
    std::cout<<testUse()<<std::endl;

}