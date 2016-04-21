/*
 * module different macro
 *
 * Copyright (C) 2008 Renesas Solutions Corp.
 * Kuninori Morimoto <morimoto.kuninori@renesas.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __MODULE_DIFF_H__
#define __MODULE_DIFF_H__

#include "./../module_comm/module_comm.h"


#define CAMERA_MODULE_NAME 		"hi708"
#define CAMERA_MODULE_PID		0x96
#define VERSION(pid, ver) 		((pid<<8)|(ver&0xFF))

#define MODULE_I2C_REAL_ADDRESS  (0x60>>1)
#define MODULE_I2C_REG_ADDRESS		(0x60>>1)

#define I2C_REGS_WIDTH			1
#define I2C_DATA_WIDTH			1
//#define IS_FRONT_OR_REAR        0

#define DEFAULT_VSYNC_ACTIVE_LEVEL		V4L2_MBUS_VSYNC_ACTIVE_LOW
#define DEFAULT_POWER_LINE_FREQUENCY	V4L2_CID_POWER_LINE_FREQUENCY_50HZ
#define DEFAULT_PCLK_SAMPLE_EDGE      V4L2_MBUS_PCLK_SAMPLE_RISING




#define PID						0x04 /* Product ID Number */

#define OUTTO_SENSO_CLOCK 		24000000


#define MODULE_DEFAULT_WIDTH 	WIDTH_QVGA
#define MODULE_DEFAULT_HEIGHT	HEIGHT_QVGA
#define MODULE_MAX_WIDTH		WIDTH_VGA
#define MODULE_MAX_HEIGHT		HEIGHT_VGA

#define AHEAD_LINE_NUM			15    //10DD = 50��??-?��
#define DROP_NUM_CAPTURE		4
#define DROP_NUM_PREVIEW		6
static unsigned int frame_rate_qvga[]  = {30,};
static unsigned int frame_rate_vga[]   = {30,};


