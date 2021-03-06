#include "InterfaceGraphique.h"


void MenuResultatDecryptagePartiel(GtkWidget *Fenetre,gchar* Text_crypt)
{
    Fenetre = gtk_widget_get_toplevel (Fenetre);
	ViderContenaire(GTK_CONTAINER(Fenetre));
	GtkWidget *Box,*Box2, *Label,*Label2,*Bouton1, *Bouton2, *Bouton3;
    gchar *Text,*Resultat,*Cle_et_resultat;
    gchar* Tableau_cle;
    Tableau_cle="abcdefghijklmnopqrstuvwxyz"; 
    Cle_et_resultat=(gchar *)malloc((strlen(Tableau_cle)+strlen(Text_crypt))*sizeof(gchar));

    DecryptageSubstitution(Resultat,Text_crypt,Tableau_cle);
    strcpy(Cle_et_resultat,Tableau_cle);
    strcat(Cle_et_resultat,Text_crypt);

    Box = gtk_vbox_new(TRUE, 0);
    gtk_container_add(GTK_CONTAINER(Fenetre), Box);

    Label=gtk_label_new(NULL);
    Text = g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">Welcome to DecryptUs</span>\n",
    -1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL(Label), Text);
    g_free(Text);
    gtk_label_set_justify(GTK_LABEL(Label), GTK_JUSTIFY_CENTER);

    gtk_box_pack_start(GTK_BOX(Box), Label, TRUE, TRUE, 0);
    
    Label2=gtk_label_new(Text_crypt);
    gtk_label_set_justify(GTK_LABEL(Label2), GTK_JUSTIFY_CENTER);
    gtk_box_pack_start(GTK_BOX(Box), Label2, TRUE, TRUE, 0);
    
    Label2=gtk_label_new(Tableau_cle);
    gtk_label_set_justify(GTK_LABEL(Label2), GTK_JUSTIFY_CENTER);
    gtk_box_pack_start(GTK_BOX(Box), Label2, TRUE, TRUE, 0);
    
    Label2=gtk_label_new(Cle_et_resultat);
    gtk_label_set_justify(GTK_LABEL(Label2), GTK_JUSTIFY_CENTER);
    gtk_box_pack_start(GTK_BOX(Box), Label2, TRUE, TRUE, 0);
    
    Box2 = gtk_hbox_new(TRUE, 0);
    gtk_container_add(GTK_CONTAINER(Box), Box2);
    
    Bouton1 = gtk_button_new_with_label("redecrypter");
    g_signal_connect(G_OBJECT(Bouton1), "clicked", G_CALLBACK(MenuResultatDecryptagePartiel), Text_crypt);
    gtk_box_pack_start(GTK_BOX(Box2), Bouton1, TRUE, TRUE, 0);
    
    Bouton2 = gtk_button_new_with_label("changer la cle");
    g_signal_connect(G_OBJECT(Bouton2), "clicked", G_CALLBACK(MenuDecryptage), NULL);
    gtk_box_pack_start(GTK_BOX(Box2), Bouton2, TRUE, TRUE, 0);
    
    Bouton3 = gtk_button_new_with_label("terminer");
    g_signal_connect(G_OBJECT(Bouton3), "clicked", G_CALLBACK(MenuResultatDecryptageSubstitution), Cle_et_resultat);
    gtk_box_pack_start(GTK_BOX(Box2), Bouton3, TRUE, TRUE, 0);
    
    gtk_widget_show_all(Fenetre);
}

void modifieLangue(GtkWidget *Fenetre, int lang)
{
    if (lang==0)
    {
        langue=0;
    }
    else
    {
        langue=1;
    }
    MenuDecryptage(Fenetre);
}

void ChoisirLangue()
{
    GtkWidget *Boite,*bouton1,*bouton2, *Label_text;
    gchar* msg;
    int i=0;
    int j=1;
    Fenetre = gtk_widget_get_toplevel (Fenetre);//je crée la seconde fenetre

    ViderContenaire(GTK_CONTAINER(Fenetre));

    Label_text=gtk_label_new(NULL);
    Boite = gtk_vbox_new(TRUE, 0);
    gtk_container_add(GTK_CONTAINER(Fenetre), Boite);

    msg= g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">Quelle est la langue ? </span>\n",
    -1, NULL, NULL, NULL);

    bouton1= gtk_button_new_with_label("Français");
    gtk_label_set_markup(GTK_LABEL(Label_text), msg);
    gtk_label_set_justify(GTK_LABEL(Label_text), GTK_JUSTIFY_CENTER);
    g_signal_connect(G_OBJECT(bouton1), "clicked", G_CALLBACK(modifieLangue), (gpointer) i );
    gtk_box_pack_start(GTK_BOX(Boite), Label_text, TRUE, FALSE,0);
    gtk_box_pack_start(GTK_BOX(Boite), bouton1, TRUE, TRUE,10);
    bouton2=gtk_button_new_with_label("Anglais");
    g_signal_connect(G_OBJECT(bouton2), "clicked", G_CALLBACK(modifieLangue), (gpointer) j);
    gtk_box_pack_start(GTK_BOX(Boite), bouton2, TRUE, TRUE,10);
   
    gtk_widget_show_all(Fenetre);
}

void MenuAttente(GtkWidget *Fenetre)
{
   GtkWidget* pWindow;
   GtkWidget* Label;
   gchar* Text;
 
   pWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
   gtk_window_set_title(GTK_WINDOW(pWindow), "fenetre d'attente");
   gtk_window_set_default_size(GTK_WINDOW(pWindow), 320, 200);
   gtk_container_set_border_width(GTK_CONTAINER(pWindow), 4);

    Label=gtk_label_new(NULL);
    Text = g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">Patientez...</span>\n",
           -1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL(Label), Text);
    g_free(Text);  
    gtk_container_add(GTK_CONTAINER(pWindow), Label);
    

   gtk_widget_show_all(pWindow);  
   gtk_widget_show_all(pWindow);
   gtk_main_iteration(); 
   gtk_main_iteration();

   sleep(3);      
   gtk_widget_destroy(pWindow);
   gtk_main();

}

