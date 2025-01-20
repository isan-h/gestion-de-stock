#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stock.h"


void ajouterProduit(Produit produits[], int *nbProduits) {
    if (*nbProduits >= MAX_PRODUITS) {
        printf("Limite de produits atteinte.\n");
        return;
    }

    Produit p;
    printf("Entrez les informations du produit :\n");
    printf("ID : "); scanf("%s", p.ID);
    printf("Nom : "); scanf("%s", p.nom);
    printf("Description : "); scanf("%s", p.description);
    printf("Utilisateur : "); scanf("%s", p.utilisateur);
    printf("Prix unitaire : "); scanf("%f", &p.prix_unitaire);
    printf("Quantité : "); scanf("%d", &p.quantite);
    printf("Seuil d'alerte : "); scanf("%d", &p.seuil_alerte);
    printf("Date d'entrée (JJ/MM/AAAA) : "); scanf("%d/%d/%d", &p.date_entree.j, &p.date_entree.m, &p.date_entree.an);
    printf("Date de sortie (JJ/MM/AAAA) : "); scanf("%d/%d/%d", &p.date_sortie.j, &p.date_sortie.m, &p.date_sortie.an);

    produits[*nbProduits] = p;
    (*nbProduits)++;
    printf("Produit ajouté avec succès.\n");
}

void modifierProduit(Produit produits[], int nbProduits) {
    char id[10];
    printf("Entrez l'ID du produit à modifier : ");
    scanf("%s", id);

    for (int i = 0; i < nbProduits; i++) {
        if (strcmp(produits[i].ID, id) == 0) {
            printf("Produit trouvé. Modifiez les informations :\n");
            printf("Nom (%s) : ", produits[i].nom); scanf("%s", produits[i].nom);
            printf("Description (%s) : ", produits[i].description); scanf("%s", produits[i].description);
            printf("Utilisateur (%s) : ", produits[i].utilisateur); scanf("%s", produits[i].utilisateur);
            printf("Prix unitaire (%.2f) : ", produits[i].prix_unitaire); scanf("%f", &produits[i].prix_unitaire);
            printf("Quantité (%d) : ", produits[i].quantite); scanf("%d", &produits[i].quantite);
            printf("Seuil d'alerte (%d) : ", produits[i].seuil_alerte); scanf("%d", &produits[i].seuil_alerte);
            printf("Date d'entrée (%02d/%02d/%04d) : ", produits[i].date_entree.j, produits[i].date_entree.m, produits[i].date_entree.an);
            scanf("%d/%d/%d", &produits[i].date_entree.j, &produits[i].date_entree.m, &produits[i].date_entree.an);
            printf("Date de sortie (%02d/%02d/%04d) : ", produits[i].date_sortie.j, produits[i].date_sortie.m, produits[i].date_sortie.an);
            scanf("%d/%d/%d", &produits[i].date_sortie.j, &produits[i].date_sortie.m, &produits[i].date_sortie.an);
            printf("Produit modifié avec succ�s.\n");
            return;
        }
    }
    printf("Produit avec ID %s introuvable.\n", id);
}

void supprimerProduit(Produit produits[], int *nbProduits) {
    char id[10];
    printf("Entrez l'ID du produit à supprimer : ");
    scanf("%s", id);

    for (int i = 0; i < *nbProduits; i++) {
        if (strcmp(produits[i].ID, id) == 0) {
            for (int j = i; j < (*nbProduits) - 1; j++) {
                produits[j] = produits[j + 1];
            }
            (*nbProduits)--;
            printf("Produit supprimé avec succ�s.\n");
            return;
        }
    }
    printf("Produit avec ID %s introuvable.\n", id);
}

void afficherProduits(Produit produits[], int nbProduits) {
    printf("\nListe des produits :\n");
    for (int i = 0; i < nbProduits; i++) {
        printf("ID: %s | Nom: %s | Utilisateur: %s | Prix: %.2f | Stock: %d\n",
               produits[i].ID, produits[i].nom, produits[i].utilisateur,
               produits[i].prix_unitaire, produits[i].quantite);
    }
}

