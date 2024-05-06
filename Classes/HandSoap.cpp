#pragma once
#include <iostream>
#include <stdexcept>
#include "Soap.cpp"

class handSoap : public Soap{
    public:
    handSoap(std::string _color, std::string _brand, double _price): Soap(_color,_brand,_price){}
    void use() override{
        if(percentage>0){
            percentage -= 1.009;
            if(percentage<0){
                percentage = 0;
            }
            std::cout<<"Your hands cleaned"<<std::endl;
        } else{
            throw std::overflow_error("Can't use it, because you already use all Soap");
        }
    }
}; 