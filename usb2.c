//gcc -std=c99 -pedantic -Wall usb2.c -o run -lusb-1.0 -I/usr/include/libusb-1.0

//pkg-config --cflags libusb-1.0
//pkg-config --libs libusb-1.0


#include "usb2.h"

int main(void){

	libusb_context** ctx = NULL;
	libusb_init(ctx);
	libusb_set_debug(*ctx, 3);	
	
	return 0;

	
}

void get_green(libusb_context** ctx){
	libusb_get_device_list(*ctx, NULL);
	
		
}



