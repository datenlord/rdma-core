/* SPDX-License-Identifier: ((GPL-2.0 WITH Linux-syscall-note) OR Linux-OpenIB) */
/*
 * Copyright (c) 2016 Mellanox Technologies Ltd. All rights reserved.
 *
 * This software is available to you under a choice of one of two
 * licenses.  You may choose to be licensed under the terms of the GNU
 * General Public License (GPL) Version 2, available from the file
 * COPYING in the main directory of this source tree, or the
 * OpenIB.org BSD license below:
 *
 *     Redistribution and use in source and binary forms, with or
 *     without modification, are permitted provided that the following
 *     conditions are met:
 *
 *	- Redistributions of source code must retain the above
 *	  copyright notice, this list of conditions and the following
 *	  disclaimer.
 *
 *	- Redistributions in binary form must reproduce the above
 *	  copyright notice, this list of conditions and the following
 *	  disclaimer in the documentation and/or other materials
 *	  provided with the distribution.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef RDMA_USER_DTLD_H
#define RDMA_USER_DTLD_H

#include <linux/types.h>
#include <linux/socket.h>
#include <linux/in.h>
#include <linux/in6.h>

enum {
	DTLD_NETWORK_TYPE_IPV4 = 1,
	DTLD_NETWORK_TYPE_IPV6 = 2,
};

union dtld_gid {
	__u8	raw[16];
	struct {
		__be64	subnet_prefix;
		__be64	interface_id;
	} global;
};

struct dtld_global_route {
	union dtld_gid	dgid;
	__u32		flow_label;
	__u8		sgid_index;
	__u8		hop_limit;
	__u8		traffic_class;
};

struct dtld_av {
	__u8			port_num;
	/* From DTLD_NETWORK_TYPE_* */
	__u8			network_type;
	__u8			dmac[6];
	struct dtld_global_route	grh;
	union {
		struct sockaddr_in	_sockaddr_in;
		struct sockaddr_in6	_sockaddr_in6;
	} sgid_addr, dgid_addr;
};

struct dtld_sge {
	__aligned_u64 addr;
	__u32	length;
	__u32	lkey;
};

struct mminfo {
	__aligned_u64		offset;
	__u32			size;
	__u32			pad;
};

struct dtld_send_wqe {
	
};

struct dtld_recv_wqe {
	__aligned_u64		wr_id;
	__u32			num_sge;
	__u32			padding;
};

struct dtld_create_ah_resp {
	__u32 ah_num;
	__u32 reserved;
};

struct dtld_ureq_create_cq {
};

struct dtld_uresp_create_cq {
	__u32 cq_id;
	__u32 num_cqe;
	__aligned_u64 q_offset;
	__aligned_u64 q_length;
};

struct dtld_resize_cq_resp {
};

struct dtld_ureq_create_qp {
};

struct dtld_uresp_create_qp {
	__aligned_u64 rq_offset;
	__aligned_u64 sq_offset;
	__aligned_u64 rq_len;
	__aligned_u64 sq_len;
};

struct dtld_create_srq_resp {
	__u32 srq_num;
	__u32 reserved;
};

struct dtld_modify_srq_cmd {
	__aligned_u64 mmap_info_addr;
};

#endif /* RDMA_USER_DTLD_H */
