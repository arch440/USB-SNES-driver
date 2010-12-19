#include <libusb-1.0/libusb.h>
//#include <usb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VID 0x0e8f
#define PID 0x3013
#define true  1
#define false 0

char string[512];
struct usb_bus* bus;
struct usb_device* dev;
usb_dev_handle* udev;

void printdev();
void probedev();
struct usb_dev_handle* get_green();
