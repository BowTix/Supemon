#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structs.h"

/**
 * @file main.c
 * @brief Fichier principal qui fait fonctionner le jeu
 * @author Enzo, Mathis et Tom
 * @version 1.0
 * @date 06/03/2024
 */

/** @brief Initialise le jeu entier
 *
*/
int main(){
    Player player;
    int choice;

    printf("BIENVENUE SUR SUPEMON !\n");
    printf("1. Nouvelle partie\n");
    printf("2. Charger partie\n");
    printf("Entrez votre choix : ");
    scanf("%d", &choice);

    // Vide le tampon d'entrée
    while (getchar() != '\n');

    switch(choice) {
        //Switch permettant au joueur de choisir une nouvelle partie ou une sauvegarde existante
        case 1:
            newGame(&player);
            break;
        case 2:
            //loadBackup(&player);
            break;
        default:
            //Si Choix invalide, envoie d'un message d'erreur
            printf("Choix invalide, merci de reessayer\n");
            return 1;
    }

    // Boucle principale du jeu
    while (1) {
        printf("\nOu voulez vous aller %s ?\n", player.name);
        printf("1. Hautes herbes\n");
        printf("2. Centre Supemon\n");
        printf("3. Boutique\n");
        printf("4. Quitter le jeu\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                battle(&player);
                break;
            case 2:
                centreSupemon(&player);
                break;
            case 3:
                shop(&player);
                break;
            case 4:
                //Case permettant au joueur de choisir si il veut sauvegarde ou non avant de quitter
                printf("\nVoulez-vous sauvegarder ?\n");
                printf("Entrez votre choix (oui/non) : ");
                char saveChoice[4];
                scanf("%s", saveChoice);
                if (strcmp(saveChoice, "oui") == 0) {
                    //saveBackup(player);
                    printf("\nPartie sauvegardee, au revoir !\n");
                } else if (strcmp(saveChoice, "non") == 0) {
                    printf("\nPartie non sauvegardee, au revoir !\n");
                } else {
                    printf("Choix invalide !\n");
                }
                return 0;
            default:
                printf("Choix invalide, merci de reessayer\n");
        }
    }

    return 0;
}