void Enregistrer (GtkWidget *p_widget, GtkWidget *text )
{
      /* Le fichier n'a pas encore ete enregistre */
        gchar *chemin;
        GtkWidget *p_dialog = NULL;

        p_dialog = gtk_file_chooser_dialog_new ("Sauvegarder le fichier", NULL,
                                                GTK_FILE_CHOOSER_ACTION_SAVE,
                                                GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
                                                GTK_STOCK_SAVE, GTK_RESPONSE_ACCEPT,
                                                NULL);
        if (gtk_dialog_run (GTK_DIALOG (p_dialog)) == GTK_RESPONSE_ACCEPT)
        {
          chemin = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (p_dialog));
        }
        gtk_widget_destroy (p_dialog);
      /* l'utilisateur vient de nous fournir son nouvel emplacement, on peut donc l'enregistrer */
        FILE *fichier = NULL;

        fichier = fopen (chemin, "w");
        if (fichier)
        {
          gchar *contents = NULL;
          gchar *locale = NULL;

          contents = gtk_label_get_text(GTK_LABEL(text));
          locale = g_locale_from_utf8 (contents, -1, NULL, NULL, NULL);
          g_free (contents), contents = NULL;
          fprintf (fichier, "%s", locale);
          g_free (locale), locale = NULL;
          fclose (fichier), fichier = NULL;
        }
  /* Parametres inutilises */
  (void)p_widget;
}

void RecupererChemin(GtkWidget *bouton, GtkWidget *file_selection)
{
    ANALYSE a;
    const gchar* chemin;
    gchar *Text_crypt,*text_clair;
    gchar contenu[TAILLEMAX];
    GtkWidget *dialog;
    chemin = gtk_file_selection_get_filename(GTK_FILE_SELECTION (file_selection) );
    dialog = gtk_message_dialog_new(GTK_WINDOW(file_selection),GTK_DIALOG_MODAL,
    GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"Vous avez choisi :\n%s", chemin);
     //ce chemin doit etre utiliser pour remplir une chaine/tableau ensuite on supprime la "dialog"
    LireFichier(contenu,TAILLEMAX,chemin);
    
   switch (choix)
	{
	case 1:
		CryptageSubstitution(Text_crypt,contenu);
  		MenuResultatSubstitution(Fenetre,Text_crypt);
  		break;
	case 2:
	
		CryptageVigenere(Text_crypt,contenu,contenu);
		MenuResultatVigenere(Fenetre,Text_crypt,Text_crypt);
		
  		break;
	case 3:
  		DecryptageSubstitution(Text_crypt,contenu,contenu);

  		MenuResultatDecryptagePartiel(Fenetre, contenu);
  		break;
	case 4:
  		DecryptageVigenere(Text_crypt,contenu,contenu);
  		MenuResultatDecryptageVigenere(Fenetre,text_clair,text_clair);
  		break;
  	case 5:
  		a=AnalyseFrequentielle(contenu);
  		MenuResultatAnalyse(Fenetre,contenu);
  		break;

}
    
    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    gtk_widget_destroy(file_selection);
}

void ChoisirFichier()
{
    GtkWidget *selection;
    
    selection = gtk_file_selection_new( g_locale_to_utf8( "Sélectionnez un fichier", -1, NULL, NULL, NULL) );
    gtk_widget_show(selection);
     
    //On interdit l'utilisation des autres fenêtres.
    gtk_window_set_modal(GTK_WINDOW(selection), TRUE);
     
    g_signal_connect(G_OBJECT(GTK_FILE_SELECTION(selection)->ok_button), "clicked", G_CALLBACK(RecupererChemin), selection );
    g_signal_connect_swapped(G_OBJECT(GTK_FILE_SELECTION(selection)->cancel_button), "clicked", G_CALLBACK(gtk_widget_destroy), selection);
}
 
void ViderContenaire(GtkContainer * container)
{
    GList * children = gtk_container_get_children(container);
    while(children)
    {
        gtk_widget_destroy(children->data);
        children = g_list_next(children);
    }
    g_list_free(children);
}

void MenuResultatSubstitution(GtkWidget *Fenetre, gchar* Text_crypt)
{
    Fenetre = gtk_widget_get_toplevel (Fenetre);
    ViderContenaire(GTK_CONTAINER(Fenetre));

    GtkWidget *Box, *Box_2,*Label, *Label_msg,*Label_cle,*Bouton1,*Bouton2,*Bouton3;
    gchar* Text;
    
    Box = gtk_vbox_new(TRUE, 0);
    gtk_container_add(GTK_CONTAINER(Fenetre), Box);
    Box_2= gtk_hbox_new(FALSE, 0);
    Label=gtk_label_new(NULL);
    Label_msg=gtk_label_new(NULL);
    Label_cle=gtk_label_new(NULL);

    Text = g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">resultat du cryptage</span>\n<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">Par substitution</span>\n",
    -1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL(Label), Text);
    g_free(Text);
    gtk_label_set_justify(GTK_LABEL(Label), GTK_JUSTIFY_CENTER);

    gtk_box_pack_start(GTK_BOX(Box), Box_2, TRUE, TRUE, 0);

    Bouton3 = gtk_button_new_with_label("R");
    g_signal_connect(G_OBJECT(Bouton3), "clicked", G_CALLBACK(MenuCryptageSubstitution), NULL);
    gtk_box_pack_start(GTK_BOX(Box_2), Bouton3, FALSE, TRUE, 0);

    gtk_box_pack_start(GTK_BOX(Box_2), Label, TRUE, TRUE, 0);

    ////////////Affichage du resultat//////////////

    gtk_label_set_markup(GTK_LABEL(Label_msg), Text_crypt);
    gtk_label_set_justify(GTK_LABEL(Label_msg), GTK_JUSTIFY_CENTER);
    gtk_box_pack_start(GTK_BOX(Box), Label_msg, TRUE, TRUE, 0);
    
    Bouton1 = gtk_button_new_with_label("Enregistrer le msg");
    g_signal_connect(G_OBJECT(Bouton1), "clicked", G_CALLBACK(Enregistrer), Label_msg);
    gtk_box_pack_start(GTK_BOX(Box), Bouton1, TRUE, TRUE, 0);

        ////////////Affichage de la cle//////////////

    gtk_label_set_markup(GTK_LABEL(Label_cle), Text_crypt);
    gtk_label_set_justify(GTK_LABEL(Label_cle), GTK_JUSTIFY_CENTER);
    gtk_box_pack_start(GTK_BOX(Box), Label_cle, TRUE, TRUE, 0);
    
    Bouton2 = gtk_button_new_with_label("Enregistrer la cle");
    g_signal_connect(G_OBJECT(Bouton2), "clicked", G_CALLBACK(Enregistrer), Label_cle);
    gtk_box_pack_start(GTK_BOX(Box), Bouton2, TRUE, TRUE, 0);
    
    gtk_widget_show_all(Fenetre);
}

