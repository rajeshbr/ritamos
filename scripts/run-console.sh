qemu-system-aarch64 \
    -machine virt \
    -cpu cortex-a72 \
    -m 2048 \
    -kernel kernel/arch/arm64/boot/Image \
    -drive file=images/rootfs.ext4,format=raw,if=virtio \
    -append "console=ttyAMA0 earlycon root=/dev/vda rw init=/init loglevel=8" \
    -serial mon:stdio \
    -nographic
