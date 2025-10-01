#include <stdio.h>
#include <string.h>

typedef struct
{
    int idclient;
    float solde;
    char nom[20];
    char prenom[20];
    char email[50];
} Client;
Client client;

int idclient = 1;
typedef struct
{
    int idProduit;
    int stock;
    char nom[20];
    char categorie[50];
    float prix;
    char descriptions[100];
} produit;

int x = 0;
int choix;
int choix_saisie, choix3;
void menu()
{
    printf("=== SYSTE1ME D'ACHAT CLIENT ===");
    printf("\n1 Gestion du profil client\n");
    printf("2 Gestion du solde virtuel\n");
    printf("3  Consultation des produits\n");
    printf("4 Effectuer un achat\n");
    printf("5 Mes statistiques\n");
    printf("0 quitter\n");
    printf("saisir votre choix\n");
    scanf("%d", &choix);
}
produit listP[4];

void initProduits()
{
    listP[0].idProduit = 1;
    listP[0].stock = 5;
    strcpy(listP[0].nom, "ordinateur");
    strcpy(listP[0].categorie, "electronique");
    listP[0].prix = 799;
    strcpy(listP[0].descriptions, "pc portable gris");

    listP[1].idProduit = 2;
    listP[1].stock = 10;
    strcpy(listP[1].nom, "smartphone");
    strcpy(listP[1].categorie, "electronique");
    listP[1].prix = 499;
    strcpy(listP[1].descriptions, "smartphone andruide");

    listP[2].idProduit = 3;
    listP[2].stock = 13;
    strcpy(listP[2].nom, "table");
    listP[2].prix = 250;
    strcpy(listP[2].categorie, "fourniture");
    strcpy(listP[2].descriptions, "petite table en bois");

    listP[3].idProduit = 4;
    listP[3].stock = 12;
    strcpy(listP[3].nom, "chaise");
    listP[3].prix = 500;
    strcpy(listP[3].categorie, "fournniture");
    strcpy(listP[3].descriptions, "chaise gamer pour ordinateur");
}
// gestion de profil
void creationProfil()
{
    printf("===informations du client====\n");
    printf("saisir le nom:\n");
    scanf("%s", client.nom);
    printf("saisir le prenom\n");
    scanf("%s", client.prenom);
    client.idclient = idclient;
    idclient++;
    printf("email: %s.%s@client.com\n", client.nom, client.prenom);
}
void modifierProfil()
{
    printf("entrer le nouveau nom:\n");
    scanf("%s", client.nom);
    printf("entrer le nouveau prenom");
    scanf("%s", client.prenom);
}
void afficherProfil()
{
    printf("===informations du client====\n");
    printf("ID: %d\n", client.idclient);
    printf("nom: %s\n", client.nom);
    printf("prenom: %s\n", client.prenom);
    printf("email: %s.%s@client.com\n", client.nom, client.prenom);
    printf("solde: %f\n", client.solde);
}
// gestion solde
void afficherSolde()
{
    float solde_dispo = 0;

    printf("mantant diponible:%.2f+ %fDH", solde_dispo + client.solde);
}
void depotArgent()
{
    printf("saisir le solde");
    scanf("%f", &client.solde);
}