static const struct regval_list module_init_regs[] =
{
	#if 0
	{0x03,0x20},
	{0x10,0x0c},
	{0x83,0x01},
	{0x84,0xe0},
	{0x85,0x78},
	{0x03,0x20},
	{0xb0,0x00},
	{0x03,0x22},
	{0x10,0x6a},
	{0x80,0x48},
	{0x81,0x20},
	{0x82,0x3d},
	{0x83,0x58},
	{0x84,0x1b},
	{0x85,0x50},
	{0x86,0x25},
	{0x03,0x22},
	{0x10,0x6a},
	{0x80,0x40},
	{0x81,0x20},
	{0x82,0x4f},
	{0x83,0x44},
	{0x84,0x3a},
	{0x85,0x47},
	{0x86,0x3a},
	{0x03,0x10},
	{0x12,0x10},
	{0x03,0x20},
	{0x10,0x1c},
	{0x88, 0x02}, //EXP Max 8.33 fps 
	{0x89, 0xbf}, 
	{0x8a, 0x20}, 

    {0x03, 0x20}, //Page 20
	{0x10, 0x9c}, 
	//{0x18, 0x30},
    {0x03, 0x20}, //Page 20
	{0xb2, 0x80},
	{0x03,0x10},
	{0x11,0x03},
	{0x12,0x30},
	{0x13,0x00},
	{0x44,0x80},
	{0x45,0x80},
	{0x47,0x7f},
	{0x03,0x13},
	{0x20,0x06},
	{0x21,0x04},
	{0x03,0x10},
	{0x12,0x30},
	{0x03,0x10},
	{0x10,0x01},
	{0x03,0x10},
	{0x10,0x03},
	{0x03,0x10},
	{0x10,0x03},
	{0x03,0x10},
	{0x11,0x03},
	{0x12,0x30},
	{0x13,0x00},
	{0x44,0x80},
	{0x45,0x80},
	{0x47,0x7f},
	{0x03,0x13},
	{0x20,0x06},
	{0x21,0x04},
	{0x03,0x10},
	{0x12,0x30},
	{0x03, 0x20}, //Page 20
	{0x10, 0x1c}, 
	//{0x18, 0x38},
 
	{0x88, 0x02}, //EXP Max 8.33 fps 
	{0x89, 0xbf}, 
	{0x8a, 0x20}, 

    {0x03, 0x20}, //Page 20
	{0x10, 0x9c}, 
	//{0x18, 0x30},
    {0x03, 0x20}, //Page 20
	{0xb2, 0x60},
	{0x03,0x22},
	{0x10,0x6a},
	{0x80,0x48},
	{0x81,0x20},
	{0x82,0x3d},
	{0x83,0x58},
	{0x84,0x1b},
	{0x85,0x50},
	{0x86,0x25},
	{0x03,0x10},
	{0x10,0x03},
	{0x03,0x10},
	{0x11,0x03},
	{0x12,0x30},
	{0x13,0x00},
	{0x44,0x80},
	{0x45,0x80},
	{0x47,0x7f},
	{0x03,0x13},
	{0x20,0x06},
	{0x21,0x04},
	{0x03,0x22},
	{0x10,0x6a},
	{0x80,0x48},
	{0x81,0x20},
	{0x82,0x3d},
	{0x83,0x58},
	{0x84,0x1b},
	{0x85,0x50},
	{0x86,0x25},
	{0x03,0x10},
	{0x12,0x30},
	{0x03, 0x20}, //Page 20
	{0x10, 0x1c}, 
	//{0x18, 0x38},
 
	{0x88, 0x02}, //EXP Max 8.33 fps 
	{0x89, 0xbf}, 
	{0x8a, 0x20}, 

    {0x03, 0x20}, //Page 20
	{0x10, 0x9c}, 
	//{0x18, 0x30},
    {0x03, 0x20}, //Page 20
	{0xb2, 0x60},
	{0x03,0x00},
	{0x0e, 0x04},//PLL On
	{0x0e, 0x74},//PLLx2
#endif
	//PAGE 0
	{0x01, 0xf1},
	{0x01, 0xf3},
	{0x01, 0xf1},
	
	{0x03, 0x00},
	//{0x11, 0x93},
	//{0x12, 0x21},
//	{0x10, 0x93},//Pre off
	{0x12, 0x00},
	{0x01, 0xf1},
	//{0x10, 0x00},
	{0x20, 0x00},
	{0x21, 0x04},
	{0x22, 0x00},
	{0x23, 0x04},
	
	{0x40, 0x01},
	{0x41, 0x58},
	{0x42, 0x00},
	{0x43, 0x64},
	
	//BLC
	{0x80, 0x2e},
	{0x81, 0x7e},
	{0x82, 0x90},
	{0x83, 0x30},
	{0x84, 0x20},
	{0x85, 0x0b},
	{0x89, 0x48},//BLC hold
	{0x90, 0x0f},
	{0x91, 0x10},
	
	{0x92, 0x48},//AG_IN
	{0x93, 0x48},//AG_OUT
	{0x98, 0x20},
	{0x99, 0x42}, //Out BLC
	{0xa0, 0x00}, //Dark BLC
	{0xa8, 0x42}, //Normal BLC
	
	//Page 2
	{0x03, 0x02},
	{0x20, 0x33},
	{0x21, 0x77},
	{0x22, 0xa7},
	{0x23, 0x30},
	{0x52, 0xa2},
	{0x55, 0x18},
	{0x56, 0x0c},
	{0x60, 0x11},
	{0x61, 0x1b},
	{0x62, 0x11},
	{0x63, 0x1a},
	{0x64, 0x11},
	{0x65, 0x1a},
	{0x72, 0x12},
	{0x73, 0x19},
	{0x74, 0x12},
	{0x75, 0x19},
	{0x80, 0x1d},
	{0x81, 0x6f},
	{0x82, 0x1e},
	{0x83, 0x2b},
	{0x84, 0x1e},
	{0x85, 0x2b},
	{0x92, 0x45},
	{0x93, 0x52},
	{0x94, 0x45},
	{0x95, 0x52},
	{0xa0, 0x1d},
	{0xa1, 0x6b},
	{0xa4, 0x6b},
	{0xa5, 0x1d},
	{0xa8, 0x2e},
	{0xa9, 0x42},
	{0xaa, 0x55},
	{0xab, 0x69},
	{0xb8, 0x10},
	{0xb9, 0x13},
	{0xbc, 0x1d},
	{0xbd, 0x1f},
	{0xc0, 0x04},
	{0xc1, 0x0d},
	{0xc4, 0x05},
	{0xc5, 0x0c},
	{0xc8, 0x06},
	{0xc9, 0x0b},
	{0xcc, 0x06},
	{0xcd, 0x0a},
	{0xc2, 0x04},
	{0xc3, 0x0d},
	{0xc6, 0x05},
	{0xc7, 0x0c},
	{0xca, 0x06},
	{0xcb, 0x0b},
	{0xce, 0x06},
	{0xcf, 0x0a},
	{0xd0, 0x03},
	{0xd1, 0x1c},
	{0xd6, 0x46},
	{0xd7, 0x48},
	
	//Page 10
	{0x03, 0x10},
	{0x10, 0x01}, //03, //ISPCTL1, YUV ORDER(FIX)
	{0x11, 0x43},
	{0x12, 0x30}, //Y offet, dy offseet enable
	{0x40, 0x88},
	{0x41, 0x00}, //00 DYOFS
	{0x48, 0x88}, //Contrast
	{0x50, 0x48}, //AGBRT
		   
	{0x60, 0x7f},
	{0x61, 0x00}, //
	{0x62, 0x94}, //SATB
	{0x63, 0x9a}, //SATR
	{0x64, 0x48}, //AGSAT
	
	//LPF
	{0x03, 0x11},
	{0x10, 0x25},	//LPF_CTL1 //0x01
	{0x11, 0x07},	//Test Setting
	{0x20, 0x00},	//LPF_AUTO_CTL
	{0x21, 0x38},	//LPF_PGA_TH
	{0x22, 0x00},	//LPF_TIME_TH
	{0x23, 0x10},	//Test Setting
	{0x60, 0x10},	//ZARA_SIGMA_TH //40->10
	{0x61, 0x82},
	{0x62, 0x00},	//ZARA_HLVL_CTL
	{0x63, 0x00},	//ZARA_LLVL_CTL
	{0x64, 0x00},	//ZARA_DY_CTL
	
	{0x67, 0xA0},	//Test Setting
	{0x68, 0x40},	//Test Setting
	{0x69, 0x10},	//Test Setting
	
	//2D
	{0x03, 0x12},
	{0x40, 0xeb},	//YC2D_LPF_CTL1
	{0x41, 0x10},	//YC2D_LPF_CTL2
	{0x50, 0x18},	//Test Setting
	{0x51, 0x24},	//Test Setting
	{0x70, 0x1f},	//GBGR_CTL1 //0x1f
	{0x71, 0x00},	//Test Setting
	{0x72, 0x00},	//Test Setting
	{0x73, 0x00},	//Test Setting
	{0x74, 0x10},	//GBGR_G_UNIT_TH
	{0x75, 0x10},	//GBGR_RB_UNIT_TH
	{0x76, 0x20},	//GBGR_EDGE_TH
	{0x77, 0x80},	//GBGR_HLVL_TH
	{0x78, 0x88},	//GBGR_HLVL_COMP
	{0x79, 0x18},	//Test Setting
	{0xb0, 0x7d},	//dpc
	
	//Edge
	{0x03, 0x13},
	{0x10, 0x01},	
	{0x11, 0x89},	
	{0x12, 0x14},	
	{0x13, 0x19},	
	{0x14,0x08},	//Test Setting
	{0x20, 0x04},	//SHARP_SLOPE
	{0x21, 0x02},	//SHARP_SLOPE_TH
	{0x23,0x30},	//SHARP_DY_CTL
	{0x24,0x33},	//40->33
	{0x25,0x08},	//SHARP_PGA_TH
	{0x26,0x18},	//Test Setting
	{0x27,0x00},	//Test Setting
	{0x28,0x08},	//Test Setting
	{0x29,0x50},	//AG_TH
	{0x2a,0xe0},	//region ratio
	{0x2b,0x10},	//Test Setting
	{0x2c,0x28},	//Test Setting
	{0x2d,0x40},	//Test Setting
	{0x2e,0x00},	//Test Setting
	{0x2f,0x00},	//Test Setting
	{0x30,0x11},	//Test Setting
	{0x80,0x03},	//SHARP2D_CTL
	{0x81,0x07},	//Test Setting
	{0x90, 0x04},	//SHARP2D_SLOPE
	{0x91, 0x02},	//SHARP2D_DIFF_CTL
	{0x92,0x00},	//SHARP2D_HI_CLIP
	{0x93,0x20},	//SHARP2D_DY_CTL
	{0x94,0x42},	//Test Setting
	{0x95,0x60},	//Test Setting
	     
	//Shading
	{0x03, 0x14},
	{0x10, 0x01},
	{0x20, 0x93}, //XCEN
	{0x21, 0x80}, //YCEN
	{0x22, 0x76}, //76, 34, 2b
	{0x23,0x50}, //4b, 15, 0d
	{0x24,0x44}, //3b, 10, 0b
       
	/////Page,CMC
	{0x03,0x15}, 
	{0x10,0x03},
       
	{0x14,0x3c},
	{0x16,0x2c},
	{0x17,0x2f},
       
	{0x30,0xcb},
	{0x31,0x61},
	{0x32,0x16},
	{0x33,0x23},
	{0x34,0xce},
	{0x35,0x2b},
	{0x36,0x01},
	{0x37,0x34},
	{0x38,0x75},
       
	{0x40,0x87},
	{0x41,0x18},
	{0x42,0x91},
	{0x43,0x94},
	{0x44,0x9f},
	{0x45,0x33},
	{0x46,0x00},
	{0x47,0x94},
	{0x48,0x14},
       
	{0x03,0x16}, 
	{0x30,0x00},
	{0x31,0x0a},
	{0x32,0x1b},
	{0x33,0x2e},
	{0x34,0x5c},
	{0x35,0x79},
	{0x36,0x95},
	{0x37,0xa4},
	{0x38,0xb1},
	{0x39,0xbd},
	{0x3a,0xc8},
	{0x3b,0xd9},
	{0x3c,0xe8},
	{0x3d,0xf5},
	{0x3e,0xff},
       
	///Page,AE 
	{0x03,0x17},
	{0xc4,0x3c},
	{0xc5,0x32},
       
	////Page,AE 
	{0x03,0x20},
	{0x10,0x0c},
	{0x11,0x04},
       
	{0x20,0x01},
	{0x28,0x27},
	{0x29,0xa1},
       
	{0x2a,0xf0},
	{0x2b,0x34},
		   
	{0x30,0xf8},
       
	{0x39,0x22},
	{0x3a,0xde},
	{0x3b,0x22}, //23->22 _10_04_06 hhzin
	{0x3c,0xde},
       
	{0x60,0x95}, //d5, 99
	{0x68,0x3c},
	{0x69,0x64},
	{0x6A,0x28},
	{0x6B,0xc8},
       
	{0x70,0x42},//Y Target 42       
	{0x76, 0x22}, //Unlock bnd1
	{0x77, 0x02}, //Unlock bnd2
	
	{0x78, 0x12}, //Yth 1
	{0x79, 0x26}, //Yth 2
	{0x7a,0x23}, //Yth 3
       
	{0x7c, 0x1c},
	{0x7d,0x22}, 
	     
	////50Hz,
	{0x83, 0x00},//ExpTime 30fps
	{0x84, 0xaf}, 
	{0x85, 0xc8}, 
	{0x86, 0x00}, //EXPMin 6000.00 fps
	{0x87, 0xfa},

	
	{0x88, 0x02}, //EXP Max 8.33 fps 
	{0x89, 0xbf}, 
	{0x8a, 0x20}, 
	{0x8B, 0x3a}, //EXP100 
	{0x8C, 0x98}, 
	{0x8D, 0x30}, //EXP120 
	{0x8E, 0xd4}, 
	{0x9c, 0x0b}, //EXP Limit 500.00 fps 
	{0x9d, 0xb8}, 
	{0x9e, 0x00}, //EXP Unit 
	{0x9f, 0xfa},	
       
	{0xb1,0x14},
	{0xb2,0x60},
	{0xb4,0x14},
	{0xb5,0x38},
	{0xb6,0x26},
	{0xb7,0x20},
	{0xb8,0x1d},
	{0xb9,0x1b},
	{0xba,0x1a},
	{0xbb,0x19},
	{0xbc,0x19},
	{0xbd,0x18},
       
	{0xc0, 0x16},	//0x1a->0x16
	{0xc3,0x48},
	{0xc4,0x48},
       
	////Page,AWB
	{0x03,0x22},
	{0x10, 0xfb},
	{0x11,0x26},
	{0x30,0x80},
	{0x31,0x80},
	{0x38,0x12},
	{0x39,0x33},
	{0x3a, 0x88},
	{0x3b, 0xc4},
	{0x40,0xf0},
	{0x41, 0x33},
	{0x42,0x33},
	{0x43,0xf3},
	{0x44, 0x55},
	{0x45, 0x44},
	{0x46,0x02},
	{0x60, 0x00},
	{0x61, 0x00},
	{0x80, 0x39},
	{0x81,0x20},
	{0x82, 0x50},
	{0x83,0x52}, //RMAX Default : 50 -> 48 -> 52 
	{0x84,0x18}, //RMIN Default : 20
	{0x85, 0x4b},
	{0x86,0x25}, //BMIN Default : 20
	{0x87,0x4d}, //RMAXB Default : 50, 4d
	{0x88,0x38}, //RMINB Default : 3e, 45 --> 42
	{0x89,0x3e}, //BMAXB Default : 2e, 2d --> 30
	{0x8a,0x29}, //BMINB Default : 20, 22 --> 26 --> 29
	{0x8b,0x02}, //OUT TH
	{0x8d,0x22},
	{0x8e,0x71},
	{0x8f, 0x63},
	{0x90, 0x60},
	{0x91, 0x5c},
	{0x92, 0x56},
	{0x93, 0x52},
	{0x94, 0x4c},
	{0x95, 0x36},
	{0x96, 0x31},
	{0x97, 0x2e},
	{0x98, 0x2a},
	{0x99, 0x29},
	{0x9a, 0x26},
	{0x9b, 0x09},
	{0xb0, 0x30},
	{0xb1, 0x48},		
	{0x03,0x22},
	{0x10,0xfb},
       
	{0x03,0x20},
	{0x10,0x9c},
	
	{0x01, 0xf0},
    ENDMARKER,
};