void MenuResultatVigenere(GtkWidget *Fenetre, gchar* Text_crypt, gchar* cle)
{
    Fenetre = gtk_widget_get_toplevel (Fenetre);
    ViderContenaire(GTK_CONTAINER(Fenetre));

    GtkWidget *Box, *Box_2,*Label, *Label_msg,*Label_cle,*Bouton1,*Bouton2,*Bouton3;
    gchar* Text; 
    
    Box = gtk_vbox_new(TRUE, 0);
    gtk_container_add(GTK_CONTAINER(Fenetre), Box);
    Box_2= gtk_hbox_new(FALSE, 0);
    Label=gtk_label_new(NULL);
    Label_msg=gtk_label_new(NULL);
    Label_cle=gtk_label_new(NULL);

    Text = g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">resultat du cryptage</span>\n<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">Par Vigenere</span>\n",
           -1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL(Label), Text);
    g_free(Text);
 
    gtk_label_set_justify(GTK_LABEL(Label), GTK_JUSTIFY_CENTER);

    gtk_box_pack_start(GTK_BOX(Box), Box_2, TRUE, TRUE, 0);

    Bouton3 = gtk_button_new_with_label("R");
    g_signal_connect(G_OBJECT(Bouton3), "clicked", G_CALLBACK(MenuCryptageVigenere), NULL);
    gtk_box_pack_start(GTK_BOX(Box_2), Bouton3, FALSE, TRUE, 0);
    
    gtk_box_pack_start(GTK_BOX(Box_2), Label, TRUE, TRUE, 0);

    ////////////Affichage du resultat//////////////

    gtk_label_set_markup(GTK_LABEL(Label_msg), Text_crypt);
    gtk_label_set_justify(GTK_LABEL(Label_msg), GTK_JUSTIFY_CENTER);
    gtk_box_pack_start(GTK_BOX(Box), Label_msg, TRUE, TRUE, 0);
    
    Bouton1 = gtk_button_new_with_label("Enregistrer le msg");
    g_signal_connect(G_OBJECT(Bouton1), "clicked", G_CALLBACK(Enregistrer), Label_msg);
    gtk_box_pack_start(GTK_BOX(Box), Bouton1, TRUE, TRUE, 0);

        ////////////Affichage de la cle//////////////

    gtk_label_set_markup(GTK_LABEL(Label_cle), cle);
    gtk_label_set_justify(GTK_LABEL(Label_cle), GTK_JUSTIFY_CENTER);
    gtk_box_pack_start(GTK_BOX(Box), Label_cle, TRUE, TRUE, 0);
    
    Bouton2 = gtk_button_new_with_label("Enregistrer la cle");
    g_signal_connect(G_OBJECT(Bouton2), "clicked", G_CALLBACK(Enregistrer), Label_cle);
    gtk_box_pack_start(GTK_BOX(Box), Bouton2, TRUE, TRUE, 0);
    
    gtk_widget_show_all(Fenetre);
}

void MenuResultatAnalyse(GtkWidget *Fenetre,gchar *analyse)
{
    Fenetre = gtk_widget_get_toplevel (Fenetre);//on passe a la fenetre du bouton 
    ViderContenaire(GTK_CONTAINER(Fenetre));//on la vide

    GtkWidget *Box, *Box_2,*Label, *Label_msg,*Label_cle,*Bouton1,*Bouton2,*Bouton3;
    gchar* Text;
    
    Box = gtk_vbox_new(TRUE, 0);
    gtk_container_add(GTK_CONTAINER(Fenetre), Box);
    Box_2= gtk_hbox_new(FALSE, 0);
    Label=gtk_label_new(NULL);
    Label_msg=gtk_label_new(NULL);
    Label_cle=gtk_label_new(NULL);

    Text = g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">resultat d'etude de texte</span>\n",
    -1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL(Label), Text);
    g_free(Text);
    gtk_label_set_justify(GTK_LABEL(Label), GTK_JUSTIFY_CENTER);

    gtk_box_pack_start(GTK_BOX(Box), Box_2, TRUE, TRUE, 0);

    Bouton3 = gtk_button_new_with_label("R");
    g_signal_connect(G_OBJECT(Bouton3), "clicked", G_CALLBACK(MenuAnalyseFrequentielle), NULL);
    gtk_box_pack_start(GTK_BOX(Box_2), Bouton3, FALSE, TRUE, 0);
    
    gtk_box_pack_start(GTK_BOX(Box_2), Label, TRUE, TRUE, 0);

    ////////////Affichage du resultat//////////////

    gtk_label_set_markup(GTK_LABEL(Label_msg), analyse);
    gtk_label_set_justify(GTK_LABEL(Label_msg), GTK_JUSTIFY_CENTER);
    gtk_box_pack_start(GTK_BOX(Box), Label_msg, TRUE, TRUE, 0);

        ////////////Affichage de la cle//////////////

    gtk_label_set_markup(GTK_LABEL(Label_cle), "ici les tableaux");
    gtk_label_set_justify(GTK_LABEL(Label_cle), GTK_JUSTIFY_CENTER);
    gtk_box_pack_start(GTK_BOX(Box), Label_cle, TRUE, TRUE, 0);
    
    Bouton2 = gtk_button_new_with_label("Enregistrer le tableau");
    g_signal_connect(G_OBJECT(Bouton2), "clicked", G_CALLBACK(Enregistrer), Label_cle);//pas label cle
    gtk_box_pack_start(GTK_BOX(Box), Bouton2, TRUE, TRUE, 0);
    
    gtk_widget_show_all(Fenetre);
}

