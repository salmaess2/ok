#include <stdio.h>
 struct client 
 {
    int id ;
    float solde;
    char nom[20];
    char prenom[20];
    char email[50];
  };
typedef struct{
   int idProdui, stock;
   char nom[20];
   char categorie[50];
   float prix;
   char descriptions[100];
}produit;
produit listProduits[4];
int choix=0;
int i=0;
void initProduits(){
    listProduits[0].prix=799;
    strcpy(listProduits[0].nom,"ordinateur");
    strcpy(listProduits[0].categorie,"electronique");
    listProduits[0].idProdui=i;
    listProduits[1].prix=499;
    listProduits[1].idProdui=i;
    strcpy(listProduits[1].nom,"smartphone");
    srtcpy(listProduits[1].categorie,"ele");
    listProduits[2].prix
    listProduits[2].idP
}


void menu(){
     printf("____SYSTÈME D'ACHAT CLIENT____");
     printf("1 Gestion du profil client\n");
     printf("2 Gestion du solde virtuel");
     printf("3  Consultation des produits");
     printf("4 Effectuer un achat");
     printf("5 Mes statistiques");
     printf("0 Quitter l'application");
     }
void gestionProfil(){
    int clic=0;
    printf("1.creation de profil");
    printf("2.modification de profil");
    printf("3.consultation de profil");
    switch (clic)
    {
    case 1 :
        creationProfil();
        break;
    case 2 :
        modification();
        break;
    case 3 :
        consultation();
    default:
        break;
    }
}

 void creationProfil(){
   struct client c1;
  printf("saisir le nom\n");
  scanf("%s",c1.nom);
  printf("saisir le prenom");
  printf("%d", c1.id);
  printf("email: %s.%s@client.com\n", c1.nom,c1.prenom);
}
int main(){
    do {  
        menu();
    switch (choix)
{
case 1 :
    gestionProfil();
    break;
case 2 :
    gestionSolde();
    break;
case 3 :
    consultations();
    break;
}
} while (choix!=0);

return 0; 
}
void consultation(){
    initProduits();
    char nomRecherch[20];
    printf("rechercher un produit \n");
     scanf("%s",&nomRecherch);
}