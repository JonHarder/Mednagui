#include<gtk/gtk.h>

static gboolean delete_event(GtkWidget *widget, GdkEvent *event, gpointer data) {
	gtk_main_quit();
	return FALSE;
}

int main(int argc, char *argv[]) {
	GtkWidget *window;

	gtk_init(&argc, &argv);

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Mednagui");

	g_signal_connect(window, "delete-event", G_CALLBACK(delete_event), NULL);

	gtk_widget_show(window);

	gtk_main();

	return 0;
}
