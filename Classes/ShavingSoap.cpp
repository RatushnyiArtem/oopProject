#pragma once
#include <iostream>
#include <stdexcept>
#include "Soap.cpp"

class shavingSoap : public Soap{
    public:
    shavingSoap(std::string _color, std::string _brand, double _price): Soap(_color,_brand,_price){}
    void use() override{
        if(percentage>0){
            percentage -= percentage*0.009;
            if(percentage<0){
                percentage = 0;
            }
            std::cout<<"Your beard shaved";
        } else{
            throw std::overflow_error("Can't use it, because you already use all Soap");
        }
    }
};