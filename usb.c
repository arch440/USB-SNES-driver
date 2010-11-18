#include <usb.h>
#include <stdio.h>

void printdev();
   
int main(){   
    
    
    
    usb_init();
    usb_find_busses();
    usb_find_devices();
    struct usb_bus* bus;
    bus = usb_get_busses();
    int ret;
    char string[512];
    struct usb_device* dev;


    printf("bus/device idVendor/idProduct\n");
    for (; bus != NULL; bus = bus->next) {
        for (dev = bus->devices; dev; dev = dev->next) {
            usb_dev_handle *udev;
            printf("%s/%s %04X/%04X\n", bus->dirname, dev->filename,
            dev->descriptor.idVendor, dev->descriptor.idProduct);
           	udev = usb_open(dev);
           	if (udev) {
        		if (dev->descriptor.iManufacturer) {
         			ret = usb_get_string_simple(udev, dev->descriptor.iManufacturer,
            		string, sizeof (string));
            		if (ret > 0)
           				printf("- Manufacturer : %s\n", string);
            		else
                		printf("- Unable to fetch manufacturer string\n");
                }
        	}
    	}
	}
}
        
