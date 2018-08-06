#include"linux/kernel.h"
#include"linux/init.h"
#include"linux/module.h"

MODULE_DESCRIPTION("HELLO WORLD");
MODULE_AUTHOR("andysetun@gmail.com");
MODULE_LICENSE("GPL");

static int __init start_hello(void){
	printk(KERN_DEBUG "\x1b[;33mhelloWorld\x1b[;0m: Hello World!\n");
	return 0;
}

static void __exit stop_hello(void){
	printk(KERN_DEBUG "\x1b[;33mhelloWorld\x1b[;0m: GOOD BYE\n");
}

module_init(start_hello);
module_exit(stop_hello);
