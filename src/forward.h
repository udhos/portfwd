/*
  forward.h

  $Id: forward.h,v 1.1 2001/05/15 00:25:00 evertonm Exp $
 */

#ifndef FORWARD_H
#define FORWARD_H

#include "solve.h"
#include "host_map.hpp"
#include "portfwd.h"

extern int grandchild_pid[MAX_FD];

int buf_copy(int src_fd, int trg_fd, int pasv);
int tcp_listen(const struct ip_addr *ip, int *port, int queue);

void tcp_forward(const struct ip_addr *local, vector<int> *port_list, vector<host_map*> *map_list, const struct ip_addr *actv_ip, const struct ip_addr *pasv_ip, int uid, int gid);
void udp_forward(const struct ip_addr *local, vector<int> *port_list, vector<host_map*> *map_list, int uid, int gid);

#endif /* FORWARD_H */

/* Eof: forward.h */