void MenuResultatDecryptageSubstitution(GtkWidget *Fenetre, gchar* Cle_et_text_clair)//appeler text clair
{
    Fenetre = gtk_widget_get_toplevel (Fenetre);
    ViderContenaire(GTK_CONTAINER(Fenetre));

    GtkWidget *Box, *Box_2,*Label, *Label_msg,*Label_cle,*Bouton1,*Bouton2,*Bouton3;
    gchar* Text;
    
    
    Box = gtk_vbox_new(TRUE, 0);
    gtk_container_add(GTK_CONTAINER(Fenetre), Box);
    Box_2= gtk_hbox_new(FALSE, 0);
    Label=gtk_label_new(NULL);
    Label_msg=gtk_label_new(NULL);
    Label_cle=gtk_label_new(NULL);

    Text = g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">resultat du decryptage</span>\n<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">Par Substitution</span>\n",
           -1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL(Label), Text);
    g_free(Text);
 
    gtk_label_set_justify(GTK_LABEL(Label), GTK_JUSTIFY_CENTER);

    gtk_box_pack_start(GTK_BOX(Box), Box_2, TRUE, TRUE, 0);

    Bouton3 = gtk_button_new_with_label("R");

    g_signal_connect(G_OBJECT(Bouton3), "clicked", G_CALLBACK(MenuDecryptageSubstitution), NULL);

    gtk_box_pack_start(GTK_BOX(Box_2), Bouton3, FALSE, TRUE, 0);
    
    gtk_box_pack_start(GTK_BOX(Box_2), Label, TRUE, TRUE, 0);

    ////////////Affichage du resultat//////////////

    gtk_label_set_markup(GTK_LABEL(Label_msg), Cle_et_text_clair);

    gtk_label_set_justify(GTK_LABEL(Label_msg), GTK_JUSTIFY_CENTER);

    gtk_box_pack_start(GTK_BOX(Box), Label_msg, TRUE, TRUE, 0);
    
    
    Bouton1 = gtk_button_new_with_label("Enregistrer le msg");

    g_signal_connect(G_OBJECT(Bouton1), "clicked", G_CALLBACK(Enregistrer), Label_msg);
   
    gtk_box_pack_start(GTK_BOX(Box), Bouton1, TRUE, TRUE, 0);

        ////////////Affichage de la cle//////////////

    gtk_label_set_markup(GTK_LABEL(Label_cle), Cle_et_text_clair);

    gtk_label_set_justify(GTK_LABEL(Label_cle), GTK_JUSTIFY_CENTER);

    gtk_box_pack_start(GTK_BOX(Box), Label_cle, TRUE, TRUE, 0);
    
    Bouton2 = gtk_button_new_with_label("Enregistrer la cle");

    g_signal_connect(G_OBJECT(Bouton2), "clicked", G_CALLBACK(Enregistrer), Label_cle);
   
    gtk_box_pack_start(GTK_BOX(Box), Bouton2, TRUE, TRUE, 0);
    
    gtk_widget_show_all(Fenetre);
}

void MenuResultatDecryptageVigenere(GtkWidget *Fenetre, gchar* Text_crypt , gchar* cle)//appeler text clair
{
    Fenetre = gtk_widget_get_toplevel (Fenetre);//on passe a la fenetre du bouton 
    ViderContenaire(GTK_CONTAINER(Fenetre));//on la vide

    GtkWidget *Box, *Box_2,*Label,*Label_msg,*Label_cle,*Bouton1,*Bouton2,*Bouton3;
    gchar* Text;
    
    Box = gtk_vbox_new(TRUE, 0);
    gtk_container_add(GTK_CONTAINER(Fenetre), Box);
    Box_2= gtk_hbox_new(FALSE, 0);
    Label=gtk_label_new(NULL);
    Label_msg=gtk_label_new(NULL);
    Label_cle=gtk_label_new(NULL);

    Text = g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">resultat du decryptage</span>\n<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">Par Vigenere</span>\n",
           -1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL(Label), Text);
    g_free(Text);
 
    gtk_label_set_justify(GTK_LABEL(Label), GTK_JUSTIFY_CENTER);

    gtk_box_pack_start(GTK_BOX(Box), Box_2, TRUE, TRUE, 0);

    Bouton3 = gtk_button_new_with_label("R");

    g_signal_connect(G_OBJECT(Bouton3), "clicked", G_CALLBACK(MenuDecryptageVigenere), NULL);

    gtk_box_pack_start(GTK_BOX(Box_2), Bouton3, FALSE, TRUE, 0);
    
    gtk_box_pack_start(GTK_BOX(Box_2), Label, TRUE, TRUE, 0);

    ////////////Affichage du resultat//////////////

    gtk_label_set_markup(GTK_LABEL(Label_msg), Text_crypt);

    gtk_label_set_justify(GTK_LABEL(Label_msg), GTK_JUSTIFY_CENTER);

    gtk_box_pack_start(GTK_BOX(Box), Label_msg, TRUE, TRUE, 0);
    
    
    Bouton1 = gtk_button_new_with_label("Enregistrer le msg");

    g_signal_connect(G_OBJECT(Bouton1), "clicked", G_CALLBACK(Enregistrer), Label_msg);
   
    gtk_box_pack_start(GTK_BOX(Box), Bouton1, TRUE, TRUE, 0);

        ////////////Affichage de la cle//////////////

    gtk_label_set_markup(GTK_LABEL(Label_cle), cle);

    gtk_label_set_justify(GTK_LABEL(Label_cle), GTK_JUSTIFY_CENTER);

    gtk_box_pack_start(GTK_BOX(Box), Label_cle, TRUE, TRUE, 0);
    
    Bouton2 = gtk_button_new_with_label("Enregistrer la cle");

    g_signal_connect(G_OBJECT(Bouton2), "clicked", G_CALLBACK(Enregistrer), Label_cle);
   
    gtk_box_pack_start(GTK_BOX(Box), Bouton2, TRUE, TRUE, 0);
    
    gtk_widget_show_all(Fenetre);
}

void BoiteDialogueSubstitution(GtkWidget *Fenetre)
{
    GtkWidget *Boite,*Entrer;
    gchar *Text_clair,*Text_crypt;
    GtkTextBuffer* Buffer;
    GtkTextIter debut;
    GtkTextIter fin;
	Fenetre = gtk_widget_get_toplevel (Fenetre);//on passe a la fenetre du bouton 
    Boite = gtk_dialog_new_with_buttons("Sasie du texte",GTK_WINDOW(Fenetre),GTK_DIALOG_MODAL,GTK_STOCK_OK,GTK_RESPONSE_OK,GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,NULL);

    Entrer= gtk_text_view_new();

    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(Boite)->vbox), Entrer, TRUE, TRUE,10);

    gtk_widget_show_all(GTK_DIALOG(Boite)->vbox);

    switch(gtk_dialog_run(GTK_DIALOG(Boite)))
        {
            case GTK_RESPONSE_OK:
                Buffer= gtk_text_view_get_buffer(GTK_TEXT_VIEW(Entrer));
                gtk_text_buffer_get_start_iter(Buffer,&debut);
                gtk_text_buffer_get_end_iter(Buffer,&fin);
                Text_clair = gtk_text_buffer_get_text(Buffer,&debut,&fin,FALSE);
                CryptageSubstitution(Text_crypt,Text_clair);
                MenuResultatSubstitution(Fenetre, Text_crypt);
                 //on rajoutera plus tard la cle de sub
                // ici on doit pouvoir sauvegarder le texte dans la variable Nom
                g_free(Text_clair);//si plus besoin
                break;
            case GTK_RESPONSE_CANCEL:
            case GTK_RESPONSE_NONE:
            default:
                break;
        }
        
    gtk_widget_destroy(Boite);
}

