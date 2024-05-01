#pragma once
#include <iostream>
#include <stdexcept>
#include "Soap.cpp"

class laundrySoap : public Soap{
    public:
    laundrySoap(std::string _color, std::string _brand, double _price): Soap(_color,_brand,_price){}
    void use() override{
        throw std::logic_error("Can't use it, it burns. Try do laundry with it.");
    }
    void doLaundry(int clothes){
        if(clothes>10){
            percentage -= percentage*0.01;
        } else if(clothes>50){
            percentage -= percentage*0.04;
        } else{
            percentage -= percentage*0.009;
        }
    }
};