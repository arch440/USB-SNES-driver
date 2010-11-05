static int __init usb_skel_init(void)
{
    int result;
    /* register this driver with the USB subsystem */
    result = usb_register(&skel_driver);
    if (result < 0) {
        err("usb_register failed for the "__FILE__
        " driver. Error number %d", result);
        return -1;
    }
    return 0;
}
module_init(usb_skel_init);
