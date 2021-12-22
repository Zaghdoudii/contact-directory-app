#include<stdio.h>
#include"contact_tel.h"
#include<string.h>
#include <stdlib.h>
//--------------------------------------------------------------------------------------------
int test(char ch[])
{
    int s,i;
    s=0;
    for(i=0; i<strlen(ch); i++)
    {
        if(((ch[i]>='a')&&(ch[i]<='z'))||((ch[i]>='A')&&(ch[i]<='Z')))
            s=s+1;
    }
    if(s==strlen(ch))
        return 1;
    return -1;
}
/*cette fonction test si la chaine de caractere contien uniqument des lettre*/
//------------------------------------------------------------------------------------------
int Recherche_cont(cont tab[],int n,int num_tel)
{
    int i ;
    for (i=0 ; i<n ; i++)
    {
        if(tab[i].num_tel ==num_tel)
            return i ;
    }
    return -1 ;
}
/*cette fonction permet de  rechercher un contact telephonique par son numero*/
//--------------------------------------------------------------------------------------------
long int  saisie_num_tel()
{
    long int num_tel;
    do
    {
        printf("\n \t\t\t\t\t\t Taper le numero du telephone du  contact : ");
        scanf("%ld",&num_tel);
    }while((num_tel<9999999)||(num_tel>100000000));
    return num_tel;
}
//--------------------------------------------------------------------------------------------
cont saisie_cont()
{
    cont c;
    adr a;
    do
    {
        printf("\n \t\t\t\t\t\t Taper le nom du contact : ");
        fflush(stdin);
        gets(c.nom);
    }
    while(test(c.nom)!=1);
    do
    {
        printf("\n \t\t\t\t\t\t Taper le prenom du contact : ");
        fflush(stdin);
        gets(c.prenom);
    }
    while(test(c.prenom)!=1);
    do
    {
       printf("\n \t\t\t\t\t\t Taper le numero de cin : ");
       scanf("%ld",&c.ncin);
    }while((c.ncin<9999999)||(c.ncin>100000000));

    printf("\n \t\t\t\t\t\t Taper l'adresse du contact : \n");
    printf("\n    \t\t\t\t\t           * Rue : ");
    fflush(stdin);
    gets(a.rue);
    do
    {
        printf("\n    \t\t\t\t\t           * Ville : ");
        fflush(stdin);
        gets(a.ville);
    }while(test(a.ville)!=1);
    do
    {
        printf("\n    \t\t\t\t\t           * Code postale : ");
        scanf("%ld",&a.code_postale);
    }while((a.code_postale<999)||(a.code_postale>10000));

    c.adresse=a;
    return c;
}
/* cette fonction saisie un contact telephonique qui contien son nom,prenom,numero de telephone,le numero de carte d'identiter,et son adresse :rue ,ville,code postale*/
//--------------------------------------------------------------------------------------------
void affiche_cont(cont c)
{
    printf("\n\t\t\t\t\t\t\t Num de telephone : %ld",c.num_tel);
    printf("\n\t\t\t\t\t\t\t Nom : %s",c.nom );
    printf("\n\t\t\t\t\t\t\t Prenom : %s",c.prenom );
    printf("\n\t\t\t\t\t\t\t Num cin : %ld",c.ncin);
    printf("\n\t\t\t\t\t\t\t Adresse :");
    printf("\n\t\t\t\t\t\t\t\t Rue : %s",c.adresse.rue);
    printf("\n\t\t\t\t\t\t\t\t Ville : %s",c.adresse.ville);
    printf("\n\t\t\t\t\t\t\t\t Code postale : %ld",c.adresse.code_postale);

}
/*cette fonction affiche un contact telephonique */
//--------------------------------------------------------------------------------------------