/* 640*480: VGA */
static const struct regval_list module_vga_regs[] = 
{

	{0x03,0x00},	//PAGEMODE(0x03)
	//{0x01,0xf1},//Sleep: For Write Reg
	     
	{0x10,0x00},//VGA Size
	     
	{0x20,0x00},
	{0x21,0x04},
	     
	{0x40,0x01},//HBLANK: 0x70 = 112
	{0x41,0x58},
	{0x42,0x00},//VBLANK: 0x04 = 4
	{0x43,0x64},
	     
	{0x03,0x11},
	{0x10,0x25},
	     
	{0x03,0x20},
	//{0x10,0x1c},//Close AE
	//{0x18,0x38},//Reset AE
	     
	{0x86,0x00},
	{0x87,0xfa}, 
	
	{0x8B,0x3a}, //EXP100 
	{0x8C,0x98}, 
	{0x8D,0x30}, //EXP120 
	{0x8E,0xd4}, 
	{0x9c,0x0b}, //EXP Limit 500.00 fps 
	{0x9d,0xb8}, 
	{0x9e,0x00}, //EXP Unit 
	{0x9f,0xfa},	
	     
	//{0x01,0xf0},//Exit Sleep: For Write Reg//brian 20120308 f0 
	     
	//{0x03,0x20},
	//{0x10,0x9c},//Open AE
	//{0x18,0x30},//Reset AE
	
    ENDMARKER,
};

