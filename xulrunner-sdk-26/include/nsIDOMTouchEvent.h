/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/dom/interfaces/events/nsIDOMTouchEvent.idl
 */

#ifndef __gen_nsIDOMTouchEvent_h__
#define __gen_nsIDOMTouchEvent_h__


#ifndef __gen_nsIDOMUIEvent_h__
#include "nsIDOMUIEvent.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#include "nsWeakPtr.h"
#include "nsPoint.h"
class nsIVariant; /* forward declaration */


/* starting interface:    nsIDOMTouch */
#define NS_IDOMTOUCH_IID_STR "2311671f-ff7e-43d2-adfb-d9e07006955e"

#define NS_IDOMTOUCH_IID \
  {0x2311671f, 0xff7e, 0x43d2, \
    { 0xad, 0xfb, 0xd9, 0xe0, 0x70, 0x06, 0x95, 0x5e }}

class NS_NO_VTABLE nsIDOMTouch : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMTOUCH_IID)

  /* readonly attribute long identifier; */
  NS_IMETHOD GetIdentifier(int32_t *aIdentifier) = 0;

  /* readonly attribute nsIDOMEventTarget target; */
  NS_IMETHOD GetTarget(nsIDOMEventTarget * *aTarget) = 0;

  /* readonly attribute long pageX; */
  NS_IMETHOD GetPageX(int32_t *aPageX) = 0;

  /* readonly attribute long pageY; */
  NS_IMETHOD GetPageY(int32_t *aPageY) = 0;

  /* readonly attribute long screenX; */
  NS_IMETHOD GetScreenX(int32_t *aScreenX) = 0;

  /* readonly attribute long screenY; */
  NS_IMETHOD GetScreenY(int32_t *aScreenY) = 0;

  /* readonly attribute long clientX; */
  NS_IMETHOD GetClientX(int32_t *aClientX) = 0;

  /* readonly attribute long clientY; */
  NS_IMETHOD GetClientY(int32_t *aClientY) = 0;

  /* readonly attribute long radiusX; */
  NS_IMETHOD GetRadiusX(int32_t *aRadiusX) = 0;

  /* readonly attribute long radiusY; */
  NS_IMETHOD GetRadiusY(int32_t *aRadiusY) = 0;

  /* readonly attribute float rotationAngle; */
  NS_IMETHOD GetRotationAngle(float *aRotationAngle) = 0;

  /* readonly attribute float force; */
  NS_IMETHOD GetForce(float *aForce) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMTouch, NS_IDOMTOUCH_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMTOUCH \
  NS_IMETHOD GetIdentifier(int32_t *aIdentifier); \
  NS_IMETHOD GetTarget(nsIDOMEventTarget * *aTarget); \
  NS_IMETHOD GetPageX(int32_t *aPageX); \
  NS_IMETHOD GetPageY(int32_t *aPageY); \
  NS_IMETHOD GetScreenX(int32_t *aScreenX); \
  NS_IMETHOD GetScreenY(int32_t *aScreenY); \
  NS_IMETHOD GetClientX(int32_t *aClientX); \
  NS_IMETHOD GetClientY(int32_t *aClientY); \
  NS_IMETHOD GetRadiusX(int32_t *aRadiusX); \
  NS_IMETHOD GetRadiusY(int32_t *aRadiusY); \
  NS_IMETHOD GetRotationAngle(float *aRotationAngle); \
  NS_IMETHOD GetForce(float *aForce); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMTOUCH(_to) \
  NS_IMETHOD GetIdentifier(int32_t *aIdentifier) { return _to GetIdentifier(aIdentifier); } \
  NS_IMETHOD GetTarget(nsIDOMEventTarget * *aTarget) { return _to GetTarget(aTarget); } \
  NS_IMETHOD GetPageX(int32_t *aPageX) { return _to GetPageX(aPageX); } \
  NS_IMETHOD GetPageY(int32_t *aPageY) { return _to GetPageY(aPageY); } \
  NS_IMETHOD GetScreenX(int32_t *aScreenX) { return _to GetScreenX(aScreenX); } \
  NS_IMETHOD GetScreenY(int32_t *aScreenY) { return _to GetScreenY(aScreenY); } \
  NS_IMETHOD GetClientX(int32_t *aClientX) { return _to GetClientX(aClientX); } \
  NS_IMETHOD GetClientY(int32_t *aClientY) { return _to GetClientY(aClientY); } \
  NS_IMETHOD GetRadiusX(int32_t *aRadiusX) { return _to GetRadiusX(aRadiusX); } \
  NS_IMETHOD GetRadiusY(int32_t *aRadiusY) { return _to GetRadiusY(aRadiusY); } \
  NS_IMETHOD GetRotationAngle(float *aRotationAngle) { return _to GetRotationAngle(aRotationAngle); } \
  NS_IMETHOD GetForce(float *aForce) { return _to GetForce(aForce); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMTOUCH(_to) \
  NS_IMETHOD GetIdentifier(int32_t *aIdentifier) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIdentifier(aIdentifier); } \
  NS_IMETHOD GetTarget(nsIDOMEventTarget * *aTarget) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTarget(aTarget); } \
  NS_IMETHOD GetPageX(int32_t *aPageX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageX(aPageX); } \
  NS_IMETHOD GetPageY(int32_t *aPageY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPageY(aPageY); } \
  NS_IMETHOD GetScreenX(int32_t *aScreenX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreenX(aScreenX); } \
  NS_IMETHOD GetScreenY(int32_t *aScreenY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetScreenY(aScreenY); } \
  NS_IMETHOD GetClientX(int32_t *aClientX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClientX(aClientX); } \
  NS_IMETHOD GetClientY(int32_t *aClientY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetClientY(aClientY); } \
  NS_IMETHOD GetRadiusX(int32_t *aRadiusX) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRadiusX(aRadiusX); } \
  NS_IMETHOD GetRadiusY(int32_t *aRadiusY) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRadiusY(aRadiusY); } \
  NS_IMETHOD GetRotationAngle(float *aRotationAngle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRotationAngle(aRotationAngle); } \
  NS_IMETHOD GetForce(float *aForce) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetForce(aForce); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMTouch : public nsIDOMTouch
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMTOUCH

  nsDOMTouch();