void BoiteDialogueVigenere(GtkWidget *Fenetre)
{

	    GtkWidget *Boite,*Entrer,*Entrer_cle,*Label_text,*Label_cle;
	    gchar *Text_crypt,*Text_clair,*cle,*msg,*indication_cle;
	    GtkTextBuffer* Buffer;
	    GtkTextIter debut;
	    GtkTextIter fin;
	    Fenetre = gtk_widget_get_toplevel (Fenetre);//on passe a la fenetre du bouton 
	    Boite = gtk_dialog_new_with_buttons("Sasie du texte",GTK_WINDOW(Fenetre),GTK_DIALOG_MODAL,GTK_STOCK_OK,GTK_RESPONSE_OK,GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,NULL);

	    Label_text=gtk_label_new(NULL);
	    Label_cle=gtk_label_new(NULL);
	    
	    	msg= g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">Votre texte : </span>\n",
	           -1, NULL, NULL, NULL);
	   

	    indication_cle = g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">Votre cle : </span>\n",
	           -1, NULL, NULL, NULL);
	    
	   
	   		
	    	Entrer= gtk_text_view_new();

	    	gtk_label_set_markup(GTK_LABEL(Label_text), msg);

	    	gtk_label_set_justify(GTK_LABEL(Label_text), GTK_JUSTIFY_CENTER);

	    	gtk_box_pack_start(GTK_BOX(GTK_DIALOG(Boite)->vbox), Entrer, TRUE, TRUE,10);


	    
	   
	    

	    Entrer_cle=gtk_text_view_new();

	    gtk_label_set_markup(GTK_LABEL(Label_cle), indication_cle);

	    gtk_label_set_justify(GTK_LABEL(Label_cle), GTK_JUSTIFY_CENTER);

	    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(Boite)->vbox), Label_cle, TRUE, FALSE,0);
	    
	    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(Boite)->vbox), Entrer_cle, TRUE, TRUE,10);
	    
	    gtk_widget_show_all(GTK_DIALOG(Boite)->vbox);

	    switch(gtk_dialog_run(GTK_DIALOG(Boite)))
	        {
	            case GTK_RESPONSE_OK:
		            Buffer= gtk_text_view_get_buffer(GTK_TEXT_VIEW(Entrer));
		            gtk_text_buffer_get_start_iter(Buffer,&debut);
		            gtk_text_buffer_get_end_iter(Buffer,&fin);
		            Text_clair = gtk_text_buffer_get_text(Buffer,&debut,&fin,FALSE);
		      
		        	
		           
	                Buffer= gtk_text_view_get_buffer(GTK_TEXT_VIEW(Entrer_cle));
	                gtk_text_buffer_get_start_iter(Buffer,&debut);
	                gtk_text_buffer_get_end_iter(Buffer,&fin);
	                cle = gtk_text_buffer_get_text(Buffer,&debut,&fin,FALSE);
	                CryptageVigenere(Text_crypt,Text_clair, cle);
	                MenuResultatVigenere(Fenetre, Text_crypt, cle);
	                 //on rajoutera plus tard la cle de sub
	                // ici on doit pouvoir sauvegarder le texte dans la variable Nom
	                g_free(Text_clair);//si plus besoin
	                break;
	            case GTK_RESPONSE_CANCEL:
	            case GTK_RESPONSE_NONE:
	            default:
	                break;
	        }
	        
	    gtk_widget_destroy(Boite);
	
}

void BoiteDialogueAnalyse(GtkWidget *Fenetre)
{
	ANALYSE a;
    GtkWidget *Boite,*Entrer;
    gchar* Text;
    GtkTextBuffer* Buffer;
    GtkTextIter debut;
    GtkTextIter fin;
	Fenetre = gtk_widget_get_toplevel (Fenetre);//on passe a la fenetre du bouton 
    Boite = gtk_dialog_new_with_buttons("Sasie du texte",GTK_WINDOW(Fenetre),GTK_DIALOG_MODAL,GTK_STOCK_OK,GTK_RESPONSE_OK,GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,NULL);

    Entrer= gtk_text_view_new();

    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(Boite)->vbox), Entrer, TRUE, TRUE,10);

    gtk_widget_show_all(GTK_DIALOG(Boite)->vbox);

    switch(gtk_dialog_run(GTK_DIALOG(Boite)))
        {
            case GTK_RESPONSE_OK:
                Buffer= gtk_text_view_get_buffer(GTK_TEXT_VIEW(Entrer));
                gtk_text_buffer_get_start_iter(Buffer,&debut);
                gtk_text_buffer_get_end_iter(Buffer,&fin);
                Text = gtk_text_buffer_get_text(Buffer,&debut,&fin,FALSE);
                a = AnalyseFrequentielle(Text);//changer pour travailler avec analyse
                MenuResultatAnalyse(Fenetre,Text);
                break;
            case GTK_RESPONSE_CANCEL:
            case GTK_RESPONSE_NONE:
            default:
                break;
        }
        
    gtk_widget_destroy(Boite);
}

void BoiteDialogueDecryptageSubstitution(GtkWidget *Fenetre)
{
    GtkWidget *Boite,*Entrer,*Entrer_cle,*Label_text,*Label_cle;
    gchar *Text_clair,*Text_crypt,*cle,*msg,*indication_cle;
    GtkTextBuffer* Buffer;
    GtkTextIter debut;
    GtkTextIter fin;
    Fenetre = gtk_widget_get_toplevel (Fenetre); 
    Boite = gtk_dialog_new_with_buttons("Sasie du texte",GTK_WINDOW(Fenetre),GTK_DIALOG_MODAL,GTK_STOCK_OK,GTK_RESPONSE_OK,GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,NULL);

    Label_text=gtk_label_new(NULL);
    Label_cle=gtk_label_new(NULL);

     msg= g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">Votre texte : </span>\n",
           -1, NULL, NULL, NULL);

    Entrer= gtk_text_view_new();

    gtk_label_set_markup(GTK_LABEL(Label_text), msg);

    gtk_label_set_justify(GTK_LABEL(Label_text), GTK_JUSTIFY_CENTER);

    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(Boite)->vbox), Label_text, TRUE, FALSE,0);


    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(Boite)->vbox), Entrer, TRUE, TRUE,10);


    gtk_widget_show_all(GTK_DIALOG(Boite)->vbox);

    switch(gtk_dialog_run(GTK_DIALOG(Boite)))
        {
            case GTK_RESPONSE_OK:
                Buffer= gtk_text_view_get_buffer(GTK_TEXT_VIEW(Entrer));
                gtk_text_buffer_get_start_iter(Buffer,&debut);
                gtk_text_buffer_get_end_iter(Buffer,&fin);
                Text_crypt = gtk_text_buffer_get_text(Buffer,&debut,&fin,FALSE);
               
                MenuResultatDecryptagePartiel(Fenetre, Text_crypt);
                break;
            case GTK_RESPONSE_CANCEL:
            case GTK_RESPONSE_NONE:
            default:
                break;
        }
        
    gtk_widget_destroy(Boite);
}

