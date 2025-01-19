# gestion-de-stock
Introduction
Ce rapport présente un programme de gestion de stock de produits développé en langage C. Le programme permet de gérer un ensemble de produits en offrant des fonctionnalités telles que l'ajout, la modification, la suppression, l'affichage, la recherche, le tri, la sauvegarde et le chargement des produits. Ce rapport explique en détail les structures de données utilisées, les fonctionnalités implémentées, les difficultés rencontrées et les solutions apportées.
Structures de Données

Le programme utilise deux structures principales pour gérer les produits et les dates 
Structure Date :
Cette structure stocke une date sous forme de jour, mois et année.
Elle est utilisée pour enregistrer les dates d'entrée et de sortie des produits.

Structure Produit :
Cette structure représente un produit avec les champs suivants :
ID : Identifiant unique du produit.
nom : Nom du produit.
description : Description du produit.
utilisateur : Nom de l'utilisateur associé au produit.
prix_unitaire : Prix unitaire du produit.
quantite : Quantité en stock.
seuil_alerte : Seuil d'alerte pour la quantité en stock.
date_entree : Date d'entrée du produit en stock.
date_sortie : Date de sortie du produit du stock.

Fonctionnalités Implémentées
Le programme offre les fonctionnalités suivantes :

Ajouter un produit :
Permet à l'utilisateur de saisir les informations d'un nouveau produit et de l'ajouter à la liste des produits.
Vérifie que la limite maximale de produits n'est pas dépassée.
Modifier un produit :
Permet de modifier les informations d'un produit existant en fonction de son ID.
Si le produit est trouvé, l'utilisateur peut modifier tous les champs.
Supprimer un produit :
Supprime un produit de la liste en fonction de son ID.
Déplace les produits suivants pour combler l'espace laissé par le produit supprimé.
Afficher tous les produits :
Affiche la liste de tous les produits enregistrés avec leurs informations principales (ID, nom, utilisateur, prix, quantité).
Rechercher un produit :
Permet de rechercher un produit par son nom ou par l'utilisateur associé.
Affiche les informations du produit si celui-ci est trouvé.
Trier les produits :
Trie les produits par nom ou par prix unitaire.
Utilise la fonction qsort pour effectuer le tri.
Sauvegarder les produits :
Sauvegarde la liste des produits dans un fichier CSV pour une utilisation ultérieure.
Le fichier contient une ligne par produit avec toutes ses informations.
Charger les produits :
Charge la liste des produits à partir d'un fichier CSV.
Permet de reprendre le travail là où il a été laissé.

Organisation du Code
Le code est organisé en trois fichiers principaux :
stock.h :
Contient les déclarations des structures et des fonctions.
Définit la constante MAX_PRODUITS pour limiter le nombre de produits.
stock.c :
Contient l'implémentation des fonctions pour gérer les produits.
Inclut des fonctions pour ajouter, modifier, supprimer, afficher, rechercher, trier, sauvegarder et charger les produits.
main.c :
Contient la fonction principale (main) qui gère le menu interactif.
Permet à l'utilisateur de choisir une opération à effectuer.

Difficultés Rencontrées et Solutions
Gestion des fichiers :
Problème : La lecture et l'écriture des fichiers CSV peuvent poser des problèmes si le format n'est pas respecté.
Solution : Utilisation de fscanf et fprintf avec des formats précis pour garantir que les données sont correctement lues et écrites.
Suppression d'un produit :
Problème : La suppression d'un produit nécessite de déplacer les produits suivants pour éviter les trous dans la liste.
Solution : Utilisation d'une boucle pour décaler les produits après la suppression.
Tri des produits :
Problème : Le tri nécessite une fonction de comparaison personnalisée.
Solution : Implémentation de fonctions de comparaison (comparerParNom et comparerParPrix) pour utiliser qsort.
Interface utilisateur :
Problème : L'interface doit être simple et intuitive pour l'utilisateur.
Solution : Création d'un menu interactif avec des options claires et des messages d'erreur explicites.

Améliorations Possibles
Validation des entrées :
Ajouter des vérifications pour s'assurer que les données saisies par l'utilisateur sont valides (par exemple, des dates valides, des prix positifs).
Gestion des erreurs :
Améliorer la gestion des erreurs pour les opérations sur les fichiers (par exemple, vérifier si le fichier existe avant de le charger).
Interface graphique :
Remplacer l'interface textuelle par une interface graphique pour une meilleure expérience utilisateur.
Gestion des catégories :
Ajouter la possibilité de catégoriser les produits pour une gestion plus fine du stock.

Conclusion
Ce programme de gestion de stock est une solution complète et fonctionnelle pour gérer un ensemble de produits. Il offre des fonctionnalités essentielles telles que l'ajout, la modification, la suppression, la recherche, le tri, la sauvegarde et le chargement des produits. Bien que le programme soit opérationnel, des améliorations peuvent être apportées pour le rendre plus robuste et convivial. Ce projet a permis de mettre en pratique les concepts de programmation en C, notamment la gestion des structures de données, des fichiers et des algorithmes de tri.
