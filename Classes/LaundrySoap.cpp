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
        if(clothes<10){
            percentage -= 1.01;
        } else if(clothes<50){
            percentage -= 1.2;
        } else if(clothes<=0){
            throw std::logic_error("You must choose how many clothes (it can't be negative or zero)!");
        }
        else{
            percentage -= 1.85;
        }
    }
};