/* 320*240: QVGA */
static const struct regval_list module_qvga_regs[] = 
{
	
	{0x03,0x00},	//PAGEMODE(0x03)
	//{0x01,0xf1},//Sleep: For Write Reg
	     
	{0x10,0x10},//QVGA Size
	     
	{0x20,0x00},
	{0x21,0x02},
	     
	{0x40,0x01},//HBLANK: 0x70 = 112
	{0x41,0x58},
	{0x42,0x00},//VBLANK: 0x04 = 4
	{0x43,0x64},
	     
	{0x03,0x11},//QVGA Fixframerate
	{0x10,0x21},
	     
	{0x03,0x20},
	//{0x10,0x1c},//Close AE
	//{0x18,0x38},//Reset AE
	     
	{0x86,0x00},
	{0x87,0xfa},
	
	{0x8B,0x3a}, //EXP100 
	{0x8C,0x98}, 
	{0x8D,0x30}, //EXP120 
	{0x8E,0xd4}, 
	{0x9c,0x0b}, //EXP Limit 500.00 fps 
	{0x9d,0xb8}, 
	{0x9e,0x00}, //EXP Unit 
	{0x9f,0xfa},	
	     
	//{0x01,0xf0},//Exit Sleep: For Write Reg brian 20120308 f0 
	     
	//{0x03,0x20},
	//{0x10,0x9c},//Open AE
	//{0x18,0x30},//Reset AE
	   ENDMARKER,
};

