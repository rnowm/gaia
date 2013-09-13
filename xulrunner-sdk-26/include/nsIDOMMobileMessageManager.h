/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/dom/mobilemessage/interfaces/nsIDOMMobileMessageManager.idl
 */

#ifndef __gen_nsIDOMMobileMessageManager_h__
#define __gen_nsIDOMMobileMessageManager_h__


#ifndef __gen_nsIDOMEventTarget_h__
#include "nsIDOMEventTarget.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMEventListener; /* forward declaration */

class nsIDOMMozSmsFilter; /* forward declaration */

class nsIDOMMozSmsSegmentInfo; /* forward declaration */

class nsIDOMDOMCursor; /* forward declaration */

class nsIDOMDOMRequest; /* forward declaration */

class nsIDOMBlob; /* forward declaration */


/* starting interface:    nsIDOMMozMobileMessageManager */
#define NS_IDOMMOZMOBILEMESSAGEMANAGER_IID_STR "efff5276-0f3f-4137-9b16-66e894400e01"

#define NS_IDOMMOZMOBILEMESSAGEMANAGER_IID \
  {0xefff5276, 0x0f3f, 0x4137, \
    { 0x9b, 0x16, 0x66, 0xe8, 0x94, 0x40, 0x0e, 0x01 }}

class NS_NO_VTABLE nsIDOMMozMobileMessageManager : public nsIDOMEventTarget {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZMOBILEMESSAGEMANAGER_IID)

  /* nsIDOMMozSmsSegmentInfo getSegmentInfoForText (in DOMString text); */
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIDOMMozSmsSegmentInfo * *_retval) = 0;

  /* jsval send (in jsval number, in DOMString message); */
  NS_IMETHOD Send(const JS::Value & number, const nsAString & message, JS::Value *_retval) = 0;

  /* nsIDOMDOMRequest sendMMS (in jsval parameters); */
  NS_IMETHOD SendMMS(const JS::Value & parameters, nsIDOMDOMRequest * *_retval) = 0;

  /* [binaryname(GetMessageMoz)] nsIDOMDOMRequest getMessage (in long id); */
  NS_IMETHOD GetMessageMoz(int32_t id, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMRequest delete (in jsval param); */
  NS_IMETHOD Delete(const JS::Value & param, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMCursor getMessages (in nsIDOMMozSmsFilter filter, in boolean reverse); */
  NS_IMETHOD GetMessages(nsIDOMMozSmsFilter *filter, bool reverse, nsIDOMDOMCursor * *_retval) = 0;

  /* nsIDOMDOMRequest markMessageRead (in long id, in boolean aValue); */
  NS_IMETHOD MarkMessageRead(int32_t id, bool aValue, nsIDOMDOMRequest * *_retval) = 0;

  /* nsIDOMDOMCursor getThreads (); */
  NS_IMETHOD GetThreads(nsIDOMDOMCursor * *_retval) = 0;

  /* nsIDOMDOMRequest retrieveMMS (in long id); */
  NS_IMETHOD RetrieveMMS(int32_t id, nsIDOMDOMRequest * *_retval) = 0;

  /* [implicit_jscontext] attribute jsval onreceived; */
  NS_IMETHOD GetOnreceived(JSContext* cx, JS::Value *aOnreceived) = 0;
  NS_IMETHOD SetOnreceived(JSContext* cx, const JS::Value & aOnreceived) = 0;

  /* [implicit_jscontext] attribute jsval onretrieving; */
  NS_IMETHOD GetOnretrieving(JSContext* cx, JS::Value *aOnretrieving) = 0;
  NS_IMETHOD SetOnretrieving(JSContext* cx, const JS::Value & aOnretrieving) = 0;

  /* [implicit_jscontext] attribute jsval onsending; */
  NS_IMETHOD GetOnsending(JSContext* cx, JS::Value *aOnsending) = 0;
  NS_IMETHOD SetOnsending(JSContext* cx, const JS::Value & aOnsending) = 0;

  /* [implicit_jscontext] attribute jsval onsent; */
  NS_IMETHOD GetOnsent(JSContext* cx, JS::Value *aOnsent) = 0;
  NS_IMETHOD SetOnsent(JSContext* cx, const JS::Value & aOnsent) = 0;

  /* [implicit_jscontext] attribute jsval onfailed; */
  NS_IMETHOD GetOnfailed(JSContext* cx, JS::Value *aOnfailed) = 0;
  NS_IMETHOD SetOnfailed(JSContext* cx, const JS::Value & aOnfailed) = 0;

  /* [implicit_jscontext] attribute jsval ondeliverysuccess; */
  NS_IMETHOD GetOndeliverysuccess(JSContext* cx, JS::Value *aOndeliverysuccess) = 0;
  NS_IMETHOD SetOndeliverysuccess(JSContext* cx, const JS::Value & aOndeliverysuccess) = 0;

  /* [implicit_jscontext] attribute jsval ondeliveryerror; */
  NS_IMETHOD GetOndeliveryerror(JSContext* cx, JS::Value *aOndeliveryerror) = 0;
  NS_IMETHOD SetOndeliveryerror(JSContext* cx, const JS::Value & aOndeliveryerror) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozMobileMessageManager, NS_IDOMMOZMOBILEMESSAGEMANAGER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZMOBILEMESSAGEMANAGER \
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIDOMMozSmsSegmentInfo * *_retval); \
  NS_IMETHOD Send(const JS::Value & number, const nsAString & message, JS::Value *_retval); \
  NS_IMETHOD SendMMS(const JS::Value & parameters, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetMessageMoz(int32_t id, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD Delete(const JS::Value & param, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetMessages(nsIDOMMozSmsFilter *filter, bool reverse, nsIDOMDOMCursor * *_retval); \
  NS_IMETHOD MarkMessageRead(int32_t id, bool aValue, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetThreads(nsIDOMDOMCursor * *_retval); \
  NS_IMETHOD RetrieveMMS(int32_t id, nsIDOMDOMRequest * *_retval); \
  NS_IMETHOD GetOnreceived(JSContext* cx, JS::Value *aOnreceived); \
  NS_IMETHOD SetOnreceived(JSContext* cx, const JS::Value & aOnreceived); \
  NS_IMETHOD GetOnretrieving(JSContext* cx, JS::Value *aOnretrieving); \
  NS_IMETHOD SetOnretrieving(JSContext* cx, const JS::Value & aOnretrieving); \
  NS_IMETHOD GetOnsending(JSContext* cx, JS::Value *aOnsending); \
  NS_IMETHOD SetOnsending(JSContext* cx, const JS::Value & aOnsending); \
  NS_IMETHOD GetOnsent(JSContext* cx, JS::Value *aOnsent); \
  NS_IMETHOD SetOnsent(JSContext* cx, const JS::Value & aOnsent); \
  NS_IMETHOD GetOnfailed(JSContext* cx, JS::Value *aOnfailed); \
  NS_IMETHOD SetOnfailed(JSContext* cx, const JS::Value & aOnfailed); \
  NS_IMETHOD GetOndeliverysuccess(JSContext* cx, JS::Value *aOndeliverysuccess); \
  NS_IMETHOD SetOndeliverysuccess(JSContext* cx, const JS::Value & aOndeliverysuccess); \
  NS_IMETHOD GetOndeliveryerror(JSContext* cx, JS::Value *aOndeliveryerror); \
  NS_IMETHOD SetOndeliveryerror(JSContext* cx, const JS::Value & aOndeliveryerror); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZMOBILEMESSAGEMANAGER(_to) \
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIDOMMozSmsSegmentInfo * *_retval) { return _to GetSegmentInfoForText(text, _retval); } \
  NS_IMETHOD Send(const JS::Value & number, const nsAString & message, JS::Value *_retval) { return _to Send(number, message, _retval); } \
  NS_IMETHOD SendMMS(const JS::Value & parameters, nsIDOMDOMRequest * *_retval) { return _to SendMMS(parameters, _retval); } \
  NS_IMETHOD GetMessageMoz(int32_t id, nsIDOMDOMRequest * *_retval) { return _to GetMessageMoz(id, _retval); } \
  NS_IMETHOD Delete(const JS::Value & param, nsIDOMDOMRequest * *_retval) { return _to Delete(param, _retval); } \
  NS_IMETHOD GetMessages(nsIDOMMozSmsFilter *filter, bool reverse, nsIDOMDOMCursor * *_retval) { return _to GetMessages(filter, reverse, _retval); } \
  NS_IMETHOD MarkMessageRead(int32_t id, bool aValue, nsIDOMDOMRequest * *_retval) { return _to MarkMessageRead(id, aValue, _retval); } \
  NS_IMETHOD GetThreads(nsIDOMDOMCursor * *_retval) { return _to GetThreads(_retval); } \
  NS_IMETHOD RetrieveMMS(int32_t id, nsIDOMDOMRequest * *_retval) { return _to RetrieveMMS(id, _retval); } \
  NS_IMETHOD GetOnreceived(JSContext* cx, JS::Value *aOnreceived) { return _to GetOnreceived(cx, aOnreceived); } \
  NS_IMETHOD SetOnreceived(JSContext* cx, const JS::Value & aOnreceived) { return _to SetOnreceived(cx, aOnreceived); } \
  NS_IMETHOD GetOnretrieving(JSContext* cx, JS::Value *aOnretrieving) { return _to GetOnretrieving(cx, aOnretrieving); } \
  NS_IMETHOD SetOnretrieving(JSContext* cx, const JS::Value & aOnretrieving) { return _to SetOnretrieving(cx, aOnretrieving); } \
  NS_IMETHOD GetOnsending(JSContext* cx, JS::Value *aOnsending) { return _to GetOnsending(cx, aOnsending); } \
  NS_IMETHOD SetOnsending(JSContext* cx, const JS::Value & aOnsending) { return _to SetOnsending(cx, aOnsending); } \
  NS_IMETHOD GetOnsent(JSContext* cx, JS::Value *aOnsent) { return _to GetOnsent(cx, aOnsent); } \
  NS_IMETHOD SetOnsent(JSContext* cx, const JS::Value & aOnsent) { return _to SetOnsent(cx, aOnsent); } \
  NS_IMETHOD GetOnfailed(JSContext* cx, JS::Value *aOnfailed) { return _to GetOnfailed(cx, aOnfailed); } \
  NS_IMETHOD SetOnfailed(JSContext* cx, const JS::Value & aOnfailed) { return _to SetOnfailed(cx, aOnfailed); } \
  NS_IMETHOD GetOndeliverysuccess(JSContext* cx, JS::Value *aOndeliverysuccess) { return _to GetOndeliverysuccess(cx, aOndeliverysuccess); } \
  NS_IMETHOD SetOndeliverysuccess(JSContext* cx, const JS::Value & aOndeliverysuccess) { return _to SetOndeliverysuccess(cx, aOndeliverysuccess); } \
  NS_IMETHOD GetOndeliveryerror(JSContext* cx, JS::Value *aOndeliveryerror) { return _to GetOndeliveryerror(cx, aOndeliveryerror); } \
  NS_IMETHOD SetOndeliveryerror(JSContext* cx, const JS::Value & aOndeliveryerror) { return _to SetOndeliveryerror(cx, aOndeliveryerror); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZMOBILEMESSAGEMANAGER(_to) \
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIDOMMozSmsSegmentInfo * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSegmentInfoForText(text, _retval); } \
  NS_IMETHOD Send(const JS::Value & number, const nsAString & message, JS::Value *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Send(number, message, _retval); } \
  NS_IMETHOD SendMMS(const JS::Value & parameters, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendMMS(parameters, _retval); } \
  NS_IMETHOD GetMessageMoz(int32_t id, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessageMoz(id, _retval); } \
  NS_IMETHOD Delete(const JS::Value & param, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Delete(param, _retval); } \
  NS_IMETHOD GetMessages(nsIDOMMozSmsFilter *filter, bool reverse, nsIDOMDOMCursor * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetMessages(filter, reverse, _retval); } \
  NS_IMETHOD MarkMessageRead(int32_t id, bool aValue, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MarkMessageRead(id, aValue, _retval); } \
  NS_IMETHOD GetThreads(nsIDOMDOMCursor * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetThreads(_retval); } \
  NS_IMETHOD RetrieveMMS(int32_t id, nsIDOMDOMRequest * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->RetrieveMMS(id, _retval); } \
  NS_IMETHOD GetOnreceived(JSContext* cx, JS::Value *aOnreceived) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnreceived(cx, aOnreceived); } \
  NS_IMETHOD SetOnreceived(JSContext* cx, const JS::Value & aOnreceived) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnreceived(cx, aOnreceived); } \
  NS_IMETHOD GetOnretrieving(JSContext* cx, JS::Value *aOnretrieving) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnretrieving(cx, aOnretrieving); } \
  NS_IMETHOD SetOnretrieving(JSContext* cx, const JS::Value & aOnretrieving) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnretrieving(cx, aOnretrieving); } \
  NS_IMETHOD GetOnsending(JSContext* cx, JS::Value *aOnsending) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnsending(cx, aOnsending); } \
  NS_IMETHOD SetOnsending(JSContext* cx, const JS::Value & aOnsending) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnsending(cx, aOnsending); } \
  NS_IMETHOD GetOnsent(JSContext* cx, JS::Value *aOnsent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnsent(cx, aOnsent); } \
  NS_IMETHOD SetOnsent(JSContext* cx, const JS::Value & aOnsent) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnsent(cx, aOnsent); } \
  NS_IMETHOD GetOnfailed(JSContext* cx, JS::Value *aOnfailed) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOnfailed(cx, aOnfailed); } \
  NS_IMETHOD SetOnfailed(JSContext* cx, const JS::Value & aOnfailed) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOnfailed(cx, aOnfailed); } \
  NS_IMETHOD GetOndeliverysuccess(JSContext* cx, JS::Value *aOndeliverysuccess) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndeliverysuccess(cx, aOndeliverysuccess); } \
  NS_IMETHOD SetOndeliverysuccess(JSContext* cx, const JS::Value & aOndeliverysuccess) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndeliverysuccess(cx, aOndeliverysuccess); } \
  NS_IMETHOD GetOndeliveryerror(JSContext* cx, JS::Value *aOndeliveryerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOndeliveryerror(cx, aOndeliveryerror); } \
  NS_IMETHOD SetOndeliveryerror(JSContext* cx, const JS::Value & aOndeliveryerror) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOndeliveryerror(cx, aOndeliveryerror); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozMobileMessageManager : public nsIDOMMozMobileMessageManager
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZMOBILEMESSAGEMANAGER

  nsDOMMozMobileMessageManager();

