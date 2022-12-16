#include <stdio.h>
#include <stdlib.h>

// fonction qui inverse les elements d'un tableau
int* reverse_tab(int* tab, int n){
    int* newTab = (int*)malloc(sizeof(int)*n);
    for(int i = n - 1; i >= 0; i--){
        for(int j = (n - 1)-i; j < n; j++){
            newTab[j] = tab[i];
        }
    }

    return newTab;
	}

// fonction qui convertit la partie entiere d'un nombre reel en un nombre binaire
int* toBinary(float n, int *nOfBits){
    int number = (int)n;
    int* binary = (int*)malloc(sizeof(int)*32);
    int numberOfBits = 0;
    while(number != 0){
        *(binary+numberOfBits) =  number%2;
        number /= 2;
        numberOfBits++;
    }
    binary = (int*)realloc(binary, sizeof(int)*numberOfBits);
    *nOfBits = numberOfBits;
    return reverse_tab(binary,numberOfBits);

}
// fonction qui convertit la partie decimale d'un nombre reel en un nombre binaire
int* decimalToBinary(float number, int numberBits){
    // on va prendre la partie entiere du nombre reel
    int formatInt = (int)number;
    // (number-formatInt) => il nous donne la partie decimale du nombre reel ex: 0.5845
    float decimal = (number-formatInt) * 2;

    int* binary = (int*)malloc(sizeof(int)*numberBits);
    for (int i = 0; i < numberBits; i++){
        if(decimal >= 1){
            decimal = (decimal - 1)*2;
            binary[i] = 1;
        }else{
            decimal *= 2;
            binary[i] = 0;
        }
    }
    return binary;

}
// fonction qui represente un nombre reel sous la forme de la norme IEEE754 (simple precision)
void ieee754(float num){
    int signe = 0;
    float floatNumber = num;
    // verifier le signe du nombre.
    if(floatNumber < 0){
        signe = 1;
        floatNumber = num * (-1);
    }
    // a => nombre des bits de la partie entiere
    int a = 0;
    // b => nombre des bits de la partie decimale
    int b = 0;
    // Declaration d'un tableau de 23 cases pour la mantisse (23 Bits)
    int *mantisse = (int*)malloc(sizeof(int)*23);
    // partieInt => la partie entiere en binaire
    int *partieInt = toBinary(floatNumber, &a);
    // exposant => Exposant en binaire
    int *exposant = toBinary((a-1)+127,&b);
    // partieDecimal => La partie decimale en binaire
    int *partieDecimal = decimalToBinary(floatNumber,23-(a-1));
    /*
        remplissage du mantisse par la partie entiere en forme binaire depuis le deuxieme bit
        exemple : partie entiere = 1011 Alors on va remplir le debut du tableau (Mantisse)
        par 011.

    */
    for(int i = 0; i < a-1; i++){
        mantisse[i] = partieInt[i+1];
    }
    /*
        remplissage le reste du tableau (mantisse) par la partie decimale en forme binaire.
    */
    for(int i = 0; i < 23-(a-1); i++){
        mantisse[i+(a-1)] = partieDecimal[i];
    }
    printf("\n---------- Representation en Forme IEEE754 du %f -----------\n\n", floatNumber);
    printf("%d | ",signe);
    for(int j = 0; j < b; j++){
        printf("%d ", exposant[j]);
    }
    printf(" | ");
    for(int j = 0; j < 23; j++){
        printf("%d ", mantisse[j]);
    }
    printf("\n\n");
}



int main()
{
    float nombre;
    printf("Donner un nombre : ");
    scanf("%f", &nombre);
    ieee754(nombre);
    return 0;
}
