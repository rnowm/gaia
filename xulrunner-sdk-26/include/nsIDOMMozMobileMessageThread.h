/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/dom/mobilemessage/interfaces/nsIDOMMozMobileMessageThread.idl
 */

#ifndef __gen_nsIDOMMozMobileMessageThread_h__
#define __gen_nsIDOMMozMobileMessageThread_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMMozMobileMessageThread */
#define NS_IDOMMOZMOBILEMESSAGETHREAD_IID_STR "5efe7dc5-4f72-4b8e-9bcd-fb0676b554ca"

#define NS_IDOMMOZMOBILEMESSAGETHREAD_IID \
  {0x5efe7dc5, 0x4f72, 0x4b8e, \
    { 0x9b, 0xcd, 0xfb, 0x06, 0x76, 0xb5, 0x54, 0xca }}

class NS_NO_VTABLE nsIDOMMozMobileMessageThread : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZMOBILEMESSAGETHREAD_IID)

  /* readonly attribute unsigned long long id; */
  NS_IMETHOD GetId(uint64_t *aId) = 0;

  /* readonly attribute DOMString body; */
  NS_IMETHOD GetBody(nsAString & aBody) = 0;

  /* readonly attribute unsigned long long unreadCount; */
  NS_IMETHOD GetUnreadCount(uint64_t *aUnreadCount) = 0;

  /* [implicit_jscontext] readonly attribute jsval participants; */
  NS_IMETHOD GetParticipants(JSContext* cx, JS::Value *aParticipants) = 0;

  /* [implicit_jscontext] readonly attribute jsval timestamp; */
  NS_IMETHOD GetTimestamp(JSContext* cx, JS::Value *aTimestamp) = 0;

  /* readonly attribute DOMString lastMessageType; */
  NS_IMETHOD GetLastMessageType(nsAString & aLastMessageType) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozMobileMessageThread, NS_IDOMMOZMOBILEMESSAGETHREAD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZMOBILEMESSAGETHREAD \
  NS_IMETHOD GetId(uint64_t *aId); \
  NS_IMETHOD GetBody(nsAString & aBody); \
  NS_IMETHOD GetUnreadCount(uint64_t *aUnreadCount); \
  NS_IMETHOD GetParticipants(JSContext* cx, JS::Value *aParticipants); \
  NS_IMETHOD GetTimestamp(JSContext* cx, JS::Value *aTimestamp); \
  NS_IMETHOD GetLastMessageType(nsAString & aLastMessageType); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZMOBILEMESSAGETHREAD(_to) \
  NS_IMETHOD GetId(uint64_t *aId) { return _to GetId(aId); } \
  NS_IMETHOD GetBody(nsAString & aBody) { return _to GetBody(aBody); } \
  NS_IMETHOD GetUnreadCount(uint64_t *aUnreadCount) { return _to GetUnreadCount(aUnreadCount); } \
  NS_IMETHOD GetParticipants(JSContext* cx, JS::Value *aParticipants) { return _to GetParticipants(cx, aParticipants); } \
  NS_IMETHOD GetTimestamp(JSContext* cx, JS::Value *aTimestamp) { return _to GetTimestamp(cx, aTimestamp); } \
  NS_IMETHOD GetLastMessageType(nsAString & aLastMessageType) { return _to GetLastMessageType(aLastMessageType); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZMOBILEMESSAGETHREAD(_to) \
  NS_IMETHOD GetId(uint64_t *aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_IMETHOD GetBody(nsAString & aBody) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBody(aBody); } \
  NS_IMETHOD GetUnreadCount(uint64_t *aUnreadCount) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUnreadCount(aUnreadCount); } \
  NS_IMETHOD GetParticipants(JSContext* cx, JS::Value *aParticipants) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetParticipants(cx, aParticipants); } \
  NS_IMETHOD GetTimestamp(JSContext* cx, JS::Value *aTimestamp) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimestamp(cx, aTimestamp); } \
  NS_IMETHOD GetLastMessageType(nsAString & aLastMessageType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLastMessageType(aLastMessageType); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozMobileMessageThread : public nsIDOMMozMobileMessageThread
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZMOBILEMESSAGETHREAD

  nsDOMMozMobileMessageThread();

private:
  ~nsDOMMozMobileMessageThread();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozMobileMessageThread, nsIDOMMozMobileMessageThread)

nsDOMMozMobileMessageThread::nsDOMMozMobileMessageThread()
{
  /* member initializers and constructor code */
}

nsDOMMozMobileMessageThread::~nsDOMMozMobileMessageThread()
{
  /* destructor code */
}

/* readonly attribute unsigned long long id; */
NS_IMETHODIMP nsDOMMozMobileMessageThread::GetId(uint64_t *aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString body; */
NS_IMETHODIMP nsDOMMozMobileMessageThread::GetBody(nsAString & aBody)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long unreadCount; */
NS_IMETHODIMP nsDOMMozMobileMessageThread::GetUnreadCount(uint64_t *aUnreadCount)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval participants; */
NS_IMETHODIMP nsDOMMozMobileMessageThread::GetParticipants(JSContext* cx, JS::Value *aParticipants)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval timestamp; */
NS_IMETHODIMP nsDOMMozMobileMessageThread::GetTimestamp(JSContext* cx, JS::Value *aTimestamp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString lastMessageType; */
NS_IMETHODIMP nsDOMMozMobileMessageThread::GetLastMessageType(nsAString & aLastMessageType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMozMobileMessageThread_h__ */
