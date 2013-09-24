#pragma once


#ifndef __OMX_LOADER_XBMC__
#define __OMX_LOADER_XBMC__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#pragma pack(4)
#include <IL/OMX_Component.h>
#include <IL/OMX_Types.h>
#pragma pack()

OMX_ERRORTYPE OMX_GetHandle_XBMC(OMX_OUT OMX_HANDLETYPE* pHandle,
  OMX_IN  OMX_STRING cComponentName,
  OMX_IN  OMX_PTR pAppData,
  OMX_IN  OMX_CALLBACKTYPE* pCallBacks);

OMX_ERRORTYPE OMX_FreeHandle_XBMC(OMX_IN OMX_HANDLETYPE hComponent);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif