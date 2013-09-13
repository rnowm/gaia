/*
 * DO NOT EDIT.  THIS FILE IS GENERATED FROM /builds/slave/m-cen-osx64-xr-ntly-0000000000/build/dom/interfaces/contacts/nsIContactProperties.idl
 */

#ifndef __gen_nsIContactProperties_h__
#define __gen_nsIContactProperties_h__


#ifndef __gen_domstubs_h__
#include "domstubs.h"
#endif

#include "jspubtd.h"

/* For IDL files that don't want to include root IDL files. */
#ifndef NS_NO_VTABLE
#define NS_NO_VTABLE
#endif

/* starting interface:    nsIContactAddress */
#define NS_ICONTACTADDRESS_IID_STR "9cbfa81c-bcab-4ca9-b0d2-f4318f295e33"

#define NS_ICONTACTADDRESS_IID \
  {0x9cbfa81c, 0xbcab, 0x4ca9, \
    { 0xb0, 0xd2, 0xf4, 0x31, 0x8f, 0x29, 0x5e, 0x33 }}

class NS_NO_VTABLE nsIContactAddress : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTACTADDRESS_IID)

  /* attribute DOMString type; */
  NS_IMETHOD GetType(nsAString & aType) = 0;
  NS_IMETHOD SetType(const nsAString & aType) = 0;

  /* attribute boolean pref; */
  NS_IMETHOD GetPref(bool *aPref) = 0;
  NS_IMETHOD SetPref(bool aPref) = 0;

  /* attribute DOMString streetAddress; */
  NS_IMETHOD GetStreetAddress(nsAString & aStreetAddress) = 0;
  NS_IMETHOD SetStreetAddress(const nsAString & aStreetAddress) = 0;

  /* attribute DOMString locality; */
  NS_IMETHOD GetLocality(nsAString & aLocality) = 0;
  NS_IMETHOD SetLocality(const nsAString & aLocality) = 0;

  /* attribute DOMString region; */
  NS_IMETHOD GetRegion(nsAString & aRegion) = 0;
  NS_IMETHOD SetRegion(const nsAString & aRegion) = 0;

  /* attribute DOMString postalCode; */
  NS_IMETHOD GetPostalCode(nsAString & aPostalCode) = 0;
  NS_IMETHOD SetPostalCode(const nsAString & aPostalCode) = 0;

  /* attribute DOMString countryName; */
  NS_IMETHOD GetCountryName(nsAString & aCountryName) = 0;
  NS_IMETHOD SetCountryName(const nsAString & aCountryName) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContactAddress, NS_ICONTACTADDRESS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTACTADDRESS \
  NS_IMETHOD GetType(nsAString & aType); \
  NS_IMETHOD SetType(const nsAString & aType); \
  NS_IMETHOD GetPref(bool *aPref); \
  NS_IMETHOD SetPref(bool aPref); \
  NS_IMETHOD GetStreetAddress(nsAString & aStreetAddress); \
  NS_IMETHOD SetStreetAddress(const nsAString & aStreetAddress); \
  NS_IMETHOD GetLocality(nsAString & aLocality); \
  NS_IMETHOD SetLocality(const nsAString & aLocality); \
  NS_IMETHOD GetRegion(nsAString & aRegion); \
  NS_IMETHOD SetRegion(const nsAString & aRegion); \
  NS_IMETHOD GetPostalCode(nsAString & aPostalCode); \
  NS_IMETHOD SetPostalCode(const nsAString & aPostalCode); \
  NS_IMETHOD GetCountryName(nsAString & aCountryName); \
  NS_IMETHOD SetCountryName(const nsAString & aCountryName); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTACTADDRESS(_to) \
  NS_IMETHOD GetType(nsAString & aType) { return _to GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return _to SetType(aType); } \
  NS_IMETHOD GetPref(bool *aPref) { return _to GetPref(aPref); } \
  NS_IMETHOD SetPref(bool aPref) { return _to SetPref(aPref); } \
  NS_IMETHOD GetStreetAddress(nsAString & aStreetAddress) { return _to GetStreetAddress(aStreetAddress); } \
  NS_IMETHOD SetStreetAddress(const nsAString & aStreetAddress) { return _to SetStreetAddress(aStreetAddress); } \
  NS_IMETHOD GetLocality(nsAString & aLocality) { return _to GetLocality(aLocality); } \
  NS_IMETHOD SetLocality(const nsAString & aLocality) { return _to SetLocality(aLocality); } \
  NS_IMETHOD GetRegion(nsAString & aRegion) { return _to GetRegion(aRegion); } \
  NS_IMETHOD SetRegion(const nsAString & aRegion) { return _to SetRegion(aRegion); } \
  NS_IMETHOD GetPostalCode(nsAString & aPostalCode) { return _to GetPostalCode(aPostalCode); } \
  NS_IMETHOD SetPostalCode(const nsAString & aPostalCode) { return _to SetPostalCode(aPostalCode); } \
  NS_IMETHOD GetCountryName(nsAString & aCountryName) { return _to GetCountryName(aCountryName); } \
  NS_IMETHOD SetCountryName(const nsAString & aCountryName) { return _to SetCountryName(aCountryName); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTACTADDRESS(_to) \
  NS_IMETHOD GetType(nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD SetType(const nsAString & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_IMETHOD GetPref(bool *aPref) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPref(aPref); } \
  NS_IMETHOD SetPref(bool aPref) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPref(aPref); } \
  NS_IMETHOD GetStreetAddress(nsAString & aStreetAddress) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetStreetAddress(aStreetAddress); } \
  NS_IMETHOD SetStreetAddress(const nsAString & aStreetAddress) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetStreetAddress(aStreetAddress); } \
  NS_IMETHOD GetLocality(nsAString & aLocality) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetLocality(aLocality); } \
  NS_IMETHOD SetLocality(const nsAString & aLocality) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetLocality(aLocality); } \
  NS_IMETHOD GetRegion(nsAString & aRegion) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetRegion(aRegion); } \
  NS_IMETHOD SetRegion(const nsAString & aRegion) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetRegion(aRegion); } \
  NS_IMETHOD GetPostalCode(nsAString & aPostalCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPostalCode(aPostalCode); } \
  NS_IMETHOD SetPostalCode(const nsAString & aPostalCode) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPostalCode(aPostalCode); } \
  NS_IMETHOD GetCountryName(nsAString & aCountryName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCountryName(aCountryName); } \
  NS_IMETHOD SetCountryName(const nsAString & aCountryName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCountryName(aCountryName); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContactAddress : public nsIContactAddress
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTACTADDRESS

  nsContactAddress();

private:
  ~nsContactAddress();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContactAddress, nsIContactAddress)

