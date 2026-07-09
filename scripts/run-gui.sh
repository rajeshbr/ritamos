qemu-system-aarch64 \
    -machine virt \
    -cpu cortex-a72 \
    -m 2048 \
    -kernel kernel/arch/arm64/boot/Image \
    -drive file=images/rootfs.ext4,if=virtio,format=raw \
    -append "root=/dev/vda rw init=/init console=ttyAMA0" \
    -serial stdio \
    -display cocoa \
    -device virtio-gpu-pci 
