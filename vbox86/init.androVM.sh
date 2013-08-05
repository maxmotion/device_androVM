#!/system/bin/sh

unset LD_PRELOAD

vbox_graph_mode="800x600-16"
vbox_dpi="160"
vbox_sdcard_drive="/dev/block/sdc"

# Disable cursor blinking - Thanks android-x86 :-)
echo -e '\033[?17;0;0c' > /dev/tty0

prop_hardware_opengl=`/system/bin/androVM-prop get hardware_opengl`
# Starting eth0 management
# First check if eth0 is 'plugged'
if [ $prop_hardware_opengl ]; then
  /system/bin/netcfg eth0 up
  CARRIER=`cat /sys/class/net/eth0/carrier`
  if [ $CARRIER -eq 1 ]; then
    /system/bin/netcfg eth0 dhcp
    IPETH0=(`ifconfig eth0`)
    IPMGMT=${IPETH0[2]}
    /system/bin/androVM-prop set androvm_ip_management $IPMGMT
    echo "IP Management : $IPMGMT" > /dev/tty0
  else
    /system/bin/androVM-prop set androvm_ip_management 0.0.0.0
    echo "eth0 interface is not connected" > /dev/tty0
  fi
else
  (
    /system/bin/netcfg eth0 dhcp
    IPETH0=(`ifconfig eth0`)
    IPMGMT=${IPETH0[2]}
    /system/bin/androVM-prop set androvm_ip_management $IPMGMT
    echo "IP Management : $IPMGMT" > /dev/tty0
  )&
fi

# Load parameters from virtualbox guest properties

# Load VM name as serial no for Android Device Chooser display
prop_genymotion_vm_name=$(/system/bin/androVM-prop get genymotion_vm_name)
if [ "$prop_genymotion_vm_name" ]; then
  setprop ro.product.model "$prop_genymotion_vm_name"
else
  setprop ro.product.model "virtual machine"
fi

prop_vbox_graph_mode=`/system/bin/androVM-prop get vbox_graph_mode`
if [ -n "$prop_vbox_graph_mode" ]; then
  vbox_graph_mode="$prop_vbox_graph_mode"
  setprop androVM.vbox_graph_mode "$prop_vbox_graph_mode"
fi

prop_vbox_dpi=`/system/bin/androVM-prop get vbox_dpi`
if [ -n "$prop_vbox_dpi" ]; then
  vbox_dpi="$prop_vbox_dpi"
  setprop androVM.vbox_dpi "$prop_vbox_dpi"
fi

prop_vbox_sdcard_drive=`/system/bin/androVM-prop get vbox_sdcard_drive`
if [ -n "$prop_vbox_sdcard_drive" ]; then
  vbox_sdcard_drive="$prop_vbox_sdcard_drive"
  setprop androVM.vbox_sdcard_drive "$prop_vbox_sdcard_drive"
fi

prop_vkeyboard_mode=`/system/bin/androVM-prop get vkeyboard_mode`
if [ -n "$prop_vkeyboard_mode" ]; then
  vkeyboard_mode="$prop_vkeyboard_mode"
  setprop androVM.vkeyboard_mode "$prop_vkeyboard_mode"
fi

prop_force_navbar=`/system/bin/androVM-prop get genymotion_force_navbar`
if [ -n "$prop_force_navbar" -a "$prop_force_navbar" == "1" ]; then
  # No hw buttons => add virtual navbar
  setprop qemu.hw.mainkeys 0
fi

prop_su_bypass=`/system/bin/androVM-prop get su_bypass`
if [ $prop_su_bypass ]; then
  setprop androVM.su.bypass 1
fi

# UVESAFB
insmod /system/lib/cfbcopyarea.ko
insmod /system/lib/cfbfillrect.ko
insmod /system/lib/cfbimgblt.ko
insmod /system/lib/uvesafb.ko mode_option=$vbox_graph_mode scroll=redraw

setprop ro.sf.lcd_density $vbox_dpi

if [ $prop_hardware_opengl ]; then
  if [ $IPMGMT ]; then
    setprop androVM.gles 1
    prop_hardware_opengl_disable_render=`/system/bin/androVM-prop get hardware_opengl_disable_render`
    if [ -z "$prop_hardware_opengl_disable_render" -o "$prop_hardware_opengl_disable_render" != "1" ]; then
      setprop androVM.gles.renderer 1
    fi
  else
    echo "eth0 is not configured correctly - HARDWARE OPENGL IS DISABLED !!!"  > /dev/tty0
    sleep 10
  fi
fi

# SDCARD
if [ -b $vbox_sdcard_drive ]; then
  echo "Trying to mount $vbox_sdcard_drive" > /dev/tty0
  mount -t vfat -o fmask=0000,dmask=0000 $vbox_sdcard_drive /mnt/sdcard
  if [ $? -ne 0 ]; then
    echo "Unable to mount $vbox_sdcard_drive, try to create FAT" > /dev/tty0
    newfs_msdos $vbox_sdcard_drive
    mount -t vfat -o fmask=0000,dmask=0000 $vbox_sdcard_drive /mnt/sdcard
    if [ $? -ne 0 ]; then
      echo "Unable to create FAT" > /dev/tty0
    fi
  fi
else
  echo "NO SDCARD" > /dev/tty0
fi

# ARM ABI
abi2_set=`getprop ro.product.cpu.abi2`
if [ ! $abi2_set ]; then
  if [ -f /system/lib/libhoudini.so ]; then
    setprop ro.product.cpu.abi2 armeabi-v7a
  fi
fi
abi3_set=`getprop ro.product.cpu.abi3`
if [ ! $abi3_set ]; then
  if [ -f /system/lib/libhoudini.so ]; then
    setprop ro.product.cpu.abi3 armeabi
  fi
fi

# Update system versions
android_version=`getprop ro.build.version.release`
genymotion_version=`getprop ro.genymotion.version`
/system/bin/androVM-prop set android_version "$android_version"
/system/bin/androVM-prop set genymotion_version "$genymotion_version"

# Finalize init
setprop androVM.inited 1
