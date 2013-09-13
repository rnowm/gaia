/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/dom/mobilemessage/interfaces/nsIMmsService.idl
 */

#ifndef __gen_nsIMmsService_h__
#define __gen_nsIMmsService_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIMobileMessageCallback; /* forward declaration */

class nsIDOMBlob; /* forward declaration */

#define MMS_SERVICE_CID { 0x06d9124b, 0x80e0, 0x40ed, \
  { 0x98, 0x71, 0x4d, 0x23, 0x4a, 0x0f, 0xd4, 0x31 } }
#define MMS_SERVICE_CONTRACTID "@mozilla.org/mms/mmsservice;1"

/* starting interface:    nsIMmsService */
#define NS_IMMSSERVICE_IID_STR "e5ef630a-eab7-425a-ac42-650ef5c4fcef"

#define NS_IMMSSERVICE_IID \
  {0xe5ef630a, 0xeab7, 0x425a, \
    { 0xac, 0x42, 0x65, 0x0e, 0xf5, 0xc4, 0xfc, 0xef }}

class NS_NO_VTABLE nsIMmsService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMMSSERVICE_IID)

  /* void send (in jsval parameters, in nsIMobileMessageCallback request); */
  NS_IMETHOD Send(const JS::Value & parameters, nsIMobileMessageCallback *request) = 0;

  /* void retrieve (in long id, in nsIMobileMessageCallback request); */
  NS_IMETHOD Retrieve(int32_t id, nsIMobileMessageCallback *request) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMmsService, NS_IMMSSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMMSSERVICE \
  NS_IMETHOD Send(const JS::Value & parameters, nsIMobileMessageCallback *request); \
  NS_IMETHOD Retrieve(int32_t id, nsIMobileMessageCallback *request); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMMSSERVICE(_to) \
  NS_IMETHOD Send(const JS::Value & parameters, nsIMobileMessageCallback *request) { return _to Send(parameters, request); } \
  NS_IMETHOD Retrieve(int32_t id, nsIMobileMessageCallback *request) { return _to Retrieve(id, request); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMMSSERVICE(_to) \
  NS_IMETHOD Send(const JS::Value & parameters, nsIMobileMessageCallback *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->Send(parameters, request); } \
  NS_IMETHOD Retrieve(int32_t id, nsIMobileMessageCallback *request) { return !_to ? NS_ERROR_NULL_POINTER : _to->Retrieve(id, request); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMmsService : public nsIMmsService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMMSSERVICE

  nsMmsService();

private:
  ~nsMmsService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMmsService, nsIMmsService)

nsMmsService::nsMmsService()
{
  /* member initializers and constructor code */
}

nsMmsService::~nsMmsService()
{
  /* destructor code */
}

/* void send (in jsval parameters, in nsIMobileMessageCallback request); */
NS_IMETHODIMP nsMmsService::Send(const JS::Value & parameters, nsIMobileMessageCallback *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void retrieve (in long id, in nsIMobileMessageCallback request); */
NS_IMETHODIMP nsMmsService::Retrieve(int32_t id, nsIMobileMessageCallback *request)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMmsService_h__ */
