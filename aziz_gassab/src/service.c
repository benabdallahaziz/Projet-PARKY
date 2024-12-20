#include <stdio.h>
#include <string.h>
#include "service.h"
#include <stdlib.h>
#include <gtk/gtk.h>



int lire_service(const char *fileservice, service tservice[]) {
    int i = 0;
    FILE *f = fopen(fileservice, "r");
    if (f != NULL) {
        while (fscanf(f, "%s %s %d %d %s %s %d \n", tservice[i].id, tservice[i].types, &tservice[i].min, &tservice[i].price, tservice[i].elec, tservice[i].typev,&tservice[i].etat) != EOF) {
            i++;
        }
        fclose(f); 
    }
    return i;
}

void ecrire_service(const char *fileservice, service tservice[], int n) {
    FILE *f = fopen(fileservice, "w"); // Ouvre le fichier en mode écriture (réécrit le fichier)
    if (f != NULL) {
        for (int i = 0; i < n; i++) {
            fprintf(f, "%s %s %d %d %s %s %d \n", tservice[i].id, tservice[i].types, tservice[i].min, tservice[i].price, tservice[i].elec, tservice[i].typev,tservice[i].etat);
        }
        fclose(f); // Ferme le fichier après avoir écrit
    }
}

void ajoute_service(const char *fileservice, service s1) {
    FILE *f = fopen(fileservice, "a"); // Ouvre le fichier en mode ajout
    if (f != NULL) {
        fprintf(f, "%s %s %d %d %s %s %d \n", s1.id, s1.types, s1.min, s1.price, s1.elec, s1.typev ,s1.etat);
        fclose(f); // Ferme le fichier après avoir écrit
    }
}
void modifier_service(const char *fileservice,char id_a_modifier[20],service s1){
service Tservice[200];int i,test=0;
int n=lire_service(fileservice,Tservice);
for (i=0;i<n;i++){
if (strcmp(Tservice[i].id,id_a_modifier)==0){
strcpy(Tservice[i].types,s1.types);Tservice[i].min=s1.min;Tservice[i].price=s1.price;strcpy(Tservice[i].elec,s1.elec);strcpy(Tservice[i].typev,s1.typev);Tservice[i].etat=s1.etat;
test=1;
break;
}
}

ecrire_service(fileservice,Tservice,n);
}
void supprimer_service(const char *fileservice,char id_a_supprimer[20]){

	service Tservice[200];int i,test=0;
	service a1;
	int n=lire_service(fileservice,Tservice);
	for (i=0;i<n;i++){
	if (strcmp(Tservice[i].id,id_a_supprimer)==0){
	int j;
	for (j=i;j<n-1;j++) {Tservice[j]=Tservice[j+1];}
	n--;test=1;break;}}
	if (test==0) printf("service n'est pa trouver\n");
	ecrire_service(fileservice,Tservice,n);

}
enum{
ID,
TYPES,
MINE,
PRICE,
ELEC,
TYPEV,
ETAT,
COLUMNS
};


void afficher_service(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
        char id [20],types[20],mine[20],price[20],elec[20],typev[20],etat[20];
	store=NULL;

	FILE *f;

	store = gtk_tree_view_get_model(GTK_TREE_VIEW(liste));
	if (store==NULL)
	{
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("ID",renderer,"text",ID,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("name",renderer,"text",TYPES,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("duration(min)",renderer,"text",MINE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("price(dt)",renderer,"text",PRICE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("electrice",renderer,"text",ELEC,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("truck or car",renderer,"text",TYPEV,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer=gtk_cell_renderer_text_new();
		column=gtk_tree_view_column_new_with_attributes("state",renderer,"text",ETAT,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
				store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);

		f=fopen("fileservice.txt","r");
		if(f==NULL) return;
		else{
			f=fopen("fileservice.txt","a+");
			while(fscanf(f,"%s %s %s %s %s %s %s\n",id,types,mine,price,elec,typev,etat)!=EOF){
			gtk_list_store_append(store ,&iter);
			gtk_list_store_set(store ,&iter,ID,id,TYPES,types,MINE,mine,PRICE,price,ELEC,elec,TYPEV,typev,ETAT,etat,-1);
			}
		fclose(f);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
		}
}}


#define MAX_LINE 100 // Taille maximale pour une ligne

int recherche_id(const char *nom_fichier, const char *id_recherche) {
    FILE *fichier;
    char ligne[MAX_LINE];

    // Ouvrir le fichier en mode lecture
    fichier = fopen(nom_fichier, "r");
    if (fichier == NULL) {
        perror("Erreur d'ouverture du fichier");
        return 0; // Retourner 0 car le fichier ne peut pas être ouvert
    }

    // Lire ligne par ligne et comparer avec l'ID recherché
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        // Supprimer le saut de ligne à la fin
        ligne[strcspn(ligne, "\n")] = '\0';
        
        if (strcmp(ligne, id_recherche) == 0) {
            fclose(fichier);
            return 1; // ID trouvé
        }
    }

    // Fermer le fichier après la lecture
    fclose(fichier);
    return 0; // ID non trouvé
}

int verifier_service_existe(const char *filename, const char *service_id) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) return 0;

    service s;
    while (fscanf(file, "%49s %49s %d %d %49s %49s %d", 
                  s.id, s.types, &s.min, &s.price, s.elec, s.typev, &s.etat) != EOF) {
        if (strcmp(s.id, service_id) == 0) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

// Fonction pour affecter un service à une réservation
int affecter_service_a_reservation(char filename[], int reservation_id, int service_id) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s.\n", filename);
        return 0;
    }

    Reservation reservations[100];
    int count = 0;
    int found = 0;

    // Lecture des réservations dans le fichier
    while (fscanf(file, "%d %d %d %s", &reservations[count].id, &reservations[count].citizen_id,
                  &reservations[count].service_id, reservations[count].date) != EOF) {
        if (reservations[count].id == reservation_id) {
            reservations[count].service_id = service_id;
            found = 1;
        }
        count++;
    }
    fclose(file);

    if (!found) {
        printf("Erreur : ID de réservation %d introuvable.\n", reservation_id);
        return 0;
    }

    // Écriture des modifications dans le fichier
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier pour écriture.\n");
        return 0;
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %d %d %s\n", reservations[i].id, reservations[i].citizen_id,
                reservations[i].service_id, reservations[i].date);
    }
    fclose(file);

    return 1;
}












