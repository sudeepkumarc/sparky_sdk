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

#define CAMERA_MODULE_NAME 		"sp0a19"
#define CAMERA_MODULE_PID		0xa6
#define VERSION(pid, ver) 		((pid<<8)|(ver&0xFF))

#define MODULE_PLATFORM_ID		SP0A19_PLATFORM_ID
#define MODULE_I2C_REAL_ADDRESS		(0x42>>1)
#define MODULE_I2C_REG_ADDRESS		(0x42>>1)
#define I2C_REGS_WIDTH			1
#define I2C_DATA_WIDTH			1

#define PID						0x02 /* Product ID Number */

#define OUTTO_SENSO_CLOCK 		24000000

#define DEFAULT_VSYNC_ACTIVE_LEVEL		V4L2_MBUS_VSYNC_ACTIVE_HIGH
#define DEFAULT_PCLK_SAMPLE_EDGE      	V4L2_MBUS_PCLK_SAMPLE_RISING 
#define DEFAULT_POWER_LINE_FREQUENCY	V4L2_CID_POWER_LINE_FREQUENCY_50HZ

#define MODULE_DEFAULT_WIDTH	WIDTH_QVGA
#define MODULE_DEFAULT_HEIGHT	HEIGHT_QVGA
#define MODULE_MAX_WIDTH		WIDTH_VGA
#define MODULE_MAX_HEIGHT		HEIGHT_VGA

#define AHEAD_LINE_NUM			15    //10ÐÐ = 50´ÎÑ­»·
#define DROP_NUM_CAPTURE		3
#define DROP_NUM_PREVIEW		5

static unsigned int frame_rate_qvga[]  = {30,};
static unsigned int frame_rate_vga[]   = {30,};

//AE target
#define  SP0A19_P0_0xf7  0x88
#define  SP0A19_P0_0xf8  0x80
#define  SP0A19_P0_0xf9  0x70
#define  SP0A19_P0_0xfa  0x68
//HEQ
#define  SP0A19_P0_0xdd  0x78	//0x7c
#define  SP0A19_P0_0xde  0xa0	//0xc4

