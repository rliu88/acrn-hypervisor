/*
 * Copyright (C) 2021 Intel Corporation. All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
/* return whether pdev is a root port */
#ifndef __PCI_UTIL_H
#define __PCI_UTIL_H

#include <stdbool.h>
#include "pciaccess.h"

int pci_find_capability(struct pci_device *pdev, const int cap_id);
int pci_find_ext_cap(struct pci_device *pdev, int cap_id);
int pci_pcie_type(struct pci_device *dev);
bool is_root_port(struct pci_device *pdev);
bool is_bridge(struct pci_device *pdev);

int get_device_count_on_bus(int bus);
int get_device_count_on_bridge(const struct pci_bridge_info *bridge_info);
int scan_pci(void);
struct pci_device * pci_find_root_port(const struct pci_device *pdev);
void clean_pci_cache(void);

#endif
