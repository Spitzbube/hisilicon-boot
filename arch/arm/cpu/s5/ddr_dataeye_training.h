#ifndef DDR_TRAINING
#define DDR_TRAINING

#ifndef __ASSEMBLY__

#include "ddr_training_common.h"

/*** register operations ***/
#define io_read(addr)                  (*(volatile unsigned int *)(addr))
#define io_write(addr,val)             (*(volatile unsigned int *)(addr)=(val))
/***ddr training err info***/
#define DDR_SWL_ERR(n) 		(1 + n*0x10)
#define DDR_SGT_ERR(n) 		(2 + n*0x10)
#define DDR_HGT_ERR(n)		(3 + n*0x10)
#define DDR_HRD_ERR(n)		(4 + n*0x10)
#define DDR_SWR_ERR(n)		(5 + n*0x10)
#define DDR_SRD_ERR(n)		(6 + n*0x10)

/*** for calculate best level definations ***/
#define DDRT_LOOP_TIMES_LMT	3
#define SSN_DDRT

#define DQ_LEVEL                     32
#define WRDQ_LEVEL                     32
#define WRDQS_LEVEL                    32
#define RDDQ_LEVEL                     32
#define RDDQS_LEVEL                    128
#define ACDQ_LEVEL                     32

/*** for ddr training item definations ***/
#define WRITE_DESKEW                   1
#define READ_DESKEW                    1

/*** for ddr phy layout definations ***/
#define BITWIDTH                       64

#define RD_MODE                               1
#define WR_MODE                               0
#define DQPHASE_INCREASE                      0xF
#define DQPHASE_DECREASE                      0xA
/*** S40 regsister ***/
/*** DDRC PHY regsister offest address ***/
#define REG_DDRPHY_RNK0_BASE                  0xff58c000
#define REG_DDRPHY_RNK1_BASE                  0xff58d000
#define REG_MDDRC_DMC0_BASE                   0xff588000
#define REG_MDDRC_DMC1_BASE                   0xff589000
#define REG_DDRT_BASE                         0xff350000
#define REG_MDDRC_BASE                        0xff580000
#define REG_BASE_MDDRC_SEC_4                  0xff582000
#define REG_BASE_MDDRC_SEC_5                  0xff582400
#define REG_BASE_MDDRC_QOS                    0xff584000
#define REG_GEN3_BASE                         0xf800008c
#define REG_GEN4_BASE                         0xf8000090
#define REG_GEN5_BASE                         0xf8000094
#define REG_GEN6_BASE                         0xf8000098

/*** SYSCTRL regsister offest address ***/
#define REG_SYSCTRL_BASE               0xf8000000

/*WR DQ0-DQ3 BIT 4:0,12:8,20:16, 28:24 */
#define DDRC_DXNWDQBDL0(n)             (0x210 + ((n) << 7))
/*WR DQ4-DQ7 BIT 4:0,12:8,20:16, 28:24*/
#define DDRC_DXNWDQBDL1(n)             (0x214 + ((n) << 7))
/*WR DM */
#define DDRC_DXNWDQBDL2(n)             (0x218 + ((n) << 7))
/*RD DQ4-DQ7 BIT 4:0,12:8,20:16, 28:24*/
#define DDRC_DXNRDQBDL0(n)             (0x21C + ((n) << 7))
/*RD DQ4-DQ7 BIT 4:0,12:8,20:16, 28:24*/
#define DDRC_DXNRDQBDL1(n)             (0x220 + ((n) << 7))
#define DDRC_DXNRDQBDL2(n)             (0x224 + ((n) << 7)) /*RD DM*/
#define DDRC_DXNRDQSDLY(n)             (0x22C + ((n) << 7)) /* rdqs_bdl 6:0 rdqs_cyc 22:16 */
#define DDRC_DXWDQSDLY(n)              (0x230 + ((n) << 7))
#define DDRC_DXNWDQDLY(n)              (0x234 + ((n) << 7)) /*WR DQ phase BIT 12:8 */
#define DDRC_DXNDQSGDLY(n)             (0x23c + ((n) << 7)) /*rddqs gating*/
#define DDRC_DXNRDBOUND(n)             (0x250 + ((n) << 7)) /*read boundary  right 0:6 left 22:16 */
#define DDRC_DXNWDBOUND(n)             (0x254 + ((n) << 7)) /*write boundary  right 0:6 left 22:16 */
#define DDRC_MISC                      0x70

#define DDRC_PHYINITCTRL               0x004