void ajout_cont(cont tab[],int *n)
{
    cont c;
    int i=*n;
    long int tel,ntel;
    char rep[3];
    do
    {
        tel=saisie_num_tel();
        if (Recherche_cont(tab,*n+1,tel)!=-1)
        {
            printf(" \t\t\t\t\t\tCe contact existe, vouler vous modifier (Oui/Non) ? \n");
            scanf("%s",rep);
            if(strcmp(rep,"oui"))
            {
                do
                {
                    printf(" \t\t\t\t\t\t\t\tTaper un autre numero de telephone : ");
                    scanf("%ld",&ntel);
                }
                while(Recherche_cont(tab,*n,ntel)!=-1);
                c=saisie_cont();
                c.num_tel=ntel;
                tab[i]=c;
                i++;

            }
            else
                Modifier_cont(tab,*n+1,tel );

        }
        else
        {
            c=saisie_cont();
            c.num_tel=tel;
            tab[i]=c;
            i++;
        }
        printf("                    *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
        printf("\n\t\t\t\t\t              Voulez_vous ajouter un contact ? (Oui/Non) \n");
        printf("\t\t\t\t");
        scanf("%s",rep);
        system("cls");
        printf("                    *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*");
    }
    while (!strcmp(rep,"oui"));
    *n=i;
}/*cette fonction permet d'ajouter un contact*/
//--------------------------------------------------------------------------------------------
void affiche_tab_cont(cont tab[],int n)
{
    int i ;
    for(i=0; i<n; i++)
    {
        printf("\n\t\t\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
        affiche_cont(tab[i]) ;
    }
}/*cette fonction affiche tout le contact telephonique*/

//--------------------------------------------------------------------------------------------
int Recherche_nom_cont(cont tab[],int n,char*nom)
{
    int i ;
    for (i=0 ; i<n ; i++)
    {
        if(!strcmp(tab[i].nom,nom))
            return i ;
    }
    return -1 ;
}/*cette fonction permet de  rechercher un contact telephonique par son nom*/
//--------------------------------------------------------------------------------------------
void Ajouter_cont(cont tab[], int *n)
{
    cont c;
    char rep1[3];
    long int tel,ntel;
    tel=saisie_num_tel();
    if (Recherche_cont(tab,*n,tel)!=-1)
    {
        printf("Ce contact existe, vouler vous modifier (Oui/Non) ? \n");
        scanf("%s",rep1);
        if(strcmp(rep1,"oui"))
        {
            do
            {
                printf("Taper un autre numero : ");
                scanf("%ld",&ntel);
            }
            while(Recherche_cont(tab,*n,ntel)!=-1);
            c=saisie_cont();
            c.num_tel=ntel;
            tab[*n]=c;
            (*n)++;

        }
        else
            Modifier_cont(tab,*n,tel);

    }
    else
    {
        c=saisie_cont();
        c.num_tel=tel;
        tab[*n]=c;
        (*n)++;
    }


}/*cette fonction permet d'ajouter un contct telephonique */
//--------------------------------------------------------------------------------------------
void Modifier_cont(cont tab[],int n, int num_tel )
{
    int choix;
    long int nvcode_p,nvcin;
    char nvnom[20],nvprnom[20],nvrue[40],nvville[40];
    int rech=Recherche_cont(tab,n,num_tel);
    if (rech==-1)
        printf("\n\t\t\t\t      LE CONTACT QUE VOUS VOULEZ MODIFIER N'EXISTE PAS :( \n");
    else
    {
        printf("\n\t\t\t\t\t\t\t Que voulez vous modifier ? \n");
        printf("\n\t\t\t\t\t\t\t 1. Le nom \n");
        printf("\n\t\t\t\t\t\t\t 2. Le prenom \n");
        printf("\n\t\t\t\t\t\t\t 3. CIN  \n");
        printf("\n\t\t\t\t\t\t\t 4. Rue \n");
        printf("\n\t\t\t\t\t\t\t 5. Ville \n");
        printf("\n\t\t\t\t\t\t\t 6. Code postale  \n");
        printf("\n\t\t\t\t\t\t\t 0. Annuler \n");
        printf("\n\t\t\t\t\t\t\t\t  CHOIX : ");
        scanf("%d",&choix);
        switch(choix)
        {
        case 1:
        {
            printf("\t\t\t\t\t\t\tTaper le nouveau nom : ");
            scanf("%s",nvnom);
            strcpy(tab[rech].nom,nvnom);
            break;
        }
        case 2:
        {
            printf("\t\t\t\t\t\t\tTaper le nouveau prenom : ");
            scanf("%s",nvprnom);
            strcpy(tab[rech].prenom,nvprnom);
            break;
        }
        case 3:
        {
            printf("\t\t\t\t\t\t\tTaper le nouveau CIN : ");
            scanf("%ld",&nvcin);
            tab[rech].ncin=nvcin;
            break;
        }
        case 4:
        {
            printf("\t\t\t\t\t\t\tTaper le nouveau rue : ");
            scanf("%s",nvrue);
            strcpy(tab[rech].adresse.rue,nvrue);
            break ;
        }
        case 5:
        {
            printf("\n\t\t\t\t\t\t\tTaper la nouvelle ville : ");
            scanf("%s",nvville);
            strcpy(tab[rech].adresse.ville,nvville);
            break ;
        }
        case 6:
        {
            printf("\n\t\t\t\t\t\t\t Taper le nouveau code postal : ");
            scanf("%ld",&nvcode_p);
            tab[rech].adresse.code_postale=nvcode_p ;
            break ;
        }
        case 0:
        {
            break;
        }
        default:
            printf("\n\t\t\t\t\t\t\t\t CHOIX INVALIDE :) ");
        }
    }
}/* cette fonction permet de modifer les champ d'un contact telephonique*/
//--------------------------------------------------------------------------------------------
void Supprimer_cont(cont tab[],int*n,int num_tel)
{
    int i;
    int rech=Recherche_cont(tab,*n,num_tel);
    if (rech==-1)
        printf("Le contact que vous voulez supprimer n'existe pas :) ");
    else
    {
        for(i=rech; i<(*n)-1; i++)
        {
            tab[i]=tab[i+1];
        }
        (*n)--;
    }

}/*cette fonction permet de suppremer un contact*/
//--------------------------------------------------------------------------------------------
void tri_cont(cont tab[],int taille)
{
    cont temp;
    int i, j;
    for (i = 0; i < taille; i++)
        for (j = 0; j < taille; j++)
            if (strcmp(tab[i].nom,tab[j].nom)<0)
            {
                temp = tab[i];
                tab[i] = tab[j];
                tab[j] = temp;
            }
}/*cette fonction permet de trier les repartoir telephonique selon l'order alphabetique de son nom*/

