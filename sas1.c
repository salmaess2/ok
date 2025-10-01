#include <stdio.h>
#include <string.h>

typedef struct {
    int idclient ;
    float solde;
    char nom[20];
    char prenom[20];
    char email[50];
  }client;
typedef struct{
   int idProduit;
   int stock;
   char nom[20];
   char categorie[50];
   float prix;
   char descriptions[100];
}produit;
int x=0;
int nbrProduits;
int choix;
int choix_saisie;
produit listP[4];  //  listProduits
void initProduits(){
    listP[0].idProduit=1;
    listP[0].stock=5;
    strcpy(listP[0].nom,"ordinateur")
    strcpy(listP[0].categorie,"electronique");
    listP[0].prix=799;
    strcpy(listProduits[0].descriptions, "pc portable gris");
    
    listP[1].idProduit=2;
    listP[1].stock=10;
    strcpy(listP[1].nom,"smartphone");
    strcpy(listP[1].categorie,"electronique");
    listP[1].prix=499;
    strcpy(listProduits[1].descriptions, "smartphone andruide");
    
    listP[2].idProduit=3;
    listP[2].stock=13;
    strcpy(listP[2].nom,"table");
    listP[2].prix=250;
    strcpy(listP[2].categorie,"fourniture");
    strcpy(listProduits[2].descriptions, "petite table en bois");

    listP[3].idProduit=4;
    listP[3].stock=12;
    strcpy(listP[3].nom,"chaise");
    listP[3].prix=500;
    strcpy(listP[3].categorie,"fournniture");
    strcpy(listProduits[3].descriptions, "chaise gamer pour ordinateur");

    
}
void menu(){
     printf("=== SYSTÈME D'ACHAT CLIENT ===");
     printf("\n1 Gestion du profil client\n");
     printf("2 Gestion du solde virtuel\n");
     printf("3  Consultation des produits\n");
     printf("4 Effectuer un achat\n");
     printf("5 Mes statistiques\n");
     printf("0 Quitter l'application\n");
     printf("saisir votre choix\n");
     scanf("%d",&choix);}
 
void creationProfil(){
   client c1;
  printf("===informations du client====\n");
  printf("saisir le nom:\n");
  scanf("%s",c1.nom);
  printf("saisir le prenom\n");
  scanf("%s", c1.prenom);
  printf("email: %s.%s@client.com\n", c1.nom,c1.prenom);
  
}
void modifierProfil (){
  int idAmodifier;
  printf("saisir id du client que vous vouler modifier");
  scanf("%d",&idAmodifier);
  for(int i=0;i<x;i++){
 if (idAmodifier==idclient) {
  printf("entrer le nouveau nom:\n");
  scanf("%s", c1.nom);
   printf("entrer le nouveau prenom");
   scanf("%s",c1.prenom);
 }}
}
void afficherProfil(){
    printf("===informations du client====\n");
    printf("%d\n",c1.idclient);
    printf("%s\n",c1.nom);
    printf("%s\n",c1.prenom);
    printf("%s\n",c1.email);
    printf("%s\n",c1.solde);
}

void afficherSolde(){
   c1.solde=0;
  printf("mantant diponible");
}
void depotArgent(){
   printf("saisir le solde");
   scanf("%f",c1.solde);
}

void verification(){
  
}
  
  
}
void consultationProduits(){
 
 
}
void afficherCatalogue(){
  printf("Liste des produits\n");
  printf
}
int main() {
	initProduits();
	do {
	  menu();
	    switch (choix) {
case 1 :
  printf("1.Creation de Profil\n");
  printf("2.Modification de Profil\n");
  printf("3.Afifichage de profile\n");
  printf("entrer votre choix:\n");
  scanf("%d",&choix);
  switch(choix_saisie){
    case 1 :
       creationProfil();
       break;
    case 2 :
       modifierProfil();
       break;
    case 3 : 
       afficherProfil();
       break;
  }
  
case 2 :
    printf("1.afficher solde");
    printf("2.depot d'argents");
    printf("3.verification");
    switch(choix_saisie){
    case 1 :
       afficherSolde();
       break;;
    case 2 :
       depotArgent();
       break;
    case 3 :
       verification();
       break;
  }
case 3 :
    printf("1.afficher le catalogue\n");
    printf("2.rechercher produit\n");
    printf("3.tri de produits\n");
    printf("4.Produits prédéfinis\n");
    switch(choix_saisie){
      
      
      
    }
case 4 :
    acheter();
    break;
case 5 :
    statistiques();
    break;
default :
    Quitter();
}while (choix!=0);
	  
   return 0;
}
