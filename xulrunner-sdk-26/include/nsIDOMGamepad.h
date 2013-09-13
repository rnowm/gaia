/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/dom/interfaces/gamepad/nsIDOMGamepad.idl
 */

#ifndef __gen_nsIDOMGamepad_h__
#define __gen_nsIDOMGamepad_h__


#ifndef __gen_nsISupports_h__
#include "nsISupports.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIVariant; /* forward declaration */


/* starting interface:    nsIDOMGamepad */
#define NS_IDOMGAMEPAD_IID_STR "ff13acd9-11da-4817-8f2a-4a5700dfd13e"

#define NS_IDOMGAMEPAD_IID \
  {0xff13acd9, 0x11da, 0x4817, \
    { 0x8f, 0x2a, 0x4a, 0x57, 0x00, 0xdf, 0xd1, 0x3e }}

class NS_NO_VTABLE nsIDOMGamepad : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMGAMEPAD_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMGamepad, NS_IDOMGAMEPAD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMGAMEPAD \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMGAMEPAD(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMGAMEPAD(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMGamepad : public nsIDOMGamepad
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMGAMEPAD

  nsDOMGamepad();

private:
  ~nsDOMGamepad();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMGamepad, nsIDOMGamepad)

nsDOMGamepad::nsDOMGamepad()
{
  /* member initializers and constructor code */
}

nsDOMGamepad::~nsDOMGamepad()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMGamepad_h__ */