void BoiteDialogueDecryptageVigenere(GtkWidget *Fenetre)
{
    GtkWidget *Boite,*Entrer,*Entrer_cle,*Label_text,*Label_cle;
    gchar *Text_clair,*Text_crypt,*cle,*msg,*indication_cle;
    GtkTextBuffer* Buffer;
    GtkTextIter debut;
    GtkTextIter fin;
    Fenetre = gtk_widget_get_toplevel (Fenetre);//on passe a la fenetre du bouton 
    Boite = gtk_dialog_new_with_buttons("Sasie du texte",GTK_WINDOW(Fenetre),GTK_DIALOG_MODAL,GTK_STOCK_OK,GTK_RESPONSE_OK,GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,NULL);

    Label_text=gtk_label_new(NULL);
    Label_cle=gtk_label_new(NULL);

     msg= g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">Votre texte : </span>\n",
           -1, NULL, NULL, NULL);

    indication_cle = g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">Votre cle : </span>\n",
           -1, NULL, NULL, NULL);

    Entrer= gtk_text_view_new();

    gtk_label_set_markup(GTK_LABEL(Label_text), msg);
    gtk_label_set_justify(GTK_LABEL(Label_text), GTK_JUSTIFY_CENTER);
    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(Boite)->vbox), Label_text, TRUE, FALSE,0);

    gtk_box_pack_start(GTK_BOX(GTK_DIALOG(Boite)->vbox), Entrer, TRUE, TRUE,10);


    gtk_widget_show_all(GTK_DIALOG(Boite)->vbox);

    switch(gtk_dialog_run(GTK_DIALOG(Boite)))
        {
            case GTK_RESPONSE_OK:
                Buffer= gtk_text_view_get_buffer(GTK_TEXT_VIEW(Entrer));
                gtk_text_buffer_get_start_iter(Buffer,&debut);
                gtk_text_buffer_get_end_iter(Buffer,&fin);
                Text_crypt = gtk_text_buffer_get_text(Buffer,&debut,&fin,FALSE);
                DecryptageVigenere(Text_clair,Text_crypt,Text_crypt);
                MenuResultatDecryptageVigenere(Fenetre, Text_clair , Text_clair);//il faut mettre la cle
                 //on rajoutera plus tard la cle de sub
                // ici on doit pouvoir sauvegarder le texte dans la variable Nom
                g_free(Text_clair);//si plus besoin
                break;
            case GTK_RESPONSE_CANCEL:
            case GTK_RESPONSE_NONE:
            default:
                break;
        }
        
    gtk_widget_destroy(Boite);
}

void MenuDecryptageVigenere(GtkWidget *Fenetre)
{
    Fenetre = gtk_widget_get_toplevel (Fenetre);
	ViderContenaire(GTK_CONTAINER(Fenetre));
	GtkWidget *Box,*Bouton1, *Bouton2, *Bouton3,*Box_2, *Label;
    gchar* Text;
    choix=4;
    
    Box = gtk_vbox_new(TRUE, 0);
    gtk_container_add(GTK_CONTAINER(Fenetre), Box);
    Box_2 = gtk_hbox_new(FALSE, 0);
    
    Label=gtk_label_new(NULL);
    Text = g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">decryptage Vige</span>\n",
    -1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL(Label), Text);
    g_free(Text);
    gtk_label_set_justify(GTK_LABEL(Label), GTK_JUSTIFY_CENTER);

    gtk_box_pack_start(GTK_BOX(Box), Box_2, TRUE, TRUE, 0);

    Bouton3 = gtk_button_new_with_label("R");
    g_signal_connect(G_OBJECT(Bouton3), "clicked", G_CALLBACK(MenuDecryptage), NULL);
    gtk_box_pack_start(GTK_BOX(Box_2), Bouton3, FALSE, TRUE, 0);

    gtk_box_pack_start(GTK_BOX(Box_2), Label, TRUE, TRUE, 0);
    
    Bouton1 = gtk_button_new_with_label("zone de texte");
    g_signal_connect(G_OBJECT(Bouton1), "clicked", G_CALLBACK(BoiteDialogueDecryptageVigenere), NULL);
    gtk_box_pack_start(GTK_BOX(Box), Bouton1, TRUE, TRUE, 0);
    
    Bouton2 = gtk_button_new_with_label("charger");
    g_signal_connect(G_OBJECT(Bouton2), "clicked", G_CALLBACK(ChoisirFichier), NULL);
    gtk_box_pack_start(GTK_BOX(Box), Bouton2, TRUE, TRUE, 0);
    
    gtk_widget_show_all(Fenetre);
}

void MenuDecryptageSubstitution(GtkWidget *Fenetre)
{
    Fenetre = gtk_widget_get_toplevel (Fenetre);
	ViderContenaire(GTK_CONTAINER(Fenetre));
	GtkWidget *Box,*Bouton1, *Bouton2, *Bouton3,*Box_2, *Label;
    gchar* Text;
    choix=3;
    
    Box = gtk_vbox_new(TRUE, 0);
    gtk_container_add(GTK_CONTAINER(Fenetre), Box);
    Box_2 = gtk_hbox_new(FALSE, 0);
    
    Label=gtk_label_new(NULL);
    Text = g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">decryptage sub</span>\n",
    -1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL(Label), Text);
    g_free(Text);
    gtk_label_set_justify(GTK_LABEL(Label), GTK_JUSTIFY_CENTER);

    gtk_box_pack_start(GTK_BOX(Box), Box_2, TRUE, TRUE, 0);

    Bouton3 = gtk_button_new_with_label("R");
    g_signal_connect(G_OBJECT(Bouton3), "clicked", G_CALLBACK(MenuDecryptage), NULL);
    gtk_box_pack_start(GTK_BOX(Box_2), Bouton3, FALSE, TRUE, 0);

    gtk_box_pack_start(GTK_BOX(Box_2), Label, TRUE, TRUE, 0);
    
    Bouton1 = gtk_button_new_with_label("zone de texte");
    g_signal_connect(G_OBJECT(Bouton1), "clicked", G_CALLBACK(BoiteDialogueDecryptageSubstitution), NULL);
    gtk_box_pack_start(GTK_BOX(Box), Bouton1, TRUE, TRUE, 0);
    
    Bouton2 = gtk_button_new_with_label("charger puis resultat");
    g_signal_connect(G_OBJECT(Bouton2), "clicked", G_CALLBACK(ChoisirFichier), NULL);
    gtk_box_pack_start(GTK_BOX(Box), Bouton2, TRUE, TRUE, 0);
    
    gtk_widget_show_all(Fenetre);
}

