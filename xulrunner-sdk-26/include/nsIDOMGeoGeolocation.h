/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/dom/interfaces/geolocation/nsIDOMGeoGeolocation.idl
 */

#ifndef __gen_nsIDOMGeoGeolocation_h__
#define __gen_nsIDOMGeoGeolocation_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif
class nsIDOMGeoPositionCallback; /* forward declaration */

class nsIDOMGeoPositionErrorCallback; /* forward declaration */

#include "DictionaryHelpers.h"

/* starting interface:    nsIDOMGeoGeolocation */
#define NS_IDOMGEOGEOLOCATION_IID_STR "1bc7d103-c7ae-4467-881c-21a8dfa17938"

#define NS_IDOMGEOGEOLOCATION_IID \
  {0x1bc7d103, 0xc7ae, 0x4467, \
    { 0x88, 0x1c, 0x21, 0xa8, 0xdf, 0xa1, 0x79, 0x38 }}

class NS_NO_VTABLE nsIDOMGeoGeolocation : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_IDOMGEOGEOLOCATION_IID)

  /* int32_t watchPosition (in nsIDOMGeoPositionCallback callback, in nsIDOMGeoPositionErrorCallback errorCallback, in NamespacedGeoPositionOptions options); */
  NS_IMETHOD WatchPosition(nsIDOMGeoPositionCallback *callback, nsIDOMGeoPositionErrorCallback *errorCallback, mozilla::idl::GeoPositionOptions *options, int32_t *_retval) = 0;

  /* void getCurrentPosition (in nsIDOMGeoPositionCallback callback, in nsIDOMGeoPositionErrorCallback errorCallback, in NamespacedGeoPositionOptions options); */
  NS_IMETHOD GetCurrentPosition(nsIDOMGeoPositionCallback *callback, nsIDOMGeoPositionErrorCallback *errorCallback, mozilla::idl::GeoPositionOptions *options) = 0;

  /* void clearWatch (in long watchId); */
  NS_IMETHOD ClearWatch(int32_t watchId) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIDOMGeoGeolocation, NS_IDOMGEOGEOLOCATION_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSIDOMGEOGEOLOCATION \
  NS_IMETHOD WatchPosition(nsIDOMGeoPositionCallback *callback, nsIDOMGeoPositionErrorCallback *errorCallback, mozilla::idl::GeoPositionOptions *options, int32_t *_retval); \
  NS_IMETHOD GetCurrentPosition(nsIDOMGeoPositionCallback *callback, nsIDOMGeoPositionErrorCallback *errorCallback, mozilla::idl::GeoPositionOptions *options); \
  NS_IMETHOD ClearWatch(int32_t watchId); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSIDOMGEOGEOLOCATION(_to) \
  NS_IMETHOD WatchPosition(nsIDOMGeoPositionCallback *callback, nsIDOMGeoPositionErrorCallback *errorCallback, mozilla::idl::GeoPositionOptions *options, int32_t *_retval) { return _to WatchPosition(callback, errorCallback, options, _retval); } \
  NS_IMETHOD GetCurrentPosition(nsIDOMGeoPositionCallback *callback, nsIDOMGeoPositionErrorCallback *errorCallback, mozilla::idl::GeoPositionOptions *options) { return _to GetCurrentPosition(callback, errorCallback, options); } \
  NS_IMETHOD ClearWatch(int32_t watchId) { return _to ClearWatch(watchId); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSIDOMGEOGEOLOCATION(_to) \
  NS_IMETHOD WatchPosition(nsIDOMGeoPositionCallback *callback, nsIDOMGeoPositionErrorCallback *errorCallback, mozilla::idl::GeoPositionOptions *options, int32_t *_retval) { return !_to ? NS_ERROR_NULL_POINTER : _to->WatchPosition(callback, errorCallback, options, _retval); } \
  NS_IMETHOD GetCurrentPosition(nsIDOMGeoPositionCallback *callback, nsIDOMGeoPositionErrorCallback *errorCallback, mozilla::idl::GeoPositionOptions *options) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCurrentPosition(callback, errorCallback, options); } \
  NS_IMETHOD ClearWatch(int32_t watchId) { return !_to ? NS_ERROR_NULL_POINTER : _to->ClearWatch(watchId); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsDOMGeoGeolocation : public nsIDOMGeoGeolocation
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSIDOMGEOGEOLOCATION

  nsDOMGeoGeolocation();

private:
  ~nsDOMGeoGeolocation();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsDOMGeoGeolocation, nsIDOMGeoGeolocation)

nsDOMGeoGeolocation::nsDOMGeoGeolocation()
{
  /* member initializers and constructor code */
}

nsDOMGeoGeolocation::~nsDOMGeoGeolocation()
{
  /* destructor code */
}

/* int32_t watchPosition (in nsIDOMGeoPositionCallback callback, in nsIDOMGeoPositionErrorCallback errorCallback, in NamespacedGeoPositionOptions options); */
NS_IMETHODIMP nsDOMGeoGeolocation::WatchPosition(nsIDOMGeoPositionCallback *callback, nsIDOMGeoPositionErrorCallback *errorCallback, mozilla::idl::GeoPositionOptions *options, int32_t *_retval)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void getCurrentPosition (in nsIDOMGeoPositionCallback callback, in nsIDOMGeoPositionErrorCallback errorCallback, in NamespacedGeoPositionOptions options); */
NS_IMETHODIMP nsDOMGeoGeolocation::GetCurrentPosition(nsIDOMGeoPositionCallback *callback, nsIDOMGeoPositionErrorCallback *errorCallback, mozilla::idl::GeoPositionOptions *options)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* void clearWatch (in long watchId); */
NS_IMETHODIMP nsDOMGeoGeolocation::ClearWatch(int32_t watchId)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIDOMGeoGeolocation_h__ */
