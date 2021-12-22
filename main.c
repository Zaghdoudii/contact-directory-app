#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "contact_tel.h"

int main()
{
    system("color 5F");
    printf("\a \a \a");
    time_t now;
    time(&now);
    printf(" \t\t\t\t\t\t\t Aujourd'hui est : %s", ctime(&now));
    int choix,i,recherche=-1,taille_tab=0 ;
    long int num_tel;
    char nom[28];
    cont tab_cont[100];
    printf("\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
    printf("\n  \t\t\t\t\t\t\t  Gestion d'un Repertoire telephonique \n ");
    FILE * fichier;
    fichier = fopen("Liste_des_contactes.txt","rt");
    if (fichier==NULL)
    {
        printf("\n");
    }
    else
    {
        i=taille_tab;
        while(!feof(fichier))
        {
            fscanf(fichier,"%ld %s %s %ld %s %s %ld \n",&tab_cont[i].num_tel,tab_cont[i].nom,tab_cont[i].prenom,&tab_cont[i].ncin,tab_cont[i].adresse.rue,tab_cont[i].adresse.ville,&tab_cont[i].adresse.code_postale);
            i++;
        }
        fclose(fichier);
        taille_tab=i;
    }
    while (1)
    {
        printf("\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
        printf("\t\t\t\t\t\t\t\t *-*  Entrer votre choix :)  *-*\n");
        printf("\n\n");
        printf("\t\t\t\t\t\t\t 1. Saisir des contacts \n");
        printf("\t\t\t\t\t\t\t 2. Afficher un contact \n");
        printf("\t\t\t\t\t\t\t 3. Lister les contacts \n");
        printf("\t\t\t\t\t\t\t 4. Rechercher un contact \n");
        printf("\t\t\t\t\t\t\t 5. Modifier un contact \n");
        printf("\t\t\t\t\t\t\t 6. Supprimer un contact \n");
        printf("\t\t\t\t\t\t\t 7. Ajouter un contact \n");
        printf("\t\t\t\t\t\t\t 8. Trier les contact \n");
        printf("\t\t\t\t\t\t\t 0. Quitter :) \n");
        printf("\n\t\t\t\t\t\t\t\tCHOIX : ");
        scanf("%d",&choix);
        system("cls");
        switch (choix)
        {
        case 1:
        {
            system("color 4F");
            ajout_cont(tab_cont,&taille_tab);
            break;
        }
        case 2:
        {
            system("color 1B");
            do
            {
                printf("\n\t\t\t\t\t\tTaper le numero de telephone de contact que vous voulez afficher : ");
                scanf("%ld",&num_tel);
            }
            while((num_tel<9999999)||(num_tel>100000000));
            recherche=Recherche_cont(tab_cont,taille_tab,num_tel);
            if(recherche==-1)
                printf("\t\t\t\t\t\t\t\tCONTACT INEXISTANT :) ");
            else
                affiche_cont(tab_cont[recherche]);
            break;
        }
        case 3:
        {
            system("color 1c");
            if (taille_tab==0)
                printf("\n\t\t\t\t\t\t\t\t La repertoire est vide :) \n");
            else
            {
                affiche_tab_cont(tab_cont,taille_tab);
                printf("\n");
            }
            break;
        }
        case 4:
        {
            system("color 8F");
            do
            {
                printf("\n\t\t\t\t\t\t\tTaper le nom de contact que vous voulez rechercher : ");
                fflush(stdin);
                gets(nom);
            }
            while(test(nom)!=1);

            recherche=Recherche_nom_cont(tab_cont,taille_tab,nom);
            if (recherche==-1)
                printf("\n\t\t\t\t\t\t\t\t CONTACT INEXISTANT :( ");
            else
                printf("\n\t\t\t\t\t\t Ce contact existe a l'indice : %d",recherche+1);
            break;
        }
        case 5:
        {
            system("color 8E");
            do
            {
                printf("\n\t\t\t\t\t  Taper le numero de telephone de contact que vous voulez modifier : ");
                scanf("%ld",&num_tel);
            }
            while((num_tel<9999999)||(num_tel>100000000));
            Modifier_cont(tab_cont,taille_tab,num_tel);
            break;
        }
        case 6:
        {
            system("color 4E");
            do
            {
                printf("\n\t\t\t\t\t Taper le num de contact que vous voulez supprimer : ");
                scanf("%ld",&num_tel);
            }
            while((num_tel<9999999)||(num_tel>100000000));
            Supprimer_cont(tab_cont,&taille_tab,num_tel);
            break;
        }
        case 7:
        {
            system("color 5A");
            Ajouter_cont(tab_cont,&taille_tab);
            break;
        }
        case 8:
        {
            system("color 0F");
            tri_cont(tab_cont,taille_tab);
            break ;
        }
        case 0:
        {
            fichier = fopen("Liste_des_contactes.txt","wt");
            if (fichier==NULL)
            {
                printf("\n ERREUR d'ouverture de fichier");
            }
            else
            {
                for(int i=0; i<taille_tab ; i++)
                {
                    fprintf(fichier,"%ld %s %s %ld %s %s %ld \n",tab_cont[i].num_tel,tab_cont[i].nom,tab_cont[i].prenom,tab_cont[i].ncin,tab_cont[i].adresse.rue,tab_cont[i].adresse.ville,tab_cont[i].adresse.code_postale);
                }
                fclose(fichier);
            }
            exit(0);
        }

        default:
            printf("\n\t\t\t\t\t\t\t ERREUR DE SAISIE :( \n\n");
        }
    }
    return 0;
}
