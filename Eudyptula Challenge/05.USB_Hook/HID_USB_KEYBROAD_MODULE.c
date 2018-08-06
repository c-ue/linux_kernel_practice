#include<linux/kernel.h>
#include<linux/init.h>
#include<linux/module.h>
#include<linux/usb.h>
#include<linux/hid.h>

MODULE_DESCRIPTION("USB Keybroad Driver sample.");
MODULE_AUTHOR("andysetun@gmail.com");
MODULE_LICENSE("GPL");

static const struct usb_device_id skel_table[] = {
	{ USB_INTERFACE_INFO(USB_INTERFACE_CLASS_HID, USB_INTERFACE_SUBCLASS_BOOT,
	USB_INTERFACE_PROTOCOL_KEYBOARD) },
	{ }
};

MODULE_DEVICE_TABLE(usb, skel_table);

static int __init start_hello(void)
{
	printk(KERN_DEBUG "\x1b[;33mHID_USB_KEYBROAD_MODULE\x1b[;0m: USB KEYBROAD INSERT.\n");
	return 0;
}

static void __exit stop_hello(void)
{
	printk(KERN_DEBUG "\x1b[;33mhelloWorld\x1b[;0m: GOOD BYE\n");
}

module_init(start_hello);
module_exit(stop_hello);