static const struct regval_list module_init_regs[] =
{
	/*init registers code.*/
	{0xfd,0x00},
	{0x1c,0x28},
	{0x32,0x00},
	{0x0f,0x2f},
	{0x10,0x2e},
	{0x11,0x00},
	{0x12,0x18},
	{0x13,0x2f},
	{0x14,0x00},
	{0x15,0x3f},
	{0x16,0x00},
	{0x17,0x18},
	{0x25,0x40},
	{0x1a,0x0b},
	{0x1b,0xc },
	{0x1e,0xb },
	{0x20,0x3f},
	{0x21,0x13},
	{0x22,0x19},
	{0x26,0x1a},
	{0x27,0xab},
	{0x28,0xfd},
	{0x30,0x00},
	{0x31,0x10}, //0x00
	{0xfb,0x33}, //0x31
	{0x1f,0x08},  

	//Blacklevel
	{0xfd,0x00},
	{0x65,0x00},//06
	{0x66,0x00},//06
	{0x67,0x00},//06
	{0x68,0x00},//06
	{0x45,0x00},
	{0x46,0x0f},

#if 0
	//ae setting 
	{0xfd,0x00},
	{0x03,0x01},
	{0x04,0x32},
	{0x06,0x00},
	{0x09,0x01},
	{0x0a,0x46},
	{0xf0,0x66},
	{0xf1,0x00},
	{0xfd,0x01},
	{0x90,0x0c},
	{0x92,0x01},
	{0x98,0x66},
	{0x99,0x00},
	{0x9a,0x01},
	{0x9b,0x00},

	//Status
	{0xfd,0x01},
	{0xce,0xc8},
	{0xcf,0x04},
	{0xd0,0xc8},
	{0xd1,0x04}, 
#else
	//24M 50HZ 20-6 FPS 
	//ae setting
	{0xfd,0x00},
	{0x03,0x01},
	{0x04,0x32},
	{0x06,0x00},
	{0x09,0x01},
	{0x0a,0x46},
	{0xf0,0x66},
	{0xf1,0x00},
	{0xfd,0x01},
	{0x90,0x10},
	{0x92,0x01},
	{0x98,0x66},
	{0x99,0x00},
	{0x9a,0x01},
	{0x9b,0x00},
	//Status
	{0xfd,0x01},
	{0xce,0x60},
	{0xcf,0x06},
	{0xd0,0x60},
	{0xd1,0x06},
	{0xfd,0x00},
#endif

	{0xfd,0x01},
	{0xc4,0x56},
	{0xc5,0x8f},
	{0xca,0x30},
	{0xcb,0x45},
	{0xcc,0x70},
	{0xcd,0x48},
	{0xfd,0x00},

	//lsc  for st
	{0xfd,0x01},
	{0x35,0x15},
	{0x36,0x15},
	{0x37,0x15},
	{0x38,0x15},
	{0x39,0x15},
	{0x3a,0x15},
	{0x3b,0x13},
	{0x3c,0x15},
	{0x3d,0x15},
	{0x3e,0x15},
	{0x3f,0x15},
	{0x40,0x18},
	{0x41,0x00},
	{0x42,0x04},
	{0x43,0x04},
	{0x44,0x00},
	{0x45,0x00},
	{0x46,0x00},
	{0x47,0x00},
	{0x48,0x00},
	{0x49,0xfd},
	{0x4a,0x00},
	{0x4b,0x00},
	{0x4c,0xfd},
	{0xfd,0x00},  
	//awb 1
	{0xfd,0x01},
	{0x28,0xc5},
	{0x29,0x9b},
	{0x2e,0x02},	
	{0x2f,0x16},
	{0x17,0x17},
	{0x18,0x19},
	{0x19,0x45},
	{0x2a,0xef},
	{0x2b,0x15},  
	//awb2
	{0xfd,0x01},
	{0x73,0x80},
	{0x1a,0x80},
	{0x1b,0x80}, 
	//d65
	{0x65,0xd5},
	{0x66,0xfa},
	{0x67,0x72},
	{0x68,0x8a},
	//indoor
	{0x69,0xc6},
	{0x6a,0xee},
	{0x6b,0x94},
	{0x6c,0xab},
	//f
	{0x61,0x7a},
	{0x62,0x98},
	{0x63,0xc5},
	{0x64,0xe6},
	//cwf
	{0x6d,0xb9},
	{0x6e,0xde},
	{0x6f,0xb2},
	{0x70,0xd5},

	//////////////////skin detect//////
	{0xfd,0x01},
	{0x08,0x15},
	{0x09,0x04},
	{0x0a,0x20},
	{0x0b,0x12},
	{0x0c,0x27},
	{0x0d,0x06},
	{0x0f,0x63},  
	//BPC_grad
	{0xfd,0x00},
	{0x79,0xf0},
	{0x7a,0x80},  //f0
	{0x7b,0x80},  //f0
	{0x7c,0x20},  //f0  

#if 0 //default
	//smooth
	{0xfd,0x00},
	//µ¥Í¨µÀ¼äÆ½»¬ãÐÖµ	
	{0x57,0x08},	//raw_dif_thr_outdoor
	{0x58,0x0c}, //raw_dif_thr_normal
	{0x56,0x0e}, //raw_dif_thr_dummy
	{0x59,0x12}, //raw_dif_thr_lowlight
	//GrGbÆ½»¬ãÐÖµ
	{0x89,0x08},	//raw_grgb_thr_outdoor 
	{0x8a,0x0c}, //raw_grgb_thr_normal  
	{0x9c,0x0e}, //raw_grgb_thr_dummy   
	{0x9d,0x12}, //raw_grgb_thr_lowlight

	//Gr\GbÖ®¼äÆ½»¬Ç¿¶È
	{0x81,0xe0},    //raw_gflt_fac_outdoor
	{0x82,0x80}, //80//raw_gflt_fac_normal
	{0x83,0x40},    //raw_gflt_fac_dummy
	{0x84,0x20},    //raw_gflt_fac_lowlight
	//Gr¡¢Gbµ¥Í¨µÀÄÚÆ½»¬Ç¿¶È  
	{0x85,0xe0}, //raw_gf_fac_outdoor  
	{0x86,0x80}, //raw_gf_fac_normal  
	{0x87,0x40}, //raw_gf_fac_dummy   
	{0x88,0x20}, //raw_gf_fac_lowlight
	//R¡¢BÆ½»¬Ç¿¶È  
	{0x5a,0xff},		 //raw_rb_fac_outdoor
	{0x5b,0xe0}, //40//raw_rb_fac_normal
	{0x5c,0x80}, 	 //raw_rb_fac_dummy
	{0x5d,0x20}, 	 //raw_rb_fac_lowlight

	//sharpen 
	{0xfd,0x01},
	{0xe2,0x50},	//sharpen_y_base
	{0xe4,0xa0},	//sharpen_y_max

	{0xe5,0x08}, //rangek_neg_outdoor
	{0xd3,0x08}, //rangek_pos_outdoor   
	{0xd7,0x08}, //range_base_outdoor   

	{0xe6,0x0a}, //rangek_neg_normal
	{0xd4,0x0a}, //rangek_pos_normal 
	{0xd8,0x0a}, //range_base_normal  

	{0xe7,0x12}, //rangek_neg_dummy
	{0xd5,0x12}, //rangek_pos_dummy
	{0xd9,0x12}, //range_base_dummy  

	{0xd2,0x15}, //rangek_neg_lowlight
	{0xd6,0x15}, //rangek_pos_lowlight
	{0xda,0x15}, //range_base_lowlight

	{0xe8,0x20},//sharp_fac_pos_outdoor
	{0xec,0x2c},//sharp_fac_neg_outdoor
	{0xe9,0x20},//sharp_fac_pos_nr
	{0xed,0x2c},//sharp_fac_neg_nr
	{0xea,0x18},//sharp_fac_pos_dummy
	{0xef,0x1c},//sharp_fac_neg_dummy
	{0xeb,0x15},//sharp_fac_pos_low
	{0xf0,0x18},//sharp_fac_neg_low 
#else
	//smooth
	{0xfd,0x00},
	//µ¥Í¨µÀ¼äÆ½»¬ãÐÖµ	
	{0x57,0x0c},	//raw_dif_thr_outdoor
	{0x58,0x14}, //raw_dif_thr_normal
	{0x56,0x18}, //raw_dif_thr_dummy
	{0x59,0x18}, //raw_dif_thr_lowlight
	//GrGbÆ½»¬ãÐÖµ
	{0x89,0x0c},	//raw_grgb_thr_outdoor 
	{0x8a,0x14}, //raw_grgb_thr_normal  
	{0x9c,0x18}, //raw_grgb_thr_dummy   
	{0x9d,0x18}, //raw_grgb_thr_lowlight

	//Gr\GbÖ®¼äÆ½»¬Ç¿¶È
	{0x81,0xd8},    //raw_gflt_fac_outdoor
	{0x82,0xd4}, //80//raw_gflt_fac_normal
	{0x83,0x74},    //raw_gflt_fac_dummy
	{0x84,0x40},    //raw_gflt_fac_lowlight
	//Gr¡¢Gbµ¥Í¨µÀÄÚÆ½»¬Ç¿¶È  
	{0x85,0xd8}, //raw_gf_fac_outdoor  
	{0x86,0xb4}, //raw_gf_fac_normal  
	{0x87,0x74}, //raw_gf_fac_dummy   
	{0x88,0x40}, //raw_gf_fac_lowlight
	//R¡¢BÆ½»¬Ç¿¶È  
	{0x5a,0xff},		 //raw_rb_fac_outdoor
	{0x5b,0xd4}, //40//raw_rb_fac_normal
	{0x5c,0x74}, 	 //raw_rb_fac_dummy
	{0x5d,0x00}, 	 //raw_rb_fac_lowlight

	//sharpen 
	{0xfd,0x01},
	{0xe2,0x30},	//sharpen_y_base
	{0xe4,0xa0},	//sharpen_y_max

	{0xe5,0x08}, //rangek_neg_outdoor
	{0xd3,0x08}, //rangek_pos_outdoor   
	{0xd7,0x08}, //range_base_outdoor   

	{0xe6,0x0a}, //rangek_neg_normal
	{0xd4,0x0a}, //rangek_pos_normal 
	{0xd8,0x0a}, //range_base_normal  

	{0xe7,0x0c}, //rangek_neg_dummy
	{0xd5,0x0c}, //rangek_pos_dummy
	{0xd9,0x0c}, //range_base_dummy  

	{0xd2,0x16}, //rangek_neg_lowlight
	{0xd6,0x16}, //rangek_pos_lowlight
	{0xda,0x16}, //range_base_lowlight

	{0xe8,0x20},//sharp_fac_pos_outdoor
	{0xec,0x2c},//sharp_fac_neg_outdoor
	{0xe9,0x20},//sharp_fac_pos_nr
	{0xed,0x2c},//sharp_fac_neg_nr
	{0xea,0x1c},//sharp_fac_pos_dummy
	{0xef,0x20},//sharp_fac_neg_dummy
	{0xeb,0x18},//sharp_fac_pos_low
	{0xf0,0x1c},//sharp_fac_neg_low 
#endif

#if 0 //default
	//CCM
	{0xfd,0x01},
	{0xa0,0x66},//80(ºìÉ«½Ó½ü£¬·ôÉ«²»ÀíÏë)
	{0xa1,0x0 },//0 
	{0xa2,0x19},//0 
	{0xa3,0xf3},//f0
	{0xa4,0x8e},//a6
	{0xa5,0x0 },//ea
	{0xa6,0x0 },//0 
	{0xa7,0xe6},//e6
	{0xa8,0x9a},//9a
	{0xa9,0x0 },//0 
	{0xaa,0x3 },//33
	{0xab,0xc },//c 
	{0xfd,0x00},
#else
	{0xfd,0x01},
	{0xa0,0x7c},//80(o¨¬¨¦??¨®?¨¹¡ê?¡¤?¨¦?2?¨¤¨ª??)
	{0xa1,0x0 },//0 
	{0xa2,0x0 },//0 
	{0xa3,0xf3},//f0
	{0xa4,0x8e},//a6
	{0xa5,0x0 },//ea
	{0xa6,0x0 },//0 
	{0xa7,0xe6},//e6
	{0xa8,0x9a},//9a
	{0xa9,0x0 },//0 
	{0xaa,0x3 },//33
	{0xab,0xc },//c 
	{0xfd,0x00},
#endif

	//gamma  

	{0xfd,0x00},
	{0x8b,0x0 },//0 
	{0x8c,0xC },//11
	{0x8d,0x19},//19 
	{0x8e,0x2C},//28 
	{0x8f,0x49},//46 
	{0x90,0x61},//61 
	{0x91,0x77},//78 
	{0x92,0x8A},//8A 
	{0x93,0x9B},//9B 
	{0x94,0xA9},//A9 
	{0x95,0xB5},//B5 
	{0x96,0xC0},//C0 
	{0x97,0xCA},//CA 
	{0x98,0xD4},//D4 
	{0x99,0xDD},//DD 
	{0x9a,0xE6},//E6 
	{0x9b,0xEF},//EF 
	{0xfd,0x01},//01 
	{0x8d,0xF7},//F7 
	{0x8e,0xFF},//FF 

	//rpc
	{0xfd,0x00},
	{0xe0,0x4c},
	{0xe1,0x3c},
	{0xe2,0x34},
	{0xe3,0x2e},
	{0xe4,0x2e},
	{0xe5,0x2c},
	{0xe6,0x2c},
	{0xe8,0x2a},
	{0xe9,0x2a},
	{0xea,0x2a},
	{0xeb,0x28},
	{0xf5,0x28},
	{0xf6,0x28},
	//ae min gain  
	{0xfd,0x01},
	{0x94,0x80},//rpc_max_indr 0xa0
	{0x95,0x28},//1e//rpc_min_indr 
	{0x9c,0xa0},//rpc_max_outdr
	{0x9d,0x28},//rpc_min_outdr    

	//ae target
	{0xfd,0x00}, 
	{0xed,SP0A19_P0_0xf7+0x04}, 
	{0xf7,SP0A19_P0_0xf7},
	{0xf8,SP0A19_P0_0xf8},  
	{0xec,SP0A19_P0_0xf8-0x04},
	{0xef,SP0A19_P0_0xf9+0x04},
	{0xf9,SP0A19_P0_0xf9},
	{0xfa,SP0A19_P0_0xfa},  
	{0xee,SP0A19_P0_0xfa-0x04}, 
	//gray detect
	{0xfd,0x01},
	{0x30,0x40},
	{0x31,0x70},//
	{0x32,0x40},//80
	{0x33,0xef},//
	{0x34,0x05},//04
	{0x4d,0x2f},//40
	{0x4e,0x20},//
	{0x4f,0x16},//13      
	//lowlight lum
	{0xfd,0x00}, 
	{0xb2,0x10},//lum_limit
	{0xb3,0x1f},//lum_set
	{0xb4,0x30},//black_vt
	{0xb5,0x45},//white_vt
	//saturation
	{0xfd,0x00},
	{0xbe,0xff},
	{0xbf,0x01}, 
	{0xc0,0xff},
	{0xc1,0xd8},
	{0xd3,0x80},//0x78
	{0xd4,0x80},//0x78
	{0xd6,0x78},//0x70      
	{0xd7,0x78},//0x50
	//HEQ
	{0xfd,0x00},
	{0xdc,0x00},
	{0xdd,SP0A19_P0_0xdd},
	{0xde,SP0A19_P0_0xde},//80
	{0xdf,0x80},    
	//func enable
	{0xfd,0x00},
	{0x32,0x15},//d
	{0x34,0x76},//16
	{0x35,0x40},
	{0x33,0xef},
	{0x5f,0x51},
	ENDMARKER,
};