/*
 * window size list
 */

/* 320*240 */
static struct camera_module_win_size module_win_qvga = {
	.name             = "QVGA",
	.width            = WIDTH_QVGA,
	.height           = HEIGHT_QVGA,
	.win_regs         = module_qvga_regs,

	.frame_rate_array = frame_rate_qvga,
	.capture_only     = 0,
};

/* 640*480 */
static struct camera_module_win_size module_win_vga = {
	.name             = "VGA",
	.width            = WIDTH_VGA,
	.height           = HEIGHT_VGA,
	.win_regs         = module_vga_regs,
	.frame_rate_array = frame_rate_vga,
	.capture_only     = 0,
};

static struct camera_module_win_size *module_win_list[] = {

	&module_win_vga,
	&module_win_qvga, 

};

static struct regval_list module_whitebance_auto_regs[]=
{
	{0x03,0x22},
	{0x10,0xea},  //AWB enable
	{0x80,0x48},
	{0x81,0x20},
	{0x82,0x3d},
	{0x83,0x58},
	{0x84,0x1b},
	{0x85,0x50},
	{0x86,0x25},

	{0x03,0x10},
	{0x11,0x03},
	{0x12,0x30},
	{0x13,0x00},
	{0x44,0x80},
	{0x45,0x80},
	{0x47,0x7f},
	{0x03,0x13},
	{0x20,0x06},
	{0x21,0x04},
	ENDMARKER,
};