private:
  ~nsDOMTouch();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMTouch, nsIDOMTouch)

nsDOMTouch::nsDOMTouch()
{
  /* member initializers and constructor code */
}

nsDOMTouch::~nsDOMTouch()
{
  /* destructor code */
}

/* readonly attribute long identifier; */
NS_IMETHODIMP nsDOMTouch::GetIdentifier(int32_t *aIdentifier)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute nsIDOMEventTarget target; */
NS_IMETHODIMP nsDOMTouch::GetTarget(nsIDOMEventTarget * *aTarget)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long pageX; */
NS_IMETHODIMP nsDOMTouch::GetPageX(int32_t *aPageX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long pageY; */
NS_IMETHODIMP nsDOMTouch::GetPageY(int32_t *aPageY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long screenX; */
NS_IMETHODIMP nsDOMTouch::GetScreenX(int32_t *aScreenX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long screenY; */
NS_IMETHODIMP nsDOMTouch::GetScreenY(int32_t *aScreenY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long clientX; */
NS_IMETHODIMP nsDOMTouch::GetClientX(int32_t *aClientX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long clientY; */
NS_IMETHODIMP nsDOMTouch::GetClientY(int32_t *aClientY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long radiusX; */
NS_IMETHODIMP nsDOMTouch::GetRadiusX(int32_t *aRadiusX)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long radiusY; */
NS_IMETHODIMP nsDOMTouch::GetRadiusY(int32_t *aRadiusY)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float rotationAngle; */
NS_IMETHODIMP nsDOMTouch::GetRotationAngle(float *aRotationAngle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute float force; */
NS_IMETHODIMP nsDOMTouch::GetForce(float *aForce)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsITouchEventReceiver */
#define NS_ITOUCHEVENTRECEIVER_IID_STR "6d5484f7-92ac-45f8-9388-39b5bad055ce"

#define NS_ITOUCHEVENTRECEIVER_IID \
  {0x6d5484f7, 0x92ac, 0x45f8, \
    { 0x93, 0x88, 0x39, 0xb5, 0xba, 0xd0, 0x55, 0xce }}

class NS_NO_VTABLE nsITouchEventReceiver : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITOUCHEVENTRECEIVER_IID)

  /* [implicit_jscontext] attribute jsval ontouchstart; */
  NS_IMETHOD GetOntouchstart(JSContext* cx, JS::Value *aOntouchstart) = 0;
  NS_IMETHOD SetOntouchstart(JSContext* cx, const JS::Value & aOntouchstart) = 0;

  /* [implicit_jscontext] attribute jsval ontouchend; */
  NS_IMETHOD GetOntouchend(JSContext* cx, JS::Value *aOntouchend) = 0;
  NS_IMETHOD SetOntouchend(JSContext* cx, const JS::Value & aOntouchend) = 0;

  /* [implicit_jscontext] attribute jsval ontouchmove; */
  NS_IMETHOD GetOntouchmove(JSContext* cx, JS::Value *aOntouchmove) = 0;
  NS_IMETHOD SetOntouchmove(JSContext* cx, const JS::Value & aOntouchmove) = 0;

  /* [implicit_jscontext] attribute jsval ontouchenter; */
  NS_IMETHOD GetOntouchenter(JSContext* cx, JS::Value *aOntouchenter) = 0;
  NS_IMETHOD SetOntouchenter(JSContext* cx, const JS::Value & aOntouchenter) = 0;

  /* [implicit_jscontext] attribute jsval ontouchleave; */
  NS_IMETHOD GetOntouchleave(JSContext* cx, JS::Value *aOntouchleave) = 0;
  NS_IMETHOD SetOntouchleave(JSContext* cx, const JS::Value & aOntouchleave) = 0;

  /* [implicit_jscontext] attribute jsval ontouchcancel; */
  NS_IMETHOD GetOntouchcancel(JSContext* cx, JS::Value *aOntouchcancel) = 0;
  NS_IMETHOD SetOntouchcancel(JSContext* cx, const JS::Value & aOntouchcancel) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITouchEventReceiver, NS_ITOUCHEVENTRECEIVER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITOUCHEVENTRECEIVER \
  NS_IMETHOD GetOntouchstart(JSContext* cx, JS::Value *aOntouchstart); \
  NS_IMETHOD SetOntouchstart(JSContext* cx, const JS::Value & aOntouchstart); \
  NS_IMETHOD GetOntouchend(JSContext* cx, JS::Value *aOntouchend); \
  NS_IMETHOD SetOntouchend(JSContext* cx, const JS::Value & aOntouchend); \
  NS_IMETHOD GetOntouchmove(JSContext* cx, JS::Value *aOntouchmove); \
  NS_IMETHOD SetOntouchmove(JSContext* cx, const JS::Value & aOntouchmove); \
  NS_IMETHOD GetOntouchenter(JSContext* cx, JS::Value *aOntouchenter); \
  NS_IMETHOD SetOntouchenter(JSContext* cx, const JS::Value & aOntouchenter); \
  NS_IMETHOD GetOntouchleave(JSContext* cx, JS::Value *aOntouchleave); \
  NS_IMETHOD SetOntouchleave(JSContext* cx, const JS::Value & aOntouchleave); \
  NS_IMETHOD GetOntouchcancel(JSContext* cx, JS::Value *aOntouchcancel); \
  NS_IMETHOD SetOntouchcancel(JSContext* cx, const JS::Value & aOntouchcancel); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITOUCHEVENTRECEIVER(_to) \
  NS_IMETHOD GetOntouchstart(JSContext* cx, JS::Value *aOntouchstart) { return _to GetOntouchstart(cx, aOntouchstart); } \
  NS_IMETHOD SetOntouchstart(JSContext* cx, const JS::Value & aOntouchstart) { return _to SetOntouchstart(cx, aOntouchstart); } \
  NS_IMETHOD GetOntouchend(JSContext* cx, JS::Value *aOntouchend) { return _to GetOntouchend(cx, aOntouchend); } \
  NS_IMETHOD SetOntouchend(JSContext* cx, const JS::Value & aOntouchend) { return _to SetOntouchend(cx, aOntouchend); } \
  NS_IMETHOD GetOntouchmove(JSContext* cx, JS::Value *aOntouchmove) { return _to GetOntouchmove(cx, aOntouchmove); } \
  NS_IMETHOD SetOntouchmove(JSContext* cx, const JS::Value & aOntouchmove) { return _to SetOntouchmove(cx, aOntouchmove); } \
  NS_IMETHOD GetOntouchenter(JSContext* cx, JS::Value *aOntouchenter) { return _to GetOntouchenter(cx, aOntouchenter); } \
  NS_IMETHOD SetOntouchenter(JSContext* cx, const JS::Value & aOntouchenter) { return _to SetOntouchenter(cx, aOntouchenter); } \
  NS_IMETHOD GetOntouchleave(JSContext* cx, JS::Value *aOntouchleave) { return _to GetOntouchleave(cx, aOntouchleave); } \
  NS_IMETHOD SetOntouchleave(JSContext* cx, const JS::Value & aOntouchleave) { return _to SetOntouchleave(cx, aOntouchleave); } \
  NS_IMETHOD GetOntouchcancel(JSContext* cx, JS::Value *aOntouchcancel) { return _to GetOntouchcancel(cx, aOntouchcancel); } \
  NS_IMETHOD SetOntouchcancel(JSContext* cx, const JS::Value & aOntouchcancel) { return _to SetOntouchcancel(cx, aOntouchcancel); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITOUCHEVENTRECEIVER(_to) \
  NS_IMETHOD GetOntouchstart(JSContext* cx, JS::Value *aOntouchstart) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOntouchstart(cx, aOntouchstart); } \
  NS_IMETHOD SetOntouchstart(JSContext* cx, const JS::Value & aOntouchstart) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOntouchstart(cx, aOntouchstart); } \
  NS_IMETHOD GetOntouchend(JSContext* cx, JS::Value *aOntouchend) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOntouchend(cx, aOntouchend); } \
  NS_IMETHOD SetOntouchend(JSContext* cx, const JS::Value & aOntouchend) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOntouchend(cx, aOntouchend); } \
  NS_IMETHOD GetOntouchmove(JSContext* cx, JS::Value *aOntouchmove) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOntouchmove(cx, aOntouchmove); } \
  NS_IMETHOD SetOntouchmove(JSContext* cx, const JS::Value & aOntouchmove) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOntouchmove(cx, aOntouchmove); } \
  NS_IMETHOD GetOntouchenter(JSContext* cx, JS::Value *aOntouchenter) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOntouchenter(cx, aOntouchenter); } \
  NS_IMETHOD SetOntouchenter(JSContext* cx, const JS::Value & aOntouchenter) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOntouchenter(cx, aOntouchenter); } \
  NS_IMETHOD GetOntouchleave(JSContext* cx, JS::Value *aOntouchleave) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOntouchleave(cx, aOntouchleave); } \
  NS_IMETHOD SetOntouchleave(JSContext* cx, const JS::Value & aOntouchleave) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOntouchleave(cx, aOntouchleave); } \
  NS_IMETHOD GetOntouchcancel(JSContext* cx, JS::Value *aOntouchcancel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOntouchcancel(cx, aOntouchcancel); } \
  NS_IMETHOD SetOntouchcancel(JSContext* cx, const JS::Value & aOntouchcancel) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOntouchcancel(cx, aOntouchcancel); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTouchEventReceiver : public nsITouchEventReceiver
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITOUCHEVENTRECEIVER

  nsTouchEventReceiver();