void MenuCryptageVigenere(GtkWidget *Fenetre)
{
    Fenetre = gtk_widget_get_toplevel (Fenetre);
	ViderContenaire(GTK_CONTAINER(Fenetre));
	GtkWidget *Box,*Bouton1, *Bouton2, *Bouton3,*Box_2, *Label;
    gchar *Text;
    GtkWidget* zone_t;
    choix=2;
    
    Box = gtk_vbox_new(TRUE, 0);
    gtk_container_add(GTK_CONTAINER(Fenetre), Box);
    Box_2 = gtk_hbox_new(FALSE, 0);
    
    Label=gtk_label_new(NULL);
    Text = g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">cryptage Vige</span>\n",
    -1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL(Label), Text);
    g_free(Text);
    gtk_label_set_justify(GTK_LABEL(Label), GTK_JUSTIFY_CENTER);

    gtk_box_pack_start(GTK_BOX(Box), Box_2, TRUE, TRUE, 0);

    Bouton3 = gtk_button_new_with_label("R");
    g_signal_connect(G_OBJECT(Bouton3), "clicked", G_CALLBACK(MenuCryptage), NULL);
    gtk_box_pack_start(GTK_BOX(Box_2), Bouton3, FALSE, TRUE, 0);

    gtk_box_pack_start(GTK_BOX(Box_2), Label, TRUE, TRUE, 0);
    
    Bouton1 = gtk_button_new_with_label("Rentrer un texte ");
    g_signal_connect(G_OBJECT(Bouton1), "clicked", G_CALLBACK(BoiteDialogueVigenere), NULL);
    gtk_box_pack_start(GTK_BOX(Box), Bouton1, TRUE, TRUE, 0);
    
    Bouton2 = gtk_button_new_with_label("choisir un fichier");
    g_signal_connect(G_OBJECT(Bouton2), "clicked", G_CALLBACK(ChoisirFichier), NULL);
    gtk_box_pack_start(GTK_BOX(Box), Bouton2, TRUE, TRUE, 0);
    
    gtk_widget_show_all(Fenetre);
}

void MenuCryptageSubstitution(GtkWidget *Fenetre)
{
    Fenetre = gtk_widget_get_toplevel (Fenetre); 
	ViderContenaire(GTK_CONTAINER(Fenetre));
	GtkWidget *Box,*Bouton1, *Bouton2, *Bouton3,*Box_2, *Label;
    gchar* Text;
    GtkWidget* zone_t;
    choix=1;
    
    Box = gtk_vbox_new(TRUE, 0);
    gtk_container_add(GTK_CONTAINER(Fenetre), Box);
    Box_2= gtk_hbox_new(FALSE, 0);
    
    Label=gtk_label_new(NULL);
    Text = g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">cryptage sub</span>\n",
    -1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL(Label), Text);
    g_free(Text);
    gtk_label_set_justify(GTK_LABEL(Label), GTK_JUSTIFY_CENTER);

    gtk_box_pack_start(GTK_BOX(Box), Box_2, TRUE, TRUE, 0);

    Bouton3 = gtk_button_new_with_label("R");
    g_signal_connect(G_OBJECT(Bouton3), "clicked", G_CALLBACK(MenuCryptage), NULL);
    gtk_box_pack_start(GTK_BOX(Box_2), Bouton3, FALSE, TRUE, 0);

    gtk_box_pack_start(GTK_BOX(Box_2), Label, TRUE, TRUE, 0);
    
    Bouton1 = gtk_button_new_with_label("Rentrer un texte ");
    g_signal_connect(G_OBJECT(Bouton1), "clicked", G_CALLBACK(BoiteDialogueSubstitution), NULL);
    gtk_box_pack_start(GTK_BOX(Box), Bouton1, TRUE, TRUE, 0);
    
    Bouton2 = gtk_button_new_with_label("choisir un fichier");
    g_signal_connect(G_OBJECT(Bouton2), "clicked", G_CALLBACK(ChoisirFichier), NULL);
    gtk_box_pack_start(GTK_BOX(Box), Bouton2, TRUE, TRUE, 0);
    
    gtk_widget_show_all(Fenetre);

}

void MenuAnalyseFrequentielle(GtkWidget *Fenetre)
{
    Fenetre = gtk_widget_get_toplevel (Fenetre);
	ViderContenaire(GTK_CONTAINER(Fenetre));
	GtkWidget *Box,*Bouton1, *Bouton2, *Bouton3,*Box_2, *Label;
    gchar* Text;
    GtkWidget* zone_t;
    choix=5;
    Box = gtk_vbox_new(TRUE, 0);
    gtk_container_add(GTK_CONTAINER(Fenetre), Box);
    Box_2 = gtk_hbox_new(FALSE, 0);
   
    Label=gtk_label_new(NULL);
    Text = g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">etude de texte</span>\n"
    "<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">Choose the method pour entrer le texte</span>\n",
    -1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL(Label), Text);
    g_free(Text);
    gtk_label_set_justify(GTK_LABEL(Label), GTK_JUSTIFY_CENTER);

    gtk_box_pack_start(GTK_BOX(Box), Box_2, TRUE, TRUE, 0);

    Bouton3 = gtk_button_new_with_label("R");
    g_signal_connect(G_OBJECT(Bouton3), "clicked", G_CALLBACK(MenuPrincipal), NULL);
    gtk_box_pack_start(GTK_BOX(Box_2), Bouton3, FALSE, TRUE, 0);

    gtk_box_pack_start(GTK_BOX(Box_2), Label, TRUE, TRUE, 0);
    
    Bouton1 = gtk_button_new_with_label("Rentrer un texte ");
    g_signal_connect(G_OBJECT(Bouton1), "clicked", G_CALLBACK(BoiteDialogueAnalyse), NULL);
    gtk_box_pack_start(GTK_BOX(Box), Bouton1, TRUE, TRUE, 0);
    
    Bouton2 = gtk_button_new_with_label("choisir un fichier");
    g_signal_connect(G_OBJECT(Bouton2), "clicked", G_CALLBACK(ChoisirFichier), NULL);
    gtk_box_pack_start(GTK_BOX(Box), Bouton2, TRUE, TRUE, 0);
    
    gtk_widget_show_all(Fenetre);

}

