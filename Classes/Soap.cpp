#include <iostream>

class Soap{
    protected:
    std::string color;
    std::string brand;
    double percentage;
    double price;

    public:
        Soap(std::string _color, std::string _brand, double _price, double _percentage = 100): color(_color), brand(_brand), price(_price), percentage(_percentage) {};
        virtual void use(){
            if(percentage>0){
                percentage -= percentage*0.012;
                if(percentage<0){
                    percentage = 0;
                }
            } else{
                std::cout<<"We don't have soap, you wasted all soap..."<<std::endl;
            }
        }
        void soapLeft(){};
        const double getPerc() const{
            return percentage;
        }
        const double getPrice() const{
            return price;
        }
        const std::string getBrand() const{
            return brand;
        }
        virtual ~Soap() {}
};