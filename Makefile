include scripts/env.mk

all: kernel busybox rootfs image

kernel:

	cd kernel && \
	make ARCH=$(ARCH) defconfig

	cd kernel && \
	make \
	ARCH=$(ARCH) \
	CROSS_COMPILE=$(CROSS) \
	-j$(JOBS)

busybox:

	cd busybox && \
	make defconfig

	cd busybox && \
	make \
	CROSS_COMPILE=$(CROSS) \
	-j$(JOBS)

	cd busybox && \
	make \
	CONFIG_PREFIX=../rootfs \
	install

rootfs:

	./scripts/rootfs.sh

image:

	cd rootfs && \
	find . | \
	cpio -H newc -ov | \
	gzip > ../images/initramfs.cpio.gz:w

run-console:
	./scripts/run-console.sh

run-gui:
	./scripts/run-gui.sh

clean:

	rm -rf rootfs

	rm -rf images/*

	cd kernel && make clean

	cd busybox && make clean

distclean: clean
	rm -rf build

