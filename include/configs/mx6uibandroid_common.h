/*
 * Copyright (C) 2013-2014 Freescale Semiconductor, Inc. All Rights Reserved.
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#ifndef MX6_UIB_ANDROID_COMMON_H
#define MX6_UIB_ANDROID_COMMON_H

#define CONFIG_MX6DL_UIB_REV_2

/*#define CONFIG_USB_DEVICE*/

#define CONFIG_USBD_HS
#define CONFIG_CI_UDC
#define CONFIG_USB_GADGET_DUALSPEED

#define CONFIG_USB_GADGET
#define CONFIG_CMD_USB_MASS_STORAGE
#define CONFIG_USB_GADGET_MASS_STORAGE
#define CONFIG_USBDOWNLOAD_GADGET
#define CONFIG_USB_GADGET_VBUS_DRAW     2

/*#define CONFIG_IMX_UDC		       1*/

#define CONFIG_FASTBOOT		       1
#define CONFIG_FASTBOOT_VENDOR_ID      0x18d1
#define CONFIG_FASTBOOT_PRODUCT_ID     0x0d02
#define CONFIG_FASTBOOT_BCD_DEVICE     0x311
#define CONFIG_FASTBOOT_MANUFACTURER_STR  "Freescale"
#define CONFIG_FASTBOOT_PRODUCT_NAME_STR "UIB"
#define CONFIG_FASTBOOT_INTERFACE_STR	 "Android fastboot"
#define CONFIG_FASTBOOT_CONFIGURATION_STR  "Android fastboot"
#define CONFIG_FASTBOOT_SERIAL_NUM	"12345"
#define CONFIG_FASTBOOT_SATA_NO		 0

#define CONFIG_CMD_FASTBOOT
#define CONFIG_ANDROID_BOOT_IMAGE
#define CONFIG_FSL_FASTBOOT
#define CONFIG_FASTBOOT_FLASH

#define CONFIG_G_DNL_VENDOR_NUM         0x18d1
#define CONFIG_G_DNL_PRODUCT_NUM        0x0d02
#define CONFIG_G_DNL_MANUFACTURER       "FSL"

#define CONFIG_USBDOWNLOAD_GADGET


#if defined CONFIG_SYS_BOOT_NAND
#define CONFIG_FASTBOOT_STORAGE_NAND
#elif defined CONFIG_SYS_BOOT_SATA
#define CONFIG_FASTBOOT_STORAGE_SATA
#else
#define CONFIG_FASTBOOT_STORAGE_MMC
#endif

/*  For system.img growing up more than 256MB, more buffer needs
*   to receive the system.img*/
#define CONFIG_FASTBOOT_TRANSFER_BUF	0x2c000000
#define CONFIG_FASTBOOT_TRANSFER_BUF_SIZE 0x20000000 /* 512M byte */

#define CONFIG_ANDROID_MAIN_MMC_BUS 2
#define CONFIG_ANDROID_BOOT_PARTITION_MMC 1
#define CONFIG_ANDROID_SYSTEM_PARTITION_MMC 5
#define CONFIG_ANDROID_RECOVERY_PARTITION_MMC 2
#define CONFIG_ANDROID_CACHE_PARTITION_MMC 6
#define CONFIG_ANDROID_DATA_PARTITION_MMC 4


#define CONFIG_CMD_BOOTA
#define CONFIG_SUPPORT_RAW_INITRD
#define CONFIG_SERIAL_TAG

/*#define CONFIG_CMD_BOOTI*/
#define CONFIG_ANDROID_RECOVERY
/* which mmc bus is your main storage ? */
/*#define CONFIG_ANDROID_MAIN_MMC_BUS 2
#define CONFIG_ANDROID_BOOT_PARTITION_MMC 1
#define CONFIG_ANDROID_SYSTEM_PARTITION_MMC 5
#define CONFIG_ANDROID_RECOVERY_PARTITION_MMC 2
#define CONFIG_ANDROID_CACHE_PARTITION_MMC 6*/

#undef CONFIG_LOADADDR

#define CONFIG_LOADADDR		0x12000000 /*0x10800000*/	/* loadaddr env var */

#undef CONFIG_EXTRA_ENV_SETTINGS
#undef CONFIG_BOOTCOMMAND

#define	CONFIG_EXTRA_ENV_SETTINGS											\
		"bootargs_base=setenv bootargs console=ttymxc0,115200 init=/init loglevel=8 "	\
		"video=mxcfb0:dev=ldb,LDB-WSVGA,bpp=32,if=RGB24 ldb=sin0 "			\
		"video=mxcfb1:off video=mxcfb2:off " CONFIG_SYS_NOSMP " "			\
		"log_buf_len=64K vmalloc=400M androidboot.console=ttymxc0 "			\
		"androidboot.hardware=freescale androidboot.selinux=permissive androidboot.dm_verity=disabled androidboot.serialno=0a01234567890abc logo.nologo\0" \
		"bootcmd_sd=mmc dev 1;"												\
		"setenv bootargs ${bootargs} androidboot.rootdevice=sd; " 			\
		"boota mmc1 ${recovery}\0"											\
		"bootcmd_emmc=mmc dev 0;"											\
		"setenv bootargs ${bootargs} androidboot.rootdevice=emmc; " 		\
		"boota mmc0 ${recovery}\0"											\
		"bootcmd=setenv recovery; run bootuib\0"							\
		"bootuib=run bootargs_base; "										\
		"if test ${bootdev} = mmc1; "										\
		"  then run bootcmd_sd; "											\
		"  else run bootcmd_emmc; fi\0"										\
		"splashimage=0x30000000\0"											\
		"splashpos=m,m\0"													\
		"fdt_high=0xffffffff\0"	  \
		"initrd_high=0xffffffff\0" \
		"serial#=12345\0" \
		"bootcmd_android_recovery=setenv recovery recovery;	run bootuib\0"	\


#define CONFIG_USB_FASTBOOT_BUF_ADDR   CONFIG_SYS_LOAD_ADDR
#define CONFIG_USB_FASTBOOT_BUF_SIZE   0x20000000

#if defined(CONFIG_FASTBOOT_STORAGE_NAND)
#define ANDROID_FASTBOOT_NAND_PARTS "16m@64m(boot) 16m@80m(recovery) 810m@96m(android_root)ubifs"
#endif

#endif /* MX6_UIB_ANDROID_COMMON_H */
