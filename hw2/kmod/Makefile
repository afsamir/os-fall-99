obj-m += export_mod.o
obj-m += import_mod.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

test:
	sudo dmesg -C
	sudo insmod print_time.ko
	sudo rmmod print_time.ko
	dmesg
