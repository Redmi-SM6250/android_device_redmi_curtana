#!/bin/bash
#
# Copyright (C) 2020 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

set -e

# Required!
export DEVICE=curtana
export DEVICE_COMMON=sm6250-common
export VENDOR=redmi

export DEVICE_BRINGUP_YEAR=2020

"./../../${VENDOR}/${DEVICE_COMMON}/setup-makefiles.sh" "$@"
