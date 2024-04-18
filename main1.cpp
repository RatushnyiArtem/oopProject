#include <iostream>

using namespace std;

class IntArray {
    int len;
    int *mem;
    public:
        IntArray(int n):
            len(n),
            mem(new int [len])
        {

        }

        void store(int i, int val){
            mem[i] = val;
        }
        void iota(){
            for(int i = 0; i < len; i++){
                mem[i] = i;
            }
        }
        void iota(int start){
            for(int i = 0 ; i < len; i++){
                mem[i] = start + i;
            }
        }

        int get(int i){
            return mem[i];
        }

        int length(){
            return len;
        }
        void square(){
            for(int i = 0; i < len; i++){
                mem[i] *= mem[i];
            }
        }
        void print(){
            cout<<len<<endl;
            for(int i = 0; i<len; i++){
                cout<<mem[i]<<endl;
            }
        }

            IntArray(const IntArray &other):
            len(other.len),
            mem(new int[len])
            {
                for(int i = 0; i < len; i++){
                    mem[i] = other.mem[i];
                }
            }
        ~IntArray() {
            delete [] mem;
        }
        // IntArray(const IntArray &) = delete;
        // IntArray& operator=(const IntArray &) = delete;

};
class DoubleArr {
    int len;
    double *mem;
    public:
        DoubleArr(int n):
        len(n),
        mem(new double[len])
        {

        }
        void store(int i, double val){
            mem[i] = val;
        }
        
        void print(){
            for(int i = 0; i<len; i++){
                cout<<mem[i]<<endl;
            }
        }
        double get(int i){
            return mem[i];
        }
        int length(){
            return len;
        }
        DoubleArr(const DoubleArr &other):
        len(other.len),
        mem(new double [len])
        {
            for(int i = 0; i < len; i++){
                mem[i] = other.mem[i];
            }
        }
        void resize(int new_len){
            if(new_len <= 0){
                cerr << "Invalid length for resize." << endl;
                return;
            }
            double *new_mem = new double[new_len];
            int copy_len;
            if(new_len<len){
                copy_len = new_len;
            } else{
                copy_len = len;
            };
            for(int i = 0; i < copy_len; i++){
                new_mem[i] = mem[i];
            }
           
            delete [] mem;

            mem = new_mem;
            len = new_len;
        }

        ~DoubleArr(){
            delete [] mem;
        }
};


int sum(IntArray &vals) {
    int sum = 0;
    for (int i = 0 ; i < vals.length() ; i++) {
        sum += vals.get(i);
    }
    return sum;
}


int main(){
    // IntArray arr(10);
    // IntArray b = arr;
    // sum(arr);
    // int *a = new int[10];
    // int *b = a;
    // b[0] = 7;
    // cout<<a[0];
    IntArray a(10); // create a new IntArray of size 10
    IntArray c(a); // create a new IntArray which is a copy of a
    DoubleArr b(10);
    b.store(0, 10); // set the first element of a to 10;
    b.store(1, 20);
    b.store(2, 20);
    b.store(3, 20);
    b.store(4, 20);
    b.store(5, 20);
    b.store(6, 20);
    b.store(7, 20);
    b.store(8, 20);
    b.store(9, 20);
    b.resize(12);
    b.store(11, 34);
    b.print();
    
    // a.square();
    // a.print();
    // std::cout << a.get(0) << std::endl; // print the first element of a
   // std::cout << b.get(0) << std::endl; // print the first element of b
    // notice that they are not the same
    // IntArray c(a); // create a new IntArray which is a copy of a
    // std::cout << c.get(0) << std::endl; // print the first element of c
    // it is the same as the first element of a
    // c.store(0, 123); // set the first element of c to 10;
    // std::cout << c.get(0) << std::endl; // c's first is now 123
    // std::cout << a.get(0) << std::endl; // however a's first is still 10
}