nsContactAddress::nsContactAddress()
{
  /* member initializers and constructor code */
}

nsContactAddress::~nsContactAddress()
{
  /* destructor code */
}

/* attribute DOMString type; */
NS_IMETHODIMP nsContactAddress::GetType(nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactAddress::SetType(const nsAString & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean pref; */
NS_IMETHODIMP nsContactAddress::GetPref(bool *aPref)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactAddress::SetPref(bool aPref)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString streetAddress; */
NS_IMETHODIMP nsContactAddress::GetStreetAddress(nsAString & aStreetAddress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactAddress::SetStreetAddress(const nsAString & aStreetAddress)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString locality; */
NS_IMETHODIMP nsContactAddress::GetLocality(nsAString & aLocality)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactAddress::SetLocality(const nsAString & aLocality)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString region; */
NS_IMETHODIMP nsContactAddress::GetRegion(nsAString & aRegion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactAddress::SetRegion(const nsAString & aRegion)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString postalCode; */
NS_IMETHODIMP nsContactAddress::GetPostalCode(nsAString & aPostalCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactAddress::SetPostalCode(const nsAString & aPostalCode)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString countryName; */
NS_IMETHODIMP nsContactAddress::GetCountryName(nsAString & aCountryName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactAddress::SetCountryName(const nsAString & aCountryName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIContactField */
#define NS_ICONTACTFIELD_IID_STR "ad19a543-69e4-44f0-adfa-37c011556bc1"

#define NS_ICONTACTFIELD_IID \
  {0xad19a543, 0x69e4, 0x44f0, \
    { 0xad, 0xfa, 0x37, 0xc0, 0x11, 0x55, 0x6b, 0xc1 }}

class NS_NO_VTABLE nsIContactField : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTACTFIELD_IID)

  /* attribute jsval type; */
  NS_IMETHOD GetType(JS::Value *aType) = 0;
  NS_IMETHOD SetType(const JS::Value & aType) = 0;

  /* attribute DOMString value; */
  NS_IMETHOD GetValue(nsAString & aValue) = 0;
  NS_IMETHOD SetValue(const nsAString & aValue) = 0;

  /* attribute boolean pref; */
  NS_IMETHOD GetPref(bool *aPref) = 0;
  NS_IMETHOD SetPref(bool aPref) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContactField, NS_ICONTACTFIELD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTACTFIELD \
  NS_IMETHOD GetType(JS::Value *aType); \
  NS_IMETHOD SetType(const JS::Value & aType); \
  NS_IMETHOD GetValue(nsAString & aValue); \
  NS_IMETHOD SetValue(const nsAString & aValue); \
  NS_IMETHOD GetPref(bool *aPref); \
  NS_IMETHOD SetPref(bool aPref); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTACTFIELD(_to) \
  NS_IMETHOD GetType(JS::Value *aType) { return _to GetType(aType); } \
  NS_IMETHOD SetType(const JS::Value & aType) { return _to SetType(aType); } \
  NS_IMETHOD GetValue(nsAString & aValue) { return _to GetValue(aValue); } \
  NS_IMETHOD SetValue(const nsAString & aValue) { return _to SetValue(aValue); } \
  NS_IMETHOD GetPref(bool *aPref) { return _to GetPref(aPref); } \
  NS_IMETHOD SetPref(bool aPref) { return _to SetPref(aPref); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTACTFIELD(_to) \
  NS_IMETHOD GetType(JS::Value *aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetType(aType); } \
  NS_IMETHOD SetType(const JS::Value & aType) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetType(aType); } \
  NS_IMETHOD GetValue(nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetValue(aValue); } \
  NS_IMETHOD SetValue(const nsAString & aValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetValue(aValue); } \
  NS_IMETHOD GetPref(bool *aPref) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPref(aPref); } \
  NS_IMETHOD SetPref(bool aPref) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPref(aPref); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContactField : public nsIContactField
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTACTFIELD

  nsContactField();

private:
  ~nsContactField();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContactField, nsIContactField)

nsContactField::nsContactField()
{
  /* member initializers and constructor code */
}

nsContactField::~nsContactField()
{
  /* destructor code */
}

/* attribute jsval type; */
NS_IMETHODIMP nsContactField::GetType(JS::Value *aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactField::SetType(const JS::Value & aType)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString value; */
NS_IMETHODIMP nsContactField::GetValue(nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactField::SetValue(const nsAString & aValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute boolean pref; */
NS_IMETHODIMP nsContactField::GetPref(bool *aPref)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactField::SetPref(bool aPref)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIContactTelField */
#define NS_ICONTACTTELFIELD_IID_STR "4d42c5a9-ea5d-4102-80c3-40cc986367ca"

#define NS_ICONTACTTELFIELD_IID \
  {0x4d42c5a9, 0xea5d, 0x4102, \
    { 0x80, 0xc3, 0x40, 0xcc, 0x98, 0x63, 0x67, 0xca }}

class NS_NO_VTABLE nsIContactTelField : public nsIContactField {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTACTTELFIELD_IID)

  /* attribute DOMString carrier; */
  NS_IMETHOD GetCarrier(nsAString & aCarrier) = 0;
  NS_IMETHOD SetCarrier(const nsAString & aCarrier) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContactTelField, NS_ICONTACTTELFIELD_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTACTTELFIELD \
  NS_IMETHOD GetCarrier(nsAString & aCarrier); \
  NS_IMETHOD SetCarrier(const nsAString & aCarrier); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTACTTELFIELD(_to) \
  NS_IMETHOD GetCarrier(nsAString & aCarrier) { return _to GetCarrier(aCarrier); } \
  NS_IMETHOD SetCarrier(const nsAString & aCarrier) { return _to SetCarrier(aCarrier); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTACTTELFIELD(_to) \
  NS_IMETHOD GetCarrier(nsAString & aCarrier) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCarrier(aCarrier); } \
  NS_IMETHOD SetCarrier(const nsAString & aCarrier) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCarrier(aCarrier); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContactTelField : public nsIContactTelField
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTACTTELFIELD

  nsContactTelField();

private:
  ~nsContactTelField();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContactTelField, nsIContactTelField)

nsContactTelField::nsContactTelField()
{
  /* member initializers and constructor code */
}

nsContactTelField::~nsContactTelField()
{
  /* destructor code */
}

/* attribute DOMString carrier; */
NS_IMETHODIMP nsContactTelField::GetCarrier(nsAString & aCarrier)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactTelField::SetCarrier(const nsAString & aCarrier)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIContactFindSortOptions */
#define NS_ICONTACTFINDSORTOPTIONS_IID_STR "0a5b1fab-70da-46dd-b902-619904d920c2"

#define NS_ICONTACTFINDSORTOPTIONS_IID \
  {0x0a5b1fab, 0x70da, 0x46dd, \
    { 0xb9, 0x02, 0x61, 0x99, 0x04, 0xd9, 0x20, 0xc2 }}

class NS_NO_VTABLE nsIContactFindSortOptions : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTACTFINDSORTOPTIONS_IID)

  /* attribute DOMString sortBy; */
  NS_IMETHOD GetSortBy(nsAString & aSortBy) = 0;
  NS_IMETHOD SetSortBy(const nsAString & aSortBy) = 0;

  /* attribute DOMString sortOrder; */
  NS_IMETHOD GetSortOrder(nsAString & aSortOrder) = 0;
  NS_IMETHOD SetSortOrder(const nsAString & aSortOrder) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContactFindSortOptions, NS_ICONTACTFINDSORTOPTIONS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTACTFINDSORTOPTIONS \
  NS_IMETHOD GetSortBy(nsAString & aSortBy); \
  NS_IMETHOD SetSortBy(const nsAString & aSortBy); \
  NS_IMETHOD GetSortOrder(nsAString & aSortOrder); \
  NS_IMETHOD SetSortOrder(const nsAString & aSortOrder); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTACTFINDSORTOPTIONS(_to) \
  NS_IMETHOD GetSortBy(nsAString & aSortBy) { return _to GetSortBy(aSortBy); } \
  NS_IMETHOD SetSortBy(const nsAString & aSortBy) { return _to SetSortBy(aSortBy); } \
  NS_IMETHOD GetSortOrder(nsAString & aSortOrder) { return _to GetSortOrder(aSortOrder); } \
  NS_IMETHOD SetSortOrder(const nsAString & aSortOrder) { return _to SetSortOrder(aSortOrder); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTACTFINDSORTOPTIONS(_to) \
  NS_IMETHOD GetSortBy(nsAString & aSortBy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSortBy(aSortBy); } \
  NS_IMETHOD SetSortBy(const nsAString & aSortBy) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSortBy(aSortBy); } \
  NS_IMETHOD GetSortOrder(nsAString & aSortOrder) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSortOrder(aSortOrder); } \
  NS_IMETHOD SetSortOrder(const nsAString & aSortOrder) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSortOrder(aSortOrder); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContactFindSortOptions : public nsIContactFindSortOptions
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTACTFINDSORTOPTIONS

  nsContactFindSortOptions();

private:
  ~nsContactFindSortOptions();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContactFindSortOptions, nsIContactFindSortOptions)

nsContactFindSortOptions::nsContactFindSortOptions()
{
  /* member initializers and constructor code */
}

nsContactFindSortOptions::~nsContactFindSortOptions()
{
  /* destructor code */
}

/* attribute DOMString sortBy; */
NS_IMETHODIMP nsContactFindSortOptions::GetSortBy(nsAString & aSortBy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactFindSortOptions::SetSortBy(const nsAString & aSortBy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString sortOrder; */
NS_IMETHODIMP nsContactFindSortOptions::GetSortOrder(nsAString & aSortOrder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactFindSortOptions::SetSortOrder(const nsAString & aSortOrder)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIContactFindOptions */
#define NS_ICONTACTFINDOPTIONS_IID_STR "28ce07d0-45d9-4b7a-8843-521df4edd8bc"

#define NS_ICONTACTFINDOPTIONS_IID \
  {0x28ce07d0, 0x45d9, 0x4b7a, \
    { 0x88, 0x43, 0x52, 0x1d, 0xf4, 0xed, 0xd8, 0xbc }}

class NS_NO_VTABLE nsIContactFindOptions : public nsIContactFindSortOptions {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTACTFINDOPTIONS_IID)

  /* attribute DOMString filterValue; */
  NS_IMETHOD GetFilterValue(nsAString & aFilterValue) = 0;
  NS_IMETHOD SetFilterValue(const nsAString & aFilterValue) = 0;

  /* attribute DOMString filterOp; */
  NS_IMETHOD GetFilterOp(nsAString & aFilterOp) = 0;
  NS_IMETHOD SetFilterOp(const nsAString & aFilterOp) = 0;

  /* attribute jsval filterBy; */
  NS_IMETHOD GetFilterBy(JS::Value *aFilterBy) = 0;
  NS_IMETHOD SetFilterBy(const JS::Value & aFilterBy) = 0;

  /* attribute unsigned long filterLimit; */
  NS_IMETHOD GetFilterLimit(uint32_t *aFilterLimit) = 0;
  NS_IMETHOD SetFilterLimit(uint32_t aFilterLimit) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContactFindOptions, NS_ICONTACTFINDOPTIONS_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTACTFINDOPTIONS \
  NS_IMETHOD GetFilterValue(nsAString & aFilterValue); \
  NS_IMETHOD SetFilterValue(const nsAString & aFilterValue); \
  NS_IMETHOD GetFilterOp(nsAString & aFilterOp); \
  NS_IMETHOD SetFilterOp(const nsAString & aFilterOp); \
  NS_IMETHOD GetFilterBy(JS::Value *aFilterBy); \
  NS_IMETHOD SetFilterBy(const JS::Value & aFilterBy); \
  NS_IMETHOD GetFilterLimit(uint32_t *aFilterLimit); \
  NS_IMETHOD SetFilterLimit(uint32_t aFilterLimit); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTACTFINDOPTIONS(_to) \
  NS_IMETHOD GetFilterValue(nsAString & aFilterValue) { return _to GetFilterValue(aFilterValue); } \
  NS_IMETHOD SetFilterValue(const nsAString & aFilterValue) { return _to SetFilterValue(aFilterValue); } \
  NS_IMETHOD GetFilterOp(nsAString & aFilterOp) { return _to GetFilterOp(aFilterOp); } \
  NS_IMETHOD SetFilterOp(const nsAString & aFilterOp) { return _to SetFilterOp(aFilterOp); } \
  NS_IMETHOD GetFilterBy(JS::Value *aFilterBy) { return _to GetFilterBy(aFilterBy); } \
  NS_IMETHOD SetFilterBy(const JS::Value & aFilterBy) { return _to SetFilterBy(aFilterBy); } \
  NS_IMETHOD GetFilterLimit(uint32_t *aFilterLimit) { return _to GetFilterLimit(aFilterLimit); } \
  NS_IMETHOD SetFilterLimit(uint32_t aFilterLimit) { return _to SetFilterLimit(aFilterLimit); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTACTFINDOPTIONS(_to) \
  NS_IMETHOD GetFilterValue(nsAString & aFilterValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilterValue(aFilterValue); } \
  NS_IMETHOD SetFilterValue(const nsAString & aFilterValue) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFilterValue(aFilterValue); } \
  NS_IMETHOD GetFilterOp(nsAString & aFilterOp) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilterOp(aFilterOp); } \
  NS_IMETHOD SetFilterOp(const nsAString & aFilterOp) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFilterOp(aFilterOp); } \
  NS_IMETHOD GetFilterBy(JS::Value *aFilterBy) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilterBy(aFilterBy); } \
  NS_IMETHOD SetFilterBy(const JS::Value & aFilterBy) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFilterBy(aFilterBy); } \
  NS_IMETHOD GetFilterLimit(uint32_t *aFilterLimit) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFilterLimit(aFilterLimit); } \
  NS_IMETHOD SetFilterLimit(uint32_t aFilterLimit) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFilterLimit(aFilterLimit); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContactFindOptions : public nsIContactFindOptions
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTACTFINDOPTIONS

  nsContactFindOptions();

private:
  ~nsContactFindOptions();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContactFindOptions, nsIContactFindOptions)

