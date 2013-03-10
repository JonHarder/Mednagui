all: mednagui

mednagui: mednagui.c
	gcc mednagui.c -o mednagui `pkg-config --cflags --libs gtk+-2.0`


