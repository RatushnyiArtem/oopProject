#include <iostream>
#include </Users/artemratushnyi/Desktop/PROJECT FOR UNI/Classes/Soap.cpp>

class shavingSoap : public Soap{
    public:
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