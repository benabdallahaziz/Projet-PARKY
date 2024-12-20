#ifndef SERVICE_H
#define SERVICE_H
#include <gtk/gtk.h>
typedef struct {
    char id[50];
    char types[50];
    int min;
    int price;
    char elec[50];
    char typev[50];
    int etat;
} service;
typedef struct {
    int id;
    int citizen_id;
    int service_id;
    char date[20];
} Reservation;

int lire_service(const char *fileservice, service tservice[]);
void ecrire_service(const char *fileservice, service tservice[], int n);
void ajoute_service(const char *fileservice, service s1);
void modifier_service(const char *fileservice,char id_a_modifier[20],service s1);
void supprimer_service(const char *fileservice,char id_a_supprimer[20]);
void afficher_service(GtkWidget *liste);
int recherche_id(const char *nom_fichier, const char *id_recherche);
//void affecter_service(resercation *res, service srv);
void vider(GtkWidget *liste);
int affecter_service_a_reservation(char filename[], int reservation_id, int service_id);

 
void charger_services(const char *filename, service tservice[], int size);
void sauvegarder_services(const char *filename, service tservice[], int size);
void charger_reservations(const char *filename, Reservation treservation[], int size);
void sauvegarder_reservations(const char *filename, Reservation treservation[], int size);

#endif

