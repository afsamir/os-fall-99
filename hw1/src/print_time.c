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
 printk(KERN_INFO "Print_Time Module Started.\n");
 struct timespec tm;
 struct tm datetime;
 getnstimeofday(&tm);
 time_to_tm(tm.tv_sec, 0, &datetime);
 printk(KERN_INFO "Time is: %d/%d/%d - %d:%d:%d", 1900 + datetime.tm_year, datetime.tm_mon, datetime.tm_mday, datetime.tm_hour, datetime.tm_min, datetime.tm_sec );
 return 0;
}
static void __exit mod_exit(void) {
 printk(KERN_INFO  "Module Exited\n");
}
module_init(mod_init);
module_exit(mod_exit);
