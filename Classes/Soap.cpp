#pragma once
#include <iostream>
#include <stdexcept>

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
                percentage -= 1.4;
                if(percentage<0){
                    percentage = 0;
                }
            } else{
                throw std::overflow_error("Can't use it, because you already use all Soap");
            }
        }
        const double getPerc() const{
            return percentage;
        }
        const std::string getColor() const {
            return color;
        }
        const double getPrice() const{
            return price;
        }
        const std::string getBrand() const{
            return brand;
        }
        virtual ~Soap() {}
};