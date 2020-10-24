/*
 * =====================================================================================
 *
 *       Filename:  export_mod.c
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
MODULE_DESCRIPTION("A module to provide fumction for calculating average.");
MODULE_VERSION("1");

int TA1 = 0, TA2 = 0;

module_param(TA1, int, 0);
module_param(TA2, int, 0);
int get_average_age_times10(void){
	return  (TA1 + TA2) * 5;
}

int get_age_gap(void){
	int diff = TA2 - TA1;
	return diff >= 0? diff : -diff;
}


EXPORT_SYMBOL(get_average_age_times10);
EXPORT_SYMBOL(get_age_gap);


__init int __init mod_init(void) {
    printk(KERN_INFO "Module installed.\n");
    return 0;
}



static void __exit mod_exit(void) {
	printk(KERN_INFO  "Module Exited\n");
}

module_init(mod_init);
module_exit(mod_exit);