/* 320*240: QVGA */
static const struct regval_list module_qvga_regs[] = 
{
	{0xfd,0x01},  
	{0x0e,0x03},
	{0xfd,0x00},
	{0x30,0x10},
ENDMARKER,
};

/* 640*480: VGA */
static const struct regval_list module_vga_regs[] = 
{
	{0xfd,0x01},  
	{0x0e,0x00},
	{0xfd,0x00},
	{0x30,0x00},
ENDMARKER,
};

static const struct regval_list module_init_auto_focus[] =
{
ENDMARKER,
//  NULL
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
	&module_win_qvga,
	&module_win_vga,
};
  
static struct regval_list module_whitebance_auto_regs[]=
{
	{0xfd,0x01},                      
	{0x28,0xc5},		                  
	{0x29,0x9b},                      
	{0xfd,0x00}, 		
	{0x32,0x15},   //awb & ae  opened
	{0xfd,0x00}, 
	ENDMARKER, 
};

static struct regval_list module_whitebance_none_auto_regs[]=
{
	//{0xfd,0x01},	
	//{0x28,0xce},	
	//{0x29,0x8a},
	{0xfd,0x00},
	{0x32,0x05},
	ENDMARKER,
};

/* Cloudy Colour Temperature : 6500K - 8000K  */
static struct regval_list module_whitebance_cloudy_regs[]=
{
	{0xfd,0x00}, 
	{0x32,0x05},          
	{0xfd,0x01},          
	{0x28,0xbf},	        
	{0x29,0x89},	        
	{0xfd,0x00},
	ENDMARKER,
};

