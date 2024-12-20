#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "service.h"
#include<stdlib.h>
const char *fileservice="fileservice.txt";
const char *reservations="reservations.txt";

int elect,elect2;
int choix[]={0,0},choix2[]={0,0};
void clear_combobox(GtkComboBox *combobox) {
    GtkTreeModel *model = gtk_combo_box_get_model(combobox);
    GtkListStore *store = GTK_LIST_STORE(model);

    // Supprimer tous les éléments
    gtk_list_store_clear(store);
}
void
on_confirmas_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *enrty_id;
GtkWidget *enrty_name;
GtkWidget *enrty_time;
GtkWidget *enrty_price;
GtkWidget *enrty_electricy;
GtkWidget *enrty_electricn;
GtkWidget *enrty_camion;
GtkWidget *enrty_car;
enrty_id=lookup_widget(button,"ids1");
enrty_name=lookup_widget(button,"names1");
enrty_time=lookup_widget(button,"durations1");
enrty_price=lookup_widget(button,"prices1");
enrty_electricy=lookup_widget(button,"ecyes1");
enrty_electricn=lookup_widget(button,"ecno1");
enrty_camion=lookup_widget(button,"camion1");
enrty_car=lookup_widget(button,"car1");
service s1;

if(strlen(gtk_entry_get_text(GTK_ENTRY(enrty_id)))==0){
GtkWidget *message = gtk_message_dialog_new(GTK_WINDOW(user_data),
                                                GTK_DIALOG_DESTROY_WITH_PARENT,
                                                GTK_MESSAGE_INFO,
                                                GTK_BUTTONS_OK,
                                                "ID field is empty!");
gtk_dialog_run(GTK_DIALOG(message));
gtk_widget_destroy(message);
}
else{
strcpy(s1.id,gtk_entry_get_text(GTK_ENTRY(enrty_id)));

 

strcpy(s1.types, gtk_entry_get_text(GTK_ENTRY(enrty_name)));
s1.min=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(enrty_time));
char price_char[20];
strcpy(price_char,gtk_entry_get_text(GTK_ENTRY(enrty_price)));
int prix;
prix=atoi(price_char);
s1.price=prix;
if(elect==1){strcpy(s1.elec,"yes");}
if(elect==0){strcpy(s1.elec,"no");}
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(enrty_car))) {
        strcpy(s1.typev,"car");}  
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(enrty_camion))) {
        strcpy(s1.typev,"truck");}
if ((gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(enrty_car))) && (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(enrty_camion)))){
	strcpy(s1.typev,"both");}
s1.etat=0;
ajoute_service(fileservice, s1);
    
// Afficher un message de confirmation (facultatif)
GtkWidget *message = gtk_message_dialog_new(GTK_WINDOW(user_data),
                                                GTK_DIALOG_DESTROY_WITH_PARENT,
                                                GTK_MESSAGE_INFO,
                                                GTK_BUTTONS_OK,
                                                "service added successfully!");
gtk_dialog_run(GTK_DIALOG(message));
gtk_widget_destroy(message); }

}
void
on_camion1_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
	{choix[0]=1;}
}


void
on_car1_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
	{choix[1]=1;}
}


void
on_ecyes1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) elect=1;
}


void
on_ecno1_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) elect=0;
}


void
on_ecyes2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) elect2=1;
}


void
on_ecno2_toggled                       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))) elect2=0;
}


void
on_car2_toggled                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
	{choix2[1]=1;}
}


void
on_camion2_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
	{choix2[0]=1;}
}


void
on_confirmms_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *enrty_id;
GtkWidget *enrty_name;
GtkWidget *enrty_time;
GtkWidget *enrty_price;
GtkWidget *enrty_electricy;
GtkWidget *enrty_electricn;
GtkWidget *enrty_camion;
GtkWidget *enrty_car;
enrty_id=lookup_widget(button,"idms");
enrty_name=lookup_widget(button,"names2");
enrty_time=lookup_widget(button,"duration2");
enrty_price=lookup_widget(button,"prices2");
enrty_electricy=lookup_widget(button,"ecyes2");
enrty_electricn=lookup_widget(button,"ecno2");
enrty_camion=lookup_widget(button,"camion2");
enrty_car=lookup_widget(button,"car2");

service s1;
char id_new[50];
strcpy(s1.id,gtk_combo_box_get_active_text(GTK_COMBO_BOX(enrty_id)));
strcpy(id_new,s1.id);
strcpy(s1.types,gtk_entry_get_text(GTK_ENTRY(enrty_name)));
s1.min=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(enrty_time));
char price_char[20];
strcpy(price_char,gtk_entry_get_text(GTK_ENTRY(enrty_price)));
int prix;
prix=atoi(price_char);
s1.price=prix;
if(elect==1){strcpy(s1.elec,"yes");}
if(elect==0){strcpy(s1.elec,"no");}

