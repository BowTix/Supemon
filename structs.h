#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_NAME_LENGTH 50
#define MAX_SUPEMON_NAME_LENGTH 20
#define MAX_ITEMS 3
#define MAX_SUPEMONS 6
#define MAX_OWNED_ITEMS 18

/**
 * @file structs.h
 * @brief Structures contenant les données nécéssaires pour le joueur, les supemons et les items
 * @author Enzo, Mathis et Tom
 * @version 1.0
 * @date 06/03/2024
 */

typedef struct {
    char name[MAX_NAME_LENGTH]; //Nom de l'attaque avec une limite de caractères
    int damage;  // Pour les attaques qui infligent des dégâts
    int attack_boost;  // Augmentation de l'attaque
    int defense_boost;  // Augmentation de la défense
    int evasion_boost;  // Augmentation de l'évasion
} Attack;

typedef struct {
    char name[MAX_SUPEMON_NAME_LENGTH]; // Nom du supémon avec une limite de caractères
    int level; // Initialisation du level
    int experience; // Initialisation de l'experience
    int hp; // Initialisation des points de vie du supémon
    int max_hp; // Initialisation des points de vie maximum du supémon
    int base_attack; // Initialisation de l'attaque de base du supémon
    int base_defense; // Initialisation de la défense de base du supémon
    int base_evasion; // Initialisation de l'esquive de base du supémon
    int accuracy; // Initialisation de la précision de base du supémon
    int speed; // Initialisation de la vitesse de base du supémon
    Attack *moves[2]; // Inclue les 2 attaques du supémon
    int attack; // Utiliser en cas de changement de statistiques (ici l'attaque)
    int defense; // Utiliser en cas de changement de statistiques (ici la defense)
    int evasion; // Utiliser en cas de changement de statistiques (ici l'esquive)
    int maxexperience; // Initialisation de l'expérience maximum du supémon
} Supemon;

extern Attack attacks[]; // Permet de définir les attaques dans le fonction.c

typedef struct {
    char name[MAX_NAME_LENGTH]; // Nom de l'objet avec une limite de caractères
    int price; // Définir le prix d'un objet
    int selling_price; // Stocker le prix de vente de l'objet
    int quantity; // Quantité d'objet possédée par le joueur
    int hp_increase; // Augmentation des points de vie pour les potions
    int level_increase; // Augmentation de niveau pour les Rare Candies
} Item;

extern Item items[]; // Permet de définir les attaques dans le fonction.c

typedef struct {
    char name[MAX_NAME_LENGTH]; // Nom du Joueur avec une limite de caractères
    Supemon supemons[MAX_SUPEMONS]; // Définir le nombre maximum de supémon que le joueur peut avoir
    int selected_supemon_index; // Définir l'index du supémon selectionné
    int supcoins; // Définir les supcoins de base du joueur
    Item items_owned[MAX_OWNED_ITEMS]; // Stocker les items achetés par le joueur avec une limite d'objet acheté
} Player;

// Déclaration des différents prototypes
void initPlayer(Player *player);
void chooseStarter(Player *player);
void newGame(Player *player);
void saveBackup(Player player);
void loadBackup(Player *player);
void centreSupemon(Player *player);
void displayItems();
void buyMode(Player *player);
void sellMode(Player *player);
void shop(Player *player);
int chooseItem(Player *player);
int chooseAttack(Supemon *supemon);
void initWildSupemon(Player *player, Supemon *supemon, int supemonIndex);
double arrondiAleatoire (double nombre);
void applyStatBoost(Supemon *supemon, Attack *attack);
void resetStats(Supemon *supemon);
void battle(Player *player);

#endif /* STRUCTS_H */
