#include<gtk/gtk.h>


static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data) {
	g_print("Bye bye!\n");
	gtk_main_quit();
	return FALSE;
}

int main(int argc, char *argv[]) {
	gtk_init(&argc, &argv);

	GtkWidget *fileSelect = gtk_file_selection_new("Select a game.");
	g_signal_connect(fileSelect, "destroy", G_CALLBACK(delete_event), NULL);

	gtk_widget_show(fileSelect);

	gtk_main();

	return 0;
}
