#include <iostream>

#include "manip_nombres.h"

// 1.1.1
int Somme(int a, int b)
{
    return a + b;
}

// 1.1.2
void Inverse(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
}

// 1.1.3
int ReplacePointeur(int a, int b, int c)
{
    c = Somme(a, b);
    int* j = &c;
    return *j;
}

int ReplaceReference(int a, int b, int c)
{
    c = Somme(a, b);
    int& r = c;
    return r;
}

// 1.1.4
void TableauAleatoire(int array[], int size, int borne)
{
    int temp, i, j;

    srand(time(NULL));
    // Génération d'un tableau aléatoire allant de 0 à la variable borne
    // et d'une taille size

    for (i = 0; i < size; i++)
    {
        array[i] = rand() % borne;
    }

    for (i = 0; i < size; i++)
    {
        std::cout << "Numero " << i + 1 << " : " << array[i] << std::endl;
    }

    // Tri par ordre croissant avec variable temporaire 

    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    std::cout << "De facon trie par ordre croissant : " << std::endl;
    for (i = 0; i < size; i++)
    {
        std::cout << array[i] << "\t" << std::endl;
    }

    // Tri par ordre decroissant avec variable temporaire

    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (array[j] > array[i])
            {
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }
    std::cout << "De facon trie par ordre decroissant : " << std::endl;
    for (i = 0; i < size; i++)
    {
        std::cout << array[i] << "\t" << std::endl;
    }

}