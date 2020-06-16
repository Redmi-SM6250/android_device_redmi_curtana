#
# Copyright (C) 2020 The LineageOS Project
#
# SPDX-License-Identifier: Apache-2.0
#

DEVICE_PATH := device/redmi/curtana

# Inherit from sm6250-common
-include device/redmi/sm6250-common/BoardConfigCommon.mk

# Assert
TARGET_OTA_ASSERT_DEVICE := curtana

# Display
TARGET_HAS_HDR_DISPLAY := true

# Init
TARGET_INIT_VENDOR_LIB := //$(DEVICE_PATH):libinit_curtana
TARGET_RECOVERY_DEVICE_MODULES := libinit_curtana

# Kernel
TARGET_KERNEL_CONFIG := vendor/curtana_defconfig
