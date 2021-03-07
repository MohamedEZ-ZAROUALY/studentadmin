#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int jour;
    int mois;
    int annee;
} date;

typedef struct {
    long int matricule;
    char nom[50];
    date dateNaissance;
    float moyenne;
} Eleve;

#endif