static struct regval_list module_scene_night_regs[] =
{	
   	{0x03, 0x20}, //Page 20
	{0x10, 0x1c}, 
	//{0x18, 0x38},
 
	{0x88, 0x02}, //EXP Max 8.33 fps 
	{0x89, 0xbf}, 
	{0x8a, 0x20}, 

    {0x03, 0x20}, //Page 20
	{0x10, 0x9c}, 
	//{0x18, 0x30},
    {0x03, 0x20}, //Page 20
	{0xb2, 0x80},
	ENDMARKER,
};


/* Cloudy Colour Temperature : 6500K - 8000K  */
static struct regval_list module_whitebance_cloudy_regs[]=
{
	{0x03,0x22},
	{0x10,0x6a},
	{0x80,0x62},
	{0x81,0x20},
	{0x82,0x2e},
	{0x83,0x6d},
	{0x84,0x65},
	{0x85,0x30},
	{0x86,0x25},
	ENDMARKER,
};

/* ClearDay Colour Temperature : 5000K - 6500K  */
static struct regval_list module_whitebance_sunny_regs[]=
{
	{0x03,0x22},
	{0x10,0x6a},
	{0x80,0x50},
	{0x81,0x20},
	{0x82,0x2d},
	{0x83,0x52},
	{0x84,0x45},
	{0x85,0x30},
	{0x86,0x1c},
    ENDMARKER,
};

