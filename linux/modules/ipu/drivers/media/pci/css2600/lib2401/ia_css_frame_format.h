/*
 * Support for Intel Camera Imaging ISP subsystem.
 *
 * Copyright (c) 2010 - 2014 Intel Corporation. All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 */

#ifndef __IA_CSS_FRAME_FORMAT_H
#define __IA_CSS_FRAME_FORMAT_H

/** @file
 * This file contains information about formats supported in the ISP
 */

/** Frame formats, some of these come from fourcc.org, others are
   better explained by video4linux2. The NV11 seems to be described only
   on MSDN pages, but even those seem to be gone now.
   Frames can come in many forms, the main categories are RAW, RGB and YUV
   (or YCbCr). The YUV frames come in 4 flavors, determined by how the U and V
   values are subsampled:
   1. YUV420: hor = 2, ver = 2
   2. YUV411: hor = 4, ver = 1
   3. YUV422: hor = 2, ver = 1
   4. YUV444: hor = 1, ver = 1

  Warning: not all frame formats are supported as input or output to/from ISP.
    Some of these formats are therefore not defined in the output table module.
    Modifications in below frame format enum can require modifications in the
    output table module.
*/
enum ia_css_frame_format {
	IA_CSS_FRAME_FORMAT_NV11 = 0,   /**< 12 bit YUV 411, Y, UV plane */
	IA_CSS_FRAME_FORMAT_NV12,       /**< 12 bit YUV 420, Y, UV plane */
	IA_CSS_FRAME_FORMAT_NV16,       /**< 16 bit YUV 422, Y, UV plane */
	IA_CSS_FRAME_FORMAT_NV21,       /**< 12 bit YUV 420, Y, VU plane */
	IA_CSS_FRAME_FORMAT_NV61,       /**< 16 bit YUV 422, Y, VU plane */
	IA_CSS_FRAME_FORMAT_YV12,       /**< 12 bit YUV 420, Y, V, U plane */
	IA_CSS_FRAME_FORMAT_YV16,       /**< 16 bit YUV 422, Y, V, U plane */
	IA_CSS_FRAME_FORMAT_YUV420,     /**< 12 bit YUV 420, Y, U, V plane */
	IA_CSS_FRAME_FORMAT_YUV420_16,  /**< yuv420, 16 bits per subpixel */
	IA_CSS_FRAME_FORMAT_YUV422,     /**< 16 bit YUV 422, Y, U, V plane */
	IA_CSS_FRAME_FORMAT_YUV422_16,  /**< yuv422, 16 bits per subpixel */
	IA_CSS_FRAME_FORMAT_UYVY,       /**< 16 bit YUV 422, UYVY interleaved */
	IA_CSS_FRAME_FORMAT_YUYV,       /**< 16 bit YUV 422, YUYV interleaved */
	IA_CSS_FRAME_FORMAT_YUV444,     /**< 24 bit YUV 444, Y, U, V plane */
	IA_CSS_FRAME_FORMAT_YUV_LINE,   /**< Internal format, 2 y lines followed
					     by a uvinterleaved line */
	IA_CSS_FRAME_FORMAT_RAW,	/**< RAW, 1 plane */
	IA_CSS_FRAME_FORMAT_RGB565,     /**< 16 bit RGB, 1 plane. Each 3 sub
					     pixels are packed into one 16 bit
					     value, 5 bits for R, 6 bits for G
					     and 5 bits for B. */
	IA_CSS_FRAME_FORMAT_PLANAR_RGB888, /**< 24 bit RGB, 3 planes */
	IA_CSS_FRAME_FORMAT_RGBA888,	/**< 32 bit RGBA, 1 plane, A=Alpha
					     (alpha is unused) */
	IA_CSS_FRAME_FORMAT_QPLANE6, /**< Internal, for advanced ISP */
	IA_CSS_FRAME_FORMAT_BINARY_8,	/**< byte stream, used for jpeg. For
					     frames of this type, we set the
					     height to 1 and the width to the
					     number of allocated bytes. */
	IA_CSS_FRAME_FORMAT_MIPI,	/**< MIPI frame, 1 plane */
	IA_CSS_FRAME_FORMAT_RAW_PACKED, /**< RAW, 1 plane, packed */
	IA_CSS_FRAME_FORMAT_CSI_MIPI_YUV420_8,	      /**< 8 bit per Y/U/V.
							   Y odd line; UYVY
							   interleaved even line */
	IA_CSS_FRAME_FORMAT_CSI_MIPI_LEGACY_YUV420_8, /**< Legacy YUV420. UY odd
							   line; VY even line */
	IA_CSS_FRAME_FORMAT_CSI_MIPI_YUV420_10       /**< 10 bit per Y/U/V. Y odd
							   line; UYVY interleaved
							   even line */
};
#define IA_CSS_FRAME_FORMAT_NUM		(IA_CSS_FRAME_FORMAT_CSI_MIPI_YUV420_10 + 1)
/** Number of valid output frame formats for ISP **/
#define IA_CSS_FRAME_OUT_FORMAT_NUM	(IA_CSS_FRAME_FORMAT_RGBA888 + 1)

#endif /* __IA_CSS_FRAME_FORMAT_H */