private:
  ~nsDOMMozMobileMessageManager();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozMobileMessageManager, nsIDOMMozMobileMessageManager)

nsDOMMozMobileMessageManager::nsDOMMozMobileMessageManager()
{
  /* member initializers and constructor code */
}

nsDOMMozMobileMessageManager::~nsDOMMozMobileMessageManager()
{
  /* destructor code */
}

/* nsIDOMMozSmsSegmentInfo getSegmentInfoForText (in DOMString text); */
NS_IMETHODIMP nsDOMMozMobileMessageManager::GetSegmentInfoForText(const nsAString & text, nsIDOMMozSmsSegmentInfo * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* jsval send (in jsval number, in DOMString message); */
NS_IMETHODIMP nsDOMMozMobileMessageManager::Send(const JS::Value & number, const nsAString & message, JS::Value *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest sendMMS (in jsval parameters); */
NS_IMETHODIMP nsDOMMozMobileMessageManager::SendMMS(const JS::Value & parameters, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [binaryname(GetMessageMoz)] nsIDOMDOMRequest getMessage (in long id); */
NS_IMETHODIMP nsDOMMozMobileMessageManager::GetMessageMoz(int32_t id, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest delete (in jsval param); */
NS_IMETHODIMP nsDOMMozMobileMessageManager::Delete(const JS::Value & param, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMCursor getMessages (in nsIDOMMozSmsFilter filter, in boolean reverse); */
NS_IMETHODIMP nsDOMMozMobileMessageManager::GetMessages(nsIDOMMozSmsFilter *filter, bool reverse, nsIDOMDOMCursor * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest markMessageRead (in long id, in boolean aValue); */
NS_IMETHODIMP nsDOMMozMobileMessageManager::MarkMessageRead(int32_t id, bool aValue, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMCursor getThreads (); */
NS_IMETHODIMP nsDOMMozMobileMessageManager::GetThreads(nsIDOMDOMCursor * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMDOMRequest retrieveMMS (in long id); */
NS_IMETHODIMP nsDOMMozMobileMessageManager::RetrieveMMS(int32_t id, nsIDOMDOMRequest * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onreceived; */
NS_IMETHODIMP nsDOMMozMobileMessageManager::GetOnreceived(JSContext* cx, JS::Value *aOnreceived)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozMobileMessageManager::SetOnreceived(JSContext* cx, const JS::Value & aOnreceived)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onretrieving; */
NS_IMETHODIMP nsDOMMozMobileMessageManager::GetOnretrieving(JSContext* cx, JS::Value *aOnretrieving)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozMobileMessageManager::SetOnretrieving(JSContext* cx, const JS::Value & aOnretrieving)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onsending; */
NS_IMETHODIMP nsDOMMozMobileMessageManager::GetOnsending(JSContext* cx, JS::Value *aOnsending)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozMobileMessageManager::SetOnsending(JSContext* cx, const JS::Value & aOnsending)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onsent; */
NS_IMETHODIMP nsDOMMozMobileMessageManager::GetOnsent(JSContext* cx, JS::Value *aOnsent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozMobileMessageManager::SetOnsent(JSContext* cx, const JS::Value & aOnsent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval onfailed; */
NS_IMETHODIMP nsDOMMozMobileMessageManager::GetOnfailed(JSContext* cx, JS::Value *aOnfailed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozMobileMessageManager::SetOnfailed(JSContext* cx, const JS::Value & aOnfailed)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondeliverysuccess; */
NS_IMETHODIMP nsDOMMozMobileMessageManager::GetOndeliverysuccess(JSContext* cx, JS::Value *aOndeliverysuccess)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozMobileMessageManager::SetOndeliverysuccess(JSContext* cx, const JS::Value & aOndeliverysuccess)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] attribute jsval ondeliveryerror; */
NS_IMETHODIMP nsDOMMozMobileMessageManager::GetOndeliveryerror(JSContext* cx, JS::Value *aOndeliveryerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMMozMobileMessageManager::SetOndeliveryerror(JSContext* cx, const JS::Value & aOndeliveryerror)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMobileMessageManager_h__ */
