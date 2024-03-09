#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structs.h"
/**
 * @file main.c
 * @brief Résumé du programme
 * @author Enzo, Mathis et Tom
 * @version 1.0
 * @date 06/03/2024
 */

Attack attacks[] = {
        //Initialisation des différentes attaques (dégats, augmentation de l'attaque, de la défense ou de l'esquive)
        {"Scratch", 3, 0, 0, 0},   // Scratch (Une attaque faisant 3 de dégats)
        {"Pound", 2, 0, 0, 0},      // Pound (dUne attaque faisant 2 de dégats)
        {"Grawl", 0, 1, 0, 0},      // Augmentation de l'attaque
        {"Foliage", 0, 0, 0, 1},    // Augmentation de l'esquive
        {"Shell", 0, 0, 1, 0},      // Augmentation de la defense
};

Item items[MAX_ITEMS] = {
        //Initialisation du prix et des effets des différents items
        {"Potion", 100, 50, 0, 5, 0},          // Potion: +5 HP
        {"Super Potion", 300, 150, 0, 10, 0},   // Super potion: +10 HP
        {"Super bonbon", 700, 350, 0, 0, 1}       // Rare candy: Ajoute un niveau au supemon
};

/** @brief Initialise le pseudo du joueur et les paramètres
 *
 *@param player Pointeur pointant vers la structure player
 *
*/
void initPlayer(Player *player) {
    // Demander le nom du joueur
    printf("\nEntrez votre pseudo : ");
    fgets(player->name, sizeof(player->name), stdin); //Sauvegarde du pseudo et vérification du max de caractères disponible
    player->name[strcspn(player->name, "\n")] = '\0'; // Supprimer le caractere de nouvelle ligne

    for (int i = 0; i < MAX_SUPEMONS; i++) {
        strcpy(player->supemons[i].name, "");
        player->supemons[i].level = 1;//Valeur par defaut pour le niveau
        player->supemons[i].experience = 0; // Valeur par defaut pour l'expérience
        player->supemons[i].hp = 0; // Valeur par defaut pour les points de vie
        player->supemons[i].max_hp = 0; // Valeur par defaut pour les points de vie maximum
        player->supemons[i].attack = 0; // Valeur par defaut pour l'attaque
        player->supemons[i].defense = 0; // Valeur par defaut pour la defense
        player->supemons[i].evasion = 0; // Valeur par defaut pour l'esquive
        player->supemons[i].accuracy = 0;// Valeur par defaut pour la précision
        player->supemons[i].speed = 0;// Valeur par defaut pour la vitesse
        // Moves
        player->supemons[i].moves[0] = NULL; // Placeholder pour l'attaque 1
        player->supemons[i].moves[1] = NULL; // Placeholder pour l'attaque 2
    }
    // Initialiser l'index du supemon selectionne a une valeur par defaut
    player->selected_supemon_index = 0;

    // Initialiser le nombre de Supcoins du joueur a une valeur par defaut
    player->supcoins = 1000; // Valeur par defaut pour les Supcoins

    // Initialiser les objets possedes par le joueur
    for (int i = 0; i < MAX_OWNED_ITEMS; i++) {
        strcpy(player->items_owned[i].name, items[i].name);
        player->items_owned[i].price = items[i].price;
        player->items_owned[i].selling_price = items[i].selling_price; // Fixer le prix de vente
        player->items_owned[i].quantity = 0; // Initialiser la quantite a zero
        player->items_owned[i].hp_increase = items[i].hp_increase;
        player->items_owned[i].level_increase = items[i].level_increase;
    }
}

/** @brief Initialise le choix que doit faire le joueur en debut de partie, Un choix entre les 3 starters disponible. Après ce choix on initialise les statistiques et attaques du supémon choisi
 *
 *@param player Pointeur pointant vers la structure player
 *
*/

