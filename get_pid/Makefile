ifneq ($(KERNELRELEASE), )
    obj-m := get_pid.o

else
    PWD := $(shell pwd)
    SOURCE := /lib/modules/$(shell uname -r)/build

default:
	$(MAKE) -C $(SOURCE) M=$(PWD) modules

clean:
	rm *.ko *.mod.c *.o Mod* mod*

endif
