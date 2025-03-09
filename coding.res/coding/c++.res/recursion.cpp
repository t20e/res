#include <iostream>

using std::cout;

void walkIterative(int steps);
void walkRecursie(int steps);

int factoriaIterative(int num);
int factoriaRecursive(int num);


int main(){

    /*
    
        ------ Recursion is a programming technique where a function invokes itself from within

                We break a complex convept into a repeatable single step


        recursion uses more memory and is slower than iterative approach.

    
    */ 
    //    walkIterative(100);
    // walkRecursie(100);


    cout << factoriaIterative(10) << "\n";
    cout << factoriaRecursive(10);
    


    return 0;
}


void walkIterative(int steps){

    for(int i = 0; i < steps; i++){
        cout << "You take a step\n";
    }
}


void walkRecursie(int steps){
    if(steps > 0 ){
        cout << "You take a step\n";
        walkRecursie(steps - 1);
    }
}



int factoriaIterative(int num){
    int result = 1;
    for (int i = 1; i <= num; i++){
        result = result * i;
    }
    return result;
}


int factoriaRecursive(int num){
    if(num > 1){
        return num * factoriaRecursive(num - 1);
    }else{
        return 1;
    }
}