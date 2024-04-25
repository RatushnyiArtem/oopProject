#include <iostream>
#include </Users/artemratushnyi/Desktop/PROJECT FOR UNI/Classes/Soap.cpp>

class liquidSoap : public Soap{
    public:
    liquidSoap(std::string _color, std::string _brand, double _price): Soap(_color,_brand,_price){}
    void use() override{
        if(percentage>0){
            percentage -= percentage*0.009;
            if(percentage < 0){
                percentage = 0;
            }
        } else{
            std::cout<<"We don't have soap, you wasted all soap..."<<std::endl;
        }
    }
    void makeBubble(){
        if(percentage>0){
            percentage -= 10;
            if(percentage<0){
                percentage = 0;
            }
        } else{
            std::cout<<"Damn, you spent all soap."<<std::endl;
        }
    }
};