/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/widget/nsIMacWebAppUtils.idl
 */

#ifndef __gen_nsIMacWebAppUtils_h__
#define __gen_nsIMacWebAppUtils_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIMacWebAppUtils; /* forward declaration */


/* starting interface:    nsIMacWebAppUtils */
#define NS_IMACWEBAPPUTILS_IID_STR "e9096367-ddd9-45e4-b762-49c0c18b7119"

#define NS_IMACWEBAPPUTILS_IID \
  {0xe9096367, 0xddd9, 0x45e4, \
    { 0xb7, 0x62, 0x49, 0xc0, 0xc1, 0x8b, 0x71, 0x19 }}

class NS_NO_VTABLE nsIMacWebAppUtils : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMACWEBAPPUTILS_IID)

  /* AString pathForAppWithIdentifier (in AString bundleIdentifier); */
  NS_IMETHOD PathForAppWithIdentifier(const nsAString & bundleIdentifier, nsAString & _retval) = 0;

  /* void launchAppWithIdentifier (in AString bundleIdentifier); */
  NS_IMETHOD LaunchAppWithIdentifier(const nsAString & bundleIdentifier) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMacWebAppUtils, NS_IMACWEBAPPUTILS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMACWEBAPPUTILS \
  NS_IMETHOD PathForAppWithIdentifier(const nsAString & bundleIdentifier, nsAString & _retval); \
  NS_IMETHOD LaunchAppWithIdentifier(const nsAString & bundleIdentifier); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMACWEBAPPUTILS(_to) \
  NS_IMETHOD PathForAppWithIdentifier(const nsAString & bundleIdentifier, nsAString & _retval) { return _to PathForAppWithIdentifier(bundleIdentifier, _retval); } \
  NS_IMETHOD LaunchAppWithIdentifier(const nsAString & bundleIdentifier) { return _to LaunchAppWithIdentifier(bundleIdentifier); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMACWEBAPPUTILS(_to) \
  NS_IMETHOD PathForAppWithIdentifier(const nsAString & bundleIdentifier, nsAString & _retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->PathForAppWithIdentifier(bundleIdentifier, _retval); } \
  NS_IMETHOD LaunchAppWithIdentifier(const nsAString & bundleIdentifier) { return !_to ? NS_ERROR_NULL_POINTER : _to->LaunchAppWithIdentifier(bundleIdentifier); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMacWebAppUtils : public nsIMacWebAppUtils
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMACWEBAPPUTILS

  nsMacWebAppUtils();

private:
  ~nsMacWebAppUtils();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMacWebAppUtils, nsIMacWebAppUtils)

nsMacWebAppUtils::nsMacWebAppUtils()
{
  /* member initializers and constructor code */
}

nsMacWebAppUtils::~nsMacWebAppUtils()
{
  /* destructor code */
}

/* AString pathForAppWithIdentifier (in AString bundleIdentifier); */
NS_IMETHODIMP nsMacWebAppUtils::PathForAppWithIdentifier(const nsAString & bundleIdentifier, nsAString & _retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void launchAppWithIdentifier (in AString bundleIdentifier); */
NS_IMETHODIMP nsMacWebAppUtils::LaunchAppWithIdentifier(const nsAString & bundleIdentifier)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMacWebAppUtils_h__ */
