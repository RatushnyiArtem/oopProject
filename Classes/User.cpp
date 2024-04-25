#pragma once
#include <iostream>
#include "Soap.cpp"

class User{
    std::string name;
    std::string surname;
    double moneyAmount;
    Soap *f;
    public:
        User(const std::string _name, const std::string _surname,double _money, Soap *smth): name(_name), surname(_surname),moneyAmount(_money), f(smth){};
        const std::string getName() const{
            return name;
        }
        const std::string getSurname() const{
            return surname;
        }
        void useSoap(){
            f->use();
        };
        Soap*& returnSoap(){
            return f;
        }
        void selectedSoap(){
            std::cout<<f->getBrand()<<" that's my selected soap. And here is a procent that remains - "<<f->getPerc()<<"%"<<std::endl;
        }
        const double getMoney() const{
            return moneyAmount;
        }
        
};