//Les produits
void afficherCatalogue(){
  printf("===Liste des produits===\n");
  for (int i=0; i<4; i++) {
  printf("produit: %s: %.2f: %d\n", listP[i].nom, listP[i].prix, listP[i].stock); }
}
int rechercherProduit_Nom(){
  char produitRech[50];
  int found =0, i;
  printf("saisir le produit que vous rechercher: ");
  scanf("%s",&produitRech);
  for(i=0; i<4; i++){
    if(!strcasecmp(produitRech,listP[i].nom))
   { printf("%d\n",listP[i].idProduit);
    printf("%d\n",listP[i].stock);
    printf("%s\n",listP[i].nom);
    printf("%.2f\n",listP[i].prix);
    printf("%s\n",listP[i].categorie);
    printf("%s\n",listP[i].descriptions); 
    found++;
    break;
  }
  }
  if (found)
    return listP[i].idProduit;
  return -1;
}
void rechercherProduit_categorie(){
    char categorieRech[50];
    int found=0, i;
    printf("saisir la categorie que vous rechercher: ");
    scanf("%s",&categorieRech);
    for(i=0; i<4; i++){
    if(!strcasecmp(categorieRech,listP[i].categorie))
   { printf("%d\n",listP[i].idProduit);
    printf("%d\n",listP[i].stock);
    printf("%s\n",listP[i].nom);
    printf("%f\n",listP[i].prix);
    printf("%s\n",listP[i].categorie);
    printf("%s\n",listP[i].descriptions); 
    found++;
    break;
  }
  }
}
void triPrixCroissant(){
    produit temp;
    for(int i=0; i<3;i++){
    for(int j=0;j<4-i-1;j++){
    if(listP[j].prix>listP[j+1].prix){

    temp = listP[j];
    listP[j] = listP[j+1];
    listP[j+1] = temp;    
   }
    }
}
}
void triPrixDecroissant(){
     produit temp;
  for(int i=0; i<3;i++){
    for(int j=0;j<4-i-1;j++)
    {
      if(listP[j].prix<listP[j+1].prix){

       temp = listP[j];
       listP[j] = listP[j+1];
       listP[j+1] = temp;    
      }
    }
   }
}
void verifierSolde(int id){
    int qu;
    float pay=0;
    printf("saisir quantite");
    scanf("%d",&qu);
    if(listP[id-1].prix <= client.solde && listP[id-1].stock>qu){
        printf("achat effectue avec succe");
        pay=pay+listP[id-1].prix*qu;
    }
     
   if(listP[id-1].prix > client.solde) 
     printf("solde insufisant");
   if (listP[id-1].stock>qu)
   printf("stock epuise");
}

//achat
void selectionProduit()
{
    int id;
    printf("ordinateur\n");
    printf("smartphone\n");
    printf("table\n");
    printf("chaise\n");

    id = rechercherProduit_Nom();
    verifierSolde(id);

}

int main()
{
    initProduits();
    do
    {
        menu();
        switch (choix)
        {
        case 1:
            do
            {
                printf("===gestion de profil===");
                printf("\n1.Creation de Profil\n");
                printf("2.Modification de Profil\n");
                printf("3.Affichage de profile\n");
                printf("0.Retour au menu\n");
                printf("entrer votre choix:\n");
                scanf("%d", &choix_saisie);

                switch (choix_saisie)
                {
                    do
                    {
                    case 1:
                        creationProfil();
                        break;
                    case 2:
                        modifierProfil();
                        break;
                    case 3:
                        afficherProfil();
                        break;
                    default:
                        printf("choix indisponible");
                        break;
                    } while (choix_saisie != 0);
                }
            } while (choix_saisie != 0);

        case 2:
            do
            {
                printf("===gestion solde===");
                printf("\n1.afficher solde\n");
                printf("2.depot d'argents\n");
                printf("entrer votre choix:\n");
                printf("0 retour au menu");
                scanf("%d", &choix_saisie);

                switch (choix_saisie)
                {
                case 1:
                    afficherSolde();
                    break;
                case 2:
                    depotArgent();
                    break;
                default:
                    printf("indisponible");
                    break;
                }
            } while (choix_saisie != 0);

        case 3:
        do{
            printf("1.afficher le catalogue\n");
            printf("2.rechercher produit par nom\n");
            printf("3.rechercher produit par categorie\n");
            printf("4.tri croissant\n");
            printf("5 tri decroissant\n");
            printf("entrer votre choix:\n");
            scanf("%d", &choix_saisie);
            switch (choix_saisie)
                {
                case 1:
                    afficherCatalogue();
                    break;
                case 2:
                    rechercherProduit_Nom();
                    break;
                case 3 :
                    rechercherProduit_categorie();
                    break;
                case 4 :
                   triPrixCroissant();
                    break;
                case 5 :
                   triPrixDecroissant();
                   break;
                default :
                   break;
                }
            } while (choix_saisie != 0);
        case 4 :
        selectionProduit();
        break;
        
        default:
        
            break;
        }
        


    } while (choix != 0);

    return 0;
}