if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(enrty_car))) {
        strcpy(s1.typev,"car");}  
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(enrty_camion))) {
        strcpy(s1.typev,"truck");}
if ((gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(enrty_car))) && (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(enrty_camion)))){
	strcpy(s1.typev,"both");}
s1.etat=0;
modifier_service(fileservice,id_new,s1);

// Afficher un message de confirmation
GtkWidget *message = gtk_message_dialog_new(NULL,
                                            GTK_DIALOG_DESTROY_WITH_PARENT,
                                            GTK_MESSAGE_INFO,
                                            GTK_BUTTONS_OK,
                                            "Service modified successfully!");
gtk_dialog_run(GTK_DIALOG(message));
gtk_widget_destroy(message);
}




void
on_refreshms_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *CB;
    service Tservice[200];
    int i, j;

    i = lire_service(fileservice, Tservice);
    CB = lookup_widget(button, "idms");

    if (CB == NULL) {
        g_print("Erreur : le widget CBavisparking est introuvable.\n");
        return;
    }

    gtk_combo_box_remove_text(GTK_COMBO_BOX(CB), 0);

    for (j = 0; j < i; j++) {
        if (strlen(Tservice[j].id) > 0) {
            gtk_combo_box_append_text(GTK_COMBO_BOX(CB), Tservice[j].id);
        } else {
            g_print("Erreur : nom_parking invalide pour l'élément %d.\n", j);
        }
    }

    gtk_combo_box_set_active(GTK_COMBO_BOX(CB), 0);
}





void
on_refreshds_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *CB;
    service Tparking[100];
    int i, j;
    i = lire_service(fileservice, Tparking);
    CB = lookup_widget(button, "idds");
	clear_combobox(CB);
    if (CB == NULL) {
        g_print("Erreur : le widget CBavisparking est introuvable.\n");
        return;
    }
    if (gtk_combo_box_get_active(GTK_COMBO_BOX(CB)) >= 0) {
    gtk_combo_box_remove_text(GTK_COMBO_BOX(CB), 0);
}
    for (j = 0; j < i; j++) {

    
            gtk_combo_box_append_text(GTK_COMBO_BOX(CB), Tparking[j].id);
      
    }
    gtk_combo_box_set_active(GTK_COMBO_BOX(CB), 0);


}
    



void
on_deleteds_clicked                    (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *cb;
cb=lookup_widget(button,"idds");
char id_new[50];
strcpy(id_new,gtk_combo_box_get_active_text(GTK_COMBO_BOX(cb)));
supprimer_service(fileservice,id_new);
GtkWidget *message = gtk_message_dialog_new(GTK_WINDOW(user_data),
                                                GTK_DIALOG_DESTROY_WITH_PARENT,
                                                GTK_MESSAGE_INFO,
                                                GTK_BUTTONS_OK,
                                                "Service deleted successfully!");
gtk_dialog_run(GTK_DIALOG(message));
gtk_widget_destroy(message);
}


void
on_despaly_clicked                     (GtkWidget       *button,
                                        gpointer         user_data)
{
GtkWidget *aff;
aff=lookup_widget(button,"treeview9");
afficher_service(aff);
}


void
on_effectres_clicked                   (GtkWidget       *button,
                                        gpointer         user_data)
{
       GtkWidget *entry_id_serv_affect = lookup_widget(GTK_WIDGET(button), "effect_id");
    GtkWidget *entry_id_resrv_affec = lookup_widget(GTK_WIDGET(button), "entry_res");

    // Vérification des widgets
    if (entry_id_serv_affect == NULL || entry_id_resrv_affec == NULL) {
        g_print("Erreur : Widgets non trouvés.\n");
        return;
    }

    // Récupération des IDs depuis les champs d'entrée
    const char *id_service_text = gtk_entry_get_text(GTK_ENTRY(entry_id_serv_affect));
    const char *id_reservation_text = gtk_entry_get_text(GTK_ENTRY(entry_id_resrv_affec));

    // Vérification des valeurs récupérées
    if (id_service_text == NULL || id_reservation_text == NULL || strlen(id_reservation_text) == 0) {
        g_print("Erreur : Les champs d'entrée sont vides ou non récupérés correctement.\n");
        return;
    }

    // Conversion des IDs en entiers
    int id_service = atoi(id_service_text);
    int id_reservation = atoi(id_reservation_text);

    // Appel à la fonction backend pour l’affectation
    int result = affecter_service_a_reservation("reservations.txt", id_reservation, id_service);

    if (result) {
        g_print("Service %d affecté à la réservation %d avec succès.\n", id_service, id_reservation);
    } else {
        g_print("Erreur : Impossible d'affecter le service %d à la réservation %d !!!\n", id_service, id_reservation);
    }

}






