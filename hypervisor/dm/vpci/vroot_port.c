/*
 * Copyright (c) 2019 Intel Corporation
 * All rights reserved.
 */

#include <x86/guest/vm.h>
#include <errno.h>
#include <logmsg.h>
#include <pci.h>
#include "vroot_port.h"

/* initialize virtual root port */
static void init_vroot_port(struct pci_vdev *vdev)
{
	pr_acrnlog("%s: vroot_port [%x:%x.%] is initialized.\n", __func__, vdev->bdf.bits.b, vdev->bdf.bits.d, vdev->bdf.bits.f);
}

/* de-initialize virtual root port */
static void deinit_vroot_port(__unused struct pci_vdev *vdev)
{
	vdev->parent_user = NULL;
	vdev->user = NULL;
}

/* read config space of virtual root port: read from corresponding physical root port */
static int32_t read_vroot_port_cfg(const struct pci_vdev *vdev, uint32_t offset,
	uint32_t bytes, uint32_t *val)
{
	*val = pci_pdev_read_cfg(vdev->pdev->bdf, offset, bytes);

	return 0;
}

/* write config space of virtual root port: write to corresponding physical root port */
static int32_t write_vroot_port_cfg(__unused struct pci_vdev *vdev, __unused uint32_t offset,
	__unused uint32_t bytes, __unused uint32_t val)
{
	pci_pdev_write_cfg(vdev->pdev->bdf, offset, bytes, val);

	return 0;
}

const struct pci_vdev_ops vroot_port_ops = {
	.init_vdev         = init_vroot_port,
	.deinit_vdev       = deinit_vroot_port,
	.write_vdev_cfg    = write_vroot_port_cfg,
	.read_vdev_cfg     = read_vroot_port_cfg,
};