void MenuDecryptage(GtkWidget *Fenetre)
{
    Fenetre = gtk_widget_get_toplevel (Fenetre); 
	ViderContenaire(GTK_CONTAINER(Fenetre));
	GtkWidget *Box,*Bouton1, *Bouton2, *Bouton3,*Box_2, *Label;
    gchar* Text;
    
    Box = gtk_vbox_new(TRUE, 0);
    gtk_container_add(GTK_CONTAINER(Fenetre), Box);
    Box_2=gtk_hbox_new(FALSE, 0);
    
    Label=gtk_label_new(NULL);
    Text = g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">Decryptage</span>\n"
    "<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">Choose the method</span>\n",
    -1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL(Label), Text);
    g_free(Text);
    gtk_label_set_justify(GTK_LABEL(Label), GTK_JUSTIFY_CENTER);

    gtk_box_pack_start(GTK_BOX(Box), Box_2, TRUE, TRUE, 0);

    Bouton3 = gtk_button_new_with_label("R");
    g_signal_connect(G_OBJECT(Bouton3), "clicked", G_CALLBACK(MenuPrincipal), NULL);
    gtk_box_pack_start(GTK_BOX(Box_2), Bouton3, FALSE, TRUE, 0);

    gtk_box_pack_start(GTK_BOX(Box_2), Label, TRUE, TRUE, 0);
    
    Bouton1 = gtk_button_new_with_label("Substitution");
    g_signal_connect(G_OBJECT(Bouton1), "clicked", G_CALLBACK(MenuDecryptageSubstitution), NULL);
    gtk_box_pack_start(GTK_BOX(Box), Bouton1, TRUE, TRUE, 0);
    
    Bouton2 = gtk_button_new_with_label("Vigenere");
    g_signal_connect(G_OBJECT(Bouton2), "clicked", G_CALLBACK(MenuDecryptageVigenere), NULL);
    gtk_box_pack_start(GTK_BOX(Box), Bouton2, TRUE, TRUE, 0);
    
    gtk_widget_show_all(Fenetre);
}

void MenuCryptage(GtkWidget *Fenetre)
{
    Fenetre = gtk_widget_get_toplevel (Fenetre);
	ViderContenaire(GTK_CONTAINER(Fenetre));
	GtkWidget *Box,*Bouton1, *Bouton2, *Bouton3,*Box_2, *Label;
    gchar* Text;
    
    Box = gtk_vbox_new(TRUE, 0);
    gtk_container_add(GTK_CONTAINER(Fenetre), Box);
    Box_2=gtk_hbox_new(FALSE, 0);

    Label=gtk_label_new(NULL);
    Text = g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">Cryptage</span>\n"
    "<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">Choose the method</span>\n",
    -1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL(Label), Text);
    g_free(Text);
    gtk_label_set_justify(GTK_LABEL(Label), GTK_JUSTIFY_CENTER);

    gtk_box_pack_start(GTK_BOX(Box), Box_2, TRUE, TRUE, 0);

    Bouton3 = gtk_button_new_with_label("R");
    g_signal_connect(G_OBJECT(Bouton3), "clicked", G_CALLBACK(MenuPrincipal), NULL);
    gtk_box_pack_start(GTK_BOX(Box_2), Bouton3, FALSE, TRUE, 0);
    
    gtk_box_pack_start(GTK_BOX(Box_2), Label, TRUE, TRUE, 0);

    Bouton1 = gtk_button_new_with_label("Substitution");
    g_signal_connect(G_OBJECT(Bouton1), "clicked", G_CALLBACK(MenuCryptageSubstitution), NULL);
    gtk_box_pack_start(GTK_BOX(Box), Bouton1, TRUE, TRUE, 0);
    
    Bouton2 = gtk_button_new_with_label("Vigenere");
    g_signal_connect(G_OBJECT(Bouton2), "clicked", G_CALLBACK(MenuCryptageVigenere), NULL);
    gtk_box_pack_start(GTK_BOX(Box), Bouton2, TRUE, TRUE, 0);
    
    gtk_widget_show_all(Fenetre);
}

void MenuPrincipal(GtkWidget *Fenetre)
{
    Fenetre = gtk_widget_get_toplevel (Fenetre);
	ViderContenaire(GTK_CONTAINER(Fenetre));
	GtkWidget *Box, *Label,*Bouton1, *Bouton2, *Bouton3;
    gchar* Text;
    
    Box = gtk_vbox_new(TRUE, 0);
    gtk_container_add(GTK_CONTAINER(Fenetre), Box);

    Label=gtk_label_new(NULL);
    Text = g_locale_to_utf8("<span font_desc=\"Times New Roman italic 12\" foreground=\"#1d1d1d\">Welcome to DecryptUs</span>\n",
    -1, NULL, NULL, NULL);
    gtk_label_set_markup(GTK_LABEL(Label), Text);
    g_free(Text);
    gtk_label_set_justify(GTK_LABEL(Label), GTK_JUSTIFY_CENTER);
    gtk_box_pack_start(GTK_BOX(Box), Label, TRUE, TRUE, 0);
    
    Bouton1 = gtk_button_new_with_label("Crypter");
    g_signal_connect(G_OBJECT(Bouton1), "clicked", G_CALLBACK(MenuCryptage), NULL);
    gtk_box_pack_start(GTK_BOX(Box), Bouton1, TRUE, TRUE, 0);
    
    Bouton2 = gtk_button_new_with_label("Decrypter");
    g_signal_connect(G_OBJECT(Bouton2), "clicked", G_CALLBACK(ChoisirLangue), NULL);
    gtk_box_pack_start(GTK_BOX(Box), Bouton2, TRUE, TRUE, 0);
    
    Bouton3 = gtk_button_new_with_label("Etude de texte");
    g_signal_connect(G_OBJECT(Bouton3), "clicked", G_CALLBACK(MenuAnalyseFrequentielle), NULL);
    gtk_box_pack_start(GTK_BOX(Box), Bouton3, TRUE, TRUE, 0);
    
    gtk_widget_show_all(Fenetre);
}



/*
 * le travail a fournir 
recuperer chemin faut mettre les clées 
il faut mettre une barre de progression pour eviter les seg faults (fait 70% )
choisir fichier pour analyse freq(fait)
changer le nom de choisirlangue

* les problemes rencontrés 
il ya des seg fault quand on fait 2 enregistrement du texte
apres avoir charger il faut une fonction remplir tableau qui emmene vers la page d'apres
*/