void chooseStarter(Player *player) {
    //Initialiser le choix du starter
    int choice;
    int confirmation = 0;

    while (!confirmation) {
        //Initialisation d'une boucle permettant de choisir un des trois starters et de valider son choix
        printf("\nChoisissez votre starter :\n");
        printf("1. Supmander\n");
        printf("2. Supasaur\n");
        printf("3. Supirtle\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Initialisation (des stats et des attaques) du supemon choisi (Supmander) pour le joueur
                strcpy(player->supemons[0].name, "Supmander");
                player->supemons[0].level = 1;
                player->supemons[0].experience = 0;
                player->supemons[0].hp = 10;
                player->supemons[0].max_hp = 10;
                player->supemons[0].attack = 1;
                player->supemons[0].defense = 1;
                player->supemons[0].evasion = 1;
                player->supemons[0].accuracy = 2;
                player->supemons[0].speed = 1;
                // Moves
                player->supemons[0].moves[0] = &attacks[0]; // Scratch
                player->supemons[0].moves[1] = &attacks[2]; // Grawl
                player->supemons[0].maxexperience = 500;
                player->supemons[0].base_attack =1;
                player->supemons[0].base_defense=1;
                player->supemons[0].base_evasion=1;
                break;
            case 2:
                // Initialisation (des stats et des attaques) du supemon choisi (Supasaur) pour le joueur
                strcpy(player->supemons[0].name, "Supasaur");
                player->supemons[0].level = 1;
                player->supemons[0].experience = 0;
                player->supemons[0].hp = 9;
                player->supemons[0].max_hp = 9;
                player->supemons[0].attack = 1;
                player->supemons[0].defense = 1;
                player->supemons[0].evasion = 3;
                player->supemons[0].accuracy = 2;
                player->supemons[0].speed = 2;
                // Moves
                player->supemons[0].moves[0] = &attacks[1]; // Pound
                player->supemons[0].moves[1] = &attacks[3]; // Foliage
                player->supemons[0].maxexperience = 500;
                player->supemons[0].base_attack =1;
                player->supemons[0].base_defense=1;
                player->supemons[0].base_evasion=3;
                break;
            case 3:
                // Initialisation (des stats et des attaques) du supemon choisi (Suprirtle) pour le joueur
                strcpy(player->supemons[0].name, "Supirtle");
                player->supemons[0].level = 1;
                player->supemons[0].experience = 0;
                player->supemons[0].hp = 11;
                player->supemons[0].max_hp = 11;
                player->supemons[0].attack = 1;
                player->supemons[0].defense = 2;
                player->supemons[0].evasion = 2;
                player->supemons[0].accuracy = 1;
                player->supemons[0].speed = 2;
                // Moves
                player->supemons[0].moves[0] = &attacks[1]; // Pound
                player->supemons[0].moves[1] = &attacks[4]; // Shell
                player->supemons[0].maxexperience = 500;
                player->supemons[0].base_attack =1;
                player->supemons[0].base_defense=2;
                player->supemons[0].base_evasion=2;
                break;
            default:
                printf("Choix invalide.\n");
                continue; // Si le choix est invilide on demande au joueur de choisir a nouveau
        }

        printf("\nVous avez choisi %s. Confirmez-vous votre choix ? (oui/non) : ", player->supemons[0].name);
        char confirm[4];
        scanf("%3s", confirm);
        //Fonction permettant la confirmation ou non du choix
        if (strcmp(confirm, "oui") == 0) {
            printf("\nVous avez choisi %s !\n", player->supemons[0].name);
            confirmation = 1; // Sortir de la boucle
        } else if (strcmp(confirm, "non") == 0) {
            // Redemander au joueur de choisir a nouveau
            continue;
        } else {
            printf("Reponse invalide.\n");
            continue; // Redemander au joueur de confirmer a nouveau
        }
    }
}

/** @brief Initialisation d'une nouvelle partie
 *
 *@param player Pointeur pointant vers la structure player
 *
*/

void newGame(Player *player) {
    // Initialiser une nouvelle partie
    initPlayer(player);
    // Choisir un starter
    chooseStarter(player);
    // Creer un supemon de depart
}

/** @brief Initialisation du Centre Supemon, Centre Supemon permettant de soigner les supémons du joueur
 *
 *@param player Pointeur pointant vers la structure player
 *
*/

void centreSupemon(Player *player) {
    printf("\nBienvenue au Centre Supemon !\n");

    // Vérifie si tous les supemon du joueur sont en pleine forme
    int maxHealthy = 1;
    for (int i = 0; i < MAX_SUPEMONS; i++) {
        if (strlen(player->supemons[i].name) > 0 && player->supemons[i].hp < player->supemons[i].max_hp) {
            maxHealthy = 0;
            break;
        }
    }

    if (maxHealthy) {
        printf("\nTous vos supemons sont en formes.\n");//Si tous les supémons sont au maximum de le vie, affiche un texte
        return;
    }

    // Afficher les supemons du joueur avec leur indice
    printf("Supemons de %s :\n", player->name);
    for (int i = 0; i < MAX_SUPEMONS; i++) {
        if (strlen(player->supemons[i].name) > 0) {
            printf("%d. %s (HP: %d/%d)\n", i + 1, player->supemons[i].name, player->supemons[i].hp, player->supemons[i].max_hp);
        }
    }

    // Demander au joueur de choisir quel supemon il veut soigner
    int choice;
    printf("Entrez le numero du supemon que vous voulez soigner : ");
    scanf("%d", &choice);
    choice--; // Convertir de l'index 1-based a l'index 0-based

    // Verifier si le choix est valide
    if (choice < 0 || choice >= MAX_SUPEMONS || strlen(player->supemons[choice].name) == 0) {
        printf("Choix invalide.\n");
        return;
    }

    // Soigner le supemon choisi
    player->supemons[choice].hp = player->supemons[choice].max_hp;

    printf("\n%s a ete soigne avec succes !\n", player->supemons[choice].name);
}