/* ClearDay Colour Temperature : 5000K - 6500K  */
static struct regval_list module_whitebance_sunny_regs[]=
{
	{0xfd,0x00}, 
	{0x32,0x05},           
	{0xfd,0x01},           
	{0x28,0xbc},	         
	{0x29,0x5d},	         
	{0xfd,0x00},
	ENDMARKER, 		
};

/* Office Colour Temperature : 3500K - 5000K ,Ó«¹âµÆ */
static struct regval_list module_whitebance_fluorescent_regs[]=
{
	{0xfd,0x00},  
	{0x32,0x05},                  
	{0xfd,0x01},                  
	{0x28,0xaf},		              
	{0x29,0x99},		              
	{0xfd,0x00},
	ENDMARKER,	
};

/* Home Colour Temperature : 2500K - 3500K £¬°×³ãµÆ */
static struct regval_list module_whitebance_incandescent_regs[]=
{
	{0xfd,0x00}, 
	{0x32,0x05},                 
	{0xfd,0x01},                 
	{0x28,0x89},		             
	{0x29,0xb8},		             
	{0xfd,0x00}, 
	ENDMARKER,
};
#if 0
/*正常模式*/
static struct regval_list module_effect_normal_regs[] =
{
	{0xfd, 0x00},
	{0x62, 0x00},
	{0x63, 0x80},
	{0x64, 0x80},
	ENDMARKER,
};

