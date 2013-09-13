/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/dom/network/interfaces/nsITCPSocketParent.idl
 */

#ifndef __gen_nsITCPSocketParent_h__
#define __gen_nsITCPSocketParent_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMTCPSocket; /* forward declaration */

class nsIDOMTCPServerSocket; /* forward declaration */

class nsITCPServerSocketParent; /* forward declaration */

class nsITCPSocketIntermediary; /* forward declaration */


/* starting interface:    nsITCPSocketParent */
#define NS_ITCPSOCKETPARENT_IID_STR "123f654b-4435-43c8-8447-db1b5420a1c2"

#define NS_ITCPSOCKETPARENT_IID \
  {0x123f654b, 0x4435, 0x43c8, \
    { 0x84, 0x47, 0xdb, 0x1b, 0x54, 0x20, 0xa1, 0xc2 }}

class NS_NO_VTABLE nsITCPSocketParent : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITCPSOCKETPARENT_IID)

  /* [implicit_jscontext] void initJS (in jsval intermediary); */
  NS_IMETHOD InitJS(const JS::Value & intermediary, JSContext* cx) = 0;

  /* [implicit_jscontext] void sendCallback (in DOMString type, in jsval data, in DOMString readyState, in uint32_t bufferedAmount); */
  NS_IMETHOD SendCallback(const nsAString & type, const JS::Value & data, const nsAString & readyState, uint32_t bufferedAmount, JSContext* cx) = 0;

  /* [implicit_jscontext] void setSocketAndIntermediary (in nsIDOMTCPSocket socket, in nsITCPSocketIntermediary intermediary); */
  NS_IMETHOD SetSocketAndIntermediary(nsIDOMTCPSocket *socket, nsITCPSocketIntermediary *intermediary, JSContext* cx) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITCPSocketParent, NS_ITCPSOCKETPARENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITCPSOCKETPARENT \
  NS_IMETHOD InitJS(const JS::Value & intermediary, JSContext* cx); \
  NS_IMETHOD SendCallback(const nsAString & type, const JS::Value & data, const nsAString & readyState, uint32_t bufferedAmount, JSContext* cx); \
  NS_IMETHOD SetSocketAndIntermediary(nsIDOMTCPSocket *socket, nsITCPSocketIntermediary *intermediary, JSContext* cx); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITCPSOCKETPARENT(_to) \
  NS_IMETHOD InitJS(const JS::Value & intermediary, JSContext* cx) { return _to InitJS(intermediary, cx); } \
  NS_IMETHOD SendCallback(const nsAString & type, const JS::Value & data, const nsAString & readyState, uint32_t bufferedAmount, JSContext* cx) { return _to SendCallback(type, data, readyState, bufferedAmount, cx); } \
  NS_IMETHOD SetSocketAndIntermediary(nsIDOMTCPSocket *socket, nsITCPSocketIntermediary *intermediary, JSContext* cx) { return _to SetSocketAndIntermediary(socket, intermediary, cx); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITCPSOCKETPARENT(_to) \
  NS_IMETHOD InitJS(const JS::Value & intermediary, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->InitJS(intermediary, cx); } \
  NS_IMETHOD SendCallback(const nsAString & type, const JS::Value & data, const nsAString & readyState, uint32_t bufferedAmount, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendCallback(type, data, readyState, bufferedAmount, cx); } \
  NS_IMETHOD SetSocketAndIntermediary(nsIDOMTCPSocket *socket, nsITCPSocketIntermediary *intermediary, JSContext* cx) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSocketAndIntermediary(socket, intermediary, cx); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTCPSocketParent : public nsITCPSocketParent
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITCPSOCKETPARENT

  nsTCPSocketParent();

private:
  ~nsTCPSocketParent();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTCPSocketParent, nsITCPSocketParent)

nsTCPSocketParent::nsTCPSocketParent()
{
  /* member initializers and constructor code */
}

nsTCPSocketParent::~nsTCPSocketParent()
{
  /* destructor code */
}

