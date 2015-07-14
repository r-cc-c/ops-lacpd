/*
 * Copyright (C) 2005-2015 Hewlett-Packard Development Company, L.P.
 * All Rights Reserved.
 *
 *   Licensed under the Apache License, Version 2.0 (the "License"); you may
 *   not use this file except in compliance with the License. You may obtain
 *   a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 *   WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 *   License for the specific language governing permissions and limitations
 *   under the License.
 */

//**************************************************************************
//    File               : mlacp_fproto.h
//    Description        : mcpu LACP function prototypes
//**************************************************************************

#ifndef _MLACP_FPROTO_H
#define _MLACP_FPROTO_H

#include "lacp_halon.h"

//***************************************************************
// Variables in lacpd.c
//***************************************************************
extern bool exiting;

//***************************************************************
// Functions in mlacp_main.c
//***************************************************************
extern void mlacpBoltonRxPdu(struct ML_event *);
extern void register_mcast_addr(port_handle_t lport_handle);
extern void deregister_mcast_addr(port_handle_t lport_handle);
extern void *lacpd_protocol_thread(void *arg);
extern int mlacp_init(u_long);

//***************************************************************
// Functions in mlacp_send.c
//***************************************************************
extern  int mlacp_blocking_send_select_aggregator(LAG_t *const lag,
                                                  lacp_per_port_variables_t *lacp_port);
extern  int mlacp_blocking_send_attach_aggregator(lacp_per_port_variables_t *lacp_port);
extern  int mlacp_blocking_send_detach_aggregator(lacp_per_port_variables_t *lacp_port);
extern  int mlacp_blocking_send_enable_collecting(lacp_per_port_variables_t *lacp_port);
extern  int mlacp_blocking_send_enable_distributing(lacp_per_port_variables_t *lacp_port);
extern  int mlacp_blocking_send_disable_collect_dist(lacp_per_port_variables_t *lacp_port);

// Halon: New function to clear super port.
extern int mlacp_blocking_send_clear_aggregator(unsigned long long sport_handle);

//***************************************************************
// Functions in mlacp related portion of FSM files
//***************************************************************
extern void mlacp_task_init(void);
extern void mlacp_process_rxPdu(port_handle_t sport_handle, unsigned char *data);

//***************************************************************
// Functions in mlacp_task.c
//***************************************************************
extern int lacp_lag_port_match(void *v1, void *v2);

//***************************************************************
// Functions in mlacp_recv.c
//***************************************************************
extern void mlacp_process_vlan_msg(struct ML_event *);
extern void mlacp_process_api_msg(struct ML_event *);
extern void mlacp_process_showmgr_msg(struct ML_event *);
extern void mlacp_process_diagmgr_msg(struct ML_event *);
extern void mlacp_process_timer(struct MLt_msglib__timer *tevent);
extern void mlacpVapiLportEvent(struct ML_event *pevent);

//***************************************************************
// Functions in lacp_support.c
//***************************************************************
extern void mlacpVapiLinkDown(port_handle_t lport_handle);
extern void mlacpVapiLinkUp(port_handle_t lport_handle, int speed);
extern void LACP_disable_lacp(port_handle_t lport_handle);
extern void mlacpVapiSportParamsChange(int msg,
                                       struct MLt_vpm_api__lacp_sport_params *pin_lacp_params);

//***************************************************************
// Functions in selection.c
//***************************************************************
extern void LAG_attached_to_aggregator(port_handle_t lport_handle,int result);

//***************************************************************
// Functions in mux_fsm.c
//***************************************************************
extern void stop_wait_while_timer(lacp_per_port_variables_t *plpinfo);

#endif //_MLACP_FPROTO_H