/*µ¥É«£¬ºÚ°×ÕÕÆ¬*/
static struct regval_list module_effect_white_black_regs[] =
{
	{0xfd, 0x00},
	{0x62, 0x20},
	{0x63, 0x80},
	{0x64, 0x80},
	ENDMARKER,
};

/*¸ºÆ¬Ð§¹û*/
static struct regval_list module_effect_negative_regs[] =
{
	{0xfd, 0x00},
	{0x62, 0x04},
	{0x63, 0x80},
	{0x64, 0x80},
	ENDMARKER,
};

/*¸´¹ÅÐ§¹û*/
static struct regval_list module_effect_antique_regs[] =
{    
	{0xfd, 0x00},
	{0x62, 0x10},
	{0x63, 0xc0},
	{0x64, 0x20},
	ENDMARKER,
};
#endif
static struct regval_list module_scene_auto_regs[] =
{
    {0xfd, 0x00},
    {0xdc, 0x00},
	ENDMARKER,
};
#if 0
static struct regval_list module_scene_night_regs[] =
{
    {0xfd, 0x00},
    {0xdc, 0x20},
	ENDMARKER,
};

static  struct regval_list module_scene_portrait[] =
{
//  NULL
ENDMARKER,
};

/*
 * The exposure target setttings
 */