/** @brief Initialisation de l'affichage des objets dans la boutique
 *
*/

void displayItems() {
    //Affiche la liste des objets disponible avec leur prix respectif
    printf("\nListe des objets disponibles :\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%d. %s - Prix: %d Supcoins\n", i + 1, items[i].name, items[i].price);
    }
}

/** @brief Initialisation du mode d'achat d'objet dans la boutique
 *
 *@param player Pointeur pointant vers la structure player
 *
*/


void buyMode(Player *player) {
    int choice;

    while (1) {
        displayItems();
        printf("\nArgent disponible : %d Supcoins\n", player->supcoins);//Affiche l'argent disponible que le joueur dispose
        printf("Entrez le numero de l'objet que vous voulez acheter (0 pour annuler) : ");//Demande au joueur quel objet il souhaite acheter
        scanf("%d", &choice);

        // Verifie si le joueur a choisi d'annuler l'achat
        if (choice == 0) {
            printf("Achat annule.\n");
            return;
        }

        choice--;

        // Verifie si le choix est valide
        if (choice < 0 || choice >= MAX_ITEMS) {
            printf("Choix invalide.\n");
            continue; // Redemande au joueur de choisir a nouveau
        }

        // Verifie si le joueur a suffisamment de Supcoins pour acheter l'objet
        if (player->supcoins < items[choice].price) {
            printf("\nVous n'avez pas assez de Supcoins pour acheter cet objet.\n");
            continue; // Redemande au joueur de choisir a nouveau
        }

        // Verifie si le joueur possede deja cet objet
        int i;
        for (i = 0; i < MAX_ITEMS; i++) {
            if (strcmp(player->items_owned[i].name, items[choice].name) == 0) {
                // L'objet est deja possede par le joueur, augmenter la quantite et mettre a jour le prix total
                player->items_owned[i].quantity++;
                player->supcoins -= items[choice].price;
                printf("\nVous avez achete 1 %s supplementaire pour %d Supcoins.\n", items[choice].name, items[choice].price);
                return;
            } else if (player->items_owned[i].name[0] == '\0') {
                // S'il y a un emplacement vide, acheter l'objet et deduire le prix des Supcoins du joueur
                printf("\nVous avez achete %s pour %d Supcoins.\n", items[choice].name, items[choice].price);
                player->supcoins -= items[choice].price;
                strcpy(player->items_owned[i].name, items[choice].name);
                player->items_owned[i].price = items[choice].price;
                player->items_owned[i].quantity = 1;
                // Applique les effets de l'objet (a implementer)
                return;
            }
        }

        // Si on arrive ici, le joueur ne peut pas acheter plus d'objets
        printf("Vous n'avez plus de place. Vendez des objets pour liberer de l'espace.\n");
        return;
    }
}

/** @brief Initialisation du mode de vente d'objet dans la boutique
 *
 *@param player Pointeur pointant vers la structure player
 *
*/

void sellMode(Player *player) {
    int choice;

    while (1) {
        //Affiche la liste des objets que le joueur possède
        printf("\nObjets que vous possedez :\n");
        for (int i = 0; i < MAX_OWNED_ITEMS; i++) {
            if (player->items_owned[i].quantity > 0) {
                printf("%d. %s - Quantite : %d - Prix de vente : %d Supcoins\n", i + 1, player->items_owned[i].name, player->items_owned[i].quantity, player->items_owned[i].selling_price);
            }
        }
        //Demande au joueur quel objet il souhaite vendre
        printf("\nArgent disponible : %d Supcoins\n", player->supcoins);
        printf("Entrez le numero de l'objet que vous voulez vendre (0 pour annuler) : ");
        scanf("%d", &choice);

        // Verifie si le joueur a choisi d'annuler la vente
        if (choice == 0) {
            printf("\nVente annulee.\n");
            return;
        }

        choice--;

        // Verifie si le choix est valide
        if (choice < 0 || choice >= MAX_OWNED_ITEMS || strlen(player->items_owned[choice].name) == 0) {
            printf("\nChoix invalide.\n");
            continue; // Redemander au joueur de choisir a nouveau
        }

        // Ajoute le prix de vente de l'objet aux Supcoins du joueur
        printf("\nVous avez vendu %s pour %d Supcoins.\n", player->items_owned[choice].name, player->items_owned[choice].selling_price);
        player->supcoins += player->items_owned[choice].selling_price;

        // Reduire la quantite de l'objet possede par le joueur
        player->items_owned[choice].quantity--;

        // Si la quantite devient 0, supprime l'objet de la liste des objets possedes
        if (player->items_owned[choice].quantity == 0) {
            strcpy(player->items_owned[choice].name, "");
        }

        return;
    }
}

