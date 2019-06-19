#ifndef __EVAL1A_CONFIG_H
#define __EVAL1A_CONFIG_H

#include "mx6_common.h"

#ifndef CONFIG_MXC_UART
#define CONFIG_MXC_UART
#endif

#define CONFIG_ENV_SIZE			SZ_8K
#define CONFIG_ENV_OFFSET		(12 * SZ_64K)

#define CONFIG_MXC_UART_BASE	UART1_BASE

#define IMX_FEC_BASE			ENET_BASE_ADDR
#define CONFIG_FEC_ENET_DEV		1
#define CONFIG_FEC_MXC_PHYADDR  0x2
#define CONFIG_FEC_XCV_TYPE     RMII
#define CONFIG_ETHPRIME			"eth0"


/* MMC Configs */
#ifdef CONFIG_FSL_USDHC
#define CONFIG_SYS_FSL_ESDHC_ADDR	USDHC1_BASE_ADDR
#endif

#define PHYS_SDRAM_SIZE	SZ_256M

#define CONFIG_SYS_MALLOC_LEN		(16 * SZ_1M)


/* Physical Memory Map */
#define PHYS_SDRAM			MMDC0_ARB_BASE_ADDR

#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM
#define CONFIG_SYS_INIT_RAM_ADDR	IRAM_BASE_ADDR
#define CONFIG_SYS_INIT_RAM_SIZE	IRAM_SIZE

#ifdef CONFIG_ENABLE_MMY
   #define CONFIG_SYS_MAPPED_RAM_BASE   CONFIG_SYS_SDRAM_BASE
#endif

#define CONFIG_SYS_MAPPED_RAM_BASE   	CONFIG_SYS_SDRAM_BASE

#define CONFIG_SYS_INIT_SP_OFFSET \
	(CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)

#define CONFIG_SYS_INIT_SP_ADDR \
	(CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_SP_OFFSET)

#define CONFIG_BOOTCOMMAND	"run main_boot"

#define CONFIG_EXTRA_ENV_SETTINGS					\
	"setenv bootdelay 3\0"						\
	"main_boot="							\
		"setenv bootargs console=ttymxc0,115200n8 earlyprintk root=/dev/mmcblk0p1 rootwait rw;" \
		"ext4load mmc 0:1 0x80001000 /boot/imx6ull-dtb-eval1a.dtb; "			\
		"ext4load mmc 0:1 0x82000000 /boot/zImage; "			\
		"bootz 0x82000000 - 0x80001000\0"				\

#endif
