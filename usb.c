#include "usb.h"

int main(void){
    usb_init();
    usb_find_busses();
    usb_find_devices();
	printdev(bus, dev);
	probedev(bus, dev);
}

void probedev(struct usb_bus* bus, struct usb_device* dev){
	int i = 0;
	for(bus = usb_get_busses(); bus != NULL; bus = bus->next){
    	for(dev = bus->devices; dev != NULL; dev = dev->next){
			printf("VID%d: %x\nPID%d: %x\n", i, dev->descriptor.idVendor,
			i, dev->descriptor.idProduct);
			i++;
		}
	}	
}

void printdev(struct usb_bus* bus, struct usb_device* dev){
    printf("bus/device idVendor/idProduct\n");
    for(bus = usb_get_busses(); bus != NULL; bus = bus->next){
        for(dev = bus->devices; dev != NULL; dev = dev->next){
            printf("%s/%s %04X/%04X\n", bus->dirname, dev->filename,
            dev->descriptor.idVendor, dev->descriptor.idProduct);
			udev = usb_open(dev);
           	if(udev){
        		if(dev->descriptor.iManufacturer){
         			int ret = usb_get_string_simple(
         			udev,dev->descriptor.iManufacturer, string, sizeof (string));
            		if(ret > 0)
           				printf("Manufacturer: %s\n", string);
            		else
                		printf("Unable to fetch manufacturer string\n");
                } else
                	printf("No manufacturer descriptor\n");
        	}
        	usb_close(udev);
    	}
    }
}

        
