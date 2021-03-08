#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include "DataTypes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void AfficherMenu(){
    printf("Nous vous proposons plusieurs choix parmi lesquels vous pouvez choisir pour effectuer l\'operation voulue\n");
    printf("Pour appliquer votre choix veuillez entrer le numero indique a cote des choix\n");
    printf("\n");
    printf("  1 - Remplissage\t\t  2 - Affichage\n\n  3 - Ajout\t\t\t  4 - Modification\n\n  5 - Suppression\t\t  6 - Recherche\n\n  7 - Tri Alphabetique\t\t  8 - Tri par merite\n\n\t\t0 - Quitter la plateforme");
    printf("\n");
}

void Remplissage(){
    FILE* file = fopen("Etudiants.txt","a");
    if (file==NULL)
        printf("Impossible d\'ouvrir ce fichier \n");
    else{
        fseek( file, 0, SEEK_SET );
        char reponse;
        do{
            printf("Vous voulez entrer les donnees des etudiants ?\nVeuillez repondre par y pour oui et n pour non \n");
            fflush(stdin);
            scanf("%c",&reponse);
            if(reponse=='y'){
                Eleve etudiant ;

                printf("Entrez la matricule de l\'etudiant \n ");
                fflush(stdin);
                scanf("%ld",&etudiant.matricule);
                fprintf(file,"%ld",etudiant.matricule);


                printf("Entrez le nom de l\'etudiant \n ");
                fflush(stdin);
                gets(etudiant.nom);
                fprintf(file,"/%s",etudiant.nom);

                printf("Entrez l\'annee de naissance de l\'etudiant \n ");
                fflush(stdin);
                scanf("%d",&etudiant.dateNaissance.annee);
                fprintf(file,"/%d",etudiant.dateNaissance.annee);

                printf("Entrez le mois de naissance de l\'etudiant \n ");
                fflush(stdin);
                scanf("%d",&etudiant.dateNaissance.mois);
                fprintf(file,"/%d",etudiant.dateNaissance.mois);

                printf("Entrez le jour de naissance de l\'etudiant \n ");
                fflush(stdin);
                scanf("%d",&etudiant.dateNaissance.jour);
                fprintf(file,"/%d",etudiant.dateNaissance.jour);

                printf("Entrez la moyenne de l\'etudiant \n ");
                fflush(stdin);
                scanf("%f",&etudiant.moyenne);
                fprintf(file,"/%.2f\n",etudiant.moyenne);
            }
        }while(reponse=='y');
        fclose(file);
    }
}

void Affichage(){
    FILE* file = fopen("Etudiants.txt","r");
    if (file==NULL)
    printf("Impossible d\'ouvrir ce fichier \n");
    else{
        char buffer[100]="";
        while(fgets(buffer,100,file)!=NULL){
            printf(" %s",buffer);
        }
        fclose(file);
    }
}

int Recherche(int mode,char* Mle){
    FILE* file = fopen("Etudiants.txt","r");
    if (file==NULL)
        printf("Impossible d\'ouvrir ce fichier \n");
    else{
        char chaine[100];
        while(fgets(chaine,100,file)!= NULL){
            char* token=strtok(chaine,"/");
            if (strcmp(token,Mle)==0){
                if(mode==1||mode==2){printf("L\'etudiant existe dans votre classe\n");}
                return 1;
            }
        }
        if(mode==0||mode==2){printf("L\'etudiant n\'existe pas  dans votre classe\n");}
        return 0;
    }
    fclose(file);
}

