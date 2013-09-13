/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/netwerk/streamconv/public/nsIAppleFileDecoder.idl
 */

#ifndef __gen_nsIAppleFileDecoder_h__
#define __gen_nsIAppleFileDecoder_h__


#ifndef __gen_nsIOutputStream_h__
#include "nsIOutputStream.h"
#endif

#ifndef __gen_nsIFile_h__
#include "nsIFile.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
#define NS_APPLEFILEDECODER_CID                      \
{ /* 3a2bb281-64b8-11d5-9daa-bb433143c53c */         \
    0x3a2bb281,                                      \
    0x64b8,                                          \
    0x11d5,                                          \
    {0x9d, 0xaa, 0xbb, 0x43, 0x31, 0x43, 0xc5, 0x3c} \
}
#define NS_IAPPLEFILEDECODER_CONTRACTID     "@mozilla.org/applefiledecoder;1"

/* starting interface:    nsIAppleFileDecoder */
#define NS_IAPPLEFILEDECODER_IID_STR "3a2bb280-64b8-11d5-9daa-bb433143c53c"

#define NS_IAPPLEFILEDECODER_IID \
  {0x3a2bb280, 0x64b8, 0x11d5, \
    { 0x9d, 0xaa, 0xbb, 0x43, 0x31, 0x43, 0xc5, 0x3c }}

class NS_NO_VTABLE nsIAppleFileDecoder : public nsIOutputStream {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPLEFILEDECODER_IID)

  /* void Initialize (in nsIOutputStream outputStream, in nsIFile outputFile); */
  NS_IMETHOD Initialize(nsIOutputStream *outputStream, nsIFile *outputFile) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAppleFileDecoder, NS_IAPPLEFILEDECODER_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPLEFILEDECODER \
  NS_IMETHOD Initialize(nsIOutputStream *outputStream, nsIFile *outputFile); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPLEFILEDECODER(_to) \
  NS_IMETHOD Initialize(nsIOutputStream *outputStream, nsIFile *outputFile) { return _to Initialize(outputStream, outputFile); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPLEFILEDECODER(_to) \
  NS_IMETHOD Initialize(nsIOutputStream *outputStream, nsIFile *outputFile) { return !_to ? NS_ERROR_NULL_POINTER : _to->Initialize(outputStream, outputFile); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAppleFileDecoder : public nsIAppleFileDecoder
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPLEFILEDECODER

  nsAppleFileDecoder();

private:
  ~nsAppleFileDecoder();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAppleFileDecoder, nsIAppleFileDecoder)

nsAppleFileDecoder::nsAppleFileDecoder()
{
  /* member initializers and constructor code */
}

nsAppleFileDecoder::~nsAppleFileDecoder()
{
  /* destructor code */
}

/* void Initialize (in nsIOutputStream outputStream, in nsIFile outputFile); */
NS_IMETHODIMP nsAppleFileDecoder::Initialize(nsIOutputStream *outputStream, nsIFile *outputFile)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIAppleFileDecoder_h__ */
