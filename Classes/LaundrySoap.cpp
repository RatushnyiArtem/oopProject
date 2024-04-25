#pragma once
#include <iostream>
#include "Soap.cpp"

class laundrySoap : public Soap{
    public:
    void use() override{
        std::cout<<"I can't touch it by myself, it burns. I can use it in laundry.";
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