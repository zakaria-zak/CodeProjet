#include "InterfaceGraphique.h" 


int main(int argc, char **argv)
{
    gtk_init(&argc, &argv);
    Fenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL); 
    gtk_rc_parse("theme");
    gtk_window_set_title(GTK_WINDOW(Fenetre), "DecryptUs");
    gtk_window_set_default_size(GTK_WINDOW(Fenetre), largeur, hauteur);

    g_signal_connect(G_OBJECT(Fenetre), "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    MenuPrincipal(Fenetre);
 
    gtk_main();
    return EXIT_SUCCESS;
}
