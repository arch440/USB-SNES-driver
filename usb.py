import sys
import usb
import usb.core
#--import usb.util

 
# find our device
dev = usb.core.find(idVendor=0x045e, idProduct=0x02B0)
 
# was it found?
if dev is None:
    raise ValueError('Device not found')
 
# set the active configuration. With no arguments, the first
# configuration will be the active one
dev.set_configuration()
 
print "all done"
