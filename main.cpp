#include <iostream>
#include <vector>

class Soap{
    std::string color;
    std::string brand;
    double percentage;

    public:
        Soap(std::string _color, std::string _brand, int _percentage = 100): color(_color), brand(_brand),percentage(_percentage) {};
        virtual void use(){
            percentage -=2;
        }
        void soapLeft(){};
        const int getPerc() const{
            return percentage;
        }
        virtual ~Soap() {}
};

class User{
    std::string name;
    std::string surname;
    Soap *f;
    public:
        User(const std::string _name, const std::string _surname, Soap *smth): name(_name), surname(_surname), f(smth){};
        const std::string getName() const{
            return name;
        }
        const std::string getSurname() const{
            return surname;
        }
        void useSoap(){
            f->use();
        };
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
    Soap p ("red", "dove");
    User m("fdfds", "slfksdf",&p);
    m.useSoap();
    std::cout<<p.getPerc();
    
}