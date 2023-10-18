/*
 * Copyright (c) 2009 Mellanox Technologies Ltd. All rights reserved.
 * Copyright (c) 2009 System Fabric Works, Inc. All rights reserved.
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
 *      - Redistributions of source code must retain the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer.
 *
 *      - Redistributions in binary form must reproduce the above
 *        copyright notice, this list of conditions and the following
 *        disclaimer in the documentation and/or other materials
 *        provided with the distribution.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#ifndef DTLD_ABI_H
#define DTLD_ABI_H

#include <infiniband/kern-abi.h>
#include <rdma/rdma_user_dtld.h>
#include <kernel-abi/rdma_user_dtld.h>

DECLARE_DRV_CMD(udtld_create_ah, IB_USER_VERBS_CMD_CREATE_AH,
		empty, dtld_create_ah_resp);
DECLARE_DRV_CMD(udtld_create_cq, IB_USER_VERBS_CMD_CREATE_CQ,
		dtld_ureq_create_cq, dtld_uresp_create_cq);
DECLARE_DRV_CMD(udtld_create_cq_ex, IB_USER_VERBS_EX_CMD_CREATE_CQ,
		empty, dtld_uresp_create_cq);
DECLARE_DRV_CMD(udtld_create_qp, IB_USER_VERBS_CMD_CREATE_QP,
		dtld_ureq_create_qp, dtld_uresp_create_qp);
DECLARE_DRV_CMD(udtld_create_qp_ex, IB_USER_VERBS_EX_CMD_CREATE_QP,
		empty, dtld_uresp_create_qp);
DECLARE_DRV_CMD(udtld_create_srq, IB_USER_VERBS_CMD_CREATE_SRQ,
		empty, dtld_create_srq_resp);
DECLARE_DRV_CMD(udtld_create_srq_ex, IB_USER_VERBS_CMD_CREATE_XSRQ,
		empty, dtld_create_srq_resp);
DECLARE_DRV_CMD(udtld_modify_srq, IB_USER_VERBS_CMD_MODIFY_SRQ,
		dtld_modify_srq_cmd, empty);
DECLARE_DRV_CMD(udtld_resize_cq, IB_USER_VERBS_CMD_RESIZE_CQ,
		empty, dtld_resize_cq_resp);

#endif /* DTLD_ABI_H */