nsContactFindOptions::nsContactFindOptions()
{
  /* member initializers and constructor code */
}

nsContactFindOptions::~nsContactFindOptions()
{
  /* destructor code */
}

/* attribute DOMString filterValue; */
NS_IMETHODIMP nsContactFindOptions::GetFilterValue(nsAString & aFilterValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactFindOptions::SetFilterValue(const nsAString & aFilterValue)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString filterOp; */
NS_IMETHODIMP nsContactFindOptions::GetFilterOp(nsAString & aFilterOp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactFindOptions::SetFilterOp(const nsAString & aFilterOp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval filterBy; */
NS_IMETHODIMP nsContactFindOptions::GetFilterBy(JS::Value *aFilterBy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactFindOptions::SetFilterBy(const JS::Value & aFilterBy)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute unsigned long filterLimit; */
NS_IMETHODIMP nsContactFindOptions::GetFilterLimit(uint32_t *aFilterLimit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactFindOptions::SetFilterLimit(uint32_t aFilterLimit)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


/* starting interface:    nsIContactProperties */
#define NS_ICONTACTPROPERTIES_IID_STR "35ad8a4e-9486-44b6-883d-550f14635e49"

#define NS_ICONTACTPROPERTIES_IID \
  {0x35ad8a4e, 0x9486, 0x44b6, \
    { 0x88, 0x3d, 0x55, 0x0f, 0x14, 0x63, 0x5e, 0x49 }}

class NS_NO_VTABLE nsIContactProperties : public nsISupports {
 public: 

  NS_DECLARE_STATIC_IID_ACCESSOR(NS_ICONTACTPROPERTIES_IID)

  /* attribute jsval name; */
  NS_IMETHOD GetName(JS::Value *aName) = 0;
  NS_IMETHOD SetName(const JS::Value & aName) = 0;

  /* attribute jsval honorificPrefix; */
  NS_IMETHOD GetHonorificPrefix(JS::Value *aHonorificPrefix) = 0;
  NS_IMETHOD SetHonorificPrefix(const JS::Value & aHonorificPrefix) = 0;

  /* attribute jsval givenName; */
  NS_IMETHOD GetGivenName(JS::Value *aGivenName) = 0;
  NS_IMETHOD SetGivenName(const JS::Value & aGivenName) = 0;

  /* attribute jsval additionalName; */
  NS_IMETHOD GetAdditionalName(JS::Value *aAdditionalName) = 0;
  NS_IMETHOD SetAdditionalName(const JS::Value & aAdditionalName) = 0;

  /* attribute jsval familyName; */
  NS_IMETHOD GetFamilyName(JS::Value *aFamilyName) = 0;
  NS_IMETHOD SetFamilyName(const JS::Value & aFamilyName) = 0;

  /* attribute jsval honorificSuffix; */
  NS_IMETHOD GetHonorificSuffix(JS::Value *aHonorificSuffix) = 0;
  NS_IMETHOD SetHonorificSuffix(const JS::Value & aHonorificSuffix) = 0;

  /* attribute jsval nickname; */
  NS_IMETHOD GetNickname(JS::Value *aNickname) = 0;
  NS_IMETHOD SetNickname(const JS::Value & aNickname) = 0;

  /* attribute jsval email; */
  NS_IMETHOD GetEmail(JS::Value *aEmail) = 0;
  NS_IMETHOD SetEmail(const JS::Value & aEmail) = 0;

  /* attribute jsval photo; */
  NS_IMETHOD GetPhoto(JS::Value *aPhoto) = 0;
  NS_IMETHOD SetPhoto(const JS::Value & aPhoto) = 0;

  /* attribute jsval url; */
  NS_IMETHOD GetUrl(JS::Value *aUrl) = 0;
  NS_IMETHOD SetUrl(const JS::Value & aUrl) = 0;

  /* attribute jsval category; */
  NS_IMETHOD GetCategory(JS::Value *aCategory) = 0;
  NS_IMETHOD SetCategory(const JS::Value & aCategory) = 0;

  /* attribute jsval adr; */
  NS_IMETHOD GetAdr(JS::Value *aAdr) = 0;
  NS_IMETHOD SetAdr(const JS::Value & aAdr) = 0;

  /* attribute jsval tel; */
  NS_IMETHOD GetTel(JS::Value *aTel) = 0;
  NS_IMETHOD SetTel(const JS::Value & aTel) = 0;

  /* attribute jsval org; */
  NS_IMETHOD GetOrg(JS::Value *aOrg) = 0;
  NS_IMETHOD SetOrg(const JS::Value & aOrg) = 0;

  /* attribute jsval jobTitle; */
  NS_IMETHOD GetJobTitle(JS::Value *aJobTitle) = 0;
  NS_IMETHOD SetJobTitle(const JS::Value & aJobTitle) = 0;

  /* attribute jsval bday; */
  NS_IMETHOD GetBday(JS::Value *aBday) = 0;
  NS_IMETHOD SetBday(const JS::Value & aBday) = 0;

  /* attribute jsval note; */
  NS_IMETHOD GetNote(JS::Value *aNote) = 0;
  NS_IMETHOD SetNote(const JS::Value & aNote) = 0;

  /* attribute jsval impp; */
  NS_IMETHOD GetImpp(JS::Value *aImpp) = 0;
  NS_IMETHOD SetImpp(const JS::Value & aImpp) = 0;

  /* attribute jsval anniversary; */
  NS_IMETHOD GetAnniversary(JS::Value *aAnniversary) = 0;
  NS_IMETHOD SetAnniversary(const JS::Value & aAnniversary) = 0;

  /* attribute DOMString sex; */
  NS_IMETHOD GetSex(nsAString & aSex) = 0;
  NS_IMETHOD SetSex(const nsAString & aSex) = 0;

  /* attribute DOMString genderIdentity; */
  NS_IMETHOD GetGenderIdentity(nsAString & aGenderIdentity) = 0;
  NS_IMETHOD SetGenderIdentity(const nsAString & aGenderIdentity) = 0;

  /* attribute jsval key; */
  NS_IMETHOD GetKey(JS::Value *aKey) = 0;
  NS_IMETHOD SetKey(const JS::Value & aKey) = 0;

};

  NS_DEFINE_STATIC_IID_ACCESSOR(nsIContactProperties, NS_ICONTACTPROPERTIES_IID)

/* Use this macro when declaring classes that implement this interface. */
#define NS_DECL_NSICONTACTPROPERTIES \
  NS_IMETHOD GetName(JS::Value *aName); \
  NS_IMETHOD SetName(const JS::Value & aName); \
  NS_IMETHOD GetHonorificPrefix(JS::Value *aHonorificPrefix); \
  NS_IMETHOD SetHonorificPrefix(const JS::Value & aHonorificPrefix); \
  NS_IMETHOD GetGivenName(JS::Value *aGivenName); \
  NS_IMETHOD SetGivenName(const JS::Value & aGivenName); \
  NS_IMETHOD GetAdditionalName(JS::Value *aAdditionalName); \
  NS_IMETHOD SetAdditionalName(const JS::Value & aAdditionalName); \
  NS_IMETHOD GetFamilyName(JS::Value *aFamilyName); \
  NS_IMETHOD SetFamilyName(const JS::Value & aFamilyName); \
  NS_IMETHOD GetHonorificSuffix(JS::Value *aHonorificSuffix); \
  NS_IMETHOD SetHonorificSuffix(const JS::Value & aHonorificSuffix); \
  NS_IMETHOD GetNickname(JS::Value *aNickname); \
  NS_IMETHOD SetNickname(const JS::Value & aNickname); \
  NS_IMETHOD GetEmail(JS::Value *aEmail); \
  NS_IMETHOD SetEmail(const JS::Value & aEmail); \
  NS_IMETHOD GetPhoto(JS::Value *aPhoto); \
  NS_IMETHOD SetPhoto(const JS::Value & aPhoto); \
  NS_IMETHOD GetUrl(JS::Value *aUrl); \
  NS_IMETHOD SetUrl(const JS::Value & aUrl); \
  NS_IMETHOD GetCategory(JS::Value *aCategory); \
  NS_IMETHOD SetCategory(const JS::Value & aCategory); \
  NS_IMETHOD GetAdr(JS::Value *aAdr); \
  NS_IMETHOD SetAdr(const JS::Value & aAdr); \
  NS_IMETHOD GetTel(JS::Value *aTel); \
  NS_IMETHOD SetTel(const JS::Value & aTel); \
  NS_IMETHOD GetOrg(JS::Value *aOrg); \
  NS_IMETHOD SetOrg(const JS::Value & aOrg); \
  NS_IMETHOD GetJobTitle(JS::Value *aJobTitle); \
  NS_IMETHOD SetJobTitle(const JS::Value & aJobTitle); \
  NS_IMETHOD GetBday(JS::Value *aBday); \
  NS_IMETHOD SetBday(const JS::Value & aBday); \
  NS_IMETHOD GetNote(JS::Value *aNote); \
  NS_IMETHOD SetNote(const JS::Value & aNote); \
  NS_IMETHOD GetImpp(JS::Value *aImpp); \
  NS_IMETHOD SetImpp(const JS::Value & aImpp); \
  NS_IMETHOD GetAnniversary(JS::Value *aAnniversary); \
  NS_IMETHOD SetAnniversary(const JS::Value & aAnniversary); \
  NS_IMETHOD GetSex(nsAString & aSex); \
  NS_IMETHOD SetSex(const nsAString & aSex); \
  NS_IMETHOD GetGenderIdentity(nsAString & aGenderIdentity); \
  NS_IMETHOD SetGenderIdentity(const nsAString & aGenderIdentity); \
  NS_IMETHOD GetKey(JS::Value *aKey); \
  NS_IMETHOD SetKey(const JS::Value & aKey); 

/* Use this macro to declare functions that forward the behavior of this interface to another object. */
#define NS_FORWARD_NSICONTACTPROPERTIES(_to) \
  NS_IMETHOD GetName(JS::Value *aName) { return _to GetName(aName); } \
  NS_IMETHOD SetName(const JS::Value & aName) { return _to SetName(aName); } \
  NS_IMETHOD GetHonorificPrefix(JS::Value *aHonorificPrefix) { return _to GetHonorificPrefix(aHonorificPrefix); } \
  NS_IMETHOD SetHonorificPrefix(const JS::Value & aHonorificPrefix) { return _to SetHonorificPrefix(aHonorificPrefix); } \
  NS_IMETHOD GetGivenName(JS::Value *aGivenName) { return _to GetGivenName(aGivenName); } \
  NS_IMETHOD SetGivenName(const JS::Value & aGivenName) { return _to SetGivenName(aGivenName); } \
  NS_IMETHOD GetAdditionalName(JS::Value *aAdditionalName) { return _to GetAdditionalName(aAdditionalName); } \
  NS_IMETHOD SetAdditionalName(const JS::Value & aAdditionalName) { return _to SetAdditionalName(aAdditionalName); } \
  NS_IMETHOD GetFamilyName(JS::Value *aFamilyName) { return _to GetFamilyName(aFamilyName); } \
  NS_IMETHOD SetFamilyName(const JS::Value & aFamilyName) { return _to SetFamilyName(aFamilyName); } \
  NS_IMETHOD GetHonorificSuffix(JS::Value *aHonorificSuffix) { return _to GetHonorificSuffix(aHonorificSuffix); } \
  NS_IMETHOD SetHonorificSuffix(const JS::Value & aHonorificSuffix) { return _to SetHonorificSuffix(aHonorificSuffix); } \
  NS_IMETHOD GetNickname(JS::Value *aNickname) { return _to GetNickname(aNickname); } \
  NS_IMETHOD SetNickname(const JS::Value & aNickname) { return _to SetNickname(aNickname); } \
  NS_IMETHOD GetEmail(JS::Value *aEmail) { return _to GetEmail(aEmail); } \
  NS_IMETHOD SetEmail(const JS::Value & aEmail) { return _to SetEmail(aEmail); } \
  NS_IMETHOD GetPhoto(JS::Value *aPhoto) { return _to GetPhoto(aPhoto); } \
  NS_IMETHOD SetPhoto(const JS::Value & aPhoto) { return _to SetPhoto(aPhoto); } \
  NS_IMETHOD GetUrl(JS::Value *aUrl) { return _to GetUrl(aUrl); } \
  NS_IMETHOD SetUrl(const JS::Value & aUrl) { return _to SetUrl(aUrl); } \
  NS_IMETHOD GetCategory(JS::Value *aCategory) { return _to GetCategory(aCategory); } \
  NS_IMETHOD SetCategory(const JS::Value & aCategory) { return _to SetCategory(aCategory); } \
  NS_IMETHOD GetAdr(JS::Value *aAdr) { return _to GetAdr(aAdr); } \
  NS_IMETHOD SetAdr(const JS::Value & aAdr) { return _to SetAdr(aAdr); } \
  NS_IMETHOD GetTel(JS::Value *aTel) { return _to GetTel(aTel); } \
  NS_IMETHOD SetTel(const JS::Value & aTel) { return _to SetTel(aTel); } \
  NS_IMETHOD GetOrg(JS::Value *aOrg) { return _to GetOrg(aOrg); } \
  NS_IMETHOD SetOrg(const JS::Value & aOrg) { return _to SetOrg(aOrg); } \
  NS_IMETHOD GetJobTitle(JS::Value *aJobTitle) { return _to GetJobTitle(aJobTitle); } \
  NS_IMETHOD SetJobTitle(const JS::Value & aJobTitle) { return _to SetJobTitle(aJobTitle); } \
  NS_IMETHOD GetBday(JS::Value *aBday) { return _to GetBday(aBday); } \
  NS_IMETHOD SetBday(const JS::Value & aBday) { return _to SetBday(aBday); } \
  NS_IMETHOD GetNote(JS::Value *aNote) { return _to GetNote(aNote); } \
  NS_IMETHOD SetNote(const JS::Value & aNote) { return _to SetNote(aNote); } \
  NS_IMETHOD GetImpp(JS::Value *aImpp) { return _to GetImpp(aImpp); } \
  NS_IMETHOD SetImpp(const JS::Value & aImpp) { return _to SetImpp(aImpp); } \
  NS_IMETHOD GetAnniversary(JS::Value *aAnniversary) { return _to GetAnniversary(aAnniversary); } \
  NS_IMETHOD SetAnniversary(const JS::Value & aAnniversary) { return _to SetAnniversary(aAnniversary); } \
  NS_IMETHOD GetSex(nsAString & aSex) { return _to GetSex(aSex); } \
  NS_IMETHOD SetSex(const nsAString & aSex) { return _to SetSex(aSex); } \
  NS_IMETHOD GetGenderIdentity(nsAString & aGenderIdentity) { return _to GetGenderIdentity(aGenderIdentity); } \
  NS_IMETHOD SetGenderIdentity(const nsAString & aGenderIdentity) { return _to SetGenderIdentity(aGenderIdentity); } \
  NS_IMETHOD GetKey(JS::Value *aKey) { return _to GetKey(aKey); } \
  NS_IMETHOD SetKey(const JS::Value & aKey) { return _to SetKey(aKey); } 

/* Use this macro to declare functions that forward the behavior of this interface to another object in a safe way. */
#define NS_FORWARD_SAFE_NSICONTACTPROPERTIES(_to) \
  NS_IMETHOD GetName(JS::Value *aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetName(aName); } \
  NS_IMETHOD SetName(const JS::Value & aName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetName(aName); } \
  NS_IMETHOD GetHonorificPrefix(JS::Value *aHonorificPrefix) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHonorificPrefix(aHonorificPrefix); } \
  NS_IMETHOD SetHonorificPrefix(const JS::Value & aHonorificPrefix) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHonorificPrefix(aHonorificPrefix); } \
  NS_IMETHOD GetGivenName(JS::Value *aGivenName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGivenName(aGivenName); } \
  NS_IMETHOD SetGivenName(const JS::Value & aGivenName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetGivenName(aGivenName); } \
  NS_IMETHOD GetAdditionalName(JS::Value *aAdditionalName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAdditionalName(aAdditionalName); } \
  NS_IMETHOD SetAdditionalName(const JS::Value & aAdditionalName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAdditionalName(aAdditionalName); } \
  NS_IMETHOD GetFamilyName(JS::Value *aFamilyName) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetFamilyName(aFamilyName); } \
  NS_IMETHOD SetFamilyName(const JS::Value & aFamilyName) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetFamilyName(aFamilyName); } \
  NS_IMETHOD GetHonorificSuffix(JS::Value *aHonorificSuffix) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetHonorificSuffix(aHonorificSuffix); } \
  NS_IMETHOD SetHonorificSuffix(const JS::Value & aHonorificSuffix) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetHonorificSuffix(aHonorificSuffix); } \
  NS_IMETHOD GetNickname(JS::Value *aNickname) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNickname(aNickname); } \
  NS_IMETHOD SetNickname(const JS::Value & aNickname) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNickname(aNickname); } \
  NS_IMETHOD GetEmail(JS::Value *aEmail) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetEmail(aEmail); } \
  NS_IMETHOD SetEmail(const JS::Value & aEmail) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetEmail(aEmail); } \
  NS_IMETHOD GetPhoto(JS::Value *aPhoto) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetPhoto(aPhoto); } \
  NS_IMETHOD SetPhoto(const JS::Value & aPhoto) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetPhoto(aPhoto); } \
  NS_IMETHOD GetUrl(JS::Value *aUrl) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetUrl(aUrl); } \
  NS_IMETHOD SetUrl(const JS::Value & aUrl) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetUrl(aUrl); } \
  NS_IMETHOD GetCategory(JS::Value *aCategory) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetCategory(aCategory); } \
  NS_IMETHOD SetCategory(const JS::Value & aCategory) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetCategory(aCategory); } \
  NS_IMETHOD GetAdr(JS::Value *aAdr) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAdr(aAdr); } \
  NS_IMETHOD SetAdr(const JS::Value & aAdr) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAdr(aAdr); } \
  NS_IMETHOD GetTel(JS::Value *aTel) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetTel(aTel); } \
  NS_IMETHOD SetTel(const JS::Value & aTel) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetTel(aTel); } \
  NS_IMETHOD GetOrg(JS::Value *aOrg) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetOrg(aOrg); } \
  NS_IMETHOD SetOrg(const JS::Value & aOrg) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetOrg(aOrg); } \
  NS_IMETHOD GetJobTitle(JS::Value *aJobTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetJobTitle(aJobTitle); } \
  NS_IMETHOD SetJobTitle(const JS::Value & aJobTitle) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetJobTitle(aJobTitle); } \
  NS_IMETHOD GetBday(JS::Value *aBday) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetBday(aBday); } \
  NS_IMETHOD SetBday(const JS::Value & aBday) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetBday(aBday); } \
  NS_IMETHOD GetNote(JS::Value *aNote) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetNote(aNote); } \
  NS_IMETHOD SetNote(const JS::Value & aNote) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetNote(aNote); } \
  NS_IMETHOD GetImpp(JS::Value *aImpp) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetImpp(aImpp); } \
  NS_IMETHOD SetImpp(const JS::Value & aImpp) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetImpp(aImpp); } \
  NS_IMETHOD GetAnniversary(JS::Value *aAnniversary) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetAnniversary(aAnniversary); } \
  NS_IMETHOD SetAnniversary(const JS::Value & aAnniversary) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetAnniversary(aAnniversary); } \
  NS_IMETHOD GetSex(nsAString & aSex) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetSex(aSex); } \
  NS_IMETHOD SetSex(const nsAString & aSex) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetSex(aSex); } \
  NS_IMETHOD GetGenderIdentity(nsAString & aGenderIdentity) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetGenderIdentity(aGenderIdentity); } \
  NS_IMETHOD SetGenderIdentity(const nsAString & aGenderIdentity) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetGenderIdentity(aGenderIdentity); } \
  NS_IMETHOD GetKey(JS::Value *aKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->GetKey(aKey); } \
  NS_IMETHOD SetKey(const JS::Value & aKey) { return !_to ? NS_ERROR_NULL_POINTER : _to->SetKey(aKey); } 

