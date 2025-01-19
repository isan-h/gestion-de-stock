#include <stdio.h>
#include <stdlib.h>
#include "stock.h"

int main() {
    Produit produits[MAX_PRODUITS];
    int nbProduits = 0;
    int choix;

    chargerProduits(produits, &nbProduits, "stock.csv");

    do {
        printf("\n--- Menu Principal ---\n");
        printf("1. Ajouter un produit\n");
        printf("2. Modifier un produit\n");
        printf("3. Supprimer un produit\n");
        printf("4. Afficher tous les produits\n");
        printf("5. Rechercher un produit\n");
        printf("6. Trier les produits\n");
        printf("7. Sauvegarder les produits\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajouterProduit(produits, &nbProduits); break;
            case 2: modifierProduit(produits, nbProduits); break;
            case 3: supprimerProduit(produits, &nbProduits); break;
            case 4: afficherProduits(produits, nbProduits); break;
            case 5: rechercherProduit(produits, nbProduits); break;
            case 6: trierProduits(produits, nbProduits); break;
            case 7: sauvegarderProduits(produits, nbProduits, "stock.csv"); break;
            case 0: printf("Au revoir !\n"); break;
            default: printf("Choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}