static struct regval_list module_exp_comp_neg4_regs[] = {
//  NULL
ENDMARKER,
};

static struct regval_list module_exp_comp_neg3_regs[] = {
//  NULL
ENDMARKER,
};

static struct regval_list module_exp_comp_neg2_regs[] = {
//  NULL
ENDMARKER,
};

static struct regval_list module_exp_comp_neg1_regs[] = {
//  NULL
ENDMARKER,
};

static struct regval_list module_exp_comp_zero_regs[] = {
//  NULL
ENDMARKER,
};

static struct regval_list module_exp_comp_pos1_regs[] = {
//  NULL
ENDMARKER,
};

static struct regval_list module_exp_comp_pos2_regs[] = {
//  NULL
ENDMARKER,
};

static struct regval_list module_exp_comp_pos3_regs[] = {
//  NULL
ENDMARKER,
};

static struct regval_list module_exp_comp_pos4_regs[] = {
//  NULL
ENDMARKER,
};
#endif
static struct v4l2_ctl_cmd_info v4l2_ctl_array[] =
{
	{	.id   = V4L2_CID_AUTO_WHITE_BALANCE, 
		.min  = 0, 
		.max  = 1, 
		.step = 1, 
		.def  = 1,},
	{	.id   = V4L2_CID_WHITE_BALANCE_TEMPERATURE, 
		.min  = 0, 
		.max  = 3, 
		.step = 1, 
		.def  = 1,},
	{	.id = V4L2_CID_GAIN, 
		.min = 10, 
		.max = 2048, 
		.step = 1, 
		.def = 30,},
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
#if 0
	{	.id   = V4L2_CID_SCENE_EXPOSURE, 
		.min  = 0, 
		.max  = 1, 
		.step = 1, 
		.def  = 0,},//3.4ÄÚºËÃ»ÓÐ¶¨Òå´ËÃüÁî×Ö
	{	.id   = V4L2_CID_PRIVATE_PREV_CAPT, 
		.min  = 0, 
		.max  = 1, 
		.step = 1, 
		.def  = PREVIEW_MODE,},//3.4ÄÚºËÃ»ÓÐ¶¨Òå´ËÃüÁî×Ö

