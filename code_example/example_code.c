#include<linux/module.h>
#include<linux/init.h>
#include<linux/moduleparam.h>

static int loops = 10;
static int i_array[10] = {0};
static char * mod_show = "hello";

static int __init mod_init(void)
{
	int i = 0;
	for(; i < loops; i++){
		printk(KERN_WARNING "S:%s:%d\n", mod_show, i_array[i]);
	}
	return 0;
}

static void __exit mod_exit(void)
{
	int i = 0;
	for(; i < loops; i++){
		printk(KERN_INFO "K:%s:%d\n", mod_show, i_array[i]);
	}
	return;
}

static void mod_export(void)
{
	printk(KERN_DEBUG "mod_export\n");
}

module_init(mod_init);
module_exit(mod_exit);
module_param(mod_show, charp, S_IRUGO|S_IWUSR);
module_param_array(i_array, int, &loops, S_IRUGO|S_IWUSR);

EXPORT_SYMBOL_GPL(mod_export);
MODULE_AUTHOR("sethe");
MODULE_DESCRIPTION("just for example.");
MODULE_VERSION("0.0.1");
MODULE_LICENSE("GPL");
