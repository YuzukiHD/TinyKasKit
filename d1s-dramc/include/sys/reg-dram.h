#ifndef __SYS_REG_DRAM_H__
#define __SYS_REG_DRAM_H__

#define MCTL_COM_BASE (0x3102000)
#define MCTL_COM_WORK_MODE0 (0x00)
#define MCTL_COM_WORK_MODE1 (0x04)
#define MCTL_COM_DBGCR (0x08)
#define MCTL_COM_TMR (0x0c)
#define MCTL_COM_CCCR (0x14)
#define MCTL_COM_MAER0 (0x20)
#define MCTL_COM_MAER1 (0x24)
#define MCTL_COM_MAER2 (0x28)
#define MCTL_COM_REMAP0 (0x500)
#define MCTL_COM_REMAP1 (0x504)
#define MCTL_COM_REMAP2 (0x508)
#define MCTL_COM_REMAP3 (0x50c)

#define MCTL_PHY_BASE (0x3103000)
#define MCTL_PHY_PIR (0x00)
#define MCTL_PHY_PWRCTL (0x04)
#define MCTL_PHY_MRCTRL0 (0x08)
#define MCTL_PHY_CLKEN (0x0c)
#define MCTL_PHY_PGSR0 (0x10)
#define MCTL_PHY_PGSR1 (0x14)
#define MCTL_PHY_STATR (0x18)
#define MCTL_PHY_LP3MR11 (0x2c)
#define MCTL_PHY_DRAM_MR0 (0x30)
#define MCTL_PHY_DRAM_MR1 (0x34)
#define MCTL_PHY_DRAM_MR2 (0x38)
#define MCTL_PHY_DRAM_MR3 (0x3c)
#define MCTL_PHY_PTR0 (0x44)
#define MCTL_PHY_PTR2 (0x4c)
#define MCTL_PHY_PTR3 (0x50)
#define MCTL_PHY_PTR4 (0x54)
#define MCTL_PHY_DRAMTMG0 (0x58)
#define MCTL_PHY_DRAMTMG1 (0x5c)
#define MCTL_PHY_DRAMTMG2 (0x60)
#define MCTL_PHY_DRAMTMG3 (0x64)
#define MCTL_PHY_DRAMTMG4 (0x68)
#define MCTL_PHY_DRAMTMG5 (0x6c)
#define MCTL_PHY_DRAMTMG6 (0x70)
#define MCTL_PHY_DRAMTMG7 (0x74)
#define MCTL_PHY_DRAMTMG8 (0x78)
#define MCTL_PHY_ODTCFG (0x7c)
#define MCTL_PHY_PITMG0 (0x80)
#define MCTL_PHY_PITMG1 (0x84)
#define MCTL_PHY_LPTPR (0x88)
#define MCTL_PHY_RFSHCTL0 (0x8c)
#define MCTL_PHY_RFSHTMG (0x90)
#define MCTL_PHY_RFSHCTL1 (0x94)
#define MCTL_PHY_PWRTMG (0x98)
#define MCTL_PHY_ASRC (0x9c)
#define MCTL_PHY_ASRTC (0xa0)
#define MCTL_PHY_VTFCR (0xb8)
#define MCTL_PHY_DQSGMR (0xbc)
#define MCTL_PHY_DTCR (0xc0)
#define MCTL_PHY_DTAR0 (0xc4)
#define MCTL_PHY_PGCR0 (0x100)
#define MCTL_PHY_PGCR1 (0x104)
#define MCTL_PHY_PGCR2 (0x108)
#define MCTL_PHY_PGCR3 (0x10c)
#define MCTL_PHY_IOVCR0 (0x110)
#define MCTL_PHY_IOVCR1 (0x114)
#define MCTL_PHY_DXCCR (0x11c)
#define MCTL_PHY_ODTMAP (0x120)
#define MCTL_PHY_ZQCTL0 (0x124)
#define MCTL_PHY_ZQCTL1 (0x128)
#define MCTL_PHY_ZQCR (0x140)
#define MCTL_PHY_ZQSR (0x144)
#define MCTL_PHY_ZQDR0 (0x148)
#define MCTL_PHY_ZQDR1 (0x14c)
#define MCTL_PHY_ZQDR2 (0x150)
#define MCTL_PHY_SCHED (0x1c0)
#define MCTL_PHY_PERFHPR0 (0x1c4)
#define MCTL_PHY_PERFHPR1 (0x1c8)
#define MCTL_PHY_PERFLPR0 (0x1cc)
#define MCTL_PHY_PERFLPR1 (0x1d0)
#define MCTL_PHY_PERFWR0 (0x1d4)
#define MCTL_PHY_PERFWR1 (0x1d8)
#define MCTL_PHY_ACMDLR (0x200)
#define MCTL_PHY_ACLDLR (0x204)
#define MCTL_PHY_ACIOCR0 (0x208)
#define MCTL_PHY_ACIOCR1(x) (0x210 + 0x4 * x)
#define MCTL_PHY_DXnMDLR(x) (0x300 + 0x80 * x)
#define MCTL_PHY_DXnLDLR0(x) (0x304 + 0x80 * x)
#define MCTL_PHY_DXnLDLR1(x) (0x308 + 0x80 * x)
#define MCTL_PHY_DXnLDLR2(x) (0x30c + 0x80 * x)
#define MCTL_PHY_DXIOCR (0x310)
#define MCTL_PHY_DATX0IOCR(x) (0x310 + 0x4 * x)
#define MCTL_PHY_DATX1IOCR(x) (0x390 + 0x4 * x)
#define MCTL_PHY_DATX2IOCR(x) (0x410 + 0x4 * x)
#define MCTL_PHY_DATX3IOCR(x) (0x490 + 0x4 * x)
#define MCTL_PHY_DXnSDLR6(x) (0x33c + 0x80 * x)
#define MCTL_PHY_DXnGTR(x) (0x340 + 0x80 * x)
#define MCTL_PHY_DXnGCR0(x) (0x344 + 0x80 * x)
#define MCTL_PHY_DXnGSR0(x) (0x348 + 0x80 * x)

#define SYS_CONTROL_REG_BASE (0x3000000)
#define LDO_CTAL_REG (0x150)
#define ZQ_CAL_CTRL_REG (0x160)
#define ZQ_RES_CTRL_REG (0x168)
#define ZQ_RES_STATUS_REG (0x16c)

#define SYS_SID_BASE (0x3006000)
#define SYS_EFUSE_REG (0x228)
#define SYS_LDOB_SID (0x21c)

#define SUNXI_R_CPUCFG_BASE (0x7000400)
#define SUNXI_R_CPUCFG_SUP_STAN_FLAG (0x1d4)

#define R_PRCM_BASE (0x7010000)
#define VDD_SYS_PWROFF_GATING_REG (0x250)
#define ANALOG_PWROFF_GATING_REG (0x254)

#endif // __SYS_REG_DRAM_H__