/** @brief Fonction principale du magasin, Initialisation de la boutique du jeu
 *
 *@param player Pointeur pointant vers la structure player
 *
*/

void shop(Player *player) {
    int mode;
    do {
        //Initialisation de l'arrivé au magasin et proposition des différentes actions dans le magasin
        printf("\nBienvenue au Magasin ! Que souhaitez-vous faire ?\n");
        printf("1. Acheter\n");
        printf("2. Vendre\n");
        printf("3. Quitter le magasin\n");
        printf("Entrez votre choix : ");
        scanf("%d", &mode);

        switch (mode) {
            case 1:
                buyMode(player);
                break;
            case 2:
                sellMode(player);
                break;
            case 3:
                printf("\nMerci d'avoir visite le Magasin !\n");
                return;
            default:
                printf("\nChoix invalide.\n");
                break;
        }
    } while (mode != 0);
}

/** @brief Initialisation de la fonction permettant de choisir un objet que le joueur possède dans son inventaire
 *
 *@param player Pointeur pointant vers la structure player
 *
*/

int chooseItem(Player *player) {
    //Affiche la liste des objets que le joueur possède
    printf("\nObjets que vous possedez :\n");
    for (int i = 0; i < MAX_OWNED_ITEMS; i++) {
        if (player->items_owned[i].quantity > 0) {
            printf("%d. %s - Quantite : %d\n", i + 1, player->items_owned[i].name, player->items_owned[i].quantity);
        }
    }

    //Initialisation de la demande au joueur pour utiliser un objet,
    int choice;
    printf("\nChoisissez un objet en entrant son numero (0 pour annuler) : ");
    scanf("%d", &choice);

    //Si choix invalide, affiche une erreur
    if (choice < 0 || choice > MAX_OWNED_ITEMS) {
        printf("Choix invalide.\n");
        return -1;
    }

    return choice - 1;
}

/** @brief Initialisation du choix de l'attaque d'un supemon
 *
 *@param supemon Pointeur pointant vers la structure supemon
 *
*/

int chooseAttack(Supemon *supemon) {
    int choice;

    // Affiche les noms des attaques du Supemon avec leur indice correspondants
    printf("\nChoisissez une attaque !\n");
    for (int i = 0; i < 2; i++) {
        printf("%d. %s\n", i + 1, supemon->moves[i]->name);
    }

    // Demande au joueur de choisir une attaque
    printf("Entrez votre choix : ");
    scanf("%d", &choice);

    // Verifie si le choix est valide
    if (choice < 1 || choice > 2) {
        printf("Choix invalide. Veuillez choisir une attaque valide.\n");
        return chooseAttack(supemon); // Redemander au joueur de choisir une attaque valide
    }

    // Retourne l'indice de l'attaque choisie
    return choice - 1; // Soustrait 1 car les indices commencent a 0 dans le liste des attaques
}

/** @brief Initialisation d'un supemon sauvage quand le joueur va dans les hautes herbes
 *
 * @param player Pointeur pointant vers la structure player
 * @param supemon Pointeur pointant vers la structure supemon
 * @param supemonIndex Initialisation d'un index pour le supemon
 *
*/

void initWildSupemon(Player *player, Supemon *supemon, int supemonIndex) {
    supemon->level = player->supemons[player->selected_supemon_index].level;
    // Initialise les attaques du Supemon sauvage en fonction de son index
    switch (supemonIndex) {
        case 0: // Supmander
            supemon->moves[0] = &attacks[0];
            supemon->moves[1] = &attacks[2];
            break;
        case 1: // Supasaur
            supemon->moves[0] = &attacks[1];
            supemon->moves[1] = &attacks[3];
            break;
        case 2: // Supirtle
            supemon->moves[0] = &attacks[1];
            supemon->moves[1] = &attacks[4];
            break;
        case 3: // Supriczhosar
            supemon->moves[0] = &attacks[2];
            supemon->moves[1] = &attacks[4];
            break;
        case 4: // Supmagocobot
            supemon->moves[0] = &attacks[0];
            supemon->moves[1] = &attacks[3];
            break;
        case 5: // Superhulham
            supemon->moves[0] = &attacks[1];
            supemon->moves[1] = &attacks[2];
            break;
        default:
            break;
    }
}

double arrondiAleatoire (double nombre) {
    // Generer un nombre aleatoire entre 0 et 1
    double rand_num = (double)rand() / RAND_MAX;

    // 50% de chances d'arrondir au-dessus et 50% de chances d'arrondir en dessous
    if (rand_num < 0.5) {
        return floor(nombre); // Arrondir a l'entier inferieur
    } else {
        return ceil(nombre); // Arrondir a l'entier superieur
    }
}

