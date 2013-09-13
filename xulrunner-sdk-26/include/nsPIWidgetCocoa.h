/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/widget/cocoa/nsPIWidgetCocoa.idl
 */

#ifndef __gen_nsPIWidgetCocoa_h__
#define __gen_nsPIWidgetCocoa_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsMenuBarX; /* forward declaration */

class nsCocoaWindow; /* forward declaration */

class nsIWidget; /* forward declaration */


/* starting interface:    nsPIWidgetCocoa */
#define NS_PIWIDGETCOCOA_IID_STR "f75ff69e-3a51-419e-bd29-042f804bc2ed"

#define NS_PIWIDGETCOCOA_IID \
  {0xf75ff69e, 0x3a51, 0x419e, \
    { 0xbd, 0x29, 0x04, 0x2f, 0x80, 0x4b, 0xc2, 0xed }}

class NS_NO_VTABLE nsPIWidgetCocoa : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_PIWIDGETCOCOA_IID)

  /* void SendSetZLevelEvent (); */
  NS_IMETHOD SendSetZLevelEvent(void) = 0;

  /* nsCocoaWindow GetChildSheet (in boolean aShown); */
  NS_IMETHOD GetChildSheet(bool aShown, nsCocoaWindow * *_retval) = 0;

  /* nsIWidget GetRealParent (); */
  NS_IMETHOD GetRealParent(nsIWidget * *_retval) = 0;

  /* readonly attribute NSWindowPtr sheetWindowParent; */
  NS_IMETHOD GetSheetWindowParent(NSWindow **aSheetWindowParent) = 0;

  /* readonly attribute boolean isSheet; */
  NS_IMETHOD GetIsSheet(bool *aIsSheet) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsPIWidgetCocoa, NS_PIWIDGETCOCOA_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSPIWIDGETCOCOA \
  NS_IMETHOD SendSetZLevelEvent(void); \
  NS_IMETHOD GetChildSheet(bool aShown, nsCocoaWindow * *_retval); \
  NS_IMETHOD GetRealParent(nsIWidget * *_retval); \
  NS_IMETHOD GetSheetWindowParent(NSWindow **aSheetWindowParent); \
  NS_IMETHOD GetIsSheet(bool *aIsSheet); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSPIWIDGETCOCOA(_to) \
  NS_IMETHOD SendSetZLevelEvent(void) { return _to SendSetZLevelEvent(); } \
  NS_IMETHOD GetChildSheet(bool aShown, nsCocoaWindow * *_retval) { return _to GetChildSheet(aShown, _retval); } \
  NS_IMETHOD GetRealParent(nsIWidget * *_retval) { return _to GetRealParent(_retval); } \
  NS_IMETHOD GetSheetWindowParent(NSWindow **aSheetWindowParent) { return _to GetSheetWindowParent(aSheetWindowParent); } \
  NS_IMETHOD GetIsSheet(bool *aIsSheet) { return _to GetIsSheet(aIsSheet); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSPIWIDGETCOCOA(_to) \
  NS_IMETHOD SendSetZLevelEvent(void) { return !_to ? NS_ERROR_NULL_POINTER : _to->SendSetZLevelEvent(); } \
  NS_IMETHOD GetChildSheet(bool aShown, nsCocoaWindow * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetChildSheet(aShown, _retval); } \
  NS_IMETHOD GetRealParent(nsIWidget * *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRealParent(_retval); } \
  NS_IMETHOD GetSheetWindowParent(NSWindow **aSheetWindowParent) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSheetWindowParent(aSheetWindowParent); } \
  NS_IMETHOD GetIsSheet(bool *aIsSheet) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetIsSheet(aIsSheet); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class _MYCLASS_ : public nsPIWidgetCocoa
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSPIWIDGETCOCOA

  _MYCLASS_();

private:
  ~_MYCLASS_();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(_MYCLASS_, nsPIWidgetCocoa)

_MYCLASS_::_MYCLASS_()
{
  /* member initializers and constructor code */
}

_MYCLASS_::~_MYCLASS_()
{
  /* destructor code */
}

/* void SendSetZLevelEvent (); */
NS_IMETHODIMP _MYCLASS_::SendSetZLevelEvent()
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsCocoaWindow GetChildSheet (in boolean aShown); */
NS_IMETHODIMP _MYCLASS_::GetChildSheet(bool aShown, nsCocoaWindow * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* nsIWidget GetRealParent (); */
NS_IMETHODIMP _MYCLASS_::GetRealParent(nsIWidget * *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute NSWindowPtr sheetWindowParent; */
NS_IMETHODIMP _MYCLASS_::GetSheetWindowParent(NSWindow **aSheetWindowParent)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* readonly attribute boolean isSheet; */
NS_IMETHODIMP _MYCLASS_::GetIsSheet(bool *aIsSheet)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsPIWidgetCocoa_h__ */
