// SPDX-FileCopyrightText: Copyright 2024 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "common/types.h"

namespace Core::Loader {
class SymbolsResolver;
}

namespace Libraries::Camera {

struct OrbisCameraDeviceInfo {
    u32 size;
    u32 info_revision;
    u32 device_revision;
    u32 unknown;
};

struct OrbisCameraConfig {
    u32 size;
    u32 unknown[100];
};

struct OrbisCameraStartParameter {
    u32 size;
    u32 unknown1;
    u32 unknown2;
    void* unknown3;
};

struct OrbisCameraFrameData {
    u32 size;
    u32 unknown1;
    u32 unknown2[32];
    void* ptr_left[4];  // 0x88 video frame pointers for left camera 4 resolution modes
    void* ptr_right[4]; // 0xa8 video frame pointers for right camera 4 resolution modes
    u32 size_left[4];   // 0xc8 video frame size for left camera 4 resolution modes
    u32 size_right[4];  // 0xd8 video frame size for right camera 4 resolution modes
    u32 status_left;
    u32 status_right;
    u32 unknown3[70];
};

int PS4_SYSV_ABI sceCameraIsAttached(int index);
int PS4_SYSV_ABI sceCameraOpen(int user_id, int, int, void*);
int PS4_SYSV_ABI sceCameraGetDeviceInfo(int, OrbisCameraDeviceInfo* info);
int PS4_SYSV_ABI sceCameraSetConfig(int handle, OrbisCameraConfig*);
int PS4_SYSV_ABI sceCameraStart(int handle, OrbisCameraStartParameter*);
int PS4_SYSV_ABI sceCameraGetFrameData(int handle, OrbisCameraFrameData* frame);
int PS4_SYSV_ABI sceCameraIsValidFrameData(int handle, OrbisCameraFrameData* frame);

void RegisterlibSceCamera(Core::Loader::SymbolsResolver* sym);
} // namespace Libraries::Camera