#include <linux/module.h>
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/moduleparam.h>


static int bye_code = 0;

static int __init mod_init(void)
{
    printk(KERN_INFO "%d\n", current->pid);
    return 0;
}

static void __exit mod_exit(void)
{
    printk(KERN_INFO "%d\n", bye_code);
    return;
}

static void mod_export(void)
{
    printk(KERN_INFO "export func\n");
    return;
}

module_init(mod_init);
module_exit(mod_exit);
module_param(bye_code, int, 0664);

EXPORT_SYMBOL(mod_export);
MODULE_AUTHOR("sethe");
MODULE_DESCRIPTION("test for get self pid");
MODULE_LICENSE("GPL");
