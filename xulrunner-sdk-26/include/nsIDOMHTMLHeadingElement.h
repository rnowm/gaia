/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/dom/interfaces/html/nsIDOMHTMLHeadingElement.idl
 */

#ifndef __gen_nsIDOMHTMLHeadingElement_h__
#define __gen_nsIDOMHTMLHeadingElement_h__


#ifndef __gen_nsIDOMHTMLElement_h__
#include "nsIDOMHTMLElement.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIDOMHTMLHeadingElement */
#define NS_IDOMHTMLHEADINGELEMENT_IID_STR "e601aadf-e9e7-4605-a6f9-2cd2006723de"

#define NS_IDOMHTMLHEADINGELEMENT_IID \
  {0xe601aadf, 0xe9e7, 0x4605, \
    { 0xa6, 0xf9, 0x2c, 0xd2, 0x00, 0x67, 0x23, 0xde }}

class NS_NO_VTABLE nsIDOMHTMLHeadingElement : public nsIDOMHTMLElement {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMHTMLHEADINGELEMENT_IID)

  /* attribute DOMString align; */
  NS_IMETHOD GetAlign(nsAString & aAlign) = 0;
  NS_IMETHOD SetAlign(const nsAString & aAlign) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMHTMLHeadingElement, NS_IDOMHTMLHEADINGELEMENT_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMHTMLHEADINGELEMENT \
  NS_IMETHOD GetAlign(nsAString & aAlign); \
  NS_IMETHOD SetAlign(const nsAString & aAlign); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMHTMLHEADINGELEMENT(_to) \
  NS_IMETHOD GetAlign(nsAString & aAlign) { return _to GetAlign(aAlign); } \
  NS_IMETHOD SetAlign(const nsAString & aAlign) { return _to SetAlign(aAlign); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMHTMLHEADINGELEMENT(_to) \
  NS_IMETHOD GetAlign(nsAString & aAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAlign(aAlign); } \
  NS_IMETHOD SetAlign(const nsAString & aAlign) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAlign(aAlign); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMHTMLHeadingElement : public nsIDOMHTMLHeadingElement
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMHTMLHEADINGELEMENT

  nsDOMHTMLHeadingElement();

private:
  ~nsDOMHTMLHeadingElement();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMHTMLHeadingElement, nsIDOMHTMLHeadingElement)

nsDOMHTMLHeadingElement::nsDOMHTMLHeadingElement()
{
  /* member initializers and constructor code */
}

nsDOMHTMLHeadingElement::~nsDOMHTMLHeadingElement()
{
  /* destructor code */
}

/* attribute DOMString align; */
NS_IMETHODIMP nsDOMHTMLHeadingElement::GetAlign(nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsDOMHTMLHeadingElement::SetAlign(const nsAString & aAlign)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMHTMLHeadingElement_h__ */