/* [implicit_jscontext] void initJS (in jsval intermediary); */
NS_IMETHODIMP nsTCPSocketParent::InitJS(const JS::Value & intermediary, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void sendCallback (in DOMString type, in jsval data, in DOMString readyState, in uint32_t bufferedAmount); */
NS_IMETHODIMP nsTCPSocketParent::SendCallback(const nsAString & type, const JS::Value & data, const nsAString & readyState, uint32_t bufferedAmount, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [implicit_jscontext] void setSocketAndIntermediary (in nsIDOMTCPSocket socket, in nsITCPSocketIntermediary intermediary); */
NS_IMETHODIMP nsTCPSocketParent::SetSocketAndIntermediary(nsIDOMTCPSocket *socket, nsITCPSocketIntermediary *intermediary, JSContext* cx)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsITCPSocketIntermediary */
#define NS_ITCPSOCKETINTERMEDIARY_IID_STR "38bec1ed-b863-40dd-ba69-7bd92e568ee3"

#define NS_ITCPSOCKETINTERMEDIARY_IID \
  {0x38bec1ed, 0xb863, 0x40dd, \
    { 0xba, 0x69, 0x7b, 0xd9, 0x2e, 0x56, 0x8e, 0xe3 }}

class NS_NO_VTABLE nsITCPSocketIntermediary : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ITCPSOCKETINTERMEDIARY_IID)

  /* nsIDOMTCPSocket open (in nsITCPSocketParent parent, in DOMString host, in unsigned short port, in boolean useSSL, in DOMString binaryType); */
  NS_IMETHOD Open(nsITCPSocketParent *parent, const nsAString & host, uint16_t port, bool useSSL, const nsAString & binaryType, nsIDOMTCPSocket * *_retval) = 0;

  /* nsIDOMTCPServerSocket listen (in nsITCPServerSocketParent parent, in unsigned short port, in unsigned short backlog, in DOMString binaryType); */
  NS_IMETHOD Listen(nsITCPServerSocketParent *parent, uint16_t port, uint16_t backlog, const nsAString & binaryType, nsIDOMTCPServerSocket * *_retval) = 0;

  /* void sendString (in DOMString data); */
  NS_IMETHOD SendString(const nsAString & data) = 0;

  /* void sendArrayBuffer (in jsval data); */
  NS_IMETHOD SendArrayBuffer(const JS::Value & data) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsITCPSocketIntermediary, NS_ITCPSOCKETINTERMEDIARY_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSITCPSOCKETINTERMEDIARY \
  NS_IMETHOD Open(nsITCPSocketParent *parent, const nsAString & host, uint16_t port, bool useSSL, const nsAString & binaryType, nsIDOMTCPSocket * *_retval); \
  NS_IMETHOD Listen(nsITCPServerSocketParent *parent, uint16_t port, uint16_t backlog, const nsAString & binaryType, nsIDOMTCPServerSocket * *_retval); \
  NS_IMETHOD SendString(const nsAString & data); \
  NS_IMETHOD SendArrayBuffer(const JS::Value & data); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSITCPSOCKETINTERMEDIARY(_to) \
  NS_IMETHOD Open(nsITCPSocketParent *parent, const nsAString & host, uint16_t port, bool useSSL, const nsAString & binaryType, nsIDOMTCPSocket * *_retval) { return _to Open(parent, host, port, useSSL, binaryType, _retval); } \
  NS_IMETHOD Listen(nsITCPServerSocketParent *parent, uint16_t port, uint16_t backlog, const nsAString & binaryType, nsIDOMTCPServerSocket * *_retval) { return _to Listen(parent, port, backlog, binaryType, _retval); } \
  NS_IMETHOD SendString(const nsAString & data) { return _to SendString(data); } \
  NS_IMETHOD SendArrayBuffer(const JS::Value & data) { return _to SendArrayBuffer(data); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSITCPSOCKETINTERMEDIARY(_to) \
  NS_IMETHOD Open(nsITCPSocketParent *parent, const nsAString & host, uint16_t port, bool useSSL, const nsAString & binaryType, nsIDOMTCPSocket * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Open(parent, host, port, useSSL, binaryType, _retval); } \
  NS_IMETHOD Listen(nsITCPServerSocketParent *parent, uint16_t port, uint16_t backlog, const nsAString & binaryType, nsIDOMTCPServerSocket * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->Listen(parent, port, backlog, binaryType, _retval); } \
  NS_IMETHOD SendString(const nsAString & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendString(data); } \
  NS_IMETHOD SendArrayBuffer(const JS::Value & data) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendArrayBuffer(data); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsTCPSocketIntermediary : public nsITCPSocketIntermediary
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSITCPSOCKETINTERMEDIARY

  nsTCPSocketIntermediary();

private:
  ~nsTCPSocketIntermediary();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsTCPSocketIntermediary, nsITCPSocketIntermediary)

nsTCPSocketIntermediary::nsTCPSocketIntermediary()
{
  /* member initializers and constructor code */
}

nsTCPSocketIntermediary::~nsTCPSocketIntermediary()
{
  /* destructor code */
}

/* nsIDOMTCPSocket open (in nsITCPSocketParent parent, in DOMString host, in unsigned short port, in boolean useSSL, in DOMString binaryType); */
NS_IMETHODIMP nsTCPSocketIntermediary::Open(nsITCPSocketParent *parent, const nsAString & host, uint16_t port, bool useSSL, const nsAString & binaryType, nsIDOMTCPSocket * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIDOMTCPServerSocket listen (in nsITCPServerSocketParent parent, in unsigned short port, in unsigned short backlog, in DOMString binaryType); */
NS_IMETHODIMP nsTCPSocketIntermediary::Listen(nsITCPServerSocketParent *parent, uint16_t port, uint16_t backlog, const nsAString & binaryType, nsIDOMTCPServerSocket * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendString (in DOMString data); */
NS_IMETHODIMP nsTCPSocketIntermediary::SendString(const nsAString & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void sendArrayBuffer (in jsval data); */
NS_IMETHODIMP nsTCPSocketIntermediary::SendArrayBuffer(const JS::Value & data)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsITCPSocketParent_h__ */