void Ajout(){
    FILE* file = fopen("Etudiants.txt","a");
    if (file==NULL)
        printf("Impossible d\'ouvrir ce fichier \n");
    else{
        printf("Veuillez entrer les informations relatives a l\'eleve que vous souhaitez ajouter\n");
        Eleve etudiant ;

        printf("Entrez la matricule de l\'etudiant \n ");
        fflush(stdin);
        scanf("%ld",&etudiant.matricule);
        char mat[10];
        itoa(etudiant.matricule,mat,10);
        if(Recherche(1,mat)==1){
            fclose(file);
            return;
        }
        fprintf(file,"%ld",etudiant.matricule);
        
        
        printf("Entrez le nom de l\'etudiant \n ");
        fflush(stdin);
        gets(etudiant.nom);
        fprintf(file,"/%s",etudiant.nom);

        printf("Entrez l\'annee de naissance de l\'etudiant \n ");
        fflush(stdin);
        scanf("%d",&etudiant.dateNaissance.annee);
        fprintf(file,"/%d",etudiant.dateNaissance.annee);

        printf("Entrez le mois de naissance de l\'etudiant \n ");
        fflush(stdin);
        scanf("%d",&etudiant.dateNaissance.mois);
        fprintf(file,"/%d",etudiant.dateNaissance.mois);

        printf("Entrez le jour de naissance de l\'etudiant \n ");
        fflush(stdin);
        scanf("%d",&etudiant.dateNaissance.jour);
        fprintf(file,"/%d",etudiant.dateNaissance.jour);

        printf("Entrez la moyenne de l\'etudiant \n ");
        fflush(stdin);
        scanf("%f",&etudiant.moyenne);
        fprintf(file,"/%.2f\n",etudiant.moyenne);

        fclose(file);
    }
    printf("\nL'etudiant a bien ete ajoute\n");
}


int Modifier(char* Mle,float nMoy){
    if(Recherche(0,Mle)==0){
        return 0;
        }
    FILE* file = fopen("Etudiants.txt","r");
    char chaine[100];
    FILE* buffer = fopen("buffer.txt","w");
    if (file==NULL)
        printf("Impossible d\'ouvrir ce fichier \n");
    else {
        char line[100];
        while(fgets(chaine,100,file)!= NULL){
            strcpy(line,chaine);
            char* token=strtok(chaine,"/");
            if (strcmp(token,Mle)!=0){
                fprintf(buffer,line);
            }
            else{
                for(int j=0;j<5;j++){
                    fprintf(buffer,"%s/",token);
                    token=strtok(NULL,"/");
                }
                fprintf(buffer ,"%.2f\n",nMoy);
            }
        }
        
    }
    fclose(file);
    fclose(buffer);
    file = fopen("Etudiants.txt","w");
    buffer = fopen("buffer.txt","r");
    while(fgets(chaine,100,buffer)!= NULL){
        fprintf(file,"%s",chaine);
    }
    printf("La moyenne a bien ete change en %.2f",nMoy);
    fclose(file);
    fclose(buffer);
    remove("buffer.txt");

}

int Suppression(char* Mle){
    char chaine[100];
    if(Recherche(0,Mle)==0){
        return 0;
        }
    FILE* file = fopen("Etudiants.txt","r");
    FILE* buffer = fopen("AfterSupp.txt","w");
    if (file==NULL)
    printf("Impossible d\'ouvrir ce fichier \n");
    else {
        char chaine[100];
        char line[100];
        while(fgets(chaine,100,file)!= NULL){
            strcpy(line,chaine);
            char* token=strtok(chaine,"/");
            if (strcmp(token,Mle)!=0){
                fprintf(buffer,line);
            }
        }
        
    }
    printf("\nL'etudiant a bien ete supprime");

    fclose(file);
    fclose(buffer);
    file = fopen("Etudiants.txt","w");
    buffer = fopen("AfterSupp.txt","r");

    while(fgets(chaine,100,buffer)!= NULL){
        fprintf(file,"%s",chaine);
    }
    fclose(file);
    fclose(buffer);
    remove("AfterSupp.txt");
}

