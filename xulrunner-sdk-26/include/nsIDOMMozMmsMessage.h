/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/dom/mobilemessage/interfaces/nsIDOMMozMmsMessage.idl
 */

#ifndef __gen_nsIDOMMozMmsMessage_h__
#define __gen_nsIDOMMozMmsMessage_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMBlob; /* forward declaration */


/* starting interface:    nsIDOMMozMmsMessage */
#define NS_IDOMMOZMMSMESSAGE_IID_STR "2e5e1c16-b7af-11e2-af04-8f4b1610a600"

#define NS_IDOMMOZMMSMESSAGE_IID \
  {0x2e5e1c16, 0xb7af, 0x11e2, \
    { 0xaf, 0x04, 0x8f, 0x4b, 0x16, 0x10, 0xa6, 0x00 }}

class NS_NO_VTABLE nsIDOMMozMmsMessage : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMMOZMMSMESSAGE_IID)

  /* readonly attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;

  /* readonly attribute long id; */
  NS_IMETHOD GetId(int32_t *aId) = 0;

  /* readonly attribute unsigned long long threadId; */
  NS_IMETHOD GetThreadId(uint64_t *aThreadId) = 0;

  /* readonly attribute DOMString delivery; */
  NS_IMETHOD GetDelivery(nsAString & aDelivery) = 0;

  /* [implicit_jscontext] readonly attribute jsval deliveryStatus; */
  NS_IMETHOD GetDeliveryStatus(JSContext* cx, JS::Value *aDeliveryStatus) = 0;

  /* readonly attribute DOMString sender; */
  NS_IMETHOD GetSender(nsAString & aSender) = 0;

  /* [implicit_jscontext] readonly attribute jsval receivers; */
  NS_IMETHOD GetReceivers(JSContext* cx, JS::Value *aReceivers) = 0;

  /* [implicit_jscontext] readonly attribute jsval timestamp; */
  NS_IMETHOD GetTimestamp(JSContext* cx, JS::Value *aTimestamp) = 0;

  /* readonly attribute boolean read; */
  NS_IMETHOD GetRead(bool *aRead) = 0;

  /* readonly attribute DOMString subject; */
  NS_IMETHOD GetSubject(nsAString & aSubject) = 0;

  /* readonly attribute DOMString smil; */
  NS_IMETHOD GetSmil(nsAString & aSmil) = 0;

  /* [implicit_jscontext] readonly attribute jsval attachments; */
  NS_IMETHOD GetAttachments(JSContext* cx, JS::Value *aAttachments) = 0;

  /* [implicit_jscontext] readonly attribute jsval expiryDate; */
  NS_IMETHOD GetExpiryDate(JSContext* cx, JS::Value *aExpiryDate) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMMozMmsMessage, NS_IDOMMOZMMSMESSAGE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMMOZMMSMESSAGE \
  NS_IMETHOD GetType(nsAString & aType); \
  NS_IMETHOD GetId(int32_t *aId); \
  NS_IMETHOD GetThreadId(uint64_t *aThreadId); \
  NS_IMETHOD GetDelivery(nsAString & aDelivery); \
  NS_IMETHOD GetDeliveryStatus(JSContext* cx, JS::Value *aDeliveryStatus); \
  NS_IMETHOD GetSender(nsAString & aSender); \
  NS_IMETHOD GetReceivers(JSContext* cx, JS::Value *aReceivers); \
  NS_IMETHOD GetTimestamp(JSContext* cx, JS::Value *aTimestamp); \
  NS_IMETHOD GetRead(bool *aRead); \
  NS_IMETHOD GetSubject(nsAString & aSubject); \
  NS_IMETHOD GetSmil(nsAString & aSmil); \
  NS_IMETHOD GetAttachments(JSContext* cx, JS::Value *aAttachments); \
  NS_IMETHOD GetExpiryDate(JSContext* cx, JS::Value *aExpiryDate); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMMOZMMSMESSAGE(_to) \
  NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_IMETHOD GetId(int32_t *aId) { return _to GetId(aId); } \
  NS_IMETHOD GetThreadId(uint64_t *aThreadId) { return _to GetThreadId(aThreadId); } \
  NS_IMETHOD GetDelivery(nsAString & aDelivery) { return _to GetDelivery(aDelivery); } \
  NS_IMETHOD GetDeliveryStatus(JSContext* cx, JS::Value *aDeliveryStatus) { return _to GetDeliveryStatus(cx, aDeliveryStatus); } \
  NS_IMETHOD GetSender(nsAString & aSender) { return _to GetSender(aSender); } \
  NS_IMETHOD GetReceivers(JSContext* cx, JS::Value *aReceivers) { return _to GetReceivers(cx, aReceivers); } \
  NS_IMETHOD GetTimestamp(JSContext* cx, JS::Value *aTimestamp) { return _to GetTimestamp(cx, aTimestamp); } \
  NS_IMETHOD GetRead(bool *aRead) { return _to GetRead(aRead); } \
  NS_IMETHOD GetSubject(nsAString & aSubject) { return _to GetSubject(aSubject); } \
  NS_IMETHOD GetSmil(nsAString & aSmil) { return _to GetSmil(aSmil); } \
  NS_IMETHOD GetAttachments(JSContext* cx, JS::Value *aAttachments) { return _to GetAttachments(cx, aAttachments); } \
  NS_IMETHOD GetExpiryDate(JSContext* cx, JS::Value *aExpiryDate) { return _to GetExpiryDate(cx, aExpiryDate); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMMOZMMSMESSAGE(_to) \
  NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD GetId(int32_t *aId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetId(aId); } \
  NS_IMETHOD GetThreadId(uint64_t *aThreadId) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetThreadId(aThreadId); } \
  NS_IMETHOD GetDelivery(nsAString & aDelivery) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDelivery(aDelivery); } \
  NS_IMETHOD GetDeliveryStatus(JSContext* cx, JS::Value *aDeliveryStatus) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDeliveryStatus(cx, aDeliveryStatus); } \
  NS_IMETHOD GetSender(nsAString & aSender) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSender(aSender); } \
  NS_IMETHOD GetReceivers(JSContext* cx, JS::Value *aReceivers) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetReceivers(cx, aReceivers); } \
  NS_IMETHOD GetTimestamp(JSContext* cx, JS::Value *aTimestamp) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTimestamp(cx, aTimestamp); } \
  NS_IMETHOD GetRead(bool *aRead) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRead(aRead); } \
  NS_IMETHOD GetSubject(nsAString & aSubject) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSubject(aSubject); } \
  NS_IMETHOD GetSmil(nsAString & aSmil) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSmil(aSmil); } \
  NS_IMETHOD GetAttachments(JSContext* cx, JS::Value *aAttachments) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAttachments(cx, aAttachments); } \
  NS_IMETHOD GetExpiryDate(JSContext* cx, JS::Value *aExpiryDate) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetExpiryDate(cx, aExpiryDate); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMMozMmsMessage : public nsIDOMMozMmsMessage
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMMOZMMSMESSAGE

  nsDOMMozMmsMessage();

