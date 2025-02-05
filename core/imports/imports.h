#pragma once

#include "exports/graphics.h"

#include <memory>
#include <stdint.h>
#include <vulkan/vulkan_core.h>

#if defined(__APICALL_EXTERN)
#define __APICALL __declspec(dllexport)
#elif defined(__APICALL_IMPORT)
#define __APICALL __declspec(dllimport)
#else
#define __APICALL
#endif

using createGraphics_t = std::unique_ptr<IGraphics> (*)(IEventsGraphics& listener, VkDevice device, VkPhysicalDevice physDev, VkInstance instance);

using runtimeExport_t = class IRuntimeExport*;

__APICALL void setCallback_createGraphics(createGraphics_t);

__APICALL void setCallback_accessRuntimeExport(runtimeExport_t);

#undef __APICALL