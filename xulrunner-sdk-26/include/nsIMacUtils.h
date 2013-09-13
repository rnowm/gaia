/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/xpcom/base/nsIMacUtils.idl
 */

#ifndef __gen_nsIMacUtils_h__
#define __gen_nsIMacUtils_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIMacUtils */
#define NS_IMACUTILS_IID_STR "5e9072d7-ff95-455e-9466-8af9841a72ec"

#define NS_IMACUTILS_IID \
  {0x5e9072d7, 0xff95, 0x455e, \
    { 0x94, 0x66, 0x8a, 0xf9, 0x84, 0x1a, 0x72, 0xec }}

class NS_NO_VTABLE nsIMacUtils : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMACUTILS_IID)

  /* readonly attribute boolean isUniversalBinary; */
  NS_IMETHOD GetIsUniversalBinary(bool *aIsUniversalBinary) = 0;

  /* readonly attribute AString architecturesInBinary; */
  NS_IMETHOD GetArchitecturesInBinary(nsAString & aArchitecturesInBinary) = 0;

  /* readonly attribute boolean isTranslated; */
  NS_IMETHOD GetIsTranslated(bool *aIsTranslated) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMacUtils, NS_IMACUTILS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMACUTILS \
  NS_IMETHOD GetIsUniversalBinary(bool *aIsUniversalBinary); \
  NS_IMETHOD GetArchitecturesInBinary(nsAString & aArchitecturesInBinary); \
  NS_IMETHOD GetIsTranslated(bool *aIsTranslated); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMACUTILS(_to) \
  NS_IMETHOD GetIsUniversalBinary(bool *aIsUniversalBinary) { return _to GetIsUniversalBinary(aIsUniversalBinary); } \
  NS_IMETHOD GetArchitecturesInBinary(nsAString & aArchitecturesInBinary) { return _to GetArchitecturesInBinary(aArchitecturesInBinary); } \
  NS_IMETHOD GetIsTranslated(bool *aIsTranslated) { return _to GetIsTranslated(aIsTranslated); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMACUTILS(_to) \
  NS_IMETHOD GetIsUniversalBinary(bool *aIsUniversalBinary) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsUniversalBinary(aIsUniversalBinary); } \
  NS_IMETHOD GetArchitecturesInBinary(nsAString & aArchitecturesInBinary) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetArchitecturesInBinary(aArchitecturesInBinary); } \
  NS_IMETHOD GetIsTranslated(bool *aIsTranslated) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsTranslated(aIsTranslated); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMacUtils : public nsIMacUtils
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMACUTILS

  nsMacUtils();

private:
  ~nsMacUtils();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMacUtils, nsIMacUtils)

nsMacUtils::nsMacUtils()
{
  /* member initializers and constructor code */
}

nsMacUtils::~nsMacUtils()
{
  /* destructor code */
}

/* readonly attribute boolean isUniversalBinary; */
NS_IMETHODIMP nsMacUtils::GetIsUniversalBinary(bool *aIsUniversalBinary)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute AString architecturesInBinary; */
NS_IMETHODIMP nsMacUtils::GetArchitecturesInBinary(nsAString & aArchitecturesInBinary)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isTranslated; */
NS_IMETHODIMP nsMacUtils::GetIsTranslated(bool *aIsTranslated)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMacUtils_h__ */