int TriMerite(){

    int compteur=0;
    float a[100];
    char chaine[100];
    char line[100];
    FILE* file = fopen("Etudiants.txt","r");
    FILE* buffer = fopen("Moyennes.txt","w");
    if (file==NULL)
        printf("Impossible d\'ouvrir ce fichier \n");
    else{
        while(fgets(chaine,100,file)!= NULL){
            strcpy(line,chaine);
            char* token=strtok(chaine,"/");
            for(int j=0;j<5;j++){
                char garbage[15];
                strcpy(garbage,token);
                token=strtok(NULL,"/");
            }
            fprintf(buffer,"%s",token);
        }
        fclose(buffer);
        buffer =fopen("Moyennes.txt","r");
        while(!feof(buffer)){
            fscanf(buffer,"%f\n",&a[compteur]);
            compteur++;
        }

        for (int i=0;i<compteur-1;i++){
            for (int j=0;j<compteur-1-i;j++){
                if (a[j]<a[j+1]){
                    float temp =a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }

        fclose(buffer);

        buffer = fopen("Moyennes.txt","w");
        for(int k=0;k<compteur;k++){
            fprintf(buffer,"%.2f\n",a[k]);
        }
        fclose(file);
        fclose(buffer);
        buffer =fopen("Moyennes.txt","r");
        FILE* ordre = fopen("Ordre.txt","w");
        char buf[100];
        while(fgets(buf,100,buffer)!=NULL){
            file = fopen("Etudiants.txt","r");
            while(fgets(chaine,100,file)!= NULL){
                strcpy(line,chaine);
                char* token=strtok(chaine,"/");
                for(int j=0;j<5;j++){
                    char garbage[15];
                    strcpy(garbage,token);
                    token=strtok(NULL,"/");
                }
                if (strcmp(token,buf)==0){
                    fprintf(ordre,"%s",line);
                }
            }
            fclose(file);
        }
        fclose(buffer);
        fclose(ordre);

        fclose(ordre);
    }
    printf("\nLe fichier a bien ete trie\n");
    file = fopen("Etudiants.txt","w");
    buffer = fopen("Ordre.txt","r");

    while(fgets(chaine,100,buffer)!= NULL){
        fprintf(file,"%s",chaine);
    }
    fclose(file);
    fclose(buffer);
    remove("Ordre.txt");
    remove("Moyennes.txt");

}

int TriAlphabetique(){
    int compteur=0;
    char a[100][50];
    char chaine[100];
    char line[100];
    FILE* file = fopen("Etudiants.txt","r");
    FILE* buffer = fopen("Names.txt","w");
    if (file==NULL)
        printf("Impossible d\'ouvrir ce fichier \n");
    else{
        while(fgets(chaine,100,file)!= NULL){
            strcpy(line,chaine);
            char* token=strtok(chaine,"/");
            char garbage[15];
            strcpy(garbage,token);
            token=strtok(NULL,"/");
            fputs(token,buffer);
            fputs("\n",buffer);
        }
        fclose(buffer);
        buffer =fopen("Names.txt","r");

        while(fgets(a[compteur],50,buffer)!=NULL){compteur++;}

        for (int i=0;i<compteur-1;i++){
            for (int j=0;j<compteur-1-i;j++){
                if (strcmp(a[j],a[j+1])>0){
                    char temp[50] ;
                    strcpy(temp,a[j]);
                    strcpy(a[j],a[j+1]);
                    strcpy(a[j+1],temp);
                }
            }
        }

        fclose(buffer);
        buffer = fopen("Names.txt","w");

        for(int k=0;k<compteur;k++){
            fputs(a[k],buffer);
        }
        fclose(file);
        fclose(buffer);
        buffer =fopen("Names.txt","r");
        FILE* ordre = fopen("OrdreN.txt","w");
        char buf[100];

        while(fgets(buf,100,buffer)!=NULL){
            buf[strlen(buf)-1] = '\0';
            file = fopen("Etudiants.txt","r");
            while(fgets(chaine,100,file)!= NULL){
                strcpy(line,chaine);
                char* token=strtok(chaine,"/");
                char garbage[15];
                strcpy(garbage,token);
                token=strtok(NULL,"/");
                if (strcmp(token,buf)==0){
                    fprintf(ordre,"%s",line);
                }
            }
            fclose(file);
        }
        fclose(buffer);
        fclose(ordre);
    }
    file = fopen("Etudiants.txt","w");
    buffer = fopen("OrdreN.txt","r");

    while(fgets(chaine,100,buffer)!= NULL){
        fprintf(file,"%s",chaine);
    }
    printf("\nLe fichier a bien ete trie\n");
    fclose(file);
    fclose(buffer);
    remove("OrdreN.txt");
    remove("Names.txt");
}
#endif
