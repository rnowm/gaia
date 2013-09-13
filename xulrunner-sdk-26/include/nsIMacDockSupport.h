/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/widget/nsIMacDockSupport.idl
 */

#ifndef __gen_nsIMacDockSupport_h__
#define __gen_nsIMacDockSupport_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIStandaloneNativeMenu; /* forward declaration */


/* starting interface:    nsIMacDockSupport */
#define NS_IMACDOCKSUPPORT_IID_STR "8be66b0c-5f71-4b74-98cf-6c2551b999b1"

#define NS_IMACDOCKSUPPORT_IID \
  {0x8be66b0c, 0x5f71, 0x4b74, \
    { 0x98, 0xcf, 0x6c, 0x25, 0x51, 0xb9, 0x99, 0xb1 }}

class NS_NO_VTABLE nsIMacDockSupport : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IMACDOCKSUPPORT_IID)

  /* attribute nsIStandaloneNativeMenu dockMenu; */
  NS_IMETHOD GetDockMenu(nsIStandaloneNativeMenu * *aDockMenu) = 0;
  NS_IMETHOD SetDockMenu(nsIStandaloneNativeMenu *aDockMenu) = 0;

  /* void activateApplication (in boolean aIgnoreOtherApplications); */
  NS_IMETHOD ActivateApplication(bool aIgnoreOtherApplications) = 0;

  /* attribute AString badgeText; */
  NS_IMETHOD GetBadgeText(nsAString & aBadgeText) = 0;
  NS_IMETHOD SetBadgeText(const nsAString & aBadgeText) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIMacDockSupport, NS_IMACDOCKSUPPORT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIMACDOCKSUPPORT \
  NS_IMETHOD GetDockMenu(nsIStandaloneNativeMenu * *aDockMenu); \
  NS_IMETHOD SetDockMenu(nsIStandaloneNativeMenu *aDockMenu); \
  NS_IMETHOD ActivateApplication(bool aIgnoreOtherApplications); \
  NS_IMETHOD GetBadgeText(nsAString & aBadgeText); \
  NS_IMETHOD SetBadgeText(const nsAString & aBadgeText); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIMACDOCKSUPPORT(_to) \
  NS_IMETHOD GetDockMenu(nsIStandaloneNativeMenu * *aDockMenu) { return _to GetDockMenu(aDockMenu); } \
  NS_IMETHOD SetDockMenu(nsIStandaloneNativeMenu *aDockMenu) { return _to SetDockMenu(aDockMenu); } \
  NS_IMETHOD ActivateApplication(bool aIgnoreOtherApplications) { return _to ActivateApplication(aIgnoreOtherApplications); } \
  NS_IMETHOD GetBadgeText(nsAString & aBadgeText) { return _to GetBadgeText(aBadgeText); } \
  NS_IMETHOD SetBadgeText(const nsAString & aBadgeText) { return _to SetBadgeText(aBadgeText); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIMACDOCKSUPPORT(_to) \
  NS_IMETHOD GetDockMenu(nsIStandaloneNativeMenu * *aDockMenu) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetDockMenu(aDockMenu); } \
  NS_IMETHOD SetDockMenu(nsIStandaloneNativeMenu *aDockMenu) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetDockMenu(aDockMenu); } \
  NS_IMETHOD ActivateApplication(bool aIgnoreOtherApplications) { return !_to ? NS_ERROR_NULL_POINTER : _to->ActivateApplication(aIgnoreOtherApplications); } \
  NS_IMETHOD GetBadgeText(nsAString & aBadgeText) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBadgeText(aBadgeText); } \
  NS_IMETHOD SetBadgeText(const nsAString & aBadgeText) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBadgeText(aBadgeText); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsMacDockSupport : public nsIMacDockSupport
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIMACDOCKSUPPORT

  nsMacDockSupport();

private:
  ~nsMacDockSupport();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsMacDockSupport, nsIMacDockSupport)

nsMacDockSupport::nsMacDockSupport()
{
  /* member initializers and constructor code */
}

nsMacDockSupport::~nsMacDockSupport()
{
  /* destructor code */
}

/* attribute nsIStandaloneNativeMenu dockMenu; */
NS_IMETHODIMP nsMacDockSupport::GetDockMenu(nsIStandaloneNativeMenu * *aDockMenu)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMacDockSupport::SetDockMenu(nsIStandaloneNativeMenu *aDockMenu)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void activateApplication (in boolean aIgnoreOtherApplications); */
NS_IMETHODIMP nsMacDockSupport::ActivateApplication(bool aIgnoreOtherApplications)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute AString badgeText; */
NS_IMETHODIMP nsMacDockSupport::GetBadgeText(nsAString & aBadgeText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsMacDockSupport::SetBadgeText(const nsAString & aBadgeText)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIMacDockSupport_h__ */
