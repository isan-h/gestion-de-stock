#ifndef STOCK_H
#define STOCK_H

#define MAX_PRODUITS 500

typedef struct {
    int j;
    int m;
    int an;
} Date;

typedef struct {
    char ID[10];
    char nom[50];
    char description[100];
    char utilisateur[50];
    float prix_unitaire;
    int quantite;
    int seuil_alerte;
    Date date_entree;
    Date date_sortie;
} Produit;

void ajouterProduit(Produit produits[], int *nbProduits);
void modifierProduit(Produit produits[], int nbProduits);
void supprimerProduit(Produit produits[], int *nbProduits);
void afficherProduits(Produit produits[], int nbProduits);
void rechercherProduit(Produit produits[], int nbProduits);
void trierProduits(Produit produits[], int nbProduits);

void sauvegarderProduits(Produit produits[], int nbProduits, const char *fichier);
void chargerProduits(Produit produits[], int *nbProduits, const char *fichier);

#endif
