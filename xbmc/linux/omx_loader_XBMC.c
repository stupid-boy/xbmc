
#include "omx_loader_XBMC.h"
#include <omx_alsasink_component.h>

OMX_ERRORTYPE OMX_GetHandle_XBMC(OMX_OUT OMX_HANDLETYPE* pHandle,
  OMX_IN  OMX_STRING cComponentName,
  OMX_IN  OMX_PTR pAppData,
  OMX_IN  OMX_CALLBACKTYPE* pCallBacks)
{
  OMX_ERRORTYPE err = OMX_ErrorNone;
  OMX_COMPONENTTYPE* openmaxStandComp;
  omx_base_component_PrivateType* priv;

  if(!strcmp("OMX.XBMC.alsa.alsasink", cComponentName))
  {
    openmaxStandComp = calloc(1,sizeof(OMX_COMPONENTTYPE));
    if (!openmaxStandComp) {
      return OMX_ErrorInsufficientResources;
    }

    err = omx_alsasink_component_Constructor(openmaxStandComp,cComponentName);
    if (err != OMX_ErrorNone)
    {
      if (err == OMX_ErrorInsufficientResources)
      {
        *pHandle = openmaxStandComp;
        priv = (omx_base_component_PrivateType *) openmaxStandComp->pComponentPrivate;
        return OMX_ErrorInsufficientResources;
      }
      DEBUG(DEB_LEV_ERR, "Error during component construction\n");
      openmaxStandComp->ComponentDeInit(openmaxStandComp);
      free(openmaxStandComp);
      openmaxStandComp = NULL;
      return OMX_ErrorComponentNotFound;
    }
    priv = (omx_base_component_PrivateType *) openmaxStandComp->pComponentPrivate;

    *pHandle = openmaxStandComp;
    ((OMX_COMPONENTTYPE*)*pHandle)->SetCallbacks(*pHandle, pCallBacks, pAppData);
  }
  else
  {
    err = OMX_ErrorComponentNotFound;
  }
  
  return err;
}


OMX_ERRORTYPE OMX_FreeHandle_XBMC(OMX_IN OMX_HANDLETYPE hComponent) 
{
  int i;
  OMX_ERRORTYPE err = OMX_ErrorNone;
  omx_base_component_PrivateType * priv = (omx_base_component_PrivateType *) ((OMX_COMPONENTTYPE*)hComponent)->pComponentPrivate;

  if(!strcmp("OMX.XBMC.alsa.alsasink", priv->name))
  {
    err = ((OMX_COMPONENTTYPE*)hComponent)->ComponentDeInit(hComponent);

    free((OMX_COMPONENTTYPE*)hComponent);
    hComponent = NULL;
  }
  else
  {
    err = OMX_ErrorComponentNotFound;
  }

  return err;
}