#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ETUDIANTS 120
#define MAX_MODULES 10
#define MAX_NOM 50
#define MAX_ADDRESS 120
#define MAX_EMAIL 120

typedef struct {
    char nom_module[MAX_NOM];
    float coefficient;
    float note;
} Module;

typedef struct {
    int id;
    char nom[MAX_NOM];
    char prenom[MAX_NOM];
    char adresse[MAX_ADDRESS];
    char email[MAX_EMAIL];
    int age;
    float moyenne;
    Module modules[MAX_MODULES];
    int nb_modules;
} Etudiant;

void ajouter(Etudiant etudiants[], int *nb_etudiants) {
    if (*nb_etudiants>= MAX_ETUDIANTS) {
        printf("La limite du nombre d'étudiants est atteinte.\n");
        return;
    }

    Etudiant nouvel_etudiant;

    printf("Entrez l'identifiant de l'étudiant : ");
    scanf("%d", &nouvel_etudiant.id);
    printf("Entrez le nom de l'étudiant : ");
    scanf("%s", nouvel_etudiant.nom);
    printf("Entrez le prénom de l'étudiant : ");
    scanf("%s", nouvel_etudiant.prenom);
    printf("Entrez l'adresse de l'étudiant : ");
    scanf(" %[^\n]s",nouvel_etudiant.adresse);
    printf("Entrez l'e-mail de l'étudiant : ");
    scanf("%s", nouvel_etudiant.email);
    do{
    printf("Entrez l'âge de l'étudiant : ");
    scanf("%d", &nouvel_etudiant.age);}while(nouvel_etudiant.age<0||nouvel_etudiant.age>150);
    printf("Entrez le nombre de modules suivis par l'étudiant : ");
    scanf("%d", &nouvel_etudiant.nb_modules);

    for (int i = 0; i < nouvel_etudiant.nb_modules; i++) {
        printf("Entrez le nom du module %d : ", i + 1);
        scanf("%s",nouvel_etudiant.modules[i].nom_module);
        do{
        printf("Entrez le coefficient du module %d : ", i + 1);
        scanf("%f", &nouvel_etudiant.modules[i].coefficient);}while(nouvel_etudiant.modules[i].coefficient<=0);
        printf("Entrez la note obtenue par l'étudiant pour le module %d : ", i + 1);
        scanf("%f", &nouvel_etudiant.modules[i].note);
    do{
        printf("Entrez la moyenne de l'étudiant %d  : ",i+1);
        scanf("%f",&nouvel_etudiant.moyenne);
        }while((nouvel_etudiant.moyenne )>20 || (nouvel_etudiant.moyenne));}


    etudiants[*nb_etudiants] = nouvel_etudiant;
    (*nb_etudiants)++;

    // Enregistrement des informations dans un fichier
    char fnom[MAX_NOM + MAX_NOM + 5];
    sprintf(fnom, "database/%s_%s.txt", nouvel_etudiant.nom, nouvel_etudiant.prenom);
    FILE *f= fopen(fnom, "w");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    fprintf(f, "ID: %d\n", nouvel_etudiant.id);
    fprintf(f, "Nom: %s\n", nouvel_etudiant.nom);
    fprintf(f, "Prénom: %s\n", nouvel_etudiant.prenom);
    fprintf(f, "Adresse: %s\n", nouvel_etudiant.adresse);
    fprintf(f, "E-mail: %s\n",nouvel_etudiant.age);
    fprintf(f, "Modules:\n");

    for (int i = 0; i <nouvel_etudiant.nb_modules; i++) {
        fprintf(f, "  Nom du module: %s\n", nouvel_etudiant.modules[i].nom_module);
        fprintf(f, "  Coefficient: %.2f\n", nouvel_etudiant.modules[i].coefficient);
        fprintf(f, "  Note: %.2f\n", nouvel_etudiant.modules[i].note);
    }
        fprintf(f," Moyennne: %.2f\n",nouvel_etudiant.moyenne);

    fclose(f);

    printf("L'étudiant a été ajouté avec succès.\n");
}

