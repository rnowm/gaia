/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/dom/mobilemessage/interfaces/nsIMobileMessageService.idl
 */

#ifndef __gen_nsIMobileMessageService_h__
#define __gen_nsIMobileMessageService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMMozSmsMessage; /* forward declaration */

class nsIDOMMozMmsMessage; /* forward declaration */

class nsIDOMMozMobileMessageThread; /* forward declaration */

class nsIDOMMozSmsSegmentInfo; /* forward declaration */

#define MOBILE_MESSAGE_SERVICE_CID { 0x829c1dd6, 0x0466, 0x4591, { 0x83, 0x6f, 0xb8, 0xf6, 0xfd, 0x1f, 0x7b, 0xa5 } }
#define MOBILE_MESSAGE_SERVICE_CONTRACTID "@mozilla.org/mobilemessage/mobilemessageservice;1"

/* starting interface:    nsIMobileMessageService */
#define NS_IMOBILEMESSAGESERVICE_IID_STR "bea56ecf-472d-4b6b-b462-66753f3c1179"

#define NS_IMOBILEMESSAGESERVICE_IID \
  {0xbea56ecf, 0x472d, 0x4b6b, \
    { 0xb4, 0x62, 0x66, 0x75, 0x3f, 0x3c, 0x11, 0x79 }}

