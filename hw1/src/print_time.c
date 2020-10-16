/*
 * =====================================================================================
 *
 *       Filename:  main.c
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
MODULE_DESCRIPTION("A module to write current time on installation.");
MODULE_VERSION("1");

static int __init mod_init(void) {
 printk(KERN_INFO "Hello, World!\n");
 struct timespec tm;
 getnstimeofday(&tm);
 ktime_get_real();
 printk(KERN_INFO "TIME IS:%l", tm.tv_sec);
 return 0;
}
static void __exit mod_exit(void) {
 printk(KERN_INFO  "Goodbye, World!\n");
}
module_init(mod_init);
module_exit(mod_exit);