void afficher(const Etudiant etudiants[], int nb_etudiants) {
    if (nb_etudiants == 0) {
        printf("Aucun étudiant enregistré.\n");
        return;
    }

    for (int i = 0; i < nb_etudiants; i++) {
        printf("Étudiant %d:\n", i + 1);
        printf("  ID: %d\n", etudiants[i].id);
        printf("  Nom: %s\n", etudiants[i].nom);
        printf("  Prénom: %s\n", etudiants[i].prenom);
        printf("  Adresse: %s\n", etudiants[i].adresse);
        printf("  E-mail: %s\n", etudiants[i].email);
        printf("  Âge: %d\n", etudiants[i].age);
        printf("    Moyenne: %.2f\n",etudiants[i].moyenne);

        printf("  Modules:\n");

        for (int j = 0; j < etudiants[i].nb_modules; j++) {
            printf("    Nom du module: %s\n", etudiants[i].modules[j].nom_module);
            printf("    Coefficient: %.2f\n", etudiants[i].modules[j].coefficient);
            printf("    Note: %.2f\n", etudiants[i].modules[j].note);

           }

        printf("\n");
    }
}

void rechercher(const Etudiant etudiants[], int nb_etudiants) {
    char search_name[MAX_NOM];
    printf("Entrez le nom ou prénom de l'étudiant à rechercher : ");
    scanf("%s", search_name);

    int tr = 0;//tr c une variable qui signifie etudiant trouvé

    for (int i = 0; i < nb_etudiants; i++) {
        if (strcmp(etudiants[i].nom, search_name) == 0 || strcmp(etudiants[i].prenom, search_name) == 0) {
            printf("Résultat de recherche pour '%s':\n", search_name);
            printf("  ID: %d\n", etudiants[i].id);
            printf("  Nom: %s\n",etudiants[i].nom);
            printf("  Prénom: %s\n",etudiants[i].prenom);
            printf("  Adresse: %s\n", etudiants[i].adresse);
            printf("  E-mail: %s\n", etudiants[i].email);
            printf("  Âge: %d\n",etudiants[i].age);
            printf("    Moyenne: %.2f\n",etudiants[i].moyenne);

            printf("  Modules:\n");

            for (int j = 0; j < etudiants[i].nb_modules; j++) {
                printf("    Nom du module: %s\n", etudiants[i].modules[j].nom_module);
                printf("    Coefficient: %.2f\n",etudiants[i].modules[j].coefficient);
                printf("    Note: %.2f\n",etudiants[i].modules[j].note);
            }

            printf("\n");
            tr= 1;
        }
    }

    if (!tr) {
        printf("Aucun étudiant trouvé avec le nom ou prénom '%s'.\n", search_name);
    }
}