void applyStatBoost(Supemon *supemon, Attack *attack) {
    // Vérifier s'il y a une augmentation de l'attaque
    if (attack->attack_boost > 0) {
        supemon->attack += attack->attack_boost;
        printf("\n%s utilise %s et augmente son attaque !\n", supemon->name, attack->name);
    }

    // Vérifier s'il y a une augmentation de la défense
    if (attack->defense_boost > 0) {
        supemon->defense += attack->defense_boost;
        printf("\n%s utilise %s et augmente sa defense !\n", supemon->name, attack->name);
    }

    // Vérifier s'il y a une augmentation de l'évasion
    if (attack->evasion_boost > 0) {
        supemon->evasion += attack->evasion_boost;
        printf("\n%s utilise %s et augmente son evasion !\n", supemon->name, attack->name);
    }
}

void resetStats(Supemon *supemon) {
    // Réinitialiser les statistiques du supemon à leurs valeurs de base
    supemon->attack = supemon->base_attack;
    supemon->defense = supemon->base_defense;
    supemon->evasion = supemon->base_evasion;
}

void battle(Player *player) {
    // Declaration et initialisation du tableau supemons
    Supemon supemons[] = {
            {"Supmander", 1, 1, 10, 10, 1, 1, 2, 1, 1, {{&attacks[0], &attacks[1]}}, 1, 1, 2},  // Supmander (Scratch, Grawl)
            {"Supasaur",  1, 1, 9,  9,  1, 1, 3, 2, 2, {{&attacks[2], &attacks[3]}}, 1, 1, 3},      // Supasaur (Grawl, Foliage)
            {"Supirtle",  1, 1, 11, 11, 1, 2, 2, 1, 2, {{&attacks[1], &attacks[4]}}, 1, 2, 2},     // Supirtle (Pound, Shell)
            {"Supriczhosar",  1, 1, 18, 18, 3, 2, 1, 6, 5, {{&attacks[2], &attacks[4]}}, 3, 2, 1}, //Supriczhosar (Pound, Foliage)
            {"Supmagocobot",  1, 1, 13, 13, 1, 1, 2, 3, 1, {{&attacks[0], &attacks[3]}}, 1, 1, 2}, //Supmagocobot (Scratch, Grawl
            {"Superhulham",1, 1, 15, 15, 2, 2, 1, 2, 3, {{&attacks[1], &attacks[2]}}, 2, 2, 1}, //Superhulham (Pound, Grawl)
    };

    // Initialiser le generateur de nombres aleatoires
    srand(time(NULL));

    // Generer un indice aleatoire pour choisir un supemon sauvage
    int randomIndex = rand() % 6;

    // Recuperer le supemon sauvage correspondant a l'indice aleatoire
    Supemon *wildSupemon = &supemons[randomIndex];

    // Initialiser les attaques du Supemon sauvage en fonction de son index
    initWildSupemon(player ,wildSupemon, randomIndex);

    double levelMultiplier = 1 + (wildSupemon->level - 1) * 0.3; // Chaque niveau augmente les stats de 30%

    // Mise a jour des statistiques du supemon sauvage en fonction du coefficient
    wildSupemon->max_hp = arrondiAleatoire(wildSupemon->max_hp * levelMultiplier);
    wildSupemon->hp = wildSupemon->max_hp;
    wildSupemon->attack = arrondiAleatoire(wildSupemon->attack * levelMultiplier);
    wildSupemon->defense = arrondiAleatoire(wildSupemon->defense * levelMultiplier);
    wildSupemon->evasion = arrondiAleatoire(wildSupemon->evasion * levelMultiplier);
    wildSupemon->accuracy = arrondiAleatoire(wildSupemon->accuracy * levelMultiplier);
    wildSupemon->speed = arrondiAleatoire(wildSupemon->speed * levelMultiplier);

    // Afficher un message pour annoncer la rencontre avec le supemon sauvage
    printf("\nUn %s sauvage de niveau %d apparait !\n", wildSupemon->name, wildSupemon->level);

    // Declaration de la variable attackChoice en dehors du switch
    int attackChoice;

    // Boucle de la bataille
    while (wildSupemon->hp > 0) {
        // Afficher les options de l'attaque
        printf("\n%s sauvage (niveau %d) : %d/%d hp\n",wildSupemon->name,wildSupemon->level,wildSupemon->hp,wildSupemon->max_hp);
        printf("Attaque : %d   Defence : %d \nPresision : %d   Vitesse : %d\n",wildSupemon->attack,wildSupemon->defense,wildSupemon->accuracy,wildSupemon->speed);
        printf("\nVotre %s (niveau %d) : %d/%d hp\n",player->supemons[player->selected_supemon_index].name,player->supemons[player->selected_supemon_index].level,player->supemons[player->selected_supemon_index].hp,player->supemons[player->selected_supemon_index].max_hp);
        printf("Attaque : %d   Defence : %d \nPresision : %d   Vitesse : %d\n",player->supemons[player->selected_supemon_index].attack,player->supemons[player->selected_supemon_index].defense,player->supemons[player->selected_supemon_index].accuracy,player->supemons[player->selected_supemon_index].speed);
        printf("\nQue voulez-vous faire ?\n");
        printf("1. Attaquer\n");
        printf("2. Changer de supemon\n");
        printf("3. Utiliser un objet\n");
        printf("4. Capturer\n");
        printf("5. S'enfuir\n");
        printf("Entrez votre choix : ");

        // Deplacer la lecture de l'entree utilisateur en dehors du switch
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Attaquer
                // Choix de l'attaque
                attackChoice = chooseAttack(&player->supemons[player->selected_supemon_index]);

                // Exécuter l'attaque du joueur
                if (attackChoice >= 0 && attackChoice < 2) {
                    // Vérifier si l'attaque est une attaque d'augmentation de statistiques
                    if (player->supemons[player->selected_supemon_index].moves[attackChoice]->attack_boost > 0 ||
                        player->supemons[player->selected_supemon_index].moves[attackChoice]->defense_boost > 0 ||
                        player->supemons[player->selected_supemon_index].moves[attackChoice]->evasion_boost > 0) {
                        // Appliquer les effets des attaques d'augmentation de statistiques
                        applyStatBoost(&player->supemons[player->selected_supemon_index], player->supemons[player->selected_supemon_index].moves[attackChoice]);
                    } else {
                        float tempEvasion = (player->supemons[player->selected_supemon_index].accuracy + wildSupemon->evasion);
                        double evasionProbability = ((double) (player->supemons[player->selected_supemon_index].accuracy/ tempEvasion)+0.1);
                        // Génère un nombre en 0 et 1
                        double random = (double) rand() / RAND_MAX;
                        // Si le nombre aléatoire est inférieur ou égal à la probabilité d'évasion, alors le supémon attaque
                        if (random <= evasionProbability) {
                            int damage = arrondiAleatoire((player->supemons[player->selected_supemon_index].attack*player->supemons[player->selected_supemon_index].moves[attackChoice]->damage)/wildSupemon->defense);
                            // Afficher les details de l'attaque
                            printf("\n%s utilise %s et inflige %d degats !\n", player->supemons[player->selected_supemon_index].name, player->supemons[player->selected_supemon_index].moves[attackChoice]->name, damage);
                            // Reduire les points de vie du supemon sauvage
                            wildSupemon->hp -= damage;
                        }   else{
                            //Si le nombre aléatoire est supérieur à la probabilité d'évasion, alors le supémon sauvage esquive
                            printf("\n%s a esquive l attaque %s\n",wildSupemon->name, player->supemons[player->selected_supemon_index].moves[attackChoice]);
                        }
                    }
                } else {
                    printf("\nChoix invalide. Essayez à nouveau.\n");
                }

                // Attaque du supemon sauvage en retour
                int wildAttackIndex = rand() % 2; // Choisir une attaque aleatoire du supemon sauvage
                if (wildSupemon->moves[wildAttackIndex]->attack_boost > 0 ||
                    wildSupemon->moves[wildAttackIndex]->defense_boost > 0 ||
                    wildSupemon->moves[wildAttackIndex]->evasion_boost > 0) {
                    // Appliquer les effets des attaques d'augmentation de statistiques
                    applyStatBoost(wildSupemon, wildSupemon->moves[wildAttackIndex]);
                } else {
                    float temp = (wildSupemon->accuracy + player->supemons[player->selected_supemon_index].evasion);
                    double evasionProbability = ((double) (wildSupemon->accuracy/ temp)+0.1);
                    // Génère un nombre en 0 et 1
                    double random = (double) rand() / RAND_MAX;
                    // Si le nombre aléatoire est inférieur ou égal à la probabilité d'évasion, alors le supémon attaque
                    if (random <= evasionProbability) {
                        int wildDamage = arrondiAleatoire(
                                (wildSupemon->attack * wildSupemon->moves[wildAttackIndex]->damage) /
                                player->supemons[player->selected_supemon_index].defense);
                        // Affiche les details de l'attaque
                        printf("\nLe %s sauvage utilise %s et inflige %d degats !\n", wildSupemon->name,
                               wildSupemon->moves[wildAttackIndex]->name, wildDamage);
                        // Reduit les points de vie du supemon du joueur
                        player->supemons[player->selected_supemon_index].hp -= wildDamage;
                    }else{
                        //Si le nombre aléatoire est supérieur à la probabilité d'évasion, alors le supémon du joueur esquive
                        printf("\n%s a esquive l'attaque %s\n", player->supemons[player->selected_supemon_index].name, wildSupemon->moves[wildAttackIndex]->name);
                    }
                }

                // Verifier si le supemon du joueur a ete vaincu
                if (player->supemons[player->selected_supemon_index].hp <= 0) {
                    printf("\nVotre %s a ete vaincu !\nVous avez couru au centre supemon le plus proche.", player->supemons[player->selected_supemon_index].name);
                    resetStats(&player->supemons[player->selected_supemon_index]);
                    player->supemons[player->selected_supemon_index].hp = player->supemons[player->selected_supemon_index].max_hp;
                    return;
                }
                break;

            case 2: // Changer de Supemon
                // Verifier si le joueur a plus d'un Supemon
                if (player->selected_supemon_index == 0) {
                    printf("\nVous n'avez qu'un seul Supemon. Vous ne pouvez pas changer.\n");
                    break;
                }

                // Selectionner un nouveau Supemon
                printf("Changer de Supemon :\n");
                for (int i = 0; i < MAX_SUPEMONS; i++) {
                    if (strlen(player->supemons[i].name) > 0) {
                        printf("%d. %s (HP: %d/%d)\n", i + 1, player->supemons[i].name, player->supemons[i].hp, player->supemons[i].max_hp);
                    }
                }
                printf("Entrez le numero du Supemon : ");
                int newSupemonIndex;
                scanf("%d", &newSupemonIndex);
                newSupemonIndex--;

                // Verifier si l'index saisi est valide
                if (newSupemonIndex < 0 || newSupemonIndex >= player->selected_supemon_index) {
                    printf("Index de Supemon invalide.\n");
                } else {
                    // Changer de Supemon
                    player->selected_supemon_index = newSupemonIndex;
                    printf("Vous avez choisi %s.\n", player->supemons[newSupemonIndex].name);
                }
                break;


            case 3: // Utiliser un objet
            {
                int itemChoice;
                printf("\nObjets que vous possedez :\n");
                for (int i=0; i < MAX_ITEMS; i++){
                    printf("%d. %s - Quantite : %d\n", i + 1, player->items_owned[i].name, player->items_owned[i].quantity);
                }
                printf("Choisissez un objet :");
                scanf("%d", &itemChoice);
                switch (itemChoice){
                    case 1:
                        if (player->items_owned[0].quantity > 0){
                            if ((player->supemons[player->selected_supemon_index].hp + 5) > player->supemons[player->selected_supemon_index].max_hp){
                                player->supemons[player->selected_supemon_index].hp = player->supemons[player->selected_supemon_index].max_hp;
                                player->items_owned[0].quantity--;
                            } else{
                                player->supemons[player->selected_supemon_index].hp += 5;
                                player->items_owned[0].quantity--;
                            }
                            printf("\nVous avez utilise 1 Potion\n");
                        } else {
                            printf("\nVous n'avez pas de Potion.\n");
                        }
                        break;

                    case 2:
                        if (player->items_owned[1].quantity > 0){
                            if ((player->supemons[player->selected_supemon_index].hp + 10) > player->supemons[player->selected_supemon_index].max_hp){
                                player->supemons[player->selected_supemon_index].hp = player->supemons[player->selected_supemon_index].max_hp;
                                player->items_owned[1].quantity--;
                            } else{
                                player->supemons[player->selected_supemon_index].hp += 10;
                                player->items_owned[1].quantity--;
                            }
                            printf("\nVous avez utilise 1 Super Potion\n");
                        } else {
                            printf("\nVous n'avez pas de Super Potion.\n");
                        }
                        break;

                    case 3:
                        if (player->items_owned[2].quantity > 0){
                            printf("\nVous avez utilise 1 Super Bonbon\n");
                            player->items_owned[2].quantity--;
                            player->supemons[player->selected_supemon_index].maxexperience += 1000;
                            player->supemons[player->selected_supemon_index].level++;
                            player->supemons[player->selected_supemon_index].experience = 0;
                            player->supemons[player->selected_supemon_index].hp = arrondiAleatoire(player->supemons[0].hp * 1.3);
                            player->supemons[player->selected_supemon_index].max_hp = arrondiAleatoire(player->supemons[0].max_hp * 1.3);
                            player->supemons[player->selected_supemon_index].attack = arrondiAleatoire(player->supemons[0].attack * 1.3);
                            player->supemons[player->selected_supemon_index].defense = arrondiAleatoire(player->supemons[0].defense * 1.3);
                            player->supemons[player->selected_supemon_index].evasion = arrondiAleatoire(player->supemons[0].evasion * 1.3);
                            player->supemons[player->selected_supemon_index].accuracy = arrondiAleatoire(player->supemons[0].accuracy * 1.3);
                            player->supemons[player->selected_supemon_index].speed = arrondiAleatoire(player->supemons[0].speed * 1.3);
                            printf("%s passe au niveau %d", player->supemons[player->selected_supemon_index].name, player->supemons[player->selected_supemon_index].level);
                        } else {
                            printf("\nVous n'avez pas de Super Bonbon.\n");
                        }
                        break;
                }
                break;
            }

            case 4: // Capturer Supemon
            {
                // Calculate the capture probability
                double captureProbability = ((double) (wildSupemon->max_hp - wildSupemon->hp)) / (wildSupemon->max_hp - 0.5);

                // Generate a random number between 0 and 1
                double random = (double) rand() / RAND_MAX;

                // If the random number is less than or equal to the capture probability, capture succeeds
                if (random <= captureProbability) {
                    // Add a clone of the enemy supemon to the player's supemons list
                    for (int i = 0; i < MAX_SUPEMONS; ++i) {
                        if (strlen(player->supemons[i].name) == 0) {
                            // Clone the enemy supemon
                            strcpy(player->supemons[i].name, wildSupemon->name);
                            player->supemons[i].level = wildSupemon->level;
                            player->supemons[i].experience = wildSupemon->experience;
                            player->supemons[i].hp = wildSupemon->hp;
                            player->supemons[i].max_hp = wildSupemon->max_hp;
                            player->supemons[i].attack = wildSupemon->attack;
                            player->supemons[i].defense = wildSupemon->defense;
                            player->supemons[i].evasion = wildSupemon->evasion;
                            player->supemons[i].accuracy = wildSupemon->accuracy;
                            player->supemons[i].speed = wildSupemon->speed;
                            player->supemons[i].moves[0] = wildSupemon->moves[0];
                            player->supemons[i].moves[1] = wildSupemon->moves[1];
                            player->supemons[i].maxexperience = wildSupemon->maxexperience;
                            break;
                        }
                    }
                    printf("\nVous avez capture un %s sauvage de niveau %d !\n", player->supemons[1].name, player->supemons[1].level);
                    player->selected_supemon_index++;
                    // End the battle (player wins)
                    return;
                } else {
                    printf("\nLa tentative de capture a echoue ! Le %s sauvage est ressorti.\n", wildSupemon->name);
                }
                break;
            }

            case 5: // S'enfuir
            {
                // Calculer la probabilite de fuite
                double escapeProbability = (double)player->supemons[player->selected_supemon_index].speed / (player->supemons[player->selected_supemon_index].speed + wildSupemon->speed);

                // Generer un nombre aleatoire entre 0 et 1
                double random = (double)rand() / RAND_MAX;

                if (random <= escapeProbability) {
                    // Message de fuite reussie
                    printf("\nVous vous etes enfui du combat !\n");
                    resetStats(&player->supemons[player->selected_supemon_index]);
                    // Actions a effectuer en cas de fuite (a implementer)
                    return;
                } else {
                    // Message de tentative de fuite echouee
                    printf("\nLa tentative de fuite a echoue !\n");
                    // Actions a effectuer en cas d'echec de la fuite (a implementer)
                    break;
                }
            }

            default:
                printf("Choix invalide.\n");
                break;
        }
    }
    // Le combat se termine lorsque le supemon sauvage est vaincu
    printf("\nLe %s sauvage a ete vaincu !\n", wildSupemon->name);
    resetStats(wildSupemon);
    int randomCoins = rand() % (500 - 100 + 1) + 100;
    player->supcoins += randomCoins;
    printf("Vous avez gagne %d supcoins ", randomCoins);

    // Calculer l'expérience gagnée en fonction du niveau du supemon sauvage
    int minXP = 100 * wildSupemon->level;
    int maxXP = 500 * wildSupemon->level;
    int randomXp = rand() % (maxXP - minXP + 1) + minXP;

    player->supemons[0].experience += randomXp;
    printf("et vous avez gagne %d xp !\n", randomXp);


    if (player->supemons[0].experience > player->supemons[0].maxexperience) {
        player->supemons[0].maxexperience += 1000;
        player->supemons[0].level++;
        player->supemons[0].experience = 0;
        player->supemons[0].hp = arrondiAleatoire(player->supemons[0].hp * 1.3);
        player->supemons[0].max_hp = arrondiAleatoire(player->supemons[0].max_hp * 1.3);
        player->supemons[0].attack = arrondiAleatoire(player->supemons[0].attack * 1.3);
        player->supemons[0].defense = arrondiAleatoire(player->supemons[0].defense * 1.3);
        player->supemons[0].evasion = arrondiAleatoire(player->supemons[0].evasion * 1.3);
        player->supemons[0].accuracy = arrondiAleatoire(player->supemons[0].accuracy * 1.3);
        player->supemons[0].speed = arrondiAleatoire(player->supemons[0].speed * 1.3);
        printf("\nVotre %s est monte au niveau %d\n", player->supemons[0].name, player->supemons[0].level);
    }

    for (int i = 0; i < MAX_SUPEMONS; i++) {
        if (strlen(player->supemons[i].name) > 0) {
            resetStats(&player->supemons[i]);
        }
    }
}