private:
  ~nsDOMMozMmsMessage();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMMozMmsMessage, nsIDOMMozMmsMessage)

nsDOMMozMmsMessage::nsDOMMozMmsMessage()
{
  /* member initializers and constructor code */
}

nsDOMMozMmsMessage::~nsDOMMozMmsMessage()
{
  /* destructor code */
}

/* readonly attribute DOMString type; */
NS_IMETHODIMP nsDOMMozMmsMessage::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute long id; */
NS_IMETHODIMP nsDOMMozMmsMessage::GetId(int32_t *aId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute unsigned long long threadId; */
NS_IMETHODIMP nsDOMMozMmsMessage::GetThreadId(uint64_t *aThreadId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString delivery; */
NS_IMETHODIMP nsDOMMozMmsMessage::GetDelivery(nsAString & aDelivery)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval deliveryStatus; */
NS_IMETHODIMP nsDOMMozMmsMessage::GetDeliveryStatus(JSContext* cx, JS::Value *aDeliveryStatus)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString sender; */
NS_IMETHODIMP nsDOMMozMmsMessage::GetSender(nsAString & aSender)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval receivers; */
NS_IMETHODIMP nsDOMMozMmsMessage::GetReceivers(JSContext* cx, JS::Value *aReceivers)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval timestamp; */
NS_IMETHODIMP nsDOMMozMmsMessage::GetTimestamp(JSContext* cx, JS::Value *aTimestamp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean read; */
NS_IMETHODIMP nsDOMMozMmsMessage::GetRead(bool *aRead)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString subject; */
NS_IMETHODIMP nsDOMMozMmsMessage::GetSubject(nsAString & aSubject)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute DOMString smil; */
NS_IMETHODIMP nsDOMMozMmsMessage::GetSmil(nsAString & aSmil)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval attachments; */
NS_IMETHODIMP nsDOMMozMmsMessage::GetAttachments(JSContext* cx, JS::Value *aAttachments)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] readonly attribute jsval expiryDate; */
NS_IMETHODIMP nsDOMMozMmsMessage::GetExpiryDate(JSContext* cx, JS::Value *aExpiryDate)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMMozMmsMessage_h__ */