void modifier(Etudiant etudiants[], int nb_etudiants) {
    char search_name[MAX_NOM];
    printf("Entrez le nom de l'étudiant à modifier : ");
    scanf("%s", search_name);

    int tr = 0;

    for (int i = 0; i < nb_etudiants; i++) {
        if (strcmp(etudiants[i].nom, search_name) == 0) {
            printf("Modifiez les informations de l'étudiant '%s':\n", etudiants[i].nom);
            printf("Nouveau prénom: ");
            scanf("%s",etudiants[i].prenom);
            printf("Nouvelle adresse: ");
            scanf(" %[^\n]s", etudiants[i].adresse);
            printf("Nouvel e-mail: ");
            scanf("%s", etudiants[i].email);
            printf("Nouvel âge: ");
            scanf("%d", &etudiants[i].age);
            printf("Entrez la moyenne obtenue par l'etudiant:");
            scanf("%f",&etudiants[i].moyenne);

            printf("Entrez le nouveau nombre de modules suivis par l'étudiant : ");
            scanf("%d", &etudiants[i].nb_modules);

            for (int j = 0; j < etudiants[i].nb_modules; j++) {
                printf("Entrez le nom du module %d : ", j + 1);
                scanf("%s", etudiants[i].modules[j].nom_module);
                printf("Entrez le coefficient du module %d : ", j + 1);
                scanf("%f", &etudiants[i].modules[j].coefficient);
                printf("Entrez la note obtenue par l'étudiant pour le module %d : ", j + 1);
                scanf("%f", &etudiants[i].modules[j].note);
            }


            // Mise à jour des informations dans le fichier
            char fnom[MAX_NOM + MAX_NOM + 5];
            sprintf(fnom, "database/%s_%s.txt", etudiants[i].nom, etudiants[i].prenom);
            FILE *f = fopen(fnom, "w");
            if (f == NULL) {
                printf("Erreur lors de l'ouverture du fichier.\n");
                return;
            }

            fprintf(f, "ID: %d\n", etudiants[i].id);
            fprintf(f, "Nom: %s\n", etudiants[i].nom);
            fprintf(f, "Prénom: %s\n", etudiants[i].prenom);
            fprintf(f, "Adresse: %s\n", etudiants[i].adresse);
            fprintf(f, "E-mail: %s\n",etudiants[i].email);
            fprintf(f, "Âge: %d\n", etudiants[i].age);
            fprintf(f,"Moyenne:%.2f\n",etudiants[i].moyenne);

            fprintf(f, "Modules:\n");

            for (int j = 0; j < etudiants[i].nb_modules; j++) {
                fprintf(f, "  Nom du module: %s\n", etudiants[i].modules[j].nom_module);
                fprintf(f, "  Coefficient: %.2f\n", etudiants[i].modules[j].coefficient);
                fprintf(f, "  Note: %.2f\n", etudiants[i].modules[j].note);
            }


            fclose(f);

            printf("Les informations de l'étudiant ont été mises à jour avec succès.\n");
            tr = 1;
        }
    }

    if (!tr) {
        printf("Aucun étudiant trouvé avec le nom '%s'.\n", search_name);
    }
}

void supprimer(Etudiant etudiants[], int *nb_etudiants) {
    char search_name[MAX_NOM];
    printf("Entrez le nom de l'étudiant à supprimer : ");
    scanf("%s", search_name);

    int tr = 0;

    for (int i = 0; i < *nb_etudiants; i++) {
        if (strcmp(etudiants[i].nom, search_name) == 0) {
            // Suppression du fichier correspondant à l'étudiant
            char fnom[MAX_NOM + MAX_NOM + 5];
            sprintf(fnom, "database/%s_%s.txt", etudiants[i].nom, etudiants[i].prenom);
            if (remove(fnom) == 0) {
                printf("Le fichier de l'étudiant '%s' a été supprimé.\n", etudiants[i].nom);
            } else {
                printf("Erreur lors de la suppression du fichier de l'étudiant '%s'.\n", etudiants[i].nom);
            }

            // Déplacement des étudiants suivants
            for (int j = i + 1; j < *nb_etudiants; j++) {
               etudiants[j - 1] = etudiants[j];
            }

            (*nb_etudiants)--;
            printf("L'étudiant a été supprimé avec succès.\n");
            tr= 1;
            break;
        }
    }

    if (!tr) {
        printf("Aucun étudiant trouvé avec le nom '%s'.\n", search_name);
    }
}

int main() {
   Etudiant etudiants[MAX_ETUDIANTS];
    int nb_etudiants = 0;

    int choix;

    do {
        printf("Menu:\n");
        printf("1. Ajouter un etudiant\n");
        printf("2. Afficher tous les etudiants\n");
        printf("3. Rechercher un etudiant\n");
        printf("4. Modifier un etudiant\n");
        printf("5. Supprimer un etudiant\n");
        printf("6. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouter(etudiants, &nb_etudiants);
                break;
            case 2:
                afficher(etudiants, nb_etudiants);
                break;
            case 3:
                rechercher(etudiants, nb_etudiants);
                break;
            case 4:
                modifier(etudiants, nb_etudiants);
                break;
            case 5:
                supprimer(etudiants, &nb_etudiants);
                break;
            case 6:
                printf("fin du traitement!\n");
                break;
            default:
                printf("Choix invalide.\n");
                break;
        }

        printf("\n");
    } while (choix != 6);

    return 0;
}
