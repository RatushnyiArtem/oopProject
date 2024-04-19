#include <iostream>
#include <vector>

class Soap{
    std::string color;
    std::string brand;
    double percentage;
    double price;

    public:
        Soap(std::string _color, std::string _brand, double _price, double _percentage = 100): color(_color), brand(_brand), price(_price), percentage(_percentage) {};
        virtual void use(){
            percentage = percentage - percentage*0.012;
        }
        void soapLeft(){};
        const double getPerc() const{
            return percentage;
        }
        const double getPrice() const{
            return price;
        }
        virtual ~Soap() {}
};

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
        const double getMoney() const{
            return moneyAmount;
        }
        
};

class Shop{
    std::string name;
    std::vector<Soap*> elements;
    public:

        ~Shop(){
            for(auto *element : elements){
                delete element;
            }
        }
};

class liquidSoap : public Soap{
};

class laundrySoap : public Soap{
};

class shavingSoap : public Soap{
};

class handSoap : public Soap{
};


int main(){
    Soap p ("red", "dove",45.0);
    User m("fdfds", "slfksdf",1001.02,&p);
    m.useSoap();
    std::cout<<p.getPerc()<<std::endl;
    std::cout<<p.getPrice();
}