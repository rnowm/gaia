/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/dom/mobilemessage/interfaces/nsISmsService.idl
 */

#ifndef __gen_nsISmsService_h__
#define __gen_nsISmsService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMMozSmsMessage; /* forward declaration */

class nsIDOMMozSmsSegmentInfo; /* forward declaration */

class nsIMobileMessageCallback; /* forward declaration */

#define SMS_SERVICE_CID { 0xbada3cb8, 0xa568, 0x4dff, { 0xb5, 0x43, 0x52, 0xbb, 0xb3, 0x14, 0x31, 0x21 } }
#define SMS_SERVICE_CONTRACTID "@mozilla.org/sms/smsservice;1"

/* starting interface:    nsISmsService */
#define NS_ISMSSERVICE_IID_STR "f0d5d11b-0326-4cb1-bb76-a3f912212287"

#define NS_ISMSSERVICE_IID \
  {0xf0d5d11b, 0x0326, 0x4cb1, \
    { 0xbb, 0x76, 0xa3, 0xf9, 0x12, 0x21, 0x22, 0x87 }}

class NS_NO_VTABLE nsISmsService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISMSSERVICE_IID)

  /* boolean hasSupport (); */
  NS_IMETHOD HasSupport(bool *_retval) = 0;

  /* nsIDOMMozSmsSegmentInfo getSegmentInfoForText (in DOMString text); */
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIDOMMozSmsSegmentInfo * *_retval) = 0;

  /* void send (in DOMString number, in DOMString message, in boolean silent, in nsIMobileMessageCallback request); */
  NS_IMETHOD Send(const nsAString & number, const nsAString & message, bool silent, nsIMobileMessageCallback *request) = 0;

  /* boolean isSilentNumber (in DOMString number); */
  NS_IMETHOD IsSilentNumber(const nsAString & number, bool *_retval) = 0;

  /* void addSilentNumber (in DOMString number); */
  NS_IMETHOD AddSilentNumber(const nsAString & number) = 0;

  /* void removeSilentNumber (in DOMString number); */
  NS_IMETHOD RemoveSilentNumber(const nsAString & number) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsISmsService, NS_ISMSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISMSSERVICE \
  NS_IMETHOD HasSupport(bool *_retval); \
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIDOMMozSmsSegmentInfo * *_retval); \
  NS_IMETHOD Send(const nsAString & number, const nsAString & message, bool silent, nsIMobileMessageCallback *request); \
  NS_IMETHOD IsSilentNumber(const nsAString & number, bool *_retval); \
  NS_IMETHOD AddSilentNumber(const nsAString & number); \
  NS_IMETHOD RemoveSilentNumber(const nsAString & number); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISMSSERVICE(_to) \
  NS_IMETHOD HasSupport(bool *_retval) { return _to HasSupport(_retval); } \
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIDOMMozSmsSegmentInfo * *_retval) { return _to GetSegmentInfoForText(text, _retval); } \
  NS_IMETHOD Send(const nsAString & number, const nsAString & message, bool silent, nsIMobileMessageCallback *request) { return _to Send(number, message, silent, request); } \
  NS_IMETHOD IsSilentNumber(const nsAString & number, bool *_retval) { return _to IsSilentNumber(number, _retval); } \
  NS_IMETHOD AddSilentNumber(const nsAString & number) { return _to AddSilentNumber(number); } \
  NS_IMETHOD RemoveSilentNumber(const nsAString & number) { return _to RemoveSilentNumber(number); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISMSSERVICE(_to) \
  NS_IMETHOD HasSupport(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->HasSupport(_retval); } \
  NS_IMETHOD GetSegmentInfoForText(const nsAString & text, nsIDOMMozSmsSegmentInfo * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSegmentInfoForText(text, _retval); } \
  NS_IMETHOD Send(const nsAString & number, const nsAString & message, bool silent, nsIMobileMessageCallback *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->Send(number, message, silent, request); } \
  NS_IMETHOD IsSilentNumber(const nsAString & number, bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->IsSilentNumber(number, _retval); } \
  NS_IMETHOD AddSilentNumber(const nsAString & number) { return !_to ? NS_ERROR_NULL_POINTER : _to->AddSilentNumber(number); } \
  NS_IMETHOD RemoveSilentNumber(const nsAString & number) { return !_to ? NS_ERROR_NULL_POINTER : _to->RemoveSilentNumber(number); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsSmsService : public nsISmsService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISMSSERVICE

  nsSmsService();

private:
  ~nsSmsService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsSmsService, nsISmsService)

nsSmsService::nsSmsService()
{
  /* member initializers and constructor code */
}

nsSmsService::~nsSmsService()
{
  /* destructor code */
}

/* boolean hasSupport (); */
NS_IMETHODIMP nsSmsService::HasSupport(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMMozSmsSegmentInfo getSegmentInfoForText (in DOMString text); */
NS_IMETHODIMP nsSmsService::GetSegmentInfoForText(const nsAString & text, nsIDOMMozSmsSegmentInfo * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void send (in DOMString number, in DOMString message, in boolean silent, in nsIMobileMessageCallback request); */
NS_IMETHODIMP nsSmsService::Send(const nsAString & number, const nsAString & message, bool silent, nsIMobileMessageCallback *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean isSilentNumber (in DOMString number); */
NS_IMETHODIMP nsSmsService::IsSilentNumber(const nsAString & number, bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void addSilentNumber (in DOMString number); */
NS_IMETHODIMP nsSmsService::AddSilentNumber(const nsAString & number)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void removeSilentNumber (in DOMString number); */
NS_IMETHODIMP nsSmsService::RemoveSilentNumber(const nsAString & number)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsISmsService_h__ */
