#include <stdio.h>
#include <stdlib.h>
#include "DataTypes.h"
#include "Fonctions.h"
void selectionEtudiant(int mode,char* c1,float* c2);
//Gher_hrabli_osf
int main (){
    char choix;
    int selection;
    char mtr[5];
    float moy;

    printf("\nBonjour dans la plate-forme Etudiant-gestion ou vous pouvez gerer vos etudiants\n");
    printf("voulez vous affichez le menu ou quitter la plateforme\n");

    do{
        printf("tapez c pour continuer oui q pour quitter\n:");
        fflush(stdin);
        scanf("%c",&choix);
        if(choix=='q'){
            printf("fin de session\n");
            return 0;
        }
    }while(choix!='c');
    
    while(1){
        AfficherMenu();
        printf("\n votre choix : ");
        scanf("%d",&selection);
        switch(selection){
            case 0 : printf("\nfin de session\n");return 0;
            case 1 : Remplissage();break;
            case 2 : Affichage();break;
            case 3 : Ajout();break;
            case 4 : selectionEtudiant(2,mtr,&moy);Modifier(mtr,moy);break;
            case 5 : selectionEtudiant(1,mtr,&moy);Suppression(mtr);break;
            case 6 : selectionEtudiant(1,mtr,&moy);Recherche(2,mtr);break;
            case 7 : TriAlphabetique();break;
            case 8 : TriMerite();break;
            default: printf("veillez selectionez un choix valide\n");break;
        }
        printf("\nTapez enter pour continuer\n");
        fflush(stdin);
        gets(&choix);

    }
    printf("\nfin de session\n");
    return 0;
}



void selectionEtudiant(int mode,char* c1,float* c2){
    printf("Quelle est le matricule de l'etudiant\nMatricule : ");
    fflush(stdin);
    gets(c1);
    if(mode==2){
        printf("Quelle est la moyenne de l'etudiant\nMoyenne : ");
        fflush(stdin);
        scanf("%f",c2);
    }
}
