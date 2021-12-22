#ifndef CONTACT_TEL_H_INCLUDED
#define CONTACT_TEL_H_INCLUDED

//-----------------------------------------------------
typedef struct
{
    char rue[40];
    char ville[40];
    long int code_postale;

} adr;
//-----------------------------------------------------
typedef struct
{
    long int num_tel;
    long int ncin;
    char nom[26];
    char prenom[26];
    adr adresse;
} cont;
//----------------------------------------------------
int test(char ch[]);
int Recherche_cont(cont tab[],int n,int num_tel);
long int saisie_num_tel();
cont saisie_cont();
void affiche_cont(cont c);
void ajout_cont(cont tab[],int* n);
void affiche_tab_cont(cont tab[], int n);
int Recherche_nom_cont(cont tab[],int n,char *nom);
void Ajouter_cont(cont tab[], int *n);
void Modifier_cont(cont tab[],int n,int num_tel );
void Supprimer_cont(cont tab[],int*n,int num_tel);
void tri_cont(cont tab[],int taille);

#endif // CONTACT_TEL_H_INCLUDED
