#pragma once
#include <iostream>
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
            std::cout<<"We don't have soap, you wasted all soap..."<<std::endl;
        }
    }
};