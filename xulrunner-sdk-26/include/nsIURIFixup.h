/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/docshell/base/nsIURIFixup.idl
 */

#ifndef __gen_nsIURIFixup_h__
#define __gen_nsIURIFixup_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIURI; /* forward declaration */

class nsIInputStream; /* forward declaration */


/* starting interface:    nsIURIFixup */
#define NS_IURIFIXUP_IID_STR "552a23bb-c1b2-426e-a801-d346c6a98f1d"

#define NS_IURIFIXUP_IID \
  {0x552a23bb, 0xc1b2, 0x426e, \
    { 0xa8, 0x01, 0xd3, 0x46, 0xc6, 0xa9, 0x8f, 0x1d }}

class NS_NO_VTABLE nsIURIFixup : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IURIFIXUP_IID)

  enum {
    FIXUP_FLAG_NONE = 0U,
    FIXUP_FLAG_ALLOW_KEYWORD_LOOKUP = 1U,
    FIXUP_FLAGS_MAKE_ALTERNATE_URI = 2U,
    FIXUP_FLAG_USE_UTF8 = 4U
  };

  /* nsIURI createExposableURI (in nsIURI aURI); */
  NS_IMETHOD CreateExposableURI(nsIURI *aURI, nsIURI * *_retval) = 0;

  /* nsIURI createFixupURI (in AUTF8String aURIText, in unsigned long aFixupFlags, [optional] out nsIInputStream aPostData); */
  NS_IMETHOD CreateFixupURI(const nsACString & aURIText, uint32_t aFixupFlags, nsIInputStream * *aPostData, nsIURI * *_retval) = 0;

  /* nsIURI keywordToURI (in AUTF8String aKeyword, [optional] out nsIInputStream aPostData); */
  NS_IMETHOD KeywordToURI(const nsACString & aKeyword, nsIInputStream * *aPostData, nsIURI * *_retval) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIURIFixup, NS_IURIFIXUP_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIURIFIXUP \
  NS_IMETHOD CreateExposableURI(nsIURI *aURI, nsIURI * *_retval); \
  NS_IMETHOD CreateFixupURI(const nsACString & aURIText, uint32_t aFixupFlags, nsIInputStream * *aPostData, nsIURI * *_retval); \
  NS_IMETHOD KeywordToURI(const nsACString & aKeyword, nsIInputStream * *aPostData, nsIURI * *_retval); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIURIFIXUP(_to) \
  NS_IMETHOD CreateExposableURI(nsIURI *aURI, nsIURI * *_retval) { return _to CreateExposableURI(aURI, _retval); } \
  NS_IMETHOD CreateFixupURI(const nsACString & aURIText, uint32_t aFixupFlags, nsIInputStream * *aPostData, nsIURI * *_retval) { return _to CreateFixupURI(aURIText, aFixupFlags, aPostData, _retval); } \
  NS_IMETHOD KeywordToURI(const nsACString & aKeyword, nsIInputStream * *aPostData, nsIURI * *_retval) { return _to KeywordToURI(aKeyword, aPostData, _retval); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIURIFIXUP(_to) \
  NS_IMETHOD CreateExposableURI(nsIURI *aURI, nsIURI * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateExposableURI(aURI, _retval); } \
  NS_IMETHOD CreateFixupURI(const nsACString & aURIText, uint32_t aFixupFlags, nsIInputStream * *aPostData, nsIURI * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->CreateFixupURI(aURIText, aFixupFlags, aPostData, _retval); } \
  NS_IMETHOD KeywordToURI(const nsACString & aKeyword, nsIInputStream * *aPostData, nsIURI * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->KeywordToURI(aKeyword, aPostData, _retval); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsURIFixup : public nsIURIFixup
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIURIFIXUP

  nsURIFixup();

private:
  ~nsURIFixup();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsURIFixup, nsIURIFixup)

nsURIFixup::nsURIFixup()
{
  /* member initializers and constructor code */
}

nsURIFixup::~nsURIFixup()
{
  /* destructor code */
}

/* nsIURI createExposableURI (in nsIURI aURI); */
NS_IMETHODIMP nsURIFixup::CreateExposableURI(nsIURI *aURI, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI createFixupURI (in AUTF8String aURIText, in unsigned long aFixupFlags, [optional] out nsIInputStream aPostData); */
NS_IMETHODIMP nsURIFixup::CreateFixupURI(const nsACString & aURIText, uint32_t aFixupFlags, nsIInputStream * *aPostData, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIURI keywordToURI (in AUTF8String aKeyword, [optional] out nsIInputStream aPostData); */
NS_IMETHODIMP nsURIFixup::KeywordToURI(const nsACString & aKeyword, nsIInputStream * *aPostData, nsIURI * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIURIFixup_h__ */
