ifneq ($(KERNELRELEASE), )
    obj-m := example_code.o

else
    PWD := $(shell pwd)
    SOURCE := /lib/modules/$(shell uname -r)/build

default:
	$(MAKE) -C $(SOURCE) M=$(PWD) modules
clean:
	rm *.ko *.mod.c *.o Mo* mo*

endif