void rechercherProduit(Produit produits[], int nbProduits) {
    int choix;
    printf("Rechercher par :\n1. Nom\n2. Utilisateur\nVotre choix : ");
    scanf("%d", &choix);

    if (choix == 1) {
        char nom[50];
        printf("Entrez le nom du produit : ");
        scanf("%s", nom);
        for (int i = 0; i < nbProduits; i++) {
            if (strcmp(produits[i].nom, nom) == 0) {
                printf("Produit trouvé : %s (ID: %s)\n", produits[i].nom, produits[i].ID);
                return;
            }
        }
        printf("Aucun produit trouvé avec ce nom.\n");
    } else if (choix == 2) {
        char utilisateur[50];
        printf("Entrez le nom de l'utilisateur : ");
        scanf("%s", utilisateur);
        for (int i = 0; i < nbProduits; i++) {
            if (strcmp(produits[i].utilisateur, utilisateur) == 0) {
                printf("Produit trouvé : %s (ID: %s)\n", produits[i].nom, produits[i].ID);
                return;
            }
        }
        printf("Aucun produit trouvé pour cet utilisateur.\n");
    } else {
        printf("Choix invalide.\n");
    }
}

void trierProduits(Produit produits[], int nbProduits) {
    int choix, i, j;
    Produit temp;

    printf("Trier par :\n1. Nom\n2. Prix unitaire\nVotre choix : ");
    scanf("%d", &choix);

    if (choix == 1) {
        for (i = 0; i < nbProduits - 1; i++) {
            for (j = i + 1; j < nbProduits; j++) {
                if (strcmp(produits[i].nom, produits[j].nom) > 0) {
                    temp = produits[i];
                    produits[i] = produits[j];
                    produits[j] = temp;
                }
            }
        }
        printf("Produits triés par nom.\n");
    } else if (choix == 2) {
        for (i = 0; i < nbProduits - 1; i++) {
            for (j = i + 1; j < nbProduits; j++) {
                if (produits[i].prix_unitaire > produits[j].prix_unitaire) {
                    temp = produits[i];
                    produits[i] = produits[j];
                    produits[j] = temp;
                }
            }
        }
        printf("Produits triés par prix unitaire.\n");
    } else {
        printf("Choix invalide.\n");
    }
}

void sauvegarderProduits(Produit produits[], int nbProduits, const char *fichier) {
    FILE *f = fopen(fichier, "a");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }
    fprintf(f, "ID,Nom,Description,Utilisateur,Prix,Quantite,Seuil,Entree,Sortie\n");
    for (int i = 0; i < nbProduits; i++) {
        fprintf(f, "%s,%s,%s,%s,%.2f,%d,%d,%02d/%02d/%04d,%02d/%02d/%04d\n",
                produits[i].ID, produits[i].nom, produits[i].description,
                produits[i].utilisateur, produits[i].prix_unitaire,
                produits[i].quantite, produits[i].seuil_alerte,
                produits[i].date_entree.j, produits[i].date_entree.m, produits[i].date_entree.an,
                produits[i].date_sortie.j, produits[i].date_sortie.m, produits[i].date_sortie.an);
    }
    fclose(f);
    printf("Donn�es sauvegard�es.\n");
}

void chargerProduits(Produit produits[], int *nbProduits, const char *fichier) {
    FILE *f = fopen(fichier, "r");
    if (f == NULL) {
        printf("Fichier introuvable. Aucun produit chargé.\n");
        return;
    }

    char header[200];
    fscanf(f, "%[^\n]\n", header);

    while (fscanf(f, "%[^,],%[^,],%[^,],%[^,],%f,%d,%d,%d/%d/%d,%d/%d/%d\n",
                  produits[*nbProduits].ID, produits[*nbProduits].nom,
                  produits[*nbProduits].description, produits[*nbProduits].utilisateur,
                  &produits[*nbProduits].prix_unitaire, &produits[*nbProduits].quantite,
                  &produits[*nbProduits].seuil_alerte,
                  &produits[*nbProduits].date_entree.j, &produits[*nbProduits].date_entree.m, &produits[*nbProduits].date_entree.an,
                  &produits[*nbProduits].date_sortie.j, &produits[*nbProduits].date_sortie.m, &produits[*nbProduits].date_sortie.an) == 13) {
        (*nbProduits)++;
    }

    fclose(f);
    printf("Données chargées.\n");
}
