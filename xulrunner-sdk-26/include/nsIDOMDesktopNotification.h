/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/dom/interfaces/notification/nsIDOMDesktopNotification.idl
 */

#ifndef __gen_nsIDOMDesktopNotification_h__
#define __gen_nsIDOMDesktopNotification_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIObserver; /* forward declaration */


/* starting interface:    nsIAppNotificationService */
#define NS_IAPPNOTIFICATIONSERVICE_IID_STR "7fb4f0f9-ff5b-4620-8e1b-d82d723605af"

#define NS_IAPPNOTIFICATIONSERVICE_IID \
  {0x7fb4f0f9, 0xff5b, 0x4620, \
    { 0x8e, 0x1b, 0xd8, 0x2d, 0x72, 0x36, 0x05, 0xaf }}

class NS_NO_VTABLE nsIAppNotificationService : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IAPPNOTIFICATIONSERVICE_IID)

  /* void showAppNotification (in AString imageUrl, in AString title, in AString text, [optional] in boolean textClickable, [optional] in AString manifestURL, [optional] in nsIObserver alertListener); */
  NS_IMETHOD ShowAppNotification(const nsAString & imageUrl, const nsAString & title, const nsAString & text, bool textClickable, const nsAString & manifestURL, nsIObserver *alertListener) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIAppNotificationService, NS_IAPPNOTIFICATIONSERVICE_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIAPPNOTIFICATIONSERVICE \
  NS_IMETHOD ShowAppNotification(const nsAString & imageUrl, const nsAString & title, const nsAString & text, bool textClickable, const nsAString & manifestURL, nsIObserver *alertListener); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIAPPNOTIFICATIONSERVICE(_to) \
  NS_IMETHOD ShowAppNotification(const nsAString & imageUrl, const nsAString & title, const nsAString & text, bool textClickable, const nsAString & manifestURL, nsIObserver *alertListener) { return _to ShowAppNotification(imageUrl, title, text, textClickable, manifestURL, alertListener); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIAPPNOTIFICATIONSERVICE(_to) \
  NS_IMETHOD ShowAppNotification(const nsAString & imageUrl, const nsAString & title, const nsAString & text, bool textClickable, const nsAString & manifestURL, nsIObserver *alertListener) { return !_to ? NS_ERROR_NULL_POINTER : _to->ShowAppNotification(imageUrl, title, text, textClickable, manifestURL, alertListener); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsAppNotificationService : public nsIAppNotificationService
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIAPPNOTIFICATIONSERVICE

  nsAppNotificationService();

private:
  ~nsAppNotificationService();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsAppNotificationService, nsIAppNotificationService)

nsAppNotificationService::nsAppNotificationService()
{
  /* member initializers and constructor code */
}

nsAppNotificationService::~nsAppNotificationService()
{
  /* destructor code */
}

/* void showAppNotification (in AString imageUrl, in AString title, in AString text, [optional] in boolean textClickable, [optional] in AString manifestURL, [optional] in nsIObserver alertListener); */
NS_IMETHODIMP nsAppNotificationService::ShowAppNotification(const nsAString & imageUrl, const nsAString & title, const nsAString & text, bool textClickable, const nsAString & manifestURL, nsIObserver *alertListener)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMDesktopNotification_h__ */