class NS_NO_VTABLE nsIMobileMessageService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMOBILEMESSAGESERVICE_IID)

  /* [implicit_jscontext] nsIDOMMozSmsMessage createSmsMessage (in long id, in unsigned long long threadId, in DOMString delivery, in DOMString deliveryStatus, in DOMString sender, in DOMString receiver, in DOMString body, in DOMString messageClass, in jsval timestamp, in bool read); */
  NS_IMETHOD CreateSmsMessage(int32_t id, uint64_t threadId, const nsAString & delivery, const nsAString & deliveryStatus, const nsAString & sender, const nsAString & receiver, const nsAString & body, const nsAString & messageClass, const JS::Value & timestamp, bool read, JSContext* cx, nsIDOMMozSmsMessage * *_retval) = 0;

  /* [implicit_jscontext] nsIDOMMozMmsMessage createMmsMessage (in long id, in unsigned long long threadId, in DOMString delivery, in jsval deliveryStatus, in DOMString sender, in jsval receivers, in jsval timestamp, in boolean read, in DOMString subject, in DOMString smil, in jsval attachments, in jsval expiryDate); */
  NS_IMETHOD CreateMmsMessage(int32_t id, uint64_t threadId, const nsAString & delivery, const JS::Value & deliveryStatus, const nsAString & sender, const JS::Value & receivers, const JS::Value & timestamp, bool read, const nsAString & subject, const nsAString & smil, const JS::Value & attachments, const JS::Value & expiryDate, JSContext* cx, nsIDOMMozMmsMessage * *_retval) = 0;

  /* nsIDOMMozSmsSegmentInfo createSmsSegmentInfo (in long segments, in long charsPerSegment, in long charsAvailableInLastSegment); */
  NS_IMETHOD CreateSmsSegmentInfo(int32_t segments, int32_t charsPerSegment, int32_t charsAvailableInLastSegment, nsIDOMMozSmsSegmentInfo * *_retval) = 0;

  /* [implicit_jscontext] nsIDOMMozMobileMessageThread createThread (in unsigned long long id, in jsval participants, in jsval timestamp, in DOMString body, in unsigned long long unreadCount, in DOMString aLastMessageType); */
  NS_IMETHOD CreateThread(uint64_t id, const JS::Value & participants, const JS::Value & timestamp, const nsAString & body, uint64_t unreadCount, const nsAString & aLastMessageType, JSContext* cx, nsIDOMMozMobileMessageThread * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMobileMessageService, NS_IMOBILEMESSAGESERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMOBILEMESSAGESERVICE \
  NS_IMETHOD CreateSmsMessage(int32_t id, uint64_t threadId, const nsAString & delivery, const nsAString & deliveryStatus, const nsAString & sender, const nsAString & receiver, const nsAString & body, const nsAString & messageClass, const JS::Value & timestamp, bool read, JSContext* cx, nsIDOMMozSmsMessage * *_retval); \
  NS_IMETHOD CreateMmsMessage(int32_t id, uint64_t threadId, const nsAString & delivery, const JS::Value & deliveryStatus, const nsAString & sender, const JS::Value & receivers, const JS::Value & timestamp, bool read, const nsAString & subject, const nsAString & smil, const JS::Value & attachments, const JS::Value & expiryDate, JSContext* cx, nsIDOMMozMmsMessage * *_retval); \
  NS_IMETHOD CreateSmsSegmentInfo(int32_t segments, int32_t charsPerSegment, int32_t charsAvailableInLastSegment, nsIDOMMozSmsSegmentInfo * *_retval); \
  NS_IMETHOD CreateThread(uint64_t id, const JS::Value & participants, const JS::Value & timestamp, const nsAString & body, uint64_t unreadCount, const nsAString & aLastMessageType, JSContext* cx, nsIDOMMozMobileMessageThread * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMOBILEMESSAGESERVICE(_to) \
  NS_IMETHOD CreateSmsMessage(int32_t id, uint64_t threadId, const nsAString & delivery, const nsAString & deliveryStatus, const nsAString & sender, const nsAString & receiver, const nsAString & body, const nsAString & messageClass, const JS::Value & timestamp, bool read, JSContext* cx, nsIDOMMozSmsMessage * *_retval) { return _to CreateSmsMessage(id, threadId, delivery, deliveryStatus, sender, receiver, body, messageClass, timestamp, read, cx, _retval); } \
  NS_IMETHOD CreateMmsMessage(int32_t id, uint64_t threadId, const nsAString & delivery, const JS::Value & deliveryStatus, const nsAString & sender, const JS::Value & receivers, const JS::Value & timestamp, bool read, const nsAString & subject, const nsAString & smil, const JS::Value & attachments, const JS::Value & expiryDate, JSContext* cx, nsIDOMMozMmsMessage * *_retval) { return _to CreateMmsMessage(id, threadId, delivery, deliveryStatus, sender, receivers, timestamp, read, subject, smil, attachments, expiryDate, cx, _retval); } \
  NS_IMETHOD CreateSmsSegmentInfo(int32_t segments, int32_t charsPerSegment, int32_t charsAvailableInLastSegment, nsIDOMMozSmsSegmentInfo * *_retval) { return _to CreateSmsSegmentInfo(segments, charsPerSegment, charsAvailableInLastSegment, _retval); } \
  NS_IMETHOD CreateThread(uint64_t id, const JS::Value & participants, const JS::Value & timestamp, const nsAString & body, uint64_t unreadCount, const nsAString & aLastMessageType, JSContext* cx, nsIDOMMozMobileMessageThread * *_retval) { return _to CreateThread(id, participants, timestamp, body, unreadCount, aLastMessageType, cx, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMOBILEMESSAGESERVICE(_to) \
  NS_IMETHOD CreateSmsMessage(int32_t id, uint64_t threadId, const nsAString & delivery, const nsAString & deliveryStatus, const nsAString & sender, const nsAString & receiver, const nsAString & body, const nsAString & messageClass, const JS::Value & timestamp, bool read, JSContext* cx, nsIDOMMozSmsMessage * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSmsMessage(id, threadId, delivery, deliveryStatus, sender, receiver, body, messageClass, timestamp, read, cx, _retval); } \
  NS_IMETHOD CreateMmsMessage(int32_t id, uint64_t threadId, const nsAString & delivery, const JS::Value & deliveryStatus, const nsAString & sender, const JS::Value & receivers, const JS::Value & timestamp, bool read, const nsAString & subject, const nsAString & smil, const JS::Value & attachments, const JS::Value & expiryDate, JSContext* cx, nsIDOMMozMmsMessage * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateMmsMessage(id, threadId, delivery, deliveryStatus, sender, receivers, timestamp, read, subject, smil, attachments, expiryDate, cx, _retval); } \
  NS_IMETHOD CreateSmsSegmentInfo(int32_t segments, int32_t charsPerSegment, int32_t charsAvailableInLastSegment, nsIDOMMozSmsSegmentInfo * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateSmsSegmentInfo(segments, charsPerSegment, charsAvailableInLastSegment, _retval); } \
  NS_IMETHOD CreateThread(uint64_t id, const JS::Value & participants, const JS::Value & timestamp, const nsAString & body, uint64_t unreadCount, const nsAString & aLastMessageType, JSContext* cx, nsIDOMMozMobileMessageThread * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateThread(id, participants, timestamp, body, unreadCount, aLastMessageType, cx, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMobileMessageService : public nsIMobileMessageService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMOBILEMESSAGESERVICE

  nsMobileMessageService();

private:
  ~nsMobileMessageService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMobileMessageService, nsIMobileMessageService)

nsMobileMessageService::nsMobileMessageService()
{
  /* member initializers and constructor code */
}

nsMobileMessageService::~nsMobileMessageService()
{
  /* destructor code */
}

/* [implicit_jscontext] nsIDOMMozSmsMessage createSmsMessage (in long id, in unsigned long long threadId, in DOMString delivery, in DOMString deliveryStatus, in DOMString sender, in DOMString receiver, in DOMString body, in DOMString messageClass, in jsval timestamp, in bool read); */
NS_IMETHODIMP nsMobileMessageService::CreateSmsMessage(int32_t id, uint64_t threadId, const nsAString & delivery, const nsAString & deliveryStatus, const nsAString & sender, const nsAString & receiver, const nsAString & body, const nsAString & messageClass, const JS::Value & timestamp, bool read, JSContext* cx, nsIDOMMozSmsMessage * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIDOMMozMmsMessage createMmsMessage (in long id, in unsigned long long threadId, in DOMString delivery, in jsval deliveryStatus, in DOMString sender, in jsval receivers, in jsval timestamp, in boolean read, in DOMString subject, in DOMString smil, in jsval attachments, in jsval expiryDate); */
NS_IMETHODIMP nsMobileMessageService::CreateMmsMessage(int32_t id, uint64_t threadId, const nsAString & delivery, const JS::Value & deliveryStatus, const nsAString & sender, const JS::Value & receivers, const JS::Value & timestamp, bool read, const nsAString & subject, const nsAString & smil, const JS::Value & attachments, const JS::Value & expiryDate, JSContext* cx, nsIDOMMozMmsMessage * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMMozSmsSegmentInfo createSmsSegmentInfo (in long segments, in long charsPerSegment, in long charsAvailableInLastSegment); */
NS_IMETHODIMP nsMobileMessageService::CreateSmsSegmentInfo(int32_t segments, int32_t charsPerSegment, int32_t charsAvailableInLastSegment, nsIDOMMozSmsSegmentInfo * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] nsIDOMMozMobileMessageThread createThread (in unsigned long long id, in jsval participants, in jsval timestamp, in DOMString body, in unsigned long long unreadCount, in DOMString aLastMessageType); */
NS_IMETHODIMP nsMobileMessageService::CreateThread(uint64_t id, const JS::Value & participants, const JS::Value & timestamp, const nsAString & body, uint64_t unreadCount, const nsAString & aLastMessageType, JSContext* cx, nsIDOMMozMobileMessageThread * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMobileMessageService_h__ */
