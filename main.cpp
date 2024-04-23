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
        const std::string getBrand() const{
            return brand;
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
        Soap*& returnSoap(){
            return f;
        }
        void selectedSoap(){
            std::cout<<f->getBrand()<<" that's my selected soap."<<std::endl;
        }
        const double getMoney() const{
            return moneyAmount;
        }
        
};

class Shop{
    std::string name;
    std::vector<Soap*> elements;
    public:
    void addSoap(Soap *t){
        elements.push_back(t);
    }
    void chooseSoap(User *k){
        for(int i = 0; i<elements.size(); i++){
            if(k->getMoney()<elements[i]->getPrice()){
                std::swap(elements[i], elements.back());
                elements.pop_back();
                i--;
            }
        }
        int choise;
        if(elements.size()!=0){
            std::cout<<"Which one do you want to buy?: "<<std::endl;
            for(int i = 0; i<elements.size();i++){
                std::cout<<i+1<<". "<<elements[i]->getBrand()<<std::endl;
            }
            std::cin>>choise;
            while(choise>elements.size() || choise<1){
                std::cout<<"Wrong choise, there are no such a number, can you peak another one?: "<<std::endl;
                std::cin>>choise;
            }
            for(int i = 0; i < elements.size(); i++){
                if(choise != i+1){
                    std::swap(elements[i], elements.back());
                    elements.pop_back();
                    i--;
                }
            }
            k->returnSoap() = elements[0];
        }
    }
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
    Soap *f = new Soap("dove","floreen",10);
    Soap *p = new Soap("dskdfksdf","dsklfdksf",20.03);
    Soap *k = new Soap("dskdfksdf","dsklfdksf",20.1);
    Soap *j = new Soap("floreen","dove",19.1);
    User m("fdfds", "slfksdf",20.02,p);
    Shop shopify;
    shopify.addSoap(f);
    shopify.addSoap(p);
    shopify.addSoap(k);
    shopify.addSoap(j);
    shopify.chooseSoap(&m);
    m.useSoap();
    m.selectedSoap();
    std::cout<<p->getPerc()<<std::endl;
    std::cout<<p->getPrice();
}