#define DDRC_ACCMDBDL0                 0x120 /*ODT0 4:0   ODT1 20:16*/
#define DDRC_ACCMDBDL1                 0x124 /*ODT2 4:0   ODT3 20:16*/
#define DDRC_ACCMDBDL2                 0x128 /*CS0 4:0   CS1 20:16*/
#define DDRC_ACCMDBDL3                 0x12c /*CS2 4:0   CS3 20:16*/
#define DDRC_ACCMDBDL4                 0x130 /*CKE0 4:0   CKE1 20:16*/
#define DDRC_ACCMDBDL5                 0x134 /*CKE2 4:0   CKE3 20:16*/
#define DDRC_ACCMDBDL6                 0x138 /*WE 4:0   CAS 20:16*/
#define DDRC_ACCMDBDL7                 0x13c /*RAS 4:0   RESET 20:16*/
#define DDRC_ACADDRBDL0                0x140 /*A0 4:0   A1 20:16*/
#define DDRC_ACADDRBDL1                0x144 /*A2 4:0   A3 20:16*/
#define DDRC_ACADDRBDL2                0x148 /*A4 4:0   A5 20:16*/
#define DDRC_ACADDRBDL3                0x14c /*A6 4:0   A7 20:16*/
#define DDRC_ACADDRBDL4                0x150 /*A8 4:0   A9 20:16*/
#define DDRC_ACADDRBDL5                0x154 /*A10 4:0   A11 20:16*/
#define DDRC_ACADDRBDL6                0x158 /*A12 4:0   A13 20:16*/
#define DDRC_ACADDRBDL7                0x15c /*A14 4:0   A15 20:16*/
#define DDRC_ACADDRBDL8                0x160 /*BA0 4:0   BA1 20:16*/
#define DDRC_ACADDRBDL9                0x164 /*BA2 4:0 */
#define DDRC_ACCLKBDL                  0x168 /*CLK*/

#define DDRT0_TRAINING_ADDR            0x00000000
#define DDRT1_TRAINING_ADDR            0x20000000
#define SW_TRAINING_REG                0xf80000d0
#define HW_RDDESKEW_MASK               0x100000

#define SWL_RNK0_MASK                  0x10
#define SWL_RNK1_MASK                  0x20
#define SDET_RNK0_MASK                 0x100000
#define SDET_RNK1_MASK                 0x200000

/* four ddr  reversal = 0xB49C863C */
/* s40v200 demo reversal=  0x8DE18DE1 */

#ifdef SSN_DDRT
#define DDRT_OP                        0x0
#define DDRT_STATUS                    0x4
#define DDRT_MEM_CONFIG                0xc
#define DDRT_BURST_NUM                 0x10
#define DDRT_ADDR_NUM                  0x14
#define DDRT_LOOP_NUM                  0x18
#define DDRT_ADDR                      0x20
#define DDRT_ADDR_OFFSET0              0x24
#define DDRT_REVERSED_DQ               0x30
#define DDRT_KDATA                     0x3c
#define DDRT_DATA0                     0x40
#define DDRT_DATA1                     0x44
#define DDRT_DATA2                     0x48
#define DDRT_DATA3                     0x4c

#define DDRT_DQ_ERR_CNT(n)             (0x60 + ((n) << 2))
#define DDRT_DQ_ERR_OVFL               0x80

#define DDRT_START                     0x1
#define BURST_NUM                      0xff

#define RW_COMPRARE_MODE               (0<<8)
#define ONLY_WRITE_MODE                (1<<8)
#define ONLY_READ_MODE                 (2<<8)
#define RANDOM_RW_MODE                 (3<<8)

#define DDRT_PATTERM_PRBS9             (0<<12)
#define DDRT_PATTERM_PRBS7             (1<<12)
#define DDRT_PATTERM_PRBS11            (2<<12)
#define DDRT_PATTERM_K28_5             (3<<12)
#endif /* SSN_DDRT */

#define DDRT_LOOP_NUM_VAL              0x0
#define DDRT_BURST_NUM_VAL             0xff

#ifdef CMD_TRAINING
#define DDR_DQSTRAIN                   1
#define DDR_ADDRTRAIN                  2
#define BYTEWIDTH                      8
#endif

/*** data of DDRC ***/
struct training_data
{
#ifdef CMD_TRAINING
	unsigned int flag;
	unsigned int wrdqs_val[BYTEWIDTH];
	unsigned int rddqs_val[BYTEWIDTH];
#endif
	unsigned int wr_bit_result[BITWIDTH];
	unsigned int rd_bit_result[BITWIDTH];
	unsigned int wr_bit_best[BITWIDTH];
	unsigned int rd_bit_best[BITWIDTH];
	unsigned short wrdq_val[BITWIDTH];
	unsigned short rddq_val[BITWIDTH];
	unsigned int ddrt_reversed_data;
	unsigned short hw_training_flag;
};

#endif /* __ASSEMBLY__ */

#endif /* DDR_TRAINING */
