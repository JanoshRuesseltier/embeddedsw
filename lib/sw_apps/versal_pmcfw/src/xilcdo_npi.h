/******************************************************************************
 *
 * Copyright (C) 2018 Xilinx, Inc.  All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * Use of the Software is limited solely to applications:
 * (a) running on a Xilinx device, or
 * (b) that interact with a Xilinx device through a bus or interconnect.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PRTNICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
 * OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * Except as contained in this notice, the name of the Xilinx shall not be used
 * in advertising or otherwise to promote the sale, use or other dealings in
 * this Software without prior written authorization from Xilinx.
 *
 ******************************************************************************/

/*****************************************************************************/
/**
 *
 * @file xilcdo_npi.h
 *
 * This is the file which contains CDO NPI functions.
 *
 * <pre>
 * MODIFICATION HISTORY:
 *
 * Ver   Who  Date        Changes
 * ----- ---- -------- -------------------------------------------------------
 * 1.00  bsv   01/05/18 Initial release
 *
 * </pre>
 *
 * @note
 *
 ******************************************************************************/
#ifndef XILCDO_NPI_H
#define XILCDO_NPI_H

#ifdef __cplusplus
extern "C" {
#endif
/***************************** Include Files *********************************/
#include "xilcdo.h"
#include "xpmcfw_hw.h"

/************************** Constant Definitions *****************************/
/**
 * Npi Parameter Mask
 */
#define XILCDO_NPI_BLK_MASK				(0xFFU)
#define XILCDO_NPI_FABRICEN_MASK				(0x100U)
#define XILCDO_NPI_APB3EN_MASK					(0x200U)
#define XILCDO_NPI_DDRMC_PRESENT_MASK			(0x400U)
#define XILCDO_NPI_PR_FREEZE_MASK			(0x800U)
/**
 * Block Type values
 */
#define XILCDO_NPI_BLK_VREF				(0x1U)
#define XILCDO_NPI_BLK_XPIO				(0x2U)
#define XILCDO_NPI_BLK_XPIO_IOMISC			(0x3U)
#define XILCDO_NPI_BLK_XPLL				(0x4U)
#define XILCDO_NPI_BLK_XPHY				(0x5U)
#define XILCDO_NPI_BLK_DDRMC				(0x6U)
#define XILCDO_NPI_BLK_XPIPE				(0x7U)
#define XILCDO_NPI_BLK_GT					(0x8U)
#define XILCDO_NPI_BLK_NOC_NPS				(0x9U)
#define XILCDO_NPI_BLK_NOC_NCRB				(0xAU)
#define XILCDO_NPI_BLK_NOC_NSU				(0xBU)
#define XILCDO_NPI_BLK_NOC_NMU				(0xCU)
#define XILCDO_NPI_BLK_NOC_IDB				(0xDU)
#define XILCDO_NPI_BLK_VERT_TO_HSR			(0xEU)
#define XILCDO_NPI_BLK_VERT_TO_HSR_GT		(0xFU)
#define XILCDO_NPI_BLK_REBUF_VRT			(0x10U)
#define XILCDO_NPI_BLK_REBUF_VRT_GT			(0x11U)
#define XILCDO_NPI_BLK_HSR_BUFGS			(0x12U)
#define XILCDO_NPI_BLK_VNOC_PS				(0x13U)
#define XILCDO_NPI_BLK_VNOC					(0x14U)
#define XILCDO_NPI_BLK_CLK_GT				(0x15U)
#define XILCDO_NPI_BLK_REBUF_HSR_TNOC_ME	(0x16U)
#define XILCDO_NPI_BLK_MMCM					(0x17U)
#define XILCDO_NPI_BLK_DPLL					(0x18U)
#define XILCDO_NPI_BLK_AMS_SAT				(0x19U)
#define XILCDO_NPI_BLK_AMS_ROOT				(0x1AU)
#define XILCDO_NPI_BLK_ME_NPI				(0x1BU)
#define XILCDO_TOTAL_NPI_BLKS				(0x20U)

/**
 * PCSR register offsets
 */
#define XILCDO_NPI_PCSR_MASK_OFFSET				(0x0U)
#define XILCDO_NPI_PCSR_CONTROL_OFFSET			(0x4U)
#define XILCDO_NPI_PCSR_STATUS_OFFSET			(0x8U)
#define XILCDO_NPI_PCSR_LOCK_OFFSET				(0xCU)
#define XILCDO_NPI_PENDING_BURST_OFFSET			(0x264U)
#define XILCDO_NPI_NMU_BUSY_OFFSET				(0x810U)

/**
 * PCSR MASK register bit fields
 */
#define PCSR_MASK_SHTDN_MASK    				(0x08000000U)
#define PCSR_MASK_NSU_PR_MASK					(0x04000000U)
#define PCSR_MASK_AXI_REQ_REJECT_MASK			(0x04000000U)
#define PCSR_MASK_DESKEW_MASK					(0x01000000U)
#define PCSR_MASK_UB_INIT_MASK					(0x01000000U)
#define PCSR_MASK_DCI_OFC_RST_MASK              (0x00200000U)
#define PCSR_MASK_STARTBISR_MASK    			(0x00080000U)
#define PCSR_MASK_MBISTCLR_MASK					(0x00040000U)
#define PCSR_MASK_SYS_RST_MASK_MASK 			(0x00038000U)
#define PCSR_MASK_PWRDN_MASK    				(0x00004000U)
#define PCSR_MASK_DISNPICLK_MASK    			(0x00002000U)
#define PCSR_MASK_APBEN_MASK    				(0x00001000U)
#define PCSR_MASK_SCANCLR_MASK    				(0x00000800U)
#define PCSR_MASK_STARTCAL_MASK    				(0x00000400U)
#define PCSR_MASK_FABRICEN_MASK    				(0x00000200U)
#define PCSR_MASK_TRISTATE_MASK    				(0x00000100U)
#define PCSR_MASK_HOLDSTATE_MASK    			(0x00000080U)
#define PCSR_MASK_INITSTATE_MASK    			(0x00000040U)
#define PCSR_MASK_ODISABLE_MASK    				(0x0000003CU)
#define PCSR_MASK_GATEREG_MASK    				(0x00000002U)
#define PCSR_MASK_PCOMPLETE_MASK    			(0x00000001U)

/**
 * Register: PCSR_STATUS
 */
#define PCSR_STATUS_BISRERR_MASK    			(0x00000200U)
#define PCSR_STATUS_BISRDONE_MASK    			(0x00000100U)
#define PCSR_STATUS_MBISTERR_MASK    			(0x00000080U)
#define PCSR_STATUS_MBISTDONE_MASK    			(0x00000040U)
#define PCSR_STATUS_CALERROR_MASK    			(0x00000020U)
#define PCSR_STATUS_CALDONE_MASK    			(0x00000010U)
#define PCSR_STATUS_INCAL_MASK    				(0x00000008U)
#define PCSR_STATUS_SCANERR_MASK    			(0x00000004U)
#define PCSR_STATUS_SCANDONE_MASK    			(0x00000002U)
#define PCSR_STATUS_PCSRLOCK_MASK    			(0x00000001U)

/**
 * Register: PCSR_LOCK
 */
#define PCSR_LOCK_STATE_MASK    				(0x00000001U)
#define PCSR_UNLOCK_VAL							(0xF9E8D7C6U)

/**************************** Type Definitions *******************************/

/************************** Structure Declarations ***************************/
typedef struct
{
	u32 XPIO_BaseAddr[XILCDO_TOTAL_NPI_BLKS];
	u32 HSR_BUFGS_BaseAddr[XILCDO_TOTAL_NPI_BLKS];
	u32 VNOC_PS_BaseAddr[XILCDO_TOTAL_NPI_BLKS];
	u32 VNOC_BaseAddr[XILCDO_TOTAL_NPI_BLKS];
	u32 CLK_GT_BaseAddr[XILCDO_TOTAL_NPI_BLKS];
	u32 WaitQueue[XILCDO_TOTAL_NPI_BLKS];
	u32 XPIO_BaseAddrCnt;
	u32 HSR_BUFGS_BaseAddrCnt;
	u32 VNOC_PS_BaseAddrCnt;
	u32 VNOC_BaseAddrCnt;
	u32 CLK_GT_BaseAddrCnt;
}XILCDO_NPI_SEQ;

/************************** Function Prototypes ******************************/

void XilCdo_WritePcsrCtrlReg(u32 BaseAddr, u32 Mask, u32 Value);
void XilCdo_ClearGateReg(u32 BaseAddr);
void XilCdo_SetGateReg(u32 BaseAddr);
void XilCdo_SetCompleteState(u32 BaseAddr);
void XilCdo_ClearCompleteState(u32 BaseAddr);
void XilCdo_SetApbEnable(u32 BaseAddr);
void XilCdo_ClearApbEnable(u32 BaseAddr);
void XilCdo_ClearHoldState(u32 BaseAddr);
void XilCdo_SetHoldState(u32 BaseAddr);
void XilCdo_ClearInitState(u32 BaseAddr);
void XilCdo_SetInitState(u32 BaseAddr);
void XilCdo_ClearDeskew(u32 BaseAddr);
void XilCdo_SetDeskew(u32 BaseAddr);
void XilCdo_SetFabricEnable(u32 BaseAddr);
void XilCdo_ClearFabricEnable(u32 BaseAddr);
void XilCdo_ClearODisable(u32 BaseAddr);
void XilCdo_SetODisable(u32 BaseAddr);
void XilCdo_RunCalibration(u32 BaseAddr, u32 Deskew);
void XilCdo_RunDeskew(u32 BaseAddr);
void XilCdo_SetStartCal(u32 BaseAddr);
void XilCdo_ClearStartCal(u32 BaseAddr);
void XilCdo_ClearTriState(u32 BaseAddr);
void XilCdo_SetTriState(u32 BaseAddr);
void XilCdo_SetLockState(u32 BaseAddr);
void XilCdo_ClearLockState(u32 BaseAddr);
void XilCdo_ClearUBInitState(u32 BaseAddr);
void XilCdo_SetUBInitState(u32 BaseAddr);
void XilCdo_SetDCIOfcReset(u32 BaseAddr);
void XilCdo_ClearDCIOfcReset(u32 BaseAddr);
void XilCdo_SetPwrDown(u32 BaseAddr);
void XilCdo_ProcBlkVREF(u32 BaseAddr);
void XilCdo_PreProcBlkXPIO(u32 BaseAddr);
void XilCdo_PostProcBlkXPIO(u32 BaseAddr);
void XilCdo_ProcBlkXPIO_IOMISC(u32 BaseAddr);
void XilCdo_ProcBlkHSR_VRT(u32 BaseAddr);
void XilCdo_ProcBlkHSR_TNOC_ME(u32 BaseAddr);
void XilCdo_PreProcBlkHSR_BUFGS(u32 BaseAddr);
void XilCdo_PostProcBlkHSR_BUFGS(u32 BaseAddr);
void XilCdo_PreProcBlkVNOC_PS(u32 BaseAddr);
void XilCdo_PostProcBlkVNOC_PS(u32 BaseAddr);
void XilCdo_PreProcBlkVNOC(u32 BaseAddr);
void XilCdo_PostProcBlkVNOC(u32 BaseAddr);
void XilCdo_PreProcBlkCLK_GT(u32 BaseAddr);
void XilCdo_PostProcBlkCLK_GT(u32 BaseAddr);
void XilCdo_ProcBlkMMCM_DPLL(u32 BaseAddr);
void XilCdo_ProcBlkXPLL(u32 BaseAddr, u32 DdrPresent);
void XilCdo_ProcBlkXPHY(u32 BaseAddr, u32 DdrPresent);
void XilCdo_ProcBlkDDRMC(u32 BaseAddr);
void XilCdo_ProcBlkAMS_SAT(u32 BaseAddr);
void XilCdo_ProcBlkAMS_ROOT(u32 BaseAddr);
void XilCdo_ProcBlkXPIPE(u32 BaseAddr);
void XilCdo_ProcBlkGT(u32 BaseAddr);
void XilCdo_ProcBlkNOC_NPS(u32 BaseAddr);
void XilCdo_ProcBlkNOC_IDB(u32 BaseAddr);
void XilCdo_ProcBlkNOC_NCRB(u32 BaseAddr);
void XilCdo_ProcBlkNOC_NSU(u32 BaseAddr);
void XilCdo_ProcBlkNOC_NMU(u32 BaseAddr);
void XilCdo_ProcBlkME_NPI(u32 BaseAddr);
void XilCdo_ShutBlkVREF(u32 BaseAddr);
void XilCdo_ShutBlkXPIO(u32 BaseAddr);
void XilCdo_ShutBlkDCI(u32 BaseAddr);
void XilCdo_ShutBlkHSR_VRT(u32 BaseAddr);
void XilCdo_ShutBlkHSR_TNOC_ME(u32 BaseAddr);
void XilCdo_ShutBlkHSR_BUFGS(u32 BaseAddr);
void XilCdo_ShutBlkVNOC_PS(u32 BaseAddr);
void XilCdo_ShutBlkVNOC(u32 BaseAddr);
void XilCdo_ShutBlkCLK_GT(u32 BaseAddr);
void XilCdo_ShutBlkMMCM_DPLL(u32 BaseAddr);
void XilCdo_ShutBlkXPHY(u32 BaseAddr);
void XilCdo_ShutBlkDDRMC(u32 BaseAddr);
void XilCdo_ShutBlkXPIPE(u32 BaseAddr);
void XilCdo_ShutBlkGT(u32 BaseAddr);
void XilCdo_ShutBlkNSU(u32 BaseAddr);
void XilCdo_ShutBlkNMU(u32 BaseAddr);
void XilCdo_ShutBlkNCRB(u32 BaseAddr);
void XilCdo_ShutBlkXPLL(u32 BaseAddr);
void XilCdo_RunNsuPRMode(u32 BaseAddr);
void XilCdo_RunAxiReqRejectMode(u32 BaseAddr);
void XilCdo_SetAxiReqRejectMode(u32 BaseAddr);
void XilCdo_ClearAxiReqRejectMode(u32 BaseAddr);
void XilCdo_SetPRMode(u32 BaseAddr);
void XilCdo_ClearPRMode(u32 BaseAddr);
void XilCdo_SetShutDown(u32 BaseAddr);
void XilCdo_ClearShutDown(u32 BaseAddr);
XStatus XilCdo_CheckDeskew(u32 BaseAddr);
XStatus XilCdo_NpiWrite(u32 CmdArgs[10U]);
XStatus XilCdo_NpiSeq(u32 CmdArgs[10U]);
XStatus XilCdo_NpiShutDown(u32 CmdArgs[10U]);
XStatus XilCdo_RunPendingNpiSeq(u32 BlockType);
XStatus XilCdo_CheckDeskew(u32 BaseAddr);
XStatus XilCdo_CheckCalibration(u32 BaseAddr);
#ifdef __cplusplus
}
#endif

#endif  /* XILCDO_NPI_H */