/* Office Colour Temperature : 3500K - 5000K ,ӫ��� */
static struct regval_list module_whitebance_fluorescent_regs[]=
{
	{0x03,0x22},
	{0x10,0x6a},
	{0x80,0x40},
	{0x81,0x20},
	{0x82,0x4f},
	{0x83,0x44},
	{0x84,0x3a},
	{0x85,0x47},
	{0x86,0x3a},
    ENDMARKER,
};

/* Home Colour Temperature : 2500K - 3500K ���׳�� */
static struct regval_list module_whitebance_incandescent_regs[]=
{
	{0x03,0x22},
	{0x10,0x6a},
	{0x80,0x26},
	{0x81,0x20},
	{0x82,0x55},
	{0x83,0x24},
	{0x84,0x1e},
	{0x85,0x58},
	{0x86,0x4a},
	ENDMARKER,
};


static struct regval_list module_scene_auto_regs[] =
{
	{0x03, 0x20}, //Page 20
	{0x10, 0x1c}, 
	//{0x18, 0x38},
 
	{0x88, 0x02}, //EXP Max 8.33 fps 
	{0x89, 0xbf}, 
	{0x8a, 0x20}, 

    {0x03, 0x20}, //Page 20
	{0x10, 0x9c}, 
	//{0x18, 0x30},
    {0x03, 0x20}, //Page 20
	{0xb2, 0x60},
	ENDMARKER,
};

/*
 * The exposure target setttings
 */
static struct regval_list module_exp_comp_neg4_regs[] = {
	{0x03,0x20},
	{0x70,0x12},
	ENDMARKER,
};

static struct regval_list module_exp_comp_neg3_regs[] = {
	{0x03,0x20},
	{0x70,0x2a},
	ENDMARKER,
};

static struct regval_list module_exp_comp_neg2_regs[] = {
	{0x03,0x20},
	{0x70,0x32},
	ENDMARKER,
};

static struct regval_list module_exp_comp_neg1_regs[] = {
	{0x03,0x20},
	{0x70,0x3a},
	ENDMARKER,
};

static struct regval_list module_exp_comp_zero_regs[] = {
	{0x03,0x20},
	{0x70,0x42},
	ENDMARKER,
};

static struct regval_list module_exp_comp_pos1_regs[] = {
	{0x03,0x20},
	{0x70,0x4a},
	ENDMARKER,
};

