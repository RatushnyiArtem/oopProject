#pragma once
#include <iostream>
#include "Soap.cpp"

class handSoap : public Soap{
    void use() override{
        if(percentage>0){
            percentage -= percentage*0.009;
            if(percentage<0){
                percentage = 0;
            }
            std::cout<<"Your hands cleaned";
        } else{
            std::cout<<"We don't have soap, you wasted all soap..."<<std::endl;
        }
    }
}; 