#if 0
/* Use the code below as a template for the implementation class for this interface. */

/* Header file */
class nsContactProperties : public nsIContactProperties
{
public:
  NS_DECL_ISUPPORTS
  NS_DECL_NSICONTACTPROPERTIES

  nsContactProperties();

private:
  ~nsContactProperties();

protected:
  /* additional members */
};

/* Implementation file */
NS_IMPL_ISUPPORTS1(nsContactProperties, nsIContactProperties)

nsContactProperties::nsContactProperties()
{
  /* member initializers and constructor code */
}

nsContactProperties::~nsContactProperties()
{
  /* destructor code */
}

/* attribute jsval name; */
NS_IMETHODIMP nsContactProperties::GetName(JS::Value *aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactProperties::SetName(const JS::Value & aName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval honorificPrefix; */
NS_IMETHODIMP nsContactProperties::GetHonorificPrefix(JS::Value *aHonorificPrefix)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactProperties::SetHonorificPrefix(const JS::Value & aHonorificPrefix)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval givenName; */
NS_IMETHODIMP nsContactProperties::GetGivenName(JS::Value *aGivenName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactProperties::SetGivenName(const JS::Value & aGivenName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval additionalName; */
NS_IMETHODIMP nsContactProperties::GetAdditionalName(JS::Value *aAdditionalName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactProperties::SetAdditionalName(const JS::Value & aAdditionalName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval familyName; */
NS_IMETHODIMP nsContactProperties::GetFamilyName(JS::Value *aFamilyName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactProperties::SetFamilyName(const JS::Value & aFamilyName)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval honorificSuffix; */
NS_IMETHODIMP nsContactProperties::GetHonorificSuffix(JS::Value *aHonorificSuffix)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactProperties::SetHonorificSuffix(const JS::Value & aHonorificSuffix)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval nickname; */
NS_IMETHODIMP nsContactProperties::GetNickname(JS::Value *aNickname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactProperties::SetNickname(const JS::Value & aNickname)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval email; */
NS_IMETHODIMP nsContactProperties::GetEmail(JS::Value *aEmail)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactProperties::SetEmail(const JS::Value & aEmail)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval photo; */
NS_IMETHODIMP nsContactProperties::GetPhoto(JS::Value *aPhoto)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactProperties::SetPhoto(const JS::Value & aPhoto)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval url; */
NS_IMETHODIMP nsContactProperties::GetUrl(JS::Value *aUrl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactProperties::SetUrl(const JS::Value & aUrl)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval category; */
NS_IMETHODIMP nsContactProperties::GetCategory(JS::Value *aCategory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactProperties::SetCategory(const JS::Value & aCategory)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval adr; */
NS_IMETHODIMP nsContactProperties::GetAdr(JS::Value *aAdr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactProperties::SetAdr(const JS::Value & aAdr)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval tel; */
NS_IMETHODIMP nsContactProperties::GetTel(JS::Value *aTel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactProperties::SetTel(const JS::Value & aTel)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval org; */
NS_IMETHODIMP nsContactProperties::GetOrg(JS::Value *aOrg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactProperties::SetOrg(const JS::Value & aOrg)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval jobTitle; */
NS_IMETHODIMP nsContactProperties::GetJobTitle(JS::Value *aJobTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactProperties::SetJobTitle(const JS::Value & aJobTitle)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval bday; */
NS_IMETHODIMP nsContactProperties::GetBday(JS::Value *aBday)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactProperties::SetBday(const JS::Value & aBday)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval note; */
NS_IMETHODIMP nsContactProperties::GetNote(JS::Value *aNote)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactProperties::SetNote(const JS::Value & aNote)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval impp; */
NS_IMETHODIMP nsContactProperties::GetImpp(JS::Value *aImpp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactProperties::SetImpp(const JS::Value & aImpp)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval anniversary; */
NS_IMETHODIMP nsContactProperties::GetAnniversary(JS::Value *aAnniversary)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactProperties::SetAnniversary(const JS::Value & aAnniversary)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString sex; */
NS_IMETHODIMP nsContactProperties::GetSex(nsAString & aSex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactProperties::SetSex(const nsAString & aSex)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute DOMString genderIdentity; */
NS_IMETHODIMP nsContactProperties::GetGenderIdentity(nsAString & aGenderIdentity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactProperties::SetGenderIdentity(const nsAString & aGenderIdentity)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* attribute jsval key; */
NS_IMETHODIMP nsContactProperties::GetKey(JS::Value *aKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}
NS_IMETHODIMP nsContactProperties::SetKey(const JS::Value & aKey)
{
    return NS_ERROR_NOT_IMPLEMENTED;
}

/* End of implementation class template. */
#endif


#endif /* __gen_nsIContactProperties_h__ */