static struct regval_list module_exp_comp_pos2_regs[] = {
	{0x03,0x20},
	{0x70,0x52},
	ENDMARKER,
};

static struct regval_list module_exp_comp_pos3_regs[] = {
	{0x03,0x20},
	{0x70,0x5a},
	ENDMARKER,
};

static struct regval_list module_exp_comp_pos4_regs[] = {
	{0x03,0x20},
	{0x70,0x62},
	ENDMARKER,
};


static struct v4l2_ctl_cmd_info v4l2_ctl_array[] =
{
	{   .id = V4L2_CID_EXPOSURE, 
		.min = 0, 
		.max = 975,
		.step = 1, 
		.def = 500,
	},
	{	.id = V4L2_CID_EXPOSURE_COMP, 
		.min = -4, 
		.max = 4, 
		.step = 1, 
		.def = 0,
	},	
	{	.id = V4L2_CID_GAIN, 
		.min = 10, 
		.max = 2048, 
		.step = 1, 
		.def = 30,
	},
	{
        .id = V4L2_CID_AUTO_WHITE_BALANCE,
        .min = 0,
        .max = 1,
        .step = 1,
        .def = 1,
    },
    {
        .id = V4L2_CID_WHITE_BALANCE_TEMPERATURE,
        .min = 0,
        .max = 3,
        .step = 1,
        .def = 1,
    },
   /* {	.id = V4L2_CID_SCENE_EXPOSURE, 
		.min = 0, 
		.max = 1, 
		.step = 1, 
		.def = 0,},*/

    {
        .id = V4L2_CID_HFLIP,
        .min = 0,
        .max = 1,
        .step = 1,
        .def = 0,
    },
    {
        .id = V4L2_CID_VFLIP,
        .min = 0,
        .max = 1,
        .step = 1,
        .def = 0,
    },
     {	.id   = V4L2_CID_FLASH_STROBE, 
		.min  = 0, 
		.max  = 1, 
		.step = 1, 
		.def  = 0,
	},
	
	{	.id   = V4L2_CID_FLASH_STROBE_STOP, 
		.min  = 0, 
		.max  = 1, 
		.step = 1, 
		.def  = 0,
	},
     {	.id = V4L2_CID_AF_MODE,
		.min = NONE_AF, 
		.max = CONTINUE_AF|SINGLE_AF, 
		.step = 1, 
		.def = NONE_AF,},
    {	.id = V4L2_CID_AF_STATUS, 
		.min = AF_STATUS_DISABLE, 
		.max = AF_STATUS_FAIL, 
		.step = 1, 
		.def = AF_STATUS_DISABLE,},
	{	.id = V4L2_CID_MIRRORFLIP, //3.4�ں�û�ж����������,ͬʱд��vflip��hflip
		.min = NONE, 
		.max = HFLIP|VFLIP, 
		.step = 1, 
		.def = NONE,},
};

static struct v4l2_ctl_cmd_info_menu v4l2_ctl_array_menu[] =
{
	 {
        .id = V4L2_CID_COLORFX,
        .max = 3,
        .mask = 0x0,
        .def = 0,
    },
    {
        .id = V4L2_CID_EXPOSURE_AUTO,
        .max = 1,
        .mask = 0x0,
        .def = 1,
    },
	{  
		   .id = V4L2_CID_SCENE_MODE, 
		   .max = V4L2_SCENE_MODE_TEXT, 
		   .mask = 0x0, 
		   .def = 0,
		},

    {	.id = V4L2_CID_FLASH_LED_MODE, 
		.max = 3,
		.mask = 0x0,
		.def = 0,},
   {
	.id = V4L2_CID_POWER_LINE_FREQUENCY, 
	.max = V4L2_CID_POWER_LINE_FREQUENCY_AUTO, 
	.mask = 0x0,
	.def = V4L2_CID_POWER_LINE_FREQUENCY_AUTO,},
};


#endif /* __MODULE_DIFF_H__ */