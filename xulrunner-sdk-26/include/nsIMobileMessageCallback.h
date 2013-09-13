/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/dom/mobilemessage/interfaces/nsIMobileMessageCallback.idl
 */

#ifndef __gen_nsIMobileMessageCallback_h__
#define __gen_nsIMobileMessageCallback_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIMobileMessageCallback */
#define NS_IMOBILEMESSAGECALLBACK_IID_STR "ea5fb581-bee7-40a6-b2dc-c98b99a2dc49"

#define NS_IMOBILEMESSAGECALLBACK_IID \
  {0xea5fb581, 0xbee7, 0x40a6, \
    { 0xb2, 0xdc, 0xc9, 0x8b, 0x99, 0xa2, 0xdc, 0x49 }}

class NS_NO_VTABLE nsIMobileMessageCallback : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMOBILEMESSAGECALLBACK_IID)

  enum {
    SUCCESS_NO_ERROR = 0U,
    NO_SIGNAL_ERROR = 1U,
    NOT_FOUND_ERROR = 2U,
    UNKNOWN_ERROR = 3U,
    INTERNAL_ERROR = 4U,
    NO_SIM_CARD_ERROR = 5U,
    RADIO_DISABLED_ERROR = 6U,
    INVALID_ADDRESS_ERROR = 7U
  };

  /* void notifyMessageSent (in nsISupports message); */
  NS_IMETHOD NotifyMessageSent(nsISupports *message) = 0;

  /* void notifySendMessageFailed (in long error); */
  NS_IMETHOD NotifySendMessageFailed(int32_t error) = 0;

  /* void notifyMessageGot (in nsISupports message); */
  NS_IMETHOD NotifyMessageGot(nsISupports *message) = 0;

  /* void notifyGetMessageFailed (in long error); */
  NS_IMETHOD NotifyGetMessageFailed(int32_t error) = 0;

  /* void notifyMessageDeleted ([array, size_is (count)] in boolean deleted, in uint32_t count); */
  NS_IMETHOD NotifyMessageDeleted(bool *deleted, uint32_t count) = 0;

  /* void notifyDeleteMessageFailed (in long error); */
  NS_IMETHOD NotifyDeleteMessageFailed(int32_t error) = 0;

  /* void notifyMessageMarkedRead (in boolean read); */
  NS_IMETHOD NotifyMessageMarkedRead(bool read) = 0;

  /* void notifyMarkMessageReadFailed (in long error); */
  NS_IMETHOD NotifyMarkMessageReadFailed(int32_t error) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMobileMessageCallback, NS_IMOBILEMESSAGECALLBACK_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMOBILEMESSAGECALLBACK \
  NS_IMETHOD NotifyMessageSent(nsISupports *message); \
  NS_IMETHOD NotifySendMessageFailed(int32_t error); \
  NS_IMETHOD NotifyMessageGot(nsISupports *message); \
  NS_IMETHOD NotifyGetMessageFailed(int32_t error); \
  NS_IMETHOD NotifyMessageDeleted(bool *deleted, uint32_t count); \
  NS_IMETHOD NotifyDeleteMessageFailed(int32_t error); \
  NS_IMETHOD NotifyMessageMarkedRead(bool read); \
  NS_IMETHOD NotifyMarkMessageReadFailed(int32_t error); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMOBILEMESSAGECALLBACK(_to) \
  NS_IMETHOD NotifyMessageSent(nsISupports *message) { return _to NotifyMessageSent(message); } \
  NS_IMETHOD NotifySendMessageFailed(int32_t error) { return _to NotifySendMessageFailed(error); } \
  NS_IMETHOD NotifyMessageGot(nsISupports *message) { return _to NotifyMessageGot(message); } \
  NS_IMETHOD NotifyGetMessageFailed(int32_t error) { return _to NotifyGetMessageFailed(error); } \
  NS_IMETHOD NotifyMessageDeleted(bool *deleted, uint32_t count) { return _to NotifyMessageDeleted(deleted, count); } \
  NS_IMETHOD NotifyDeleteMessageFailed(int32_t error) { return _to NotifyDeleteMessageFailed(error); } \
  NS_IMETHOD NotifyMessageMarkedRead(bool read) { return _to NotifyMessageMarkedRead(read); } \
  NS_IMETHOD NotifyMarkMessageReadFailed(int32_t error) { return _to NotifyMarkMessageReadFailed(error); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMOBILEMESSAGECALLBACK(_to) \
  NS_IMETHOD NotifyMessageSent(nsISupports *message) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyMessageSent(message); } \
  NS_IMETHOD NotifySendMessageFailed(int32_t error) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifySendMessageFailed(error); } \
  NS_IMETHOD NotifyMessageGot(nsISupports *message) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyMessageGot(message); } \
  NS_IMETHOD NotifyGetMessageFailed(int32_t error) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyGetMessageFailed(error); } \
  NS_IMETHOD NotifyMessageDeleted(bool *deleted, uint32_t count) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyMessageDeleted(deleted, count); } \
  NS_IMETHOD NotifyDeleteMessageFailed(int32_t error) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyDeleteMessageFailed(error); } \
  NS_IMETHOD NotifyMessageMarkedRead(bool read) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyMessageMarkedRead(read); } \
  NS_IMETHOD NotifyMarkMessageReadFailed(int32_t error) { return !_to ? NS_ERROR_NULL_POINTER : _to->NotifyMarkMessageReadFailed(error); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMobileMessageCallback : public nsIMobileMessageCallback
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMOBILEMESSAGECALLBACK

  nsMobileMessageCallback();

private:
  ~nsMobileMessageCallback();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMobileMessageCallback, nsIMobileMessageCallback)

nsMobileMessageCallback::nsMobileMessageCallback()
{
  /* member initializers and constructor code */
}

nsMobileMessageCallback::~nsMobileMessageCallback()
{
  /* destructor code */
}

/* void notifyMessageSent (in nsISupports message); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyMessageSent(nsISupports *message)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifySendMessageFailed (in long error); */
NS_IMETHODIMP nsMobileMessageCallback::NotifySendMessageFailed(int32_t error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyMessageGot (in nsISupports message); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyMessageGot(nsISupports *message)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyGetMessageFailed (in long error); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyGetMessageFailed(int32_t error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyMessageDeleted ([array, size_is (count)] in boolean deleted, in uint32_t count); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyMessageDeleted(bool *deleted, uint32_t count)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyDeleteMessageFailed (in long error); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyDeleteMessageFailed(int32_t error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyMessageMarkedRead (in boolean read); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyMessageMarkedRead(bool read)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void notifyMarkMessageReadFailed (in long error); */
NS_IMETHODIMP nsMobileMessageCallback::NotifyMarkMessageReadFailed(int32_t error)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMobileMessageCallback_h__ */
