#include <usb.h>
#include <stdio.h>
#define MID 0x0000
#define VID 0x0000

char string[256];
struct usb_bus* bus;
struct usb_device* dev;
usb_dev_handle* udev;

void printdev();
void probedev();
