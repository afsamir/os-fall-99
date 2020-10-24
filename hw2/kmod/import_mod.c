/*
 * =====================================================================================
 *
 *       Filename:  import_mod.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/16/2020 01:06:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Amir Afsari
 *
 *
 * =====================================================================================
 */


#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/time.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("afsamir");
MODULE_DESCRIPTION("A module to print average and mean age of geraami ta's.");
MODULE_VERSION("1");



int get_average_age_times10(void);
int get_age_gap(void);

__init int __init mod_init(void) {
	int avg = get_average_age_times10();
	printk(KERN_INFO "Module installed.\n");
	avg%10==0? printk(KERN_INFO "Average age is %d\n",avg/10):printk(KERN_INFO"Average age is %d.5\n", avg/10);
    printk(KERN_INFO "Age gap is %d\n", get_age_gap());
	return 0;
}



static void __exit mod_exit(void) {
	printk(KERN_INFO  "Module Exited\n");
}

module_init(mod_init);
module_exit(mod_exit);