	{	.id   = V4L2_CID_GAIN, 
		.min  = 0,
		.max  = 0,
		.step = 0,
		.def  = 0,},
	{   .id   = V4L2_CID_EXPOSURE, 
		.min  = 0, 
		.max  = 0,
		.step = 0, 
		.def  = 0,},
	{	.id   = V4L2_CID_EXPOSURE_COMP, 
		.min  = -4, 
		.max  = 4, 
		.step = 1, 
		.def  = 0,},
	{	.id   = V4L2_CID_FLASH_STROBE, 
		.min  = 0, 
		.max  = 1, 
		.step = 1, 
		.def  = 0,},
	{	.id   = V4L2_CID_FLASH_STROBE_STOP, 
		.min  = 0, 
		.max  = 1, 
		.step = 1, 
		.def  = 0,},
    {	.id   = V4L2_CID_AF_MODE,
		.min  = NONE_AF, 
		.max  = CONTINUE_AF|SINGLE_AF, 
		.step = 1, 
		.def  = CONTINUE_AF|SINGLE_AF,},
	{	.id   = V4L2_CID_AF_STATUS, 
		.min  = AF_STATUS_DISABLE, 
		.max  = AF_STATUS_FAIL, 
		.step = 1, 
		.def  = AF_STATUS_DISABLE,},
#endif
		{	.id = V4L2_CID_MIRRORFLIP, //3.10ÄÚºËÃ»ÓÐ¶¨Òå´ËÃüÁî×Ö,Í¬Ê±Ð´ÈëvflipºÍhflip
		.min = NONE, 
		.max = HFLIP|VFLIP, 
		.step = 1, 
		.def = NONE,},
};

static struct v4l2_ctl_cmd_info_menu v4l2_ctl_array_menu[] =
{
	{	.id   = V4L2_CID_COLORFX, 
		.max  = 3, 
		.mask = 0x0, 
		.def  = 0,},
	{	.id   = V4L2_CID_EXPOSURE_AUTO, 
		.max  = 1, 
		.mask = 0x0, 
		.def  = 1,},
	{  
	   .id = V4L2_CID_SCENE_MODE, 
	   .max = V4L2_SCENE_MODE_TEXT, 
	   .mask = 0x0, 
	   .def = 0,
	},
#if 1
	{	.id   = V4L2_CID_FLASH_LED_MODE, 
		.max  = 3,
		.mask = 0x0,
		.def  = 0,},
#endif
	{.id = V4L2_CID_POWER_LINE_FREQUENCY, 
	.max = V4L2_CID_POWER_LINE_FREQUENCY_AUTO, 
	.mask = 0x0,
	.def = V4L2_CID_POWER_LINE_FREQUENCY_AUTO,},
};


#endif /* __MODULE_DIFF_H__ */
