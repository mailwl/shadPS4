// SPDX-FileCopyrightText: Copyright 2024 shadPS4 Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#include "camera.h"
#include "common/logging/log.h"
#include "core/libraries/error_codes.h"
#include "core/libraries/libs.h"

namespace Libraries::Camera {

int PS4_SYSV_ABI sceCameraIsAttached(int index) {
    LOG_INFO(Lib_Camera, "(STUBBED) called, camera index: {}", index);
    return false;
}

int PS4_SYSV_ABI sceCameraOpen(int user_id, int type, int index, void*)
{
    LOG_ERROR(Lib_Camera, "(STUBBED) called, user id: {}", user_id);
    return 0xFACE; // camera handle
}

int PS4_SYSV_ABI sceCameraGetDeviceInfo(int, OrbisCameraDeviceInfo* info)
{
    LOG_ERROR(Lib_Camera, "(STUBBED) called");
    info->info_revision = 1;
    info->device_revision = 1;
    return ORBIS_OK;
}

int PS4_SYSV_ABI sceCameraSetConfig(int handle, OrbisCameraConfig*)
{
    LOG_ERROR(Lib_Camera, "(STUBBED) called");
    return ORBIS_OK;
}

int PS4_SYSV_ABI sceCameraStart(int handle, OrbisCameraStartParameter*)
{
    LOG_ERROR(Lib_Camera, "(STUBBED) called");
    return ORBIS_OK;
}

int PS4_SYSV_ABI sceCameraGetFrameData(int handle, OrbisCameraFrameData* frame)
{
    LOG_ERROR(Lib_Camera, "(STUBBED) called");
    return ORBIS_OK;
}

int PS4_SYSV_ABI sceCameraIsValidFrameData(int handle, OrbisCameraFrameData* frame)
{
    LOG_ERROR(Lib_Camera, "(STUBBED) called");
    return 1;
}

void RegisterlibSceCamera(Core::Loader::SymbolsResolver* sym) {
    LIB_FUNCTION("p6n3Npi3YY4", "libSceCamera", 1, "libSceCamera", 1, 1, sceCameraIsAttached);
    LIB_FUNCTION("BHn83xrF92E", "libSceCamera", 1, "libSceCamera", 1, 1, sceCameraOpen);
    LIB_FUNCTION("WZpxnSAM-ds", "libSceCamera", 1, "libSceCamera", 1, 1, sceCameraGetDeviceInfo);
    LIB_FUNCTION("VQ+5kAqsE2Q", "libSceCamera", 1, "libSceCamera", 1, 1, sceCameraSetConfig);
    LIB_FUNCTION("9EpRYMy7rHU", "libSceCamera", 1, "libSceCamera", 1, 1, sceCameraStart);
    LIB_FUNCTION("mxgMmR+1Kr0", "libSceCamera", 1, "libSceCamera", 1, 1, sceCameraGetFrameData);
    LIB_FUNCTION("U3BVwQl2R5Q", "libSceCamera", 1, "libSceCamera", 1, 1, sceCameraIsValidFrameData);
};

} // namespace Libraries::Camera