/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/dom/interfaces/html/nsIDOMHTMLTableElement.idl
 */

#ifndef __gen_nsIDOMHTMLTableElement_h__
#define __gen_nsIDOMHTMLTableElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLTableElement */
#define NS_IDOMHTMLTABLEELEMENT_IID_STR "1a7bf1f1-5d6c-4200-9ceb-455874322315"

#define NS_IDOMHTMLTABLEELEMENT_IID \
  {0x1a7bf1f1, 0x5d6c, 0x4200, \
    { 0x9c, 0xeb, 0x45, 0x58, 0x74, 0x32, 0x23, 0x15 }}

class NS_NO_VTABLE nsIDOMHTMLTableElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLTABLEELEMENT_IID)

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLTableElement, NS_IDOMHTMLTABLEELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLTABLEELEMENT \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLTABLEELEMENT(_to) \
  /* no methods! */

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLTABLEELEMENT(_to) \
  /* no methods! */

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLTableElement : public nsIDOMHTMLTableElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLTABLEELEMENT

  nsDOMHTMLTableElement();

private:
  ~nsDOMHTMLTableElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLTableElement, nsIDOMHTMLTableElement)

nsDOMHTMLTableElement::nsDOMHTMLTableElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLTableElement::~nsDOMHTMLTableElement()
{
  /* destructor code */
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLTableElement_h__ */
