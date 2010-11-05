tatic struct usb_driver skel_driver = {
    name:        "skeleton",
    probe:       skel_probe,
    disconnect:  skel_disconnect,
    fops:        &skel_fops,
    minor:       USB_SKEL_MINOR_BASE,
    id_table:    skel_table,
};
