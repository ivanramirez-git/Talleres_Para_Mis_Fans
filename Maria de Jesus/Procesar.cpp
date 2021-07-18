// Your C++ Program
#include <iostream>
#include<cstring> // string operations
    
int procesar(char p[]) {

    for(int i=0; i< strlen(p); i++) {
        for(int j=0; j< strlen(p); j++) {

            if(p[i]==p[j] && i != j)
                return 1;
        }
    }
    return 0;
}

int main() {

    char p[15]="Vamos Mundo";

    procesar(p);
    
    std::cout << "Hello World!";
    return 0;
}
