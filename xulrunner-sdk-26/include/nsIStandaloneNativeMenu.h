/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/widget/nsIStandaloneNativeMenu.idl
 */

#ifndef __gen_nsIStandaloneNativeMenu_h__
#define __gen_nsIStandaloneNativeMenu_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMElement; /* forward declaration */


/* starting interface:    nsIStandaloneNativeMenu */
#define NS_ISTANDALONENATIVEMENU_IID_STR "7f7201eb-510c-4cef-bdf0-04a15a7a4a8c"

#define NS_ISTANDALONENATIVEMENU_IID \
  {0x7f7201eb, 0x510c, 0x4cef, \
    { 0xbd, 0xf0, 0x04, 0xa1, 0x5a, 0x7a, 0x4a, 0x8c }}

class NS_NO_VTABLE nsIStandaloneNativeMenu : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ISTANDALONENATIVEMENU_IID)

  /* void init (in nsIDOMElement aDOMElement); */
  NS_IMETHOD Init(nsIDOMElement *aDOMElement) = 0;

  /* boolean menuWillOpen (); */
  NS_IMETHOD MenuWillOpen(bool *_retval) = 0;

  /* [noscript] readonly attribute voidPtr nativeMenu; */
  NS_IMETHOD GetNativeMenu(void **aNativeMenu) = 0;

  /* void activateNativeMenuItemAt (in AString anIndexString); */
  NS_IMETHOD ActivateNativeMenuItemAt(const nsAString & anIndexString) = 0;

  /* void forceUpdateNativeMenuAt (in AString anIndexString); */
  NS_IMETHOD ForceUpdateNativeMenuAt(const nsAString & anIndexString) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIStandaloneNativeMenu, NS_ISTANDALONENATIVEMENU_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSISTANDALONENATIVEMENU \
  NS_IMETHOD Init(nsIDOMElement *aDOMElement); \
  NS_IMETHOD MenuWillOpen(bool *_retval); \
  NS_IMETHOD GetNativeMenu(void **aNativeMenu); \
  NS_IMETHOD ActivateNativeMenuItemAt(const nsAString & anIndexString); \
  NS_IMETHOD ForceUpdateNativeMenuAt(const nsAString & anIndexString); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSISTANDALONENATIVEMENU(_to) \
  NS_IMETHOD Init(nsIDOMElement *aDOMElement) { return _to Init(aDOMElement); } \
  NS_IMETHOD MenuWillOpen(bool *_retval) { return _to MenuWillOpen(_retval); } \
  NS_IMETHOD GetNativeMenu(void **aNativeMenu) { return _to GetNativeMenu(aNativeMenu); } \
  NS_IMETHOD ActivateNativeMenuItemAt(const nsAString & anIndexString) { return _to ActivateNativeMenuItemAt(anIndexString); } \
  NS_IMETHOD ForceUpdateNativeMenuAt(const nsAString & anIndexString) { return _to ForceUpdateNativeMenuAt(anIndexString); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSISTANDALONENATIVEMENU(_to) \
  NS_IMETHOD Init(nsIDOMElement *aDOMElement) { return !_to ? NS_ERROR_NULL_POINTER : _to->Init(aDOMElement); } \
  NS_IMETHOD MenuWillOpen(bool *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->MenuWillOpen(_retval); } \
  NS_IMETHOD GetNativeMenu(void **aNativeMenu) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNativeMenu(aNativeMenu); } \
  NS_IMETHOD ActivateNativeMenuItemAt(const nsAString & anIndexString) { return !_to ? NS_ERROR_NULL_POINTER : _to->ActivateNativeMenuItemAt(anIndexString); } \
  NS_IMETHOD ForceUpdateNativeMenuAt(const nsAString & anIndexString) { return !_to ? NS_ERROR_NULL_POINTER : _to->ForceUpdateNativeMenuAt(anIndexString); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsStandaloneNativeMenu : public nsIStandaloneNativeMenu
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSISTANDALONENATIVEMENU

  nsStandaloneNativeMenu();

private:
  ~nsStandaloneNativeMenu();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsStandaloneNativeMenu, nsIStandaloneNativeMenu)

nsStandaloneNativeMenu::nsStandaloneNativeMenu()
{
  /* member initializers and constructor code */
}

nsStandaloneNativeMenu::~nsStandaloneNativeMenu()
{
  /* destructor code */
}

/* void init (in nsIDOMElement aDOMElement); */
NS_IMETHODIMP nsStandaloneNativeMenu::Init(nsIDOMElement *aDOMElement)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* boolean menuWillOpen (); */
NS_IMETHODIMP nsStandaloneNativeMenu::MenuWillOpen(bool *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* [noscript] readonly attribute voidPtr nativeMenu; */
NS_IMETHODIMP nsStandaloneNativeMenu::GetNativeMenu(void **aNativeMenu)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void activateNativeMenuItemAt (in AString anIndexString); */
NS_IMETHODIMP nsStandaloneNativeMenu::ActivateNativeMenuItemAt(const nsAString & anIndexString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void forceUpdateNativeMenuAt (in AString anIndexString); */
NS_IMETHODIMP nsStandaloneNativeMenu::ForceUpdateNativeMenuAt(const nsAString & anIndexString)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIStandaloneNativeMenu_h__ */