private:
  ~nsTouchEventReceiver();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTouchEventReceiver, nsITouchEventReceiver)

nsTouchEventReceiver::nsTouchEventReceiver()
{
  /* member initializers and constructor code */
}

nsTouchEventReceiver::~nsTouchEventReceiver()
{
  /* destructor code */
}

/* [implicit_jscontext] attribute jsval ontouchstart; */
NS_IMETHODIMP nsTouchEventReceiver::GetOntouchstart(JSContext* cx, JS::Value *aOntouchstart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTouchEventReceiver::SetOntouchstart(JSContext* cx, const JS::Value & aOntouchstart)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ontouchend; */
NS_IMETHODIMP nsTouchEventReceiver::GetOntouchend(JSContext* cx, JS::Value *aOntouchend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTouchEventReceiver::SetOntouchend(JSContext* cx, const JS::Value & aOntouchend)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ontouchmove; */
NS_IMETHODIMP nsTouchEventReceiver::GetOntouchmove(JSContext* cx, JS::Value *aOntouchmove)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTouchEventReceiver::SetOntouchmove(JSContext* cx, const JS::Value & aOntouchmove)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ontouchenter; */
NS_IMETHODIMP nsTouchEventReceiver::GetOntouchenter(JSContext* cx, JS::Value *aOntouchenter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTouchEventReceiver::SetOntouchenter(JSContext* cx, const JS::Value & aOntouchenter)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ontouchleave; */
NS_IMETHODIMP nsTouchEventReceiver::GetOntouchleave(JSContext* cx, JS::Value *aOntouchleave)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTouchEventReceiver::SetOntouchleave(JSContext* cx, const JS::Value & aOntouchleave)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ontouchcancel; */
NS_IMETHODIMP nsTouchEventReceiver::GetOntouchcancel(JSContext* cx, JS::Value *aOntouchcancel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsTouchEventReceiver::SetOntouchcancel(JSContext* cx, const JS::Value & aOntouchcancel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMTouchEvent_h__ */
