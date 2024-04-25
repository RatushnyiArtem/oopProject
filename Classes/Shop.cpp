#include <iostream>
#include <vector>
#include </Users/artemratushnyi/Desktop/PROJECT FOR UNI/Classes/Soap.cpp>
#include </Users/artemratushnyi/Desktop/PROJECT FOR UNI/Classes/User.cpp>

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
                if(choise == i+1){
                    std::swap(elements[choise-1], elements[0]);
                    elements.resize(1);
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
