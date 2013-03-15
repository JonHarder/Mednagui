#include<gtk/gtk.h>


static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data) {
	g_print("Bye bye!\n");
	gtk_main_quit();
	return FALSE;
}

void store_filename(GtkWidget *widget, gpointer user_data) {
	GtkWidget *fileSelector = GTK_WIDGET(user_data);
	const gchar *selected_filename;

	selected_filename = gtk_file_selection_get_filename(GTK_FILE_SELECTION(fileSelector));
	g_print("Selected filename: %s\n", selected_filename);
}


int main(int argc, char *argv[]) {
	gtk_init(&argc, &argv);

	GtkWidget *fileSelect = gtk_file_selection_new("Select a game.");
	g_signal_connect(fileSelect, "destroy", G_CALLBACK(delete_event), NULL);
	// call store_filename when ok is pressed
	g_signal_connect(GTK_FILE_SELECTION(fileSelect)->ok_button, "clicked",
			G_CALLBACK(store_filename), fileSelect);
	g_signal_connect(GTK_FILE_SELECTION(fileSelect)->cancel_button,
			"clicked", G_CALLBACK(delete_event), fileSelect);

	gtk_widget_show(fileSelect);

	gtk_main();

